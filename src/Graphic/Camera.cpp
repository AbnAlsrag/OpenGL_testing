#include "Camera.h"

namespace NAQH
{
    Camera::Camera(Window* p_window, glm::vec3 p_position)
    {
        width = p_window->GetWindowSize().x;
        height = p_window->GetWindowSize().y;
        lastTime = Utils::hireTimeInSecond();
        setDiff = 15;
        position = p_position;
    }

    void Camera::Matrix(float FOVdeg, float nearPlane, float farPlane, Shader* shader, const char* uniform)
    {
        // Initializes matrices since otherwise they will be the null matrix
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 projection = glm::mat4(1.0f);

        // Makes camera look in the right direction from the right position
        view = glm::lookAt(position, position + Orientation, Up);
        // Adds perspective to the scene
        projection = glm::perspective(glm::radians(FOVdeg), (float)width / height, nearPlane, farPlane);

        // Exports the camera matrix to the Vertex _Shader
        shader->setMatrix4(uniform, projection * view);
    }

    void Camera::Inputs(Window* p_window, Input* p_input)
    {
        width = p_window->GetWindowSize().x;
        height = p_window->GetWindowSize().y;

        // Fetches the coordinates of the cursor
        mouseX = p_input->MousePosition().x;
        mouseY = p_input->MousePosition().y;

        // Handles mouse inputs
        if(p_input->MouseButtonDown(p_input->right))
        {
            // Hides mouse cursor
            p_window->ShowCursor(false);

            if(p_input->KeyDown(p_input->Key_LCTRL))
            {
                speed = 0.001f;
            }
            else if(p_input->KeyDown(p_input->Key_LSHIFT))
            {
                speed = 0.04f;
            }
            else
            {
                speed = 0.01f;
            }

            // Handles key inputs
            if(p_input->KeyDown(p_input->Key_W))
            {
                position += speed * Orientation;
            }

            if(p_input->KeyDown(p_input->Key_A))
            {
                position += speed * -glm::normalize(glm::cross(Orientation, Up));
            }

            if(p_input->KeyDown(p_input->Key_S))
            {
                position += speed * -Orientation;
            }

            if(p_input->KeyDown(p_input->Key_D))
            {
                position += speed * glm::normalize(glm::cross(Orientation, Up));
            }

            if(p_input->KeyDown(p_input->Key_SPACE))
            {
                position += speed * Up;
            }

            if(p_input->KeyDown(p_input->Key_LALT))
            {
                position += speed * -Up;
            }

            // Prevents camera from jumping on the first click
            if(firstClick)
            {
                // p_window->SetMousePosition(p_window->GetWindowSize().x/2, p_window->GetWindowSize().y/2);
                firstClick = false;
            }
            
            if(mouseX <= 0)
            {
                mouseX = width-setDiff;
                lastMousePosition.x = mouseX;
                p_window->SetMousePosition(mouseX, p_input->MousePosition().y);
                diffX = 0;
            }
            else if(mouseX >= width-1)
            {
                mouseX = 0+setDiff;
                lastMousePosition.x = mouseX;
                p_window->SetMousePosition(mouseX, p_input->MousePosition().y);
                diffX = 0;
            }
            else
            {
                diffX = mouseX - lastMousePosition.x;
            }

            if(mouseY <= 0)
            {
                mouseY = height-setDiff;
                p_window->SetMousePosition(p_input->MousePosition().x, mouseY);
                diffY = 0;
            }
            else if(mouseY >= height-1)
            {
                mouseY = 0+setDiff;
                lastMousePosition.y = mouseY;
                p_window->SetMousePosition(p_input->MousePosition().x, mouseY);
                diffY = 0;
            }
            else
            {
                diffY = mouseY - lastMousePosition.y;
            }

            // Normalizes and shifts the coordinates of the cursor such that they begin in the middle of the screen
            // and then "transforms" them into degrees 
            float rotX = sensitivity * (diffY / 2);
            float rotY = sensitivity * (diffX / 2);

            // Calculates upcoming vertical change in the Orientation
            glm::vec3 newOrientation = glm::rotate(Orientation, glm::radians(-rotX), glm::normalize(glm::cross(Orientation, Up)));

            // Decides whether or not the next vertical Orientation is legal or not
            if(abs(glm::angle(newOrientation, Up) - glm::radians(90.0f)) <= glm::radians(85.0f))
            {
                Orientation = newOrientation;
            }

            // Rotates the Orientation left and right
            Orientation = glm::rotate(Orientation, glm::radians(-rotY), Up);

            lastMousePosition.x = mouseX;
            lastMousePosition.y = mouseY;
        }
        else if(p_input->MouseButtonReleased(p_input->right))
        {
            // Unhides cursor since camera is not looking around anymore
            p_window->ShowCursor(true);
            speed = 0.01f;

            // Makes sure the next time the camera looks around it doesn't jump
            firstClick = true;
            lastMousePosition = p_input->MousePosition();
        }
        else
        {
            speed = 0.01f;
            p_window->ShowCursor(true);
            lastMousePosition = p_input->MousePosition();
        }
    }
}
#include <sstream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "NAQH.h"

std::vector<Vertex> vertices = 
{    //Position                     //Color                      //Texture coords        //Normals
    {Vector3(-0.5f, -0.5f,  0.5), Vector3(1.0f, 1.0f, 1.0f), Vector2(1.0f,  1.0f), Vector3(1.0f, 1.0f, 1.0f)},
    {Vector3( 0.5f, -0.5f,  0.5), Vector3(1.0f, 1.0f, 1.0f), Vector2(1.0f,  0.0f), Vector3(1.0f, 1.0f, 1.0f)},
    {Vector3( 0.5f,  0.5f,  0.5), Vector3(1.0f, 1.0f, 1.0f), Vector2(0.0f,  0.0f), Vector3(1.0f, 1.0f, 1.0f)},
    {Vector3(-0.5f,  0.5f,  0.5), Vector3(1.0f, 1.0f, 1.0f), Vector2(0.0f,  1.0f), Vector3(1.0f, 1.0f, 1.0f)},
    {Vector3(-0.5f, -0.5f, -0.5), Vector3(1.0f, 1.0f, 1.0f), Vector2(0.0f, -1.0f), Vector3(1.0f, 1.0f, 1.0f)},
    {Vector3( 0.5f, -0.5f, -0.5), Vector3(1.0f, 1.0f, 1.0f), Vector2(0.0f,  0.0f), Vector3(1.0f, 1.0f, 1.0f)},
    {Vector3( 0.5f,  0.5f, -0.5), Vector3(1.0f, 1.0f, 1.0f), Vector2(1.0f,  0.0f), Vector3(1.0f, 1.0f, 1.0f)},
    {Vector3(-0.5f,  0.5f, -0.5), Vector3(1.0f, 1.0f, 1.0f), Vector2(1.0f, -1.0f), Vector3(1.0f, 1.0f, 1.0f)},
};

std::vector<unsigned int> indices =
{
    // front
    0, 1, 2,
    2, 3, 0,
    // right
    1, 5, 6,
    6, 2, 1,
    // back
    7, 6, 5,
    5, 4, 7,
    // left
    4, 0, 3,
    3, 7, 4,
    // bottom
    4, 5, 1,
    1, 0, 4,
    // top
    3, 2, 6,
    6, 7, 3
};

int main(int argc, char** argv)
{
    Application app({"NAQH", Vector2(1280, 720), RenderingApi::OpenGL});
    Window* window = app.GetWindow();
    Renderer* renderer = app.GetRenderer();
    Input* input = app.GetInput();

    SDL_Event event;

    bool gameRunning = true, isFull = false;
    unsigned int fps = 0, frames = 0, time = SDL_GetTicks();

    renderer->SetClearColor(GOODIE);

    Camera cam(window, glm::vec3(0.0f, 0.0f, 2.0f));

    Mesh cube1(vertices, indices);

    renderer->AddCamera(&cam);
    renderer->DrawMesh(&cube1);

    while(gameRunning)
    {
        input->Update();
        cam.Inputs(window, input);

        frames++;

        if(time + 1000 < SDL_GetTicks())
        {
            fps = frames;
            time = SDL_GetTicks();
            frames = 0;
        }

        std::stringstream title;
        title << "NAQH | FPS: " << fps;
        window->SetWindowTitle(title.str().c_str());

        while(SDL_PollEvent(&event) != 0)
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    gameRunning = false;
                    break;
            }
        }

        if(input->KeyPressed(input->Key_F1))
        {
            switch(isFull)
            {
                case false:
                    window->SetWindowFullscreen(Window::FullScreenType::BorderlessFullScreen);
                    isFull = true;
                    break;
                case true:
                    window->SetWindowFullscreen(Window::FullScreenType::NotFullScreen);
                    isFull = false;
                    break;
            }
        }

        renderer->SetViewport(Vector4(0, 0, window->GetWindowSize().x, window->GetWindowSize().y));

        renderer->Clear();
        renderer->Update();
        input->UpdatePrev();
    }

    return 0;
}
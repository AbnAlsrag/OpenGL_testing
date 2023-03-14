#ifndef CAMERA_H
#define CAMERA_H

#include "Graphic/Window.h"
#include "Graphic/Shader.h"
#include "Events/Input.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>

namespace NAQH
{
    class Camera
    {
	public:
		glm::vec3 position;
		glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
		glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);

		// Prevents the camera from jumping around when first clicking left click
		bool firstClick = true;

		// Stores the width and height of the window
		int width;
		int height;

		// Adjust the speed of the camera and it's sensitivity when looking around
		float speed = 0.01f;
		float sensitivity = 0.3f;

		// Camera constructor to set up initial values
		Camera(Window* p_window, glm::vec3 p_position);

		// Updates and exports the camera matrix to the Vertex _Shader
		void Matrix(float FOVdeg, float nearPlane, float farPlane, Shader* shader, const char* uniform);

		// Handles camera inputs
		void Inputs(Window* p_window, Input* p_input);
	private:
		float lastTime, diffX, diffY, mouseX, mouseY, setDiff;
		Vector2 lastMousePosition;
    };
}

#endif
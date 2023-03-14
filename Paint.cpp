#include <iostream>
#include <sstream>
#include <vector>

#include "NAQH.hpp"

// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";

GLfloat vertices[] =
{
	-0.4f, -0.4f, 0.0f,
	 0.4f,  0.4f, 0.0f,
	 0.4f, -0.4f, 0.0f
};

//SDL_HitTestResult MyCallback(SDL_Window* win, const SDL_Point* area, void* data)
//{
//	return SDL_HITTEST_DRAGGABLE;
//}

int main(int argc, char *args[])
{
	Window window("NAQH Engine", 1280, 720, SDL_WINDOW_MAXIMIZED);
	Renderer renderer(window);
	Input input;
	SDL_Point point;
	SDL_Event event;
	bool gameRunning = true;
	SDL_Rect rec, rev;
	Vector2 size;
	Vector3 color;
	size.x = 6;
	size.y = 6;
	//MyCallback(window.GetWindow(), &point, 0);
	//SDL_SetWindowHitTest(window.GetWindow(), MyCallback, 0);
	
	//glViewport(200, 200, 1280, 720);
//
	//GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	//glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	//glCompileShader(vertexShader);
//
	//GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	//glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	//glCompileShader(fragmentShader);
//
	//GLuint shaderProgram = glCreateProgram();
//
	//glAttachShader(shaderProgram, vertexShader);
	//glAttachShader(shaderProgram, fragmentShader);
	//glLinkProgram(shaderProgram);
//
	//glDeleteShader(vertexShader);
	//glDeleteShader(fragmentShader);
//
	//GLuint VAO, VBO;
//
	//glGenVertexArrays(1, &VAO);
	//glGenBuffers(1, &VBO);
	//glBindVertexArray(VAO);
	//glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	//glEnableVertexAttribArray(0);
//
	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindVertexArray(0);
//
	//glClear(GL_COLOR_BUFFER_BIT);
	//SDL_GL_SwapWindow(window.GetWindow());

	SDL_SetRenderDrawColor(window.GetRenderer(), 255, 255, 255, 255);
	SDL_RenderClear(window.GetRenderer());
	while (gameRunning)
	{
		input.Update();
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				gameRunning = false;
		}

		rev.x = 2;
		rev.y = 2;
		rev.h = size.x;
		rev.w = size.y;
		rec.h = size.x;
		rec.w = size.y;
		rec.x = input.MousePosition().x;
		rec.y = input.MousePosition().y;
		color.x = (input.KeyDown(SDL_SCANCODE_F1) ? color.x += 1 : color.x);
		color.x = (input.KeyDown(SDL_SCANCODE_F2) ? color.x -= 1 : color.x);
		color.y = (input.KeyDown(SDL_SCANCODE_F3) ? color.y += 1 : color.y);
		color.y = (input.KeyDown(SDL_SCANCODE_F4) ? color.y -= 1 : color.y);
		color.z = (input.KeyDown(SDL_SCANCODE_F5) ? color.z += 1 : color.z);
		color.z = (input.KeyDown(SDL_SCANCODE_F6) ? color.z -= 1 : color.z);
		color.x = (color.x < 0) ? 0 : color.x;
		color.x = (color.x > 255) ? 255 : color.x;
		color.y = (color.y < 0) ? 0 : color.y;
		color.y = (color.y > 255) ? 255 : color.y;
		color.z = (color.z < 0) ? 0 : color.z;
		color.z = (color.z > 255) ? 255 : color.z;
		size.x = (input.KeyDown(SDL_SCANCODE_F7) ? size.x += 1 : size.x);
		size.x = (input.KeyDown(SDL_SCANCODE_F8) ? size.x -= 1 : size.x);
		size.y = (input.KeyDown(SDL_SCANCODE_F7) ? size.y += 1 : size.y);
		size.y = (input.KeyDown(SDL_SCANCODE_F8) ? size.y -= 1 : size.y);
		size.x = (size.x < 6) ? 6 : size.x;
		size.x = (size.x > 120) ? 120 : size.x;
		size.y = (size.y < 6) ? 6 : size.y;
		size.y = (size.y > 120) ? 120 : size.y;
		if(input.KeyDown(SDL_SCANCODE_F10))
		{
			color.x = 255;
			color.y = 255;
			color.z = 255;
		}
		SDL_SetRenderDrawColor(window.GetRenderer(), color.x, color.y, color.z, 255);
		SDL_RenderFillRect(window.GetRenderer(), &rev);
		if(input.KeyDown(SDL_SCANCODE_F1)|input.KeyDown(SDL_SCANCODE_F2)|input.KeyDown(SDL_SCANCODE_F3)|input.KeyDown(SDL_SCANCODE_F4)|input.KeyDown(SDL_SCANCODE_F5)|input.KeyDown(SDL_SCANCODE_F6))
			Utils::Delay(4);
		if(input.KeyDown(SDL_SCANCODE_F7))
			Utils::Delay(20);
		if(input.KeyDown(SDL_SCANCODE_F8))
		{
			Utils::Delay(20);
			SDL_SetRenderDrawColor(window.GetRenderer(), 255, 255, 255, 255);
			SDL_RenderDrawRect(window.GetRenderer(), &rev);
			SDL_SetRenderDrawColor(window.GetRenderer(), color.x, color.y, color.z, 255);
		}
		if(input.KeyPressed(SDL_SCANCODE_F9))
		{
			SDL_SetRenderDrawColor(window.GetRenderer(), 255, 255, 255, 255);
			SDL_RenderClear(window.GetRenderer());
			SDL_SetRenderDrawColor(window.GetRenderer(), color.x, color.y, color.z, 255);
		}
		if(input.KeyPressed(SDL_SCANCODE_F11))
			SDL_RenderClear(window.GetRenderer());
		if(input.MouseButtonDown(input.left))
		{
			SDL_RenderFillRect(window.GetRenderer(), &rec);
		}
		SDL_RenderPresent(window.GetRenderer());
		if(input.KeyPressed(SDL_SCANCODE_F12))
		{
			SDL_SaveBMP(window.TakeScreenShot(window.GetWindowSize()), "screenshot.bmp");
		}

		//renderer.DrawColor(0.07, 0.13, 0.17);
		//glClear(GL_COLOR_BUFFER_BIT);
		//glUseProgram(shaderProgram);
		//glBindVertexArray(VAO);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		//SDL_GL_SwapWindow(window.GetWindow());

		input.UpdatePrev();
	}

	//glDeleteVertexArrays(1, &VAO);
	//glDeleteBuffers(1, &VBO);
	//glDeleteProgram(shaderProgram);

	window.Quit();

	return 0;
}
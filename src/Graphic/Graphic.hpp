#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>

#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>

#include "Math/Math.h"
#include "Utils/Utils.h"
#include "Events/Input.h"

using namespace NAQH;

namespace NAQH{ namespace Graphic{
	//Stuff
    struct _Color
    {
    public:
		_Color() {}
        _Color(float p_r, float p_g, float p_b, float p_a = 1.0);
		void Set(float p_r, float p_g, float p_b, float p_a = 1.0);

        float r, g, b, a;
    private:
    };

	static _Color GREY(192, 192, 192), DARK_GREY(128, 128, 128), VERY_DARK_GREY(64, 64, 64),
				 RED(255, 0, 0), DARK_RED(128, 0, 0), VERY_DARK_RED(64, 0, 0),
				 YELLOW(255, 255, 0), DARK_YELLOW(128, 128, 0), VERY_DARK_YELLOW(64, 64, 0),
				 GREEN(0, 255, 0), DARK_GREEN(0, 128, 0), VERY_DARK_GREEN(0, 64, 0),
				 CYAN(0, 255, 255), DARK_CYAN(0, 128, 128), VERY_DARK_CYAN(0, 64, 64),
				 BLUE(0, 0, 255), DARK_BLUE(0, 0, 128), VERY_DARK_BLUE(0, 0, 64),
				 MAGENTA(255, 0, 255), DARK_MAGENTA(128, 0, 128), VERY_DARK_MAGENTA(64, 0, 64),
				 WHITE(255, 255, 255), BLACK(0, 0, 0), BLANK(0, 0, 0, 0), GOODIE(0.07, 0.13, 0.17);

    struct _Texture
    {
    public:
		_Texture(const char* p_path);
		void Bind(int p_number = 0);
		void UnBind();
		void Delete();
    private:
		unsigned int texture;
    };

	struct Font
	{
	public:
		Font(const char* p_path);
	private:
	};

	struct MessageBoxData
	{
	public:
		MessageBoxData();
		void SetColor(_Color p_background, _Color p_text, _Color p_buttonBorder, _Color p_buttonBackground, _Color p_buttonSelected);
	private:
	};

    //_Window
	struct _Window 
	{
	public:
		enum FullScreenType {
		FullScreen = SDL_WINDOW_FULLSCREEN,
		BorderlessFullScreen = SDL_WINDOW_FULLSCREEN_DESKTOP,
		NotFullScreen = 0};

		enum ProgramType {
		BackGroundProgram = SDL_WINDOW_HIDDEN | SDL_WINDOW_SKIP_TASKBAR,
		BorderlessWindow = SDL_WINDOW_BORDERLESS,
		EditorWindow = SDL_WINDOW_BORDERLESS | SDL_WINDOW_SKIP_TASKBAR};
		
		enum MessageBox { OK };
		_Window(const char* p_title, int p_w, int p_h, Uint32 p_flag);
		_Window(const char* p_title, int p_w, int p_h);
		void SetMousePosition(int p_x, int p_y);
		void SetMousePositionGlobal(int p_x, int p_y);
		const char* GetWindowTitle();
		SDL_Window* GetWindow();
		SDL_Renderer* GetRenderer();
		SDL_Surface* TakeScreenShot(Vector2 p_size);
		SDL_Surface* TakeScreenShot(int p_x, int p_y);
		SDL_DisplayMode GetWindowDisplayMode();
		int SetWindowDisplayMode(SDL_DisplayMode p_displayMode);
		SDL_DisplayMode GetDesktopDisplayMode(int p_display = 0);
		void GetWindowPosition(int *out_x, int *out_y);
		void GetWindowSize(int *out_w, int *out_h);
		void SetScreenSaver(bool p_flag);
		SDL_Window* GrabbedWindow();
		int DisplayNum();
		void ResetWindow();
		void SetMouseArea(Vector4 p_area);
		Vector4 GetMouseArea();
		Uint32 GetWindowFlags();
		Vector2 GetWindowSize();
		Vector2 GetWindowCenter();
		bool IsScreenKeyboard();
		void SetMaximumSize(int p_w, int p_h);
		void SetMinimumSize(int p_w, int p_h);
		void GetMaximumSize(int* p_w, int* p_h);
		void GetMinimumSize(int* p_w, int* p_h);
		void GetWindowOpacity(float *out_opacity);
		float GetBrightness();
		void CalculateGammaRamp(float p_gamma, Uint16* p_ramp);
		Uint16* CalculateGammaRamp(float p_gamma);
		int SetGammaRamp(Uint16* p_red, Uint16* p_green, Uint16* p_blue);
		int SetGammaRamp(float p_red, float p_green, float p_blue);
		int GetGammaRamp(Uint16* p_red, Uint16* p_green, Uint16* p_blue);
		void SetCursor(SDL_Cursor *p_cursor);
		SDL_Cursor* GetCursor();
		SDL_Cursor* CreateCursor(Uint8* p_data, Uint8* p_mask, int p_w, int p_h, int p_x, int p_y);
		SDL_Cursor* CreateSysCursor(SDL_SystemCursor p_sysCursor);
		SDL_Cursor* CreateColorCursor(SDL_Surface* p_surface, int p_x, int p_y);
		void ClearCursor(SDL_Cursor* p_cursor);
		void SetWindowTitle(const char* p_title);
		void SetWindowIcon(SDL_Surface* p_icon);
		void SetWindowPosition(int p_x, int p_y);
		void SetWindowSize(int p_w, int p_h);
		void SetWindowOpacity(float p_opacity);
		void SetBrightness(float p_brightness);
		void SetWindowResizable(bool p_flag);
		void SetWindowFullscreen(FullScreenType p_flag);
		void SetWindowBorderless();
		int GetBorderSize(int* p_top, int* p_bottom, int* p_right, int* p_left);
		void AlwaysOnTop(SDL_bool p_flag);
		void HideWindow();
		int MouseRelative();
		int MouseRelative(bool p_flag);
		void RaiseWindow();
		void FlashWindow(SDL_FlashOperation p_operation);
		void ShowWindow();
		void ShowCursor(int p_flag);
		void ShowSimpleMessageBox(const char* p_title, const char* p_message);
		bool ShowSimpleMessageBox(const char* p_title, const char* p_message, MessageBox p_layout);
		bool ShowSimpleMessageBox(MessageBoxData p_data);
		void Quit();
	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
		SDL_DisplayMode windowDisplayMode;
		SDL_DisplayMode desktopDisplayMode;
	};

    //_Renderer
	struct Vertex
	{
	public:
		Vertex() { }

		Vertex(Vector3 p_position, _Color p_color, Vector2 p_texCoord, Vector3 p_normal);

		void Set(Vector3 p_position, _Color p_color, Vector2 p_texCoord, Vector3 p_normal);

		Vector3 position;
		_Color color;
		Vector2 texCoord;
		Vector3 normal;
	private:
	};

    struct _Renderer
    {
    public:
		enum RenderFlag { };

        _Renderer(_Window p_window);
        void DrawColor(float p_r, float p_g, float p_b, float p_a = 1.0);
        void DrawColor(_Color p_color);
		// void DrawMesh(_Mesh);
        void Update();
        void Clear();
		double GetFPS();
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
		double deltaTime, secondPerFrame, fps;
    };

	struct _Shader
	{
	public:
		_Shader(const char* p_vertexPath = "res/shader/defvert.nqShader", const char* p_fragmentPath = "res/shader/defFrag.nqShader");
		void Use();
		void Delete();
		void setBool(const char* p_name, bool p_value) const;
		void setInt(const char* p_name, int p_value) const;
		void setFloat(const char* p_name, float p_value) const;
		void setMatrix4(const char* p_name, glm::mat4 p_value) const;
		void setVector3(const char* p_name, glm::vec3 p_value) const;
		void setVector2(const char* p_name, glm::vec2 p_value) const;
	private:
		unsigned int shaderProgram;
	};

	struct _VertexArray
	{
	public:
		_VertexArray();
		void Bind();
		void Delete();
		unsigned int GetBuffer();
	private:
		unsigned int ID;
	};

	struct _VertexBuffer
	{
	public:
		_VertexBuffer(float* p_vertices, size_t p_size);
		void Bind();
		void Delete();
		unsigned int GetBuffer();
	private:
		unsigned int ID;
	};

	struct _IndexBuffer
	{
	public:
		_IndexBuffer(unsigned int* p_indices, size_t p_size);
		void Bind();
		void Delete();
		unsigned int GetBuffer();
	private:
		unsigned int ID;
	};

	//WIP
	class Model
	{
	public:
		Model(const char* p_path);
	private:

		Vertex* vertices;
	};

	//Deprecated
	class _Mesh
	{
	public:
		_Mesh(float* p_vertices, size_t p_vertexSize, unsigned int* p_indices, size_t p_indexSize)
		: vbo(p_vertices, p_vertexSize), ebo(p_indices, p_indexSize), shader(), position(glm::vec3(0, 0, 0)), color(0, 0, 0)
		{
			glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &bufferSize);
			trans = glm::mat4(1.0f);
		}

		_Mesh(float* p_vertices, size_t p_vertexSize, unsigned int* p_indices, size_t p_indexSize, const char* p_vertexPath, const char* p_fragmentPath)
		: vbo(p_vertices, p_vertexSize), ebo(p_indices, p_indexSize), shader(p_vertexPath, p_fragmentPath), color(0, 0, 0)
		{
			glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &bufferSize);
			trans = glm::mat4(1.0f);
		}

		_Mesh()
		: vbo(0, 0), ebo(0, 0), shader(), position(glm::vec3(0, 0, 0)), color(0, 0, 0)
		{
			glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &bufferSize);
			trans = glm::mat4(1.0f);
		}

		~_Mesh()
		{
			vao.Delete();
			vbo.Delete();
			ebo.Delete();
			shader.Delete();
		}
		
		void Draw()
		{
			vao.Bind();
			// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			glDrawElements(GL_TRIANGLES, bufferSize/sizeof(Uint16), GL_UNSIGNED_INT, 0);
		}

		glm::mat4 Rotate(Vector3 p_vec, float p_angle = 0.06f)
		{
			trans = glm::rotate(trans, glm::radians(p_angle), glm::vec3(p_vec.x, p_vec.y, p_vec.z));
			rotation.x += p_vec.x;
			rotation.y += p_vec.y;
			rotation.z += p_vec.z;
			return trans;
		}

		glm::mat4 SetRotate(Vector3 p_vec, float p_angle = 0.06f)
		{
			trans = glm::rotate(glm::radians(p_angle), glm::vec3(p_vec.x, p_vec.y, p_vec.z));
			trans = glm::translate(trans, position);
			trans = glm::scale(trans, size);
			rotation.x = p_vec.x;
			rotation.y = p_vec.y;
			rotation.z = p_vec.z;
			return trans;
		}

		glm::mat4 Translate(Vector3 p_vec)
		{
			trans = glm::translate(trans, glm::vec3(p_vec.x, p_vec.y, p_vec.z));
			position.x += p_vec.x;
			position.y += p_vec.y;
			position.z += p_vec.z;
			return trans;
		}

		glm::mat4 SetPosition(Vector3 p_vec)
		{
			trans = glm::translate(glm::vec3(p_vec.x, p_vec.y, p_vec.z));
			trans = glm::scale(trans, size);
			trans = glm::rotate(trans, glm::radians(0.06f), rotation);
			position.x = p_vec.x;
			position.y = p_vec.y;
			position.z = p_vec.z;
			return trans;
		}

		glm::mat4 Scale(Vector3 p_vec)
		{
			trans = glm::scale(trans, glm::vec3(p_vec.x, p_vec.y, p_vec.z));
			size.x += p_vec.x;
			size.y += p_vec.y;
			size.z += p_vec.z;
			return trans;
		}

		glm::mat4 SetScale(Vector3 p_vec)
		{
			trans = glm::scale(glm::vec3(p_vec.x, p_vec.y, p_vec.z));
			trans = glm::translate(trans, position);
			trans = glm::rotate(trans, glm::radians(0.06f), rotation);
			size.x = p_vec.x;
			size.y = p_vec.y;
			size.z = p_vec.z;
			return trans;
		}

		glm::vec3 GetPosition()
		{
			return position;
		}

		glm::vec3 GetSize()
		{
			return size;
		}

		glm::vec3 GetRotation()
		{
			return rotation;
		}

		_Shader* GetShader()
		{
			return &shader;
		}

	private:
		_VertexBuffer vbo;
		_VertexArray vao;
		_IndexBuffer ebo;
		_Shader shader;
		glm::mat4 trans;
		glm::vec3 position, size, rotation;
		_Color color;
		int bufferSize;
	};

	class _Camera
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

		// _Camera constructor to set up initial values
		_Camera(_Window p_window, glm::vec3 p_position)
		{
			width = p_window.GetWindowSize().x;
			height = p_window.GetWindowSize().y;
			lastTime = Utils::hireTimeInSecond();
			setDiff = 15;
			position = p_position;
		}

		// Updates and exports the camera matrix to the Vertex _Shader
		void Matrix(float FOVdeg, float nearPlane, float farPlane, _Shader* shader, const char* uniform)
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

		// Handles camera inputs
		void Inputs(_Window p_window, Input p_input)
		{
			width = p_window.GetWindowSize().x;
			height = p_window.GetWindowSize().y;

			// Fetches the coordinates of the cursor
			mouseX = p_input.MousePosition().x;
			mouseY = p_input.MousePosition().y;

			// Handles mouse inputs
			if(p_input.MouseButtonDown(p_input.right))
			{
				// Hides mouse cursor
				p_window.ShowCursor(false);

				// Handles key inputs
				if(p_input.KeyDown(p_input.Key_W))
				{
					position += speed * Orientation;
				}

				if(p_input.KeyDown(p_input.Key_A))
				{
					position += speed * -glm::normalize(glm::cross(Orientation, Up));
				}

				if(p_input.KeyDown(p_input.Key_S))
				{
					position += speed * -Orientation;
				}

				if(p_input.KeyDown(p_input.Key_D))
				{
					position += speed * glm::normalize(glm::cross(Orientation, Up));
				}

				if(p_input.KeyDown(p_input.Key_SPACE))
				{
					position += speed * Up;
				}

				if(p_input.KeyDown(p_input.Key_LALT))
				{
					position += speed * -Up;
				}

				if(p_input.KeyDown(p_input.Key_LCTRL))
				{
					speed = 0.001f;
				}
				else if(p_input.KeyReleased(p_input.Key_LCTRL))
				{
					speed = 0.01f;
				}

				if(p_input.KeyDown(p_input.Key_LSHIFT))
				{
					speed = 0.04f;
				}
				else if(p_input.KeyReleased(p_input.Key_LSHIFT))
				{
					speed = 0.01f;
				}

				// Prevents camera from jumping on the first click
				if(firstClick)
				{
					// p_window.SetMousePosition(p_window.GetWindowSize().x/2, p_window.GetWindowSize().y/2);
					firstClick = false;
				}
				
				if(mouseX <= 0)
				{
					mouseX = width-setDiff;
					lastMousePosition.x = mouseX;
					p_window.SetMousePosition(mouseX, p_input.MousePosition().y);
					diffX = 0;
				}
				else if(mouseX >= width-1)
				{
					mouseX = 0+setDiff;
					lastMousePosition.x = mouseX;
					p_window.SetMousePosition(mouseX, p_input.MousePosition().y);
					diffX = 0;
				}
				else
				{
					diffX = mouseX - lastMousePosition.x;
				}

				if(mouseY <= 0)
				{
					mouseY = height-setDiff;
					p_window.SetMousePosition(p_input.MousePosition().x, mouseY);
					diffY = 0;
				}
				else if(mouseY >= height-1)
				{
					mouseY = 0+setDiff;
					lastMousePosition.y = mouseY;
					p_window.SetMousePosition(p_input.MousePosition().x, mouseY);
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
			else if(p_input.MouseButtonReleased(p_input.right))
			{
				// Unhides cursor since camera is not looking around anymore
				p_window.ShowCursor(true);

				// Makes sure the next time the camera looks around it doesn't jump
				firstClick = true;
				lastMousePosition = p_input.MousePosition();
			}
			else
			{
				p_window.ShowCursor(true);
				lastMousePosition = p_input.MousePosition();
			}
		}
	private:
		float lastTime, diffX, diffY, mouseX, mouseY, setDiff;
		Vector2 lastMousePosition;
	};

	struct GUI
	{
	public:
		GUI(_Renderer* p_renderer);
	private:
	};
}}
#include "Graphic.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace NAQH{ namespace Graphic{
	_Color::_Color(float p_r, float p_g, float p_b, float p_a)
    :r(p_r), g(p_g), b(p_b), a(p_a)
    {
		r = (r > 255) ? 255 : r;
        r = (r < 0) ? 0 : r;
        r = (r > 1) ? r/255 : r;
		g = (g > 255) ? 255 : g;
        g = (g < 0) ? 0 : g;
        g = (g > 1) ? g/255 : g;
		b = (b > 255) ? 255 : b;
        b = (b < 0) ? 0 : b;
        b = (b > 1) ? b/255 : b;
		a = (a > 255) ? 255 : a;
        a = (a < 0) ? 0 : a;
        a = (a > 1) ? a/255 : a;
    }

	void _Color::Set(float p_r, float p_g, float p_b, float p_a)
	{
		r = p_r;
		g = p_g;
		b = p_b;
		a = p_a;
	}

	_Texture::_Texture(const char* p_path)
	{
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		int width, height, nrChannels;
		unsigned char* data = stbi_load(p_path, &width, &height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			printf("Failed to load texture: %s", p_path);
		}
		stbi_image_free(data);
	}

	void _Texture::Bind(int p_number)
	{
		glActiveTexture(GL_TEXTURE0 + p_number);
		glBindTexture(GL_TEXTURE_2D, texture);
	}

	void _Texture::UnBind()
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void _Texture::Delete()
	{
		glDeleteTextures(1, &texture);
	}
	
	

    //_Window
	//WANT TO REFACTOR
	/**
	 * Create an NAQH _Window
	 * \param p_title string for the title
	 * \param p_w int for the window width
	 * \param p_h int for the window height
	 * \param p_flag give it some sdl window flags
	*/
	_Window::_Window(const char* p_title, int p_w, int p_h, Uint32 p_flag)
	{	
		SDL_Init(SDL_INIT_VIDEO);
		window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, p_flag | SDL_WINDOW_OPENGL);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		SDL_SetWindowResizable(window, SDL_TRUE);
	}

	/**
	 * Create an NAQH _Window
	 * \param p_title string for the title
	 * \param p_w int for the window width
	 * \param p_h int for the window height
	*/
	_Window::_Window(const char* p_title, int p_w, int p_h)
	{	
		SDL_Init(SDL_INIT_VIDEO);
		window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_OPENGL);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		SDL_SetWindowResizable(window, SDL_TRUE);
	}

	/**Give you a pointer to your epic NAQH window*/
	SDL_Window* _Window::GetWindow()
	{
		return window;
	}

	/**Give you a pointer to your epic NAQH renderer*/
	SDL_Renderer* _Window::GetRenderer()
	{
		return renderer;
	}

	SDL_DisplayMode _Window::GetWindowDisplayMode()
	{
		SDL_GetWindowDisplayMode(window, &windowDisplayMode);
		return windowDisplayMode;
	}

	int _Window::SetWindowDisplayMode(SDL_DisplayMode p_displayMode)
	{
		return SDL_SetWindowDisplayMode(window, &p_displayMode);
	}

	SDL_DisplayMode _Window::GetDesktopDisplayMode(int p_display)
	{
		SDL_GetDesktopDisplayMode(p_display, &desktopDisplayMode);
		return desktopDisplayMode;
	}


	SDL_Surface* _Window::TakeScreenShot(Vector2 p_size)
	{
		SDL_Surface* shot = SDL_CreateRGBSurface(0, p_size.x, p_size.y, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
		SDL_RenderReadPixels(renderer, NULL, SDL_PIXELFORMAT_ARGB8888, shot->pixels, shot->pitch);
		return shot;
		SDL_FreeSurface(shot);
	}

	SDL_Surface* _Window::TakeScreenShot(int p_x, int p_y)
	{
		SDL_Surface* shot = SDL_CreateRGBSurface(0, p_x, p_y, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
		SDL_RenderReadPixels(renderer, NULL, SDL_PIXELFORMAT_ARGB8888, shot->pixels, shot->pitch);
		return shot;
		SDL_FreeSurface(shot);
	}

	void _Window::Quit()
	{
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
	}

	void _Window::ShowSimpleMessageBox(const char* p_title, const char* p_message)
	{
		SDL_ShowSimpleMessageBox(0, p_title, p_message, window);
	}

	//WIP
	bool _Window::ShowSimpleMessageBox(const char* p_title, const char* p_message, MessageBox p_layout)
	{
		if(p_layout == MessageBox::OK)
		{

		}

		return false;
	}

	void _Window::SetScreenSaver(bool p_flag)
	{
		if (p_flag)
			SDL_EnableScreenSaver();
		else
			SDL_DisableScreenSaver();
	}

	SDL_Cursor* _Window::GetCursor()
	{
		return SDL_GetCursor();
	}

	SDL_Window* _Window::GrabbedWindow()
	{
		return SDL_GetGrabbedWindow();
	}

	int _Window::DisplayNum()
	{
		return SDL_GetNumVideoDisplays();
	}

	void _Window::ResetWindow()
	{
		SDL_RestoreWindow(window);
	}

	void _Window::SetMouseArea(Vector4 p_area)
	{
		SDL_Rect mouseArea;

		mouseArea.x = p_area.x;
		mouseArea.y = p_area.y;
		mouseArea.h = p_area.z;
		mouseArea.w = p_area.w;

		SDL_SetWindowMouseRect(window, &mouseArea);
	}

	Vector4 _Window::GetMouseArea()
	{
		return { (float)SDL_GetWindowMouseRect(window)->x, (float)SDL_GetWindowMouseRect(window)->y, (float)SDL_GetWindowMouseRect(window)->h, (float)SDL_GetWindowMouseRect(window)->w };
	}

	Uint32 _Window::GetWindowFlags()
	{
		return SDL_GetWindowFlags(window);
	}

	const char* _Window::GetWindowTitle()
	{
		return SDL_GetWindowTitle(window);
	}

	float _Window::GetBrightness()
	{
		return SDL_GetWindowBrightness(window);
	}

	bool _Window::IsScreenKeyboard()
	{
		if (SDL_IsScreenKeyboardShown(window))
			return true;
		else
			return false;
	}

	void _Window::GetWindowOpacity(float *out_opacity)
	{
		SDL_GetWindowOpacity(window, out_opacity);
	}

	void _Window::GetWindowPosition(int *out_x, int *out_y)
	{
		SDL_GetWindowPosition(window, out_x, out_y);
	}

	void _Window::GetWindowSize(int *out_w, int *out_h)
	{
		SDL_GetWindowSize(window, out_w, out_h);
	}

	void _Window::SetMaximumSize(int p_w, int p_h)
	{
		SDL_SetWindowMaximumSize(window, p_w, p_h);
	}

	void _Window::SetMinimumSize(int p_w, int p_h)
	{
		SDL_SetWindowMinimumSize(window, p_w, p_h);
	}

	void _Window::GetMaximumSize(int* p_w, int* p_h)
	{
		SDL_GetWindowMinimumSize(window, p_w, p_h);
	}

	void _Window::GetMinimumSize(int* p_w, int* p_h)
	{
		SDL_GetWindowMinimumSize(window, p_w, p_h);
	}

	Vector2 _Window::GetWindowSize()
	{
		int x, y;
		SDL_GetWindowSize(window, &x, &y);

		return Vector2(x, y);
	}

	Vector2 _Window::GetWindowCenter()
	{
		int x, y;
		SDL_GetWindowSize(window, &x, &y);

		return Vector2(x / 2, y / 2);
	}
	
	void _Window::SetCursor(SDL_Cursor *p_cursor)
	{
		SDL_SetCursor(p_cursor);
	}

	SDL_Cursor* _Window::CreateCursor(Uint8* p_data, Uint8* p_mask, int p_w, int p_h, int p_x, int p_y)
	{
		return SDL_CreateCursor(p_data, p_mask, p_w, p_h, p_x, p_y);
	}

	SDL_Cursor* _Window::CreateSysCursor(SDL_SystemCursor p_sysCursor)
	{
		return SDL_CreateSystemCursor(p_sysCursor);
	}

	SDL_Cursor* _Window::CreateColorCursor(SDL_Surface* p_surface, int p_x, int p_y)
	{
		return SDL_CreateColorCursor(p_surface, p_x, p_y);
	}

	void _Window::ClearCursor(SDL_Cursor* p_cursor)
	{
		SDL_FreeCursor(p_cursor);
	}

	void _Window::SetWindowTitle(const char* p_title)
	{
		SDL_SetWindowTitle(window, p_title);
	}

	void _Window::SetBrightness(float p_brightness)
	{
		SDL_SetWindowBrightness(window, p_brightness);
	}

	void _Window::SetWindowFullscreen(FullScreenType p_flag)
	{
		SDL_SetWindowFullscreen(window, p_flag);
	}

	void _Window::SetWindowBorderless()
	{
		SDL_SetWindowBordered(window, SDL_FALSE);
	}

	int _Window::GetBorderSize(int* p_top, int* p_bottom, int* p_right, int* p_left)
	{
		return SDL_GetWindowBordersSize(window, p_top, p_left, p_bottom, p_right);
	}

	void _Window::SetWindowIcon(SDL_Surface* p_icon)
	{
		SDL_SetWindowIcon(window, p_icon);
	}

	void _Window::SetWindowResizable(bool p_flag)
	{
		if(p_flag)
			SDL_SetWindowResizable(window, SDL_TRUE);
		else
			SDL_SetWindowResizable(window, SDL_FALSE);
	}

	void _Window::SetWindowOpacity(float p_opacity)
	{
		SDL_SetWindowOpacity(window, p_opacity);
	}

	void _Window::SetWindowPosition(int p_x, int p_y)
	{
		SDL_SetWindowPosition(window, p_x, p_y);
	}

	void _Window::SetWindowSize(int p_w, int p_h)
	{
		SDL_SetWindowSize(window, p_w, p_h);
	}

	void _Window::AlwaysOnTop(SDL_bool p_flag)
	{
		SDL_SetWindowAlwaysOnTop(window, p_flag);
	}

	void _Window::ShowCursor(int p_flag)
	{
		SDL_ShowCursor(p_flag);
	}

	void _Window::HideWindow()
	{
		SDL_HideWindow(window);
	}

	int _Window::MouseRelative()
	{
		return SDL_SetRelativeMouseMode(SDL_TRUE);
	}

	int _Window::MouseRelative(bool p_flag)
	{
		if (p_flag)
			return SDL_SetRelativeMouseMode(SDL_TRUE);
		else
			return SDL_SetRelativeMouseMode(SDL_FALSE);
	}

	void _Window::ShowWindow()
	{
		SDL_ShowWindow(window);
	}

	void _Window::RaiseWindow()
	{
		SDL_RaiseWindow(window);
	}

	void _Window::FlashWindow(SDL_FlashOperation p_operation)
	{
		SDL_FlashWindow(window, p_operation);
	}

	void _Window::SetMousePosition(int p_x, int p_y)
	{
		SDL_WarpMouseInWindow(window, p_x, p_y);
	}

	void _Window::SetMousePositionGlobal(int p_x, int p_y)
	{
		SDL_WarpMouseGlobal(p_x, p_y);
	}

	Vertex::Vertex(Vector3 p_position, _Color p_color, Vector2 p_texCoord, Vector3 p_normal)
	{
		position = p_position;
		color = p_color;
		texCoord = p_texCoord;
		normal = p_normal;
	}

	void Vertex::Set(Vector3 p_position, _Color p_color, Vector2 p_texCoord, Vector3 p_normal)
	{
		position = p_position;
		color = p_color;
		texCoord = p_texCoord;
		normal = p_normal;
	}

    //_Renderer
    _Renderer::_Renderer(_Window p_window)
    {
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

        window = p_window.GetWindow();
        SDL_GL_CreateContext(window);
        gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glEnable(GL_DEPTH_TEST);
		// glFrontFace(GL_CW);
		// glCullFace(GL_BACK);
		// glEnable(GL_CULL_FACE);
		// glEnable(GL_FRAMEBUFFER_SRGB);
    }

    void _Renderer::DrawColor(float p_r, float p_g, float p_b, float p_a)
    {
        glClearColor(p_r, p_g, p_b, p_a);
    }

    void _Renderer::DrawColor(_Color p_color)
    {
        glClearColor(p_color.r, p_color.g, p_color.b, p_color.a);
    }

    void _Renderer::Update()
    {
		unsigned int lastTime, newTime;
		lastTime = newTime;

        SDL_GL_SwapWindow(window);

		newTime = SDL_GetTicks();
		deltaTime = newTime - lastTime;
		secondPerFrame = deltaTime/1000.0;
		fps = 1000.0/deltaTime;
    }

    void _Renderer::Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

	double _Renderer::GetFPS()
	{
		return fps;
	}

	_Shader::_Shader(const char* p_vertexPath, const char* p_fragmentPath)
	{
		const char* vertexShaderSource = Utils::ReadFile(p_vertexPath);
		const char* fragmentShaderSource = Utils::ReadFile(p_fragmentPath);
		unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vertexShaderSource, NULL);
		glCompileShader(vertex);
		unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragment);
		shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertex);
		glAttachShader(shaderProgram, fragment);
		glLinkProgram(shaderProgram);
		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}

	void _Shader::Use()
	{
		glUseProgram(shaderProgram);
	}

	void _Shader::Delete()
	{
		glDeleteProgram(shaderProgram);
	}

	void _Shader::setBool(const char* p_name, bool p_value) const
	{
		glUniform1i(glGetUniformLocation(shaderProgram, p_name), (int)p_value);
	}

	void _Shader::setInt(const char* p_name, int p_value) const
	{
		glUniform1i(glGetUniformLocation(shaderProgram, p_name), p_value);
	}

	void _Shader::setFloat(const char* p_name, float p_value) const
	{
		glUniform1f(glGetUniformLocation(shaderProgram, p_name), p_value);
	}

	void _Shader::setMatrix4(const char* p_name, glm::mat4 p_value) const
	{
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram, p_name), 1, GL_FALSE, glm::value_ptr(p_value));
	}

	void _Shader::setVector3(const char* p_name, glm::vec3 p_value) const
	{
		glUniform3f(glGetUniformLocation(shaderProgram, p_name), p_value.x, p_value.y, p_value.z);
	}

	void _Shader::setVector2(const char* p_name, glm::vec2 p_value) const
	{
		glUniform2f(glGetUniformLocation(shaderProgram, p_name), p_value.x, p_value.y);
	}

	_VertexArray::_VertexArray()
	{
		glGenVertexArrays(1, &ID);
		glBindVertexArray(ID);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(9 * sizeof(float)));
		glEnableVertexAttribArray(3);
	}

	void _VertexArray::Bind()
	{
		glBindVertexArray(ID);
	}

	void _VertexArray::Delete()
	{
		glDeleteVertexArrays(1, &ID);
	}

	unsigned int _VertexArray::GetBuffer()
	{
		return ID;
	}

	_VertexBuffer::_VertexBuffer(float* p_vertices, size_t p_size)
	{
		glGenBuffers(1, &ID);
		glBindBuffer(GL_ARRAY_BUFFER, ID);
		glBufferData(GL_ARRAY_BUFFER, p_size, p_vertices, GL_STATIC_DRAW);
	}

	void _VertexBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, ID);
	}

	void _VertexBuffer::Delete()
	{
		glDeleteBuffers(1, &ID);
	}

	unsigned int _VertexBuffer::GetBuffer()
	{
		return ID;
	}

	_IndexBuffer::_IndexBuffer(unsigned int* p_indices, size_t p_size)
	{
		glGenBuffers(1, &ID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, p_size, p_indices, GL_STATIC_DRAW);
		// glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	void _IndexBuffer::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	}

	void _IndexBuffer::Delete()
	{
		glDeleteBuffers(1, &ID);
	}

	unsigned int _IndexBuffer::GetBuffer()
	{
		return ID;
	}
}}
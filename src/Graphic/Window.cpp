#include "Window.h"

namespace NAQH
{
    Window::Window(const char* p_title, int p_w, int p_h)
    {
		SDL_Init(SDL_INIT_VIDEO);
		m_window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
        SDL_ShowWindow(m_window);
    }

    Window::~Window()
    {
        SDL_DestroyWindow(m_window);
    }

    const char* Window::SetWindowTitle(const char* p_title)
    {
        if(p_title != NULL)
        {
            SDL_SetWindowTitle(m_window, p_title);
        }

        return SDL_GetWindowTitle(m_window);
    }

    void Window::SetMousePosition(int p_x, int p_y)
    {
        SDL_WarpMouseInWindow(m_window, p_x, p_y);
    }

    // void Window::SetMousePositionGlobal(int p_x, int p_y);

    SDL_Window* Window::GetWindow()
    {
        return m_window;
    }

    Vector2 Window::GetWindowPosition(Vector2 out_vec)
    {
        int x, y;
        SDL_GetWindowPosition(m_window, &x, &y);

        return Vector2(x, y);
    }

    Vector2 Window::GetWindowSize(Vector2 out_vec)
    {
        int x, y;
        SDL_GetWindowSize(m_window, &x, &y);

        return Vector2(x, y);
    }

    // void Window::ResetWindow();
    // void Window::SetMouseArea(Vector4 p_area);
    // Vector4 Window::GetMouseArea();
    // Vector2 Window::GetWindowCenter();
    // Vector2 Window::SetMaximumSize(Vector2 p_size);
    // Vector2 Window::SetMinimumSize(Vector2 p_size);
    // void Window::SetWindowIcon(SDL_Surface* p_icon);
    // Vector2 Window::SetWindowPosition(Vector2 p_vec);
    // Vector2 Window::SetWindowSize(Vector2 p_vec);
    // void Window::SetWindowResizable(bool p_flag);

    void Window::SetWindowFullscreen(FullScreenType p_flag)
    {
		SDL_SetWindowFullscreen(m_window, (unsigned int)p_flag);
    }

    void Window::ShowCursor(int p_flag)
    {
        SDL_ShowCursor(p_flag);
    }

    // void Window::ShowSimpleMessageBox(const char* p_title, const char* p_message);
}
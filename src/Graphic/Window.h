#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <glad/glad.h>

#include "Math/Math.h"
#include "Utils/Utils.h"
#include "Events/Input.h"

namespace NAQH
{
    class Window
    {
    public:
        enum class FullScreenType {
        FullScreen = SDL_WINDOW_FULLSCREEN,
        BorderlessFullScreen = SDL_WINDOW_FULLSCREEN_DESKTOP,
        NotFullScreen = 0};

        Window(const char* p_title, int p_w, int p_h);
        ~Window();

        void SetMousePosition(int p_x, int p_y);
        void SetMousePositionGlobal(int p_x, int p_y);
        SDL_Window* GetWindow();
        Vector2 GetWindowPosition(Vector2 out_vec = Vector2());
        Vector2 GetWindowSize(Vector2 out_vec = Vector2());
        void ResetWindow();
        void SetMouseArea(Vector4 p_area);
        Vector4 GetMouseArea();
        Vector2 GetWindowCenter();
        Vector2 SetMaximumSize(Vector2 p_size = Vector2(-1, -1));
        Vector2 SetMinimumSize(Vector2 p_size = Vector2(-1, -1));
        const char* SetWindowTitle(const char* p_title = NULL);
        void SetWindowIcon(SDL_Surface* p_icon);
        Vector2 SetWindowPosition(Vector2 p_vec = Vector2(-1, -1));
        Vector2 SetWindowSize(Vector2 p_vec = Vector2(-1, -1));
        void SetWindowResizable(bool p_flag);
        void SetWindowFullscreen(FullScreenType p_flag);
        void ShowCursor(int p_flag);
        void ShowSimpleMessageBox(const char* p_title, const char* p_message);
    private:
        SDL_Window* m_window;
    };
}
#endif
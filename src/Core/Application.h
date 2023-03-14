#ifndef APPLICATION_H
#define APPLICATION_H

#include "Graphic/RenderingApi.h"
#include "Graphic/Window.h"
#include "Graphic/Renderer.h"
#include "Events/Input.h"
#include "Math/Math.h"

namespace NAQH
{
    struct ApplicationSpec
    {
        const char* name;
        Vector2 size;
        RenderingApi api;
    };

    class Application
    {
    public:
        Application(ApplicationSpec p_appSpec);
        ~Application();
        
        void ChangeApi(RenderingApi p_api);

        inline Window* GetWindow() { return m_window; };
        inline Renderer* GetRenderer() { return m_renderer; };
        inline Input* GetInput() { return m_input; }
    private:
        Window* m_window;
        Renderer* m_renderer;
        Input* m_input;
        RenderingApi m_api;
    };
}

#endif
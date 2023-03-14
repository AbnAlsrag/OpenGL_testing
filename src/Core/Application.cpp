#include "Application.h"

namespace NAQH
{
    Application::Application(ApplicationSpec p_appSpec)
    {
        m_window = new Window(p_appSpec.name, p_appSpec.size.x, p_appSpec.size.y);
        m_input = new Input();
        m_renderer = Renderer::Create(m_window, p_appSpec.api);
    }

    Application::~Application()
    {
        delete m_window;
        delete m_input;
        delete m_renderer;
    }

    //For now the change api function dont work because we dont have any other rendering apis
    void Application::ChangeApi(RenderingApi p_api)
    {
        if(p_api != Renderer::GetRenderingApi() && Renderer::isSupportedApi(p_api))
        {
            m_api = p_api;
            delete m_renderer;
            m_renderer = Renderer::Create(m_window, p_api);
        }
    }
}
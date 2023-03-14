#include "Renderer.h"
#include "OpenGL/Renderer_OpenGL.h"

namespace NAQH
{
    RenderingApi Renderer::m_renderingApi = RenderingApi::None;

    RenderingApi Renderer::GetRenderingApi()
    {
        return m_renderingApi;
    }

    bool Renderer::isSupportedApi(RenderingApi p_api)
    {
        return true;
    }

    Renderer* Renderer::Create(Window* p_window, RenderingApi p_api)
    {
        if(isSupportedApi(p_api))
        {
            m_renderingApi = p_api;

            switch(p_api)
            {
                case RenderingApi::None:
                    return nullptr;
                case RenderingApi::OpenGL:
                    return new OpenGLRenderer(p_window);
                case RenderingApi::Vulkan:
                    return nullptr;
            }
        }
        else
        {
            m_renderingApi = RenderingApi::OpenGL;
            return new OpenGLRenderer(p_window);
        }

        return nullptr;
    }
}
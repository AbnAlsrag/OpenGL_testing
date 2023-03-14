#include "Shader.h"
#include "Renderer.h"
#include "OpenGL/Shader_OpenGL.h"

namespace NAQH
{
    Shader* Shader::Create(const char* p_vertexPath, const char* p_fragmentPath)
    {
        switch(Renderer::GetRenderingApi())
        {
            case RenderingApi::None:
                return nullptr;
            case RenderingApi::OpenGL:
                return new OpenGLShader(p_vertexPath, p_fragmentPath);
            case RenderingApi::Vulkan:
                return nullptr;
        }

        return nullptr;
    }
}
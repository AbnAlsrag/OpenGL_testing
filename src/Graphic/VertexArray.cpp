#include "VertexArray.h"
#include "OpenGL/VertexArray_OpenGL.h"
#include "Renderer.h"

namespace NAQH
{
    VertexArray* VertexArray::Create()
    {
        switch(Renderer::GetRenderingApi())
        {
            case RenderingApi::None:
                return nullptr;
            case RenderingApi::OpenGL:
                return new OpenGLVertexArray();
            case RenderingApi::Vulkan:
                return nullptr;
        }

        return nullptr;
    }
}
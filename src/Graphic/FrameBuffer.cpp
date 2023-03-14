#include "FrameBuffer.h"
#include "OpenGL/FrameBuffer_OpenGL.h"
#include "Renderer.h"

namespace NAQH
{
    FrameBuffer* FrameBuffer::Create()
    {
        switch(Renderer::GetRenderingApi())
        {
            case RenderingApi::None:
                return nullptr;
            case RenderingApi::OpenGL:
                return  nullptr;
            case RenderingApi::Vulkan:
                return nullptr;
        }

        return nullptr;
    }
}
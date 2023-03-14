#include "Renderer.h"
#include "Buffer.h"
#include "OpenGL/Buffer_OpenGL.h"

namespace NAQH
{
    VertexBuffer* VertexBuffer::Create(Vertex* p_vertices, unsigned int p_size)
    {
        switch(Renderer::GetRenderingApi())
        {
            case RenderingApi::None:
                return nullptr;
            case RenderingApi::OpenGL:
                return new OpenGLVertexBuffer(p_vertices, p_size);
            case RenderingApi::Vulkan:
                return nullptr;
        }

        return nullptr;
    }

    /*Vertex Buffer*/
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /*Index Buffer*/


    IndexBuffer* IndexBuffer::Create(unsigned int* p_indices, unsigned int p_size)
    {
        switch(Renderer::GetRenderingApi())
        {
            case RenderingApi::None:
                return nullptr;
            case RenderingApi::OpenGL:
                return new OpenGLIndexBuffer(p_indices, p_size);
            case RenderingApi::Vulkan:
                return nullptr;
        }

        return nullptr;
    }
}
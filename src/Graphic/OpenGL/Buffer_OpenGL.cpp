#include "Buffer_OpenGL.h"

#include <glad/glad.h>
#include <stdio.h>

namespace NAQH
{
    OpenGLVertexBuffer::OpenGLVertexBuffer(Vertex* p_vertices, unsigned int p_size)
    {
        glGenBuffers(1, &rendererID);
        glBindBuffer(GL_ARRAY_BUFFER, rendererID);
        glBufferData(GL_ARRAY_BUFFER, p_size * sizeof(Vertex), p_vertices, GL_STATIC_DRAW);
    }

    OpenGLVertexBuffer::~OpenGLVertexBuffer()
    {
        glDeleteBuffers(1, &rendererID);
    }

    void OpenGLVertexBuffer::Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, rendererID);
    }

    void OpenGLVertexBuffer::UnBind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    /*Vertex Buffer*/
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /*Index Buffer*/

    OpenGLIndexBuffer::OpenGLIndexBuffer(unsigned int* p_indices, unsigned int p_size)
    {
        glGenBuffers(1, &rendererID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, p_size, p_indices, GL_STATIC_DRAW);
    }

    OpenGLIndexBuffer::~OpenGLIndexBuffer()
    {
        glDeleteBuffers(1, &rendererID);
    }

    void OpenGLIndexBuffer::Bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererID);
    }

    void OpenGLIndexBuffer::UnBind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
}
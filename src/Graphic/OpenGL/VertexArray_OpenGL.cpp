#include "VertexArray_OpenGL.h"
#include "Graphic/Vertex.h"

#include <glad/glad.h>

namespace NAQH
{
    OpenGLVertexArray::OpenGLVertexArray()
    {
        glGenVertexArrays(1, &rendererID);
        glBindVertexArray(rendererID);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(offsetof(Vertex, position) * sizeof(float)));
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(offsetof(Vertex, color) * sizeof(float)));
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(offsetof(Vertex, texCoord) * sizeof(float)));
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(offsetof(Vertex, normal) * sizeof(float)));
        glEnableVertexAttribArray(3);
    }

    OpenGLVertexArray::~OpenGLVertexArray()
    {
        glDeleteVertexArrays(1, &rendererID);
    }

    void OpenGLVertexArray::Bind() const
    {
        glBindVertexArray(rendererID);
    }

    void OpenGLVertexArray::UnBind() const
    {
        glBindVertexArray(0);
    }
}
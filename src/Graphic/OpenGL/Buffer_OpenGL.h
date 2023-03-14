#ifndef BUFFER_OPENGL_H
#define BUFFER_OPENGL_H

#include "Graphic/Buffer.h"
#include "Graphic/Vertex.h"

namespace NAQH
{
    class OpenGLVertexBuffer : public VertexBuffer
    {
    public:
        OpenGLVertexBuffer(Vertex* p_vertices, unsigned int p_size);
        virtual ~OpenGLVertexBuffer();

        virtual void Bind() const override;
        virtual void UnBind() const override;
    private:
        unsigned int rendererID;
    };

    /*Vertex Buffer*/
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /*Index Buffer*/


    class OpenGLIndexBuffer : public IndexBuffer
    {
    public:
        OpenGLIndexBuffer(unsigned int* p_indices, unsigned int p_size);
        virtual ~OpenGLIndexBuffer();

        virtual void Bind() const override;
        virtual void UnBind() const override;
    private:
        unsigned int rendererID;
    };
}

#endif
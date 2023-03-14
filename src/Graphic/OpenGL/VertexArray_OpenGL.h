#ifndef VERTEX_ARRAY_OPENGL_H
#define VERTEX_ARRAY_OPENGL_H

#include "Graphic/VertexArray.h"

namespace NAQH
{
    class OpenGLVertexArray : public VertexArray
    {
    public:
        OpenGLVertexArray();
        virtual ~OpenGLVertexArray();

        virtual void Bind() const override;
        virtual void UnBind() const override;
    private:
        unsigned int rendererID;
    };
}

#endif
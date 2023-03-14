#ifndef BUFFER_H
#define BUFFER_H

#include "Vertex.h"

namespace NAQH
{
    class VertexBuffer
    {
    public:
        virtual ~VertexBuffer() {}

        virtual void Bind() const = 0;
        virtual void UnBind() const = 0;

        static VertexBuffer* Create(Vertex* p_vertices, unsigned int p_size);
    };

    /*Vertex Buffer*/
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /*Index Buffer*/


    class IndexBuffer
    {
    public:
        virtual ~IndexBuffer() {}

        virtual void Bind() const = 0;
        virtual void UnBind() const = 0;

        static IndexBuffer* Create(unsigned int* p_indices, unsigned int p_size);
    };
}

#endif
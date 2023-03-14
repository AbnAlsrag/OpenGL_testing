#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

namespace NAQH
{
    class VertexArray
    {
    public:
        virtual ~VertexArray() {}

        virtual void Bind() const = 0;
        virtual void UnBind() const = 0;

        static VertexArray* Create();
    };
}

#endif
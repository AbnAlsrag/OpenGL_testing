#ifndef FRAME_BUFFER_OPENGL_H
#define FRAME_BUFFER_OPENGL_H

#include "Graphic/FrameBuffer.h"

namespace NAQH
{
    class OpenGLFrameBuffer : public FrameBuffer
    {
    public:
        OpenGLFrameBuffer();
        virtual ~OpenGLFrameBuffer();
    };
}

#endif
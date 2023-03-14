#ifndef FRAME_BUFFER_H
#define FRAME_BUFFER_H

namespace NAQH
{
    class FrameBuffer
    {
    public:
        virtual ~FrameBuffer() {}

        static FrameBuffer* Create();
    };
}

#endif
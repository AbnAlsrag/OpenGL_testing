#ifndef NETWORK_H
#define NETWORK_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_net.h>

namespace NAQH
{
    struct Network
    {
    public:
        enum NetworkType
        {
            Server,
            Client
        };

        Network(NetworkType p_type);
        ~Network();

        void Update();
        void SetTarget(char* p_target);
        void SendData(void* p_data, unsigned int p_len);
        int OpenURL(const char* p_URL);
    private:
        char* m_target;
        void* m_data;
        unsigned int m_len;
        NetworkType m_type;
        TCPsocket m_server;
    };
}

#endif
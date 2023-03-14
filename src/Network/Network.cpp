#include "Network.h"

namespace NAQH
{
    Network::Network(NetworkType p_type)
    {
        m_type = p_type;

        SDLNet_Init();

        IPaddress ip;

        if(m_type == Server)
            SDLNet_ResolveHost(&ip, NULL, 7540);

        
        m_server = SDLNet_TCP_Open(&ip);
    }

    Network::~Network()
    {
        SDLNet_TCP_Close(m_server);
        SDLNet_Quit();
    }

    void Network::Update()
    {
        if(m_type == Server)
        {
            TCPsocket client = SDLNet_TCP_Accept(m_server);

            if(client)
            {
                SDLNet_TCP_Send(client, m_data, m_len);
                SDLNet_TCP_Close(client);
            }
        }
    }

    void Network::SetTarget(char* p_target)
    {
        m_target = p_target;
    }

    void Network::SendData(void* p_data, unsigned int p_len)
    {
        m_len = p_len;
        m_data = p_data;
    }

    int Network::OpenURL(const char* p_URL)
    {
        return SDL_OpenURL(p_URL);
    }
}
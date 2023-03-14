#ifndef RENDERER_OPENGL_H
#define RENDERER_OPENGL_H

#include "Graphic/Renderer.h"
#include "Graphic/Window.h"

#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <vector>

namespace NAQH
{
    class OpenGLRenderer : public Renderer
    {
    public:
        OpenGLRenderer(Window* p_window);
        ~OpenGLRenderer();

        virtual void SetViewport(Vector4 p_rect) override;
        virtual void SetClearColor(Color p_color) override;
        virtual void AddCamera(Camera* p_camera) override;
        virtual void DrawMesh(Mesh* p_mesh) override;
        virtual void Update() override;
        virtual void Clear() override;
    private:
        int m_bufferSize;
        SDL_Window* window;
        std::vector<Mesh*> meshes;
        std::vector<Camera*> cameras;
    };
}

#endif
#ifndef RENDERER_H
#define RENDERER_H

#include "RenderingApi.h"
#include "Window.h"
#include "Mesh.h"
#include "Camera.h"
#include "Color.h"
#include "Math/Math.h"

namespace NAQH
{
    class Renderer
    {
    public:
        virtual ~Renderer(){}

        virtual void SetViewport(Vector4 p_rect) = 0;
        virtual void SetClearColor(Color p_color) = 0;
        virtual void AddCamera(Camera* p_camera) = 0;
        virtual void DrawMesh(Mesh* p_mesh) = 0;
        virtual void Update() = 0;
        virtual void Clear() = 0;

        static RenderingApi GetRenderingApi();
        static bool isSupportedApi(RenderingApi p_api);
        static Renderer* Create(Window* p_window, RenderingApi p_api);
    private:
        static RenderingApi m_renderingApi;
    };
}
#endif
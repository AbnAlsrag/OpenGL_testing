#include "Renderer_OpenGL.h"

//TODO: Finish this shit
namespace NAQH
{
    OpenGLRenderer::OpenGLRenderer(Window* p_window)
    {
        window = p_window->GetWindow();
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

        SDL_GL_CreateContext(window);
        gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glEnable(GL_DEPTH_TEST);
        // glFrontFace(GL_CW);
		// glCullFace(GL_BACK);
		// glEnable(GL_CULL_FACE);
		// glEnable(GL_FRAMEBUFFER_SRGB);
    }

    OpenGLRenderer::~OpenGLRenderer()
    {

    }

    void OpenGLRenderer::SetViewport(Vector4 p_rect)
    {
        glViewport(p_rect.x, p_rect.y, p_rect.z, p_rect.w);
    }

    void OpenGLRenderer::SetClearColor(Color p_color)
    {
        glClearColor(p_color.r, p_color.g, p_color.b, p_color.a);
    }

    void OpenGLRenderer::AddCamera(Camera* p_camera)
    {
        cameras.push_back(p_camera);
    }

    void OpenGLRenderer::DrawMesh(Mesh* p_mesh)
    {
        meshes.push_back(p_mesh);
    }

    void OpenGLRenderer::Update()
    {
        for(Camera* camera : cameras)
        {
            for(Mesh* mesh : meshes)
            {
                camera->Matrix(45.0f, 0.01f, 100.0f, mesh->GetShader(), "camera");
                mesh->GetShader()->setMatrix4("transform", mesh->GetTransform());

                mesh->GetIBO()->Bind();
                mesh->GetVBO()->Bind();
                mesh->GetShader()->Use();
                mesh->GetVAO()->Bind();

    			// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    			glDrawElements(GL_TRIANGLES, mesh->GetIndexSize()/3, GL_UNSIGNED_INT, 0);
            }
        }

        SDL_GL_SwapWindow(window);
    }

    void OpenGLRenderer::Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
}
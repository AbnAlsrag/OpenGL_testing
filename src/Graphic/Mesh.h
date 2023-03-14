#ifndef MESH_H
#define MESH_H

#include "Buffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Vertex.h"
#include "Color.h"

#include <glm/glm.hpp>
#include <vector>

namespace NAQH
{
    class Mesh
    {
    public:
        Mesh();
        Mesh(std::vector<Vertex> p_vertices, std::vector<unsigned int> p_indices);

        unsigned int GetIndexSize();
        glm::mat4 GetTransform();
        VertexArray* GetVAO();
        VertexBuffer* GetVBO();
        IndexBuffer* GetIBO();
        Shader* GetShader();

        bool m_isStatic;
    private:
        glm::mat4 m_transform;
		glm::vec3 m_position, m_size, m_rotation;
        Shader* m_shader;
        VertexArray* m_vao;
        VertexBuffer* m_vbo;
        IndexBuffer* m_ibo;
        std::vector<Vertex> m_vertices;
        std::vector<unsigned int> m_indices;
    };
}

#endif
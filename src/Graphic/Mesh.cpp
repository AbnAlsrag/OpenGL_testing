#include "Mesh.h"

namespace NAQH
{
    Mesh::Mesh(std::vector<Vertex> p_vertices, std::vector<unsigned int> p_indices)
    {
        m_isStatic = false;
        m_vertices = p_vertices;
        m_indices = p_indices;
        m_transform = glm::mat4(1.0f);

        m_shader = Shader::Create();
        m_vbo = VertexBuffer::Create(m_vertices.data(), m_vertices.capacity());
        m_ibo = IndexBuffer::Create(m_indices.data(), m_indices.capacity());
        m_vao = VertexArray::Create();
    }

    unsigned int Mesh::GetIndexSize()
    {
        return m_indices.size();
    }

    glm::mat4 Mesh::GetTransform()
    {
        return m_transform;
    }

    VertexArray* Mesh::GetVAO()
    {
        return m_vao;
    }

    VertexBuffer* Mesh::GetVBO()
    {
        return m_vbo;
    }

    IndexBuffer* Mesh::GetIBO()
    {
        return m_ibo;
    }

    Shader* Mesh::GetShader()
    {
        return m_shader;
    }
}
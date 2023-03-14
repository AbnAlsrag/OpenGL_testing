#include "Shader_OpenGL.h"
#include "Utils/Utils.h"

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

namespace NAQH
{
    OpenGLShader::OpenGLShader(const char* p_vertexPath, const char* p_fragmentPath)
    {
        const char* vertexShaderSource = Utils::ReadFile(p_vertexPath);
        const char* fragmentShaderSource = Utils::ReadFile(p_fragmentPath);
        unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vertexShaderSource, NULL);
        glCompileShader(vertex);
        unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragment);
        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertex);
        glAttachShader(shaderProgram, fragment);
        glLinkProgram(shaderProgram);
        glDeleteShader(vertex);
        glDeleteShader(fragment);
    }

    void OpenGLShader::Use()
    {
        glUseProgram(shaderProgram);
    }

    void OpenGLShader::Delete()
    {
        glDeleteProgram(shaderProgram);
    }

    void OpenGLShader::setBool(const char* p_name, bool p_value) const
    {
        glUniform1i(glGetUniformLocation(shaderProgram, p_name), (int)p_value);
    }

    void OpenGLShader::setInt(const char* p_name, int p_value) const
    {
        glUniform1i(glGetUniformLocation(shaderProgram, p_name), p_value);
    }

    void OpenGLShader::setFloat(const char* p_name, float p_value) const
    {
        glUniform1f(glGetUniformLocation(shaderProgram, p_name), p_value);
    }

    void OpenGLShader::setMatrix4(const char* p_name, glm::mat4 p_value) const
    {
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, p_name), 1, GL_FALSE, glm::value_ptr(p_value));
    }

    void OpenGLShader::setVector3(const char* p_name, Vector3 p_value) const
    {
        glUniform3f(glGetUniformLocation(shaderProgram, p_name), p_value.x, p_value.y, p_value.z);
    }

    void OpenGLShader::setVector2(const char* p_name, Vector2 p_value) const
    {
        glUniform2f(glGetUniformLocation(shaderProgram, p_name), p_value.x, p_value.y);
    }
}
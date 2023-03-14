#ifndef SHADER_OPENGL_H
#define SHADER_OPENGL_H

#include "Graphic/Shader.h"
#include "Math/Math.h"

namespace NAQH
{
    class OpenGLShader : public Shader
    {
    public:
        OpenGLShader(const char* p_vertexPath = "res/shader/defvert.nqShader", const char* p_fragmentPath = "res/shader/defFrag.nqShader");

        virtual void Use() override;
        virtual void Delete() override;
        virtual void setBool(const char* p_name, bool p_value) const override;
        virtual void setInt(const char* p_name, int p_value) const override;
        virtual void setFloat(const char* p_name, float p_value) const override;
        virtual void setMatrix4(const char* p_name, glm::mat4 p_value) const override;
        virtual void setVector3(const char* p_name, Vector3 p_value) const override;
        virtual void setVector2(const char* p_name, Vector2 p_value) const override;
    private:
        unsigned int shaderProgram;
    };
}

#endif
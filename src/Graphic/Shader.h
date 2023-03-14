#ifndef SHADER_H
#define SHADER_H

#include "Math/Math.h"

#include <glm/glm.hpp>

namespace NAQH
{
    class Shader
    {
    public:
        virtual ~Shader() {}

        virtual void Use() = 0;
        virtual void Delete() = 0;
        virtual void setBool(const char* p_name, bool p_value) const = 0;
        virtual void setInt(const char* p_name, int p_value) const = 0;
        virtual void setFloat(const char* p_name, float p_value) const = 0;
        virtual void setMatrix4(const char* p_name, glm::mat4 p_value) const = 0;
        virtual void setVector3(const char* p_name, Vector3 p_value) const = 0;
        virtual void setVector2(const char* p_name, Vector2 p_value) const = 0;

        static Shader* Create(const char* p_vertexPath = "res/shader/defvert.nqShader", const char* p_fragmentPath = "res/shader/defFrag.nqShader");
    };
}

#endif
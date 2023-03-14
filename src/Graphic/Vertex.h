#ifndef VERTEX_H
#define VERTEX_H

#include "Color.h"
#include "Math/Math.h"

#include <glm/glm.hpp>

namespace NAQH
{
    struct Vertex
	{
		Vector3 position;
		Vector3 color;
		Vector2 texCoord;
		Vector3 normal;
	};
}

#endif
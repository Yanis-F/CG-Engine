#pragma once

#include "CG/Vector3.hpp"
#include "CG/Vector2.hpp"
#include "CG/Color.hpp"

namespace CG
{

struct Vertex
{
	Vector3 position;
	Vector3 normal;

	Color color;
	Vector2 textureUV; // will be ignored if no texture
};

}

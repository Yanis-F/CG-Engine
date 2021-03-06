#pragma once

#include "CG/GameObject.hpp"
#include "CG/math/Vector3.hpp"
#include "CG/Color.hpp"

namespace CG::prefabs {

class PointLight : public GameObject {
public:
	PointLight(const Vector3 &pos, const Color &color);

};

}
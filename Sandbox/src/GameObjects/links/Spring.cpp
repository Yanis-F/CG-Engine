#include <spdlog/spdlog.h>

#include <CG/components/Rigidbody.hpp>
#include <CG/components/renderer/LineRenderer.hpp>
#include <CG/components/Transform.hpp>

#include "GameObjects/links/Spring.hpp"

Spring::Spring(CG::GameObject &a, CG::GameObject &b, double force, double restLength)
	: m_obj1(a), m_obj2(b), m_force(force), m_restLength(restLength)
{
	setTag<"simulation_object"_hs>();

	addComponent<CG::LineRenderer>();
}

void Spring::update(double d)
{
	auto pos1 = m_obj1.getComponent<CG::Transform>().position;
	auto pos2 = m_obj2.getComponent<CG::Transform>().position;

	auto currentLength = CG::Vector3::distance(pos1, pos2);
	auto force_1to2 = (pos2 - pos1).normalized() * m_force * (currentLength - m_restLength);


	if (getGame()->isFrozen())
		return;

	m_obj1.getComponent<CG::Rigidbody>().addForce(force_1to2);
	m_obj2.getComponent<CG::Rigidbody>().addForce(-force_1to2);
}

void Spring::lateUpdate(double d)
{
	auto pos1 = m_obj1.getComponent<CG::Transform>().position;
	auto pos2 = m_obj2.getComponent<CG::Transform>().position;

	auto currentLength = CG::Vector3::distance(pos1, pos2);
	auto force_1to2 = (pos2 - pos1).normalized() * m_force * (currentLength - m_restLength);

	auto &lr = getComponent<CG::LineRenderer>();
	lr.from = pos1;
	lr.to = pos2;

	lr.material.color = CG::Color::lerp(CG::Color::Green(), CG::Color::Red(), std::min(1.0, force_1to2.magnitude() * 0.2));
}
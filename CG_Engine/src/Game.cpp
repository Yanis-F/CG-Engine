#include <stdexcept>

#include "CG/Game.hpp"
#include "CG/internal/components/ICollider.hpp"
#include "CG/components/collider/SphereCollider.hpp"

CG::AGame::AGame(const CG::Vector2 windowSize, const std::string &windowName) : m_window(windowSize, windowName), m_inputManager(m_window.getWindow())
{
	if (AGame::instance)
		throw std::logic_error("Cannot run two game at once");
	AGame::instance = this;
}

void CG::AGame::getAllColliders(std::function<void(AGameObject &, ICollider*)> func) noexcept
{
	auto view = m_world.view<SphereCollider>();
	view.each([&](auto e, SphereCollider &c) { func(*m_objects.at(e), &c); });
}

void CG::AGame::clearScene()
{
	for (auto &[e, obj] : m_objects)
		obj->destroy();
}

void CG::AGame::immediateDestroy(AGameObject::id_type obj) noexcept
{
	m_objects.erase(obj);
}

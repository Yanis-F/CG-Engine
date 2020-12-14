#pragma once

#include <vector>
#include <imgui.h>

#include "CG/Game.hpp"
#include "CG/Color.hpp"
#include "CG/Vector2.hpp"

#include "CG/ui/imfilebrowser.h"
#include <CG/prefabs/PointLight.hpp>

#include "GameObjects/Mesh.hpp"

class Sandbox : public CG::AGame {
public:
	Sandbox() : CG::AGame(CG::Vector2{ 1600, 900 }, "Sandbox")
	{}

	void start() override;
	void update(double deltatime) override;

private:
	ImGui::FileBrowser m_fileBrowser {ImGuiFileBrowserFlags_CloseOnEsc};

	std::vector<Mesh *> m_meshes;
	CG::prefabs::PointLight *m_pointLight;
};
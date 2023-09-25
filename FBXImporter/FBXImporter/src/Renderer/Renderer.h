#pragma once
#include "Texture3D.h"
#include "../Common.h"

namespace Renderer {

	void Init();
	void RenderFrame(float current_time=0.0f);
	void RenderEditorFrame();
	void RenderUI();
	void HotloadShaders();
	void WipeShadowMaps();
	void QueueUIForRendering(std::string textureName, int screenX, int screenY, bool centered);
	void QueueUIForRendering(UIRenderInfo renderInfo);
	void ToggleDrawingLights();
	void ToggleDrawingProbes();
	void ToggleDrawingLines();
	void ToggleRenderingAsVoxelDirectLighting();

	Texture3D& GetIndirectLightingTexture();
	int GetRenderWidth();
	int GetRenderHeight();
	void NextMode();
}
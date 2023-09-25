#pragma once

namespace Engine {

	void Run();
	void Init();
	void Update(float deltaTime);
	void RenderFrame(float current_time = 0.0f);
}
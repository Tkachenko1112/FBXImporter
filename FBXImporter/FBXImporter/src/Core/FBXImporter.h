#pragma once
#include <string>
#include <map>
#include <vector>
#include "../Renderer/Mesh.h"
#include "ofbx.h"


enum ACTION_TYPE { TRANSLATION, ROTATION, SCALE };

struct KeyFrame {
    int64_t time;
    ACTION_TYPE type;
    glm::vec3 translation = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f);
};

struct Channel {
    std::string boneName;
    std::vector<KeyFrame> keyFrames;
};

struct Animation {
    std::string _name;
    float duration;
    float ticksPerSecond;
    std::vector<Channel> channels;

    // Add any other data you might need for an animation.
};

struct SkinnedModel {
	std::vector<Mesh> _meshes;
	std::map<std::string, unsigned int> _boneMapping; 
	std::vector<Animation> _animations;
	std::vector<const ofbx::Object*> _bones;			// Ideally remove this obfx dependancy
};

namespace FBXImporter {

	void LoadFile(std::string filepath, SkinnedModel* out);

}
#pragma once
 
#include <glm\glm.hpp>

#include <vulkan\vulkan.h>

namespace guiTools 
{


	struct Rect{
		float x, y, w, h;
	};

	bool intersect(float x, float y, VkRect2D rect); //return true if a belong to rect
	bool intersect(glm::vec2 c, VkRect2D rect);//Return true if c belong to the rect
}


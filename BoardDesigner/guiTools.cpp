#include "guiTools.h"

namespace guiTools
{

	bool intersect(float x, float y, VkRect2D rect)
	{
		if (x<rect.offset.x || y<rect.offset.y || x>(rect.offset.x + rect.extent.width)|| (y>rect.offset.y + rect.extent.height)) {
			return false;
		}
		return true;
	}

	bool intersect(glm::vec2 c, VkRect2D rect)
	{
		return intersect(c.x, c.y, rect);
	}

}
#pragma once

#include <stdio.h>

#include "guiTools.h"
#include "GUIObject.h"
#include "Command.h"

#include <glm\glm.hpp>

#include <vulkan\vulkan.h>

class GUIButton : public GUIObject
{
public:
	GUIButton(float x, float y, float w, float h, float depth, glm::vec2 &mouse);
	virtual ~GUIButton();
	
	virtual void updateLogic(); //check if the button is pressed, entered
	

	void action();

	

protected:
	
	glm::vec2 &_mouseCoordPtr;

	bool _isEntered; 
	bool _isPressed; 
	VkRect2D rect;
	float _depth;

};


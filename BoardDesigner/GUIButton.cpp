#include "GUIButton.h"



GUIButton::GUIButton(float x, float y, float w, float h, float depth, glm::vec2 &mousePtr) : _isEntered(false), _isPressed(false),
	_depth(depth), _mouseCoordPtr(mousePtr)
{
	rect.offset.x = x;
	rect.offset.y = y;
	rect.extent.width = w;
	rect.extent.height = h;
}


GUIButton::~GUIButton()
{

}


void GUIButton::updateLogic()
{
	if (guiTools::intersect(_mouseCoordPtr, rect)) {
		
		if (!_isEntered) {
			_isEntered = true;
		}
	}
	else {
		if (_isEntered) {
			_isEntered = false;
		}
	}
}

#include "MainGUI.h"



MainGUI::MainGUI(glm::vec2 &mousePtr) : _mousePtr(mousePtr), _data(), _objects()
{
	initObjects();
}


MainGUI::~MainGUI()
{
	destroyObjects();
}

void MainGUI::updateLogic()
{
	for (size_t i = 0; i < _objects.size();i++) {
		_objects[i]->updateLogic();
	}
}

void MainGUI::generateGuiCoord()
{

}

void MainGUI::initObjects()
{

	if (_objects.size() > 0) {
		destroyObjects();
	}

	_objects.push_back(new GUIButton(10.0f, 10.0f, 10.0f, 10.0f, 0.1f, _mousePtr));


}

void MainGUI::destroyObjects()
{
	for (size_t i = 0; i < _objects.size(); i++) {
		delete _objects[i];
		_objects[i] = 0;
	}
}

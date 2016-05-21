#pragma once
#include <iostream>
#include <vector>

#include "guiTools.h"
#include "GUIButton.h"

#include <vulkan\vulkan.h>


struct GuiDataStructure
{
	float pos[3];
	float color[3];
};

struct indicesData {

};

struct DrawData
{

};


class MainGUI
{
public:
	MainGUI(glm::vec2 &mousePtr);
	~MainGUI();
	

	void update();
	void updateLogic();
	void drawQuad();
	void drawTexture();
	void clearGUI(float r, float g, float b, float a);

	bool beenUpdated() const;

	
	void getDrawQueue();

private:

	glm::vec2 &_mousePtr;

	std::vector<GuiDataStructure> _data;
	std::vector<GUIObject*> _objects;

	void generateGuiCoord();
	void initObjects();
	void buildCommandBuffers();

	void destroyObjects();

};


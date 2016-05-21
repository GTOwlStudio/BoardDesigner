#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <vector>

#ifdef _WIN32
#define VK_USE_PLATFORM_WIN32_KHR
#endif

#define GLM_FORCE_RADIANS
#define GLm_FORCE_DEPTH_To_ZERO

#include <vulkan\vulkan.h>
#include "core_base.h"
#include "MainGUI.h"

#define VERTEX_BUFFER_BIND_ID 0

#define USE_STAGING true

struct Vertex {
	float pos[3];
	float uv[2];
};

struct Texture {
	VkSampler sampler;
	VkImage image;
	VkImageLayout imageLayout;
	VkDeviceMemory deviceMemory;
	VkImageView view;
	uint32_t width, height;
	uint32_t mipLevels;
};

class BD_core : public core_base
{
protected:

	MainGUI gui;

	Texture texture;

	struct {
		VkBuffer buf;
		VkDeviceMemory mem;
		VkPipelineVertexInputStateCreateInfo inputState;
		std::vector<VkVertexInputBindingDescription> bindingDescriptions;
		std::vector<VkVertexInputAttributeDescription> attributeDescriptions;
	} vertices;
	
	struct {
		VkBuffer buf;
		VkDeviceMemory mem;
		uint32_t count;
	} indices;

	vkTools::UniformData uniformDataVS;

	struct {
		glm::mat4 projection;
		glm::mat4 model;
		float lodBias = 0.0f;
	} uboVS;

	struct {
		/*VkPipeline dtext; //Pipeline use to render text that is update frequentely
		VkPipeline faces; //Pipeline use to display faces		 (triangle)
		VkPipeline edges; //Pipeline use to display edges		 (lines)	
		VkPipeline vertices; //Pipelines use to display vertices (points)*/
		VkPipeline solid;
	} pipelines;

	VkPipelineLayout pipelineLayout;
	VkDescriptorSet descriptorSet;
	VkDescriptorSetLayout descriptorSetLayout;


	void buildCommandBuffers();
	void setImageLayout(VkCommandBuffer cmdBuffer, VkImage image, VkImageAspectFlags ascpectMask,
			VkImageLayout oldImageLayout, VkImageLayout newImageLayout, uint32_t mipLevel, uint32_t mipLevelCount);

	void generateCoord(float x, float y, float w, float h, float depth);
	void setupVertexDescription();
	void prepareUniformBuffers();
	void updateUniformBuffers();

	void setupDescriptorSetLayout();
	void setupDescriptorPool();
	void setupDescriptorSet();

	void preparePipelines();

	void loadTexture(std::string filename, VkFormat format, bool forceLinearTiling);

	void destroyTextureImage(Texture texture);

	virtual void viewChanged();

public:



	BD_core(bool enableValidation);
	~BD_core();
	
	void draw();

	virtual void prepare();
	virtual void render();



};


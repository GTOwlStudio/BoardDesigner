#include "vulkandebug.h"
#include <iostream>

namespace vkDebug
{
	int validationLayerCount = 1;
	const char *validationLayerNames[] = {
		"VK_LAYER_LUNARG_standard_validation"
	};

	PFN_vkCreateDebugReportCallbackEXT CreateDebugReportCallback;
	PFN_vkDestroyDebugReportCallbackEXT DestroyDebugReportCallback;
	PFN_vkDebugReportMessageEXT dbgBreakCallback;

	VkDebugReportCallbackEXT msgCallback;

	VkBool32 messageCallback(
		VkDebugReportFlagsEXT flags,
		VkDebugReportObjectTypeEXT objType,
		uint64_t srcObject,
		size_t location,
		int32_t msgCode,
		const char* pLayerPrefix,
		const char* pMsg,
		void* pUserData)
	{
		char *message = (char *)malloc(strlen(pMsg) + 100);

		assert(message);

		if (flags & VK_DEBUG_REPORT_ERROR_BIT_EXT)
		{
			std::cout << "ERROR: " << "[" << pLayerPrefix << "] Code " << msgCode << " : " << pMsg << "\n";
		}
		else
			if (flags & VK_DEBUG_REPORT_WARNING_BIT_EXT)
			{
				// Uncomment to see warnings
				std::cout << "WARNING: " << "[" << pLayerPrefix << "] Code " << msgCode << " : " << pMsg << "\n";
			}
			else
			{
				return false;
			}

		fflush(stdout);

		free(message);
		return false;
	}

	void setupDebugging(VkInstance instance, VkDebugReportFlagsEXT flags, VkDebugReportCallbackEXT callBack)
	{
		CreateDebugReportCallback = (PFN_vkCreateDebugReportCallbackEXT)vkGetInstanceProcAddr(instance, "vkCreateDebugReportCallbackEXT");
		DestroyDebugReportCallback = (PFN_vkDestroyDebugReportCallbackEXT)vkGetInstanceProcAddr(instance, "vkDestroyDebugReportCallbackEXT");
		dbgBreakCallback = (PFN_vkDebugReportMessageEXT)vkGetInstanceProcAddr(instance, "vkDebugReportMessageEXT");

		VkDebugReportCallbackCreateInfoEXT dbgCreateInfo = {};
		dbgCreateInfo.sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CREATE_INFO_EXT;
		dbgCreateInfo.pfnCallback = (PFN_vkDebugReportCallbackEXT)messageCallback;
		dbgCreateInfo.flags = flags;

		VkResult err = CreateDebugReportCallback(
			instance,
			&dbgCreateInfo,
			nullptr,
			&msgCallback);
		assert(!err);
	}

	void freeDebugCallback(VkInstance instance) {
		/*if (msgCallback !=VK_NULL_HANDLE) {
		TODO
		}*/
	}

}

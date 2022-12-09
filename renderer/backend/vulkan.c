#include "vulkan.h"

#include "app.h"

#include <vulkan.h>
#include <stdio.h>
#include <GLFW/glfw3.h>

bool initVulkan(Engine* engine) {
	bool result = createInstance((const char*)engine->name);
	if(result) return false;

	return true;
}

bool createInstance(const char* name) {
    VkInstance instance;

	VkApplicationInfo app_info = {};
	app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	app_info.pApplicationName = name;
	app_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	app_info.pEngineName = "Enuma";
	app_info.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	app_info.apiVersion = VK_API_VERSION_1_0;

	VkInstanceCreateInfo create_info = {};
	create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	create_info.pApplicationInfo = &app_info;
	
	uint32 glfw_extension_count = 0;
	const char** glfw_extensions;

	glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extension_count);

	create_info.enabledExtensionCount = glfw_extension_count;
	create_info.ppEnabledExtensionNames = glfw_extensions;

	create_info.enabledLayerCount = 0;

	VkResult result = vkCreateInstance(&create_info, NULL, &instance);

	if (result != VK_SUCCESS) {
		printf("Failed to create a Vulkan Instance!\n");
        return false;
    }

	return true;
}
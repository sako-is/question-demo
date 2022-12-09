#pragma once 

#include <vulkan.h>

#include <defines.h>

#include "app.h"
#include <renderer/render.h>

bool initVulkan(Engine* engine);

bool createInstance(const char* name);
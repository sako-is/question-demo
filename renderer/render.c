#include "render.h"

#include "./backend/vulkan.h"
#include <stdio.h>


void initRenderer(Engine* engine) {
    switch(engine->backend) {
        case 1:
            initVulkan(engine);
            break;
        case 2:
            printf("OpenGL backend not implemented yet\n");
            break;
        case 3:
            printf("DirectX backend not implemented yet\n");
            break;
    }
}
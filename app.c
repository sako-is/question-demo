#include "app.h"

#include <renderer/render.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GLFW/glfw3.h>

// ------------------------------------------------------------------------------------------------
// Implementation
// ------------------------------------------------------------------------------------------------
Engine createEngine(uint16 w, uint16 h, int backend, char* name) {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	Engine engine = { .w = w,
					  .h = h, 
                      .backend = backend,
					  .window = glfwCreateWindow(w, h, name, NULL, NULL),
					  .name = malloc(strlen(name)) 
					};
	if(engine.window == NULL) printf("no window :(");
					
	memset(engine.name, '\0', strlen(name));
	strcpy(engine.name, name);

	return engine;
}

bool runEngine(Engine* engine) {
    initRenderer(engine);

    if(!engine->onStart) { printf("onStart() function not defined"); return false; }
    engine->onStart();

	while (!glfwWindowShouldClose(engine->window)) {
		glfwPollEvents();
        if(!engine->Update) { printf("Update() function not defined"); return false; }
        engine->Update();
	}

	glfwDestroyWindow(engine->window);
	glfwTerminate();
    return true;
}

void destroyEngine(Engine* engine) { 
    freeVector(&engine->entities);
	free(engine->name); 
	engine->name = NULL; 
}

void* onStart() {
    printf("ENGINE STARTED\n");
    return NULL;
}

void* Update() {
    printf("Every frame\n");
    return NULL;
}

// ------------------------------------------------------------------------------------------------
// Test
// ------------------------------------------------------------------------------------------------
int main() {
	Engine engine = createEngine(1280, 720, 1, "Enuma 0.1");

    engine.onStart = &onStart;
    engine.Update = &Update;

	runEngine(&engine);
	
	destroyEngine(&engine);
}
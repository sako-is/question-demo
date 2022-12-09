#pragma once

#include <defines.h>

#include <string.h>
#include <GLFW/glfw3.h>

#include <renderer/render.h>
#include <containers/vector.h>

/*
 * @brief struct that holds the information about the engine instance
 * @field w width of the window
 * @field h height of the window
 * @field name title of the window
 */
typedef struct Engine {
	uint16 w;
	uint16 h;
    GLFWwindow* window;
    int backend;
    Vector entities;
	char* name;

    void* (*Update)();
    void* (*onStart)();
} Engine;

/*
 * @brief creates the engine instance
 * @param w width of the window to be created
 * @param h height of the window to be created
 * @param name name of the engine, any string
 * @return the engine instance
 */
Engine createEngine(uint16 w, uint16 h, int backend, char* name);

/*
 * @brief destroys the engine instance
 * @param engine pointer to engine instance
 * @note the createEngine() function cleans up the GLFW window on its own,
 * so this function only frees the char* name string
 */
bool runEngine(Engine* engine);

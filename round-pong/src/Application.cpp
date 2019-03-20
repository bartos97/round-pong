#include "pch.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Window.h"

int main() {
	auto window = Window::create();
	delete window;
	return 0;
}
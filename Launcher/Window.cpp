#include <iostream>
#include <GLFW/glfw3.h>

class Window {
public:
	void createWindow() {
		if (!glfwInit()) {
			print("Error Loading GLFW");
			return;
		};

		window = glfwCreateWindow(800, 600, "title", NULL, NULL);
		print("Window Created\n");

		if (window == NULL) {
			print("Window is NULL");
			close();
			return;
		}

		glfwMakeContextCurrent(window);
		glfwShowWindow(window);
	}

	bool isCloseRequested() {

		return glfwWindowShouldClose(window);
	};

	void update() {
		glfwSwapBuffers(window);
		glfwPollEvents();
	};

	void close()
	{
		print("Window Closed");
		glfwDestroyWindow(window);
		glfwTerminate();
	};

private:
	GLFWwindow* window;
	void print(std::string message) {
		std::cout << message << " \n" << std::endl << std::flush;
	}
};
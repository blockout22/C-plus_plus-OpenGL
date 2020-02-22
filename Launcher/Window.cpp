#include <iostream>
#include <sstream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <algorithm>

class Window {
public:

	//creates a new Window using GLFW
	void createWindow(int _width, int _height) {
		width = _width;
		height = _height;


		if (!glfwInit()) {
			print("Error Loading GLFW");
			return;
		};

		window = glfwCreateWindow(width, height, "Title", NULL, NULL);
		print("Window Created\n");

		if (window == NULL) {
			print("Window is NULL");
			close();
			return;
		}

		glfwMakeContextCurrent(window);
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		glfwShowWindow(window);
		glViewport(0, 0, width, height);
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

		lastTime = glfwGetTime();
	}

	//checks if the GLFW window has been closed using the X button
	bool isCloseRequested() {
		double currentTime = glfwGetTime();
		fps++;
		if (currentTime - lastTime >= 1.0) {
			fpsString.str(std::string());
			fpsString << "FPS " << fps;
			
			setTitle(fpsString.str().c_str());
			
			print("" + fpsString.str());
			fps = 0;
			lastTime = currentTime;
		}
		glClear(GL_COLOR_BUFFER_BIT);

		return glfwWindowShouldClose(window);
	};

	//can be called each frame and will attempt to update at the specified frames per second
	void sync(int target_fps) {
		if (target_fps <= 10) {
			return;
		}

		while (glfwGetTime() < fpsLimitTime + 1.0 / target_fps) {
		}
		fpsLimitTime += 1.0 / target_fps;
	}

	void setTitle(const char* title) {
		glfwSetWindowTitle(window, title);
	}

	//updates to the next frame on the GLFW window
	void update() {
		glfwSwapBuffers(window);
		glfwPollEvents();
	};

	//closes the GLFW windows and terminates it
	void close()
	{
		print("Window Closed");
		glfwDestroyWindow(window);
		glfwTerminate();
	};

private:
	GLFWwindow* window;
	int width;
	int height;
	double lastTime;
	double fpsLimitTime;
	int fps = 0;
	std::stringstream fpsString;

	void print(std::string message) {
		std::cout << message << std::endl;
	}
};
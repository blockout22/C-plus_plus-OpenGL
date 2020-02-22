#include <iostream>
#include "Window.cpp"

int main()
{
    Window window;

    window.createWindow(800, 600);

    while (!window.isCloseRequested()) {
       window.update();
       window.sync(60);
    }

    window.close();
    
}

#include <iostream>
#include "Window.cpp"

int main()
{
    Window window;

    window.createWindow(1600, 600);

    while (!window.isCloseRequested()) {
       window.update();
    }

    window.close();
    
}

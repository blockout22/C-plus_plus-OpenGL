#include <iostream>
#include "Window.cpp"

int main()
{
    Window window;

    window.createWindow();

    while (!window.isCloseRequested()) {
       window.update();
    }

    window.close();
    
}

#include "Window.h"
#include "resources.h"


int main() {

    Window window {800, 600, "hello"};
    window.run();

    resources::clear();
    
    return 0;
}
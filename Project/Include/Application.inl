#include <Application.hpp>

/*explicit*/ inline Application::Application() {}
/*virtual*/ inline Application::~Application() {}
/*virtual*/ inline void Application::OnInitialize(int argc, char** argv) {}
/*virtual*/ inline void Application::OnUpdate(float deltaTimeInSeconds) {}
/*virtual*/ inline void Application::OnResizingWindow(unsigned int width, unsigned int height) {}
/*virtual*/ inline void Application::OnKeyPressed(Key key) {}
/*virtual*/ inline void Application::OnKeyReleased(Key key) {}
/*virtual*/ inline void Application::OnMouseButtonPressed(EMouseButton button, int positionX, int positionY) {}
/*virtual*/ inline void Application::OnMouseButtonReleased(EMouseButton button, int positionX, int positionY) {}
/*virtual*/ inline void Application::OnMouseMoved(int positionX, int positionY) {}
/*virtual*/ inline void Application::OnMouseScrolled(int delta, int positionX, int positionY) {}
/*virtual*/ inline void Application::OnRelease() {}
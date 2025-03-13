// MainApp.cpp
#include "App.h"
#include "MainWindow.h"
#include <Alert.h>

App::App()
    : BApplication("application/x-vnd.settings-explorer") {}

void App::ReadyToRun() {
    MainWindow* window = new MainWindow();
    window->Show();
}

void App::AboutRequested() {
    // Show a simple About box
    BAlert* about = new BAlert("About", "Settings Explorer\n\nBy You!", "OK");
    about->Go();
}

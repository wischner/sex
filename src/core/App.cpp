// MainApp.cpp
#include "App.h"
#include "MainWindow.h"
#include "AboutWindow.h"

App::App()
    : BApplication("application/x-vnd.settings-explorer") {}

void App::ReadyToRun() {
    MainWindow* window = new MainWindow();
    window->Show();
}

void App::AboutRequested() {
    BWindow* mainWindow = dynamic_cast<BWindow*>(be_app->WindowAt(0));
    new AboutWindow(mainWindow);
}
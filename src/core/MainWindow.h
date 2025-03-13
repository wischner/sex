// MainWindow.h
#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <Window.h>

class MainMenu;
class FileView;
class FileOpenDialog;

class MainWindow : public BWindow {
public:
    MainWindow();
    virtual bool QuitRequested();
    virtual void MessageReceived(BMessage* message);

private:
    MainMenu* fMainMenu;
    FileView* fFileView;
    FileOpenDialog* fFileOpenDialog;
};

#endif

// MainWindow.cpp
#include <Application.h>
#include "MainWindow.h"
#include "MainMenu.h"
#include "FileView.h"
#include "FileOpenDialog.h"

#include <MenuBar.h>

MainWindow::MainWindow()
    : BWindow(BRect(100, 100, 800, 600), "Settings Explorer",
              B_TITLED_WINDOW, B_QUIT_ON_WINDOW_CLOSE) {

    // Create menu bar through MainMenu helper
    fMainMenu = new MainMenu(this);
    AddChild(fMainMenu->MenuBar());

    // Create the view where file contents will be displayed
    BRect contentRect = Bounds();
    contentRect.top = fMainMenu->MenuBar()->Bounds().Height() + 1;
    fFileView = new FileView(contentRect);
    AddChild(fFileView);

    // Create file open dialog
    fFileOpenDialog = new FileOpenDialog(this);
}

bool MainWindow::QuitRequested() {
    be_app->PostMessage(B_QUIT_REQUESTED);
    return true;
}

void MainWindow::MessageReceived(BMessage* message) {
    switch (message->what) {
        case 'open':
            fFileOpenDialog->Show();
            break;

        case 'file':
            // Message from the file open dialog
            fFileView->LoadFile(message);
            break;

        default:
            BWindow::MessageReceived(message);
            break;
    }
}

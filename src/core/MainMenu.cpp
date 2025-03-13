// MainMenu.cpp
#include "MainMenu.h"

#include <Menu.h>
#include <MenuItem.h>
#include <Message.h>

MainMenu::MainMenu(BHandler* target) {
    BRect menuRect(0, 0, 0, 0);  // Width/height is auto-sized by layout
    fMenuBar = new BMenuBar(menuRect, "MenuBar");

    // File Menu
    BMenu* fileMenu = new BMenu("File");
    fileMenu->AddItem(new BMenuItem("Open...", new BMessage('open'), 'O', B_COMMAND_KEY));
    fileMenu->AddItem(new BMenuItem("Quit", new BMessage(B_QUIT_REQUESTED), 'Q', B_COMMAND_KEY));
    fMenuBar->AddItem(fileMenu);

    // View Menu
    BMenu* viewMenu = new BMenu("View");
    viewMenu->SetRadioMode(true);

    viewMenu->AddItem(new BMenuItem("Auto-Detect", new BMessage('auto')));
    viewMenu->AddItem(new BMenuItem("Settings View", new BMessage('bmsg')));
    viewMenu->AddItem(new BMenuItem("Text View", new BMessage('text')));
    viewMenu->AddItem(new BMenuItem("Hex View", new BMessage('hexv')));

    fMenuBar->AddItem(viewMenu);

    // Set target to MainWindow for message handling
    fileMenu->SetTargetForItems(target);
    viewMenu->SetTargetForItems(target);
}

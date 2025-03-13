#include "MainMenu.h"

#include <Menu.h>
#include <MenuItem.h>
#include <Message.h>
#include <Application.h> // For B_ABOUT_REQUESTED and B_QUIT_REQUESTED

MainMenu::MainMenu(BHandler* target) {
    BRect menuRect(0, 0, 0, 0);  // The size is auto-adjusted
    fMenuBar = new BMenuBar(menuRect, "MenuBar");

    BMenu* fileMenu = new BMenu("File");
    fileMenu->AddItem(new BMenuItem("Open...", new BMessage('open'), 'O', B_COMMAND_KEY));
    fileMenu->AddSeparatorItem();
    fileMenu->AddItem(new BMenuItem("Quit", new BMessage(B_QUIT_REQUESTED), 'Q', B_COMMAND_KEY));
    fMenuBar->AddItem(fileMenu);
    
    BMenu* viewMenu = new BMenu("View");
    viewMenu->SetRadioMode(true);
    viewMenu->AddItem(new BMenuItem("Auto-Detect", new BMessage('auto')));
    viewMenu->AddItem(new BMenuItem("Settings View", new BMessage('bmsg')));
    viewMenu->AddItem(new BMenuItem("Text View", new BMessage('text')));
    viewMenu->AddItem(new BMenuItem("Hex View", new BMessage('hexv')));
    fMenuBar->AddItem(viewMenu);
    
    BMenu* helpMenu = new BMenu("Help");
    helpMenu->AddItem(new BMenuItem("About Settings Explorer...", new BMessage(B_ABOUT_REQUESTED)));
    fMenuBar->AddItem(helpMenu);
    
    // Set targets
    fileMenu->SetTargetForItems(target);
    viewMenu->SetTargetForItems(target);
    helpMenu->SetTargetForItems(be_app);  // About is typically handled in App::AboutRequested()
    
}
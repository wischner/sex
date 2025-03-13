// MainMenu.h
#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <MenuBar.h>

class MainMenu {
public:
    MainMenu(BHandler* target);
    BMenuBar* MenuBar() const { return fMenuBar; }

private:
    BMenuBar* fMenuBar;
};

#endif

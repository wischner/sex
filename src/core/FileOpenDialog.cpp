// FileOpenDialog.cpp
#include "FileOpenDialog.h"

FileOpenDialog::FileOpenDialog(BHandler* target) {
    fFilePanel = new BFilePanel(B_OPEN_PANEL, new BMessenger(target));
}

void FileOpenDialog::Show() {
    fFilePanel->Show();
}

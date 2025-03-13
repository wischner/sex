// FileOpenDialog.h
#ifndef FILE_OPEN_DIALOG_H
#define FILE_OPEN_DIALOG_H

#include <FilePanel.h>
#include <Messenger.h>

class FileOpenDialog {
public:
    FileOpenDialog(BHandler* target);
    void Show();

private:
    BFilePanel* fFilePanel;
};

#endif

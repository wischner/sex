// FileView.h
#ifndef FILE_VIEW_H
#define FILE_VIEW_H

#include <View.h>

class FileView : public BView {
public:
    FileView(BRect frame);
    void LoadFile(BMessage* fileRefMsg);

private:
    void ShowAsMessage(const char* path);
    void ShowAsText(const char* path);
    void ShowAsHex(const char* path);
};

#endif

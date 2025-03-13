#ifndef ABOUT_WINDOW_H
#define ABOUT_WINDOW_H

#include <Window.h>
#include <TextView.h>
#include <Button.h>

class AboutWindow : public BWindow {
public:
    AboutWindow(BWindow* parent);

private:
    void CenterInParent(BWindow* parent);

    BWindow* fParentWindow;
};

#endif

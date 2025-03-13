#include "AboutWindow.h"
#include <LayoutBuilder.h>
#include <StringView.h>

AboutWindow::AboutWindow(BWindow* parent)
    : BWindow(BRect(0, 0, 300, 200), "About Settings Explorer", B_TITLED_WINDOW,
              B_NOT_RESIZABLE | B_NOT_ZOOMABLE | B_AUTO_UPDATE_SIZE_LIMITS),
              fParentWindow(parent)  {

    SetFeel(B_MODAL_APP_WINDOW_FEEL); 

    // Create content
    BStringView* title = new BStringView("title", "Settings Explorer");
    title->SetFont(be_bold_font);

    BStringView* version = new BStringView("version", "Version 1.0");
    BStringView* copyright = new BStringView("copyright",
                                             "© 2024 Wischner Ltd. All rights reserved.");

    BButton* closeButton = new BButton("Close", new BMessage(B_QUIT_REQUESTED));

    // Layout
    BLayoutBuilder::Group<>(this, B_VERTICAL)
        .SetInsets(B_USE_WINDOW_SPACING)
        .Add(title)
        .Add(version)
        .AddGlue()
        .Add(copyright)
        .AddGlue()
        .Add(closeButton);


    BLayout* layout = GetLayout();
    if (layout) {
        layout->Relayout();
    }
    ResizeToPreferred();

    CenterInParent(fParentWindow);

    // Show the window
    Show();
}


void AboutWindow::CenterInParent(BWindow* parent) {
    if (!parent)
        return;

    BRect parentFrame = parent->Frame();
    BRect myFrame = Frame();

    float x = parentFrame.left + (parentFrame.Width() - myFrame.Width()) / 2.0f;
    float y = parentFrame.top + (parentFrame.Height() - myFrame.Height()) / 2.0f;

    MoveTo(x, y);
}
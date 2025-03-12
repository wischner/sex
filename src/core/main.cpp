#include <Application.h>
#include <Window.h>
#include <View.h>
#include <Button.h>
#include <FilePanel.h>
#include <Messenger.h>
#include <Entry.h>
#include <Path.h>
#include <stdio.h>

class MainWindow : public BWindow {
public:
    MainWindow()
        : BWindow(BRect(100, 100, 400, 300), "File Open Dialog Example",
                  B_TITLED_WINDOW, B_QUIT_ON_WINDOW_CLOSE)
    {
        BButton* openButton = new BButton(BRect(10, 10, 120, 40),
                                          "openButton", "Open File",
                                          new BMessage('opnF'));

        BView* background = new BView(Bounds(), "background", B_FOLLOW_ALL,
                                      B_WILL_DRAW);
        background->SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
        AddChild(background);

        background->AddChild(openButton);
    }

    void MessageReceived(BMessage* message)
    {
        switch (message->what) {
        case 'opnF':
            ShowOpenFileDialog();
            break;

        case B_REFS_RECEIVED:
            HandleRefs(message);
            break;

        default:
            BWindow::MessageReceived(message);
            break;
        }
    }

private:
    void ShowOpenFileDialog()
    {
        // Create a Messenger to send messages back to this window.
        BMessenger messenger(this);

        // Create the file panel for opening files.
        BFilePanel* openPanel = new BFilePanel(B_OPEN_PANEL, &messenger);

        // Show the panel.
        openPanel->Show();

        // NOTE: If you need to reuse this panel later, save the pointer.
    }

    void HandleRefs(BMessage* message)
    {
        // A file (or files) was selected.
        entry_ref ref;
        if (message->FindRef("refs", &ref) == B_OK) {
            BEntry entry(&ref);
            BPath path;
            if (entry.GetPath(&path) == B_OK) {
                printf("Selected file: %s\n", path.Path());
            }
        }
    }
};

class FileOpenApp : public BApplication {
public:
    FileOpenApp()
        : BApplication("application/x-vnd.MyFileOpenApp")
    {
    }

    void ReadyToRun()
    {
        MainWindow* window = new MainWindow();
        window->Show();
    }
};

int main()
{
    FileOpenApp app;
    app.Run();
    return 0;
}

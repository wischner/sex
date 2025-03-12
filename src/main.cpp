#include <Application.h>
#include <Window.h>
#include <View.h>
#include <StringView.h>

class HelloWorldWindow : public BWindow {
public:
    HelloWorldWindow()
        : BWindow(BRect(100, 100, 400, 200), "Hello Haiku", B_TITLED_WINDOW, B_QUIT_ON_WINDOW_CLOSE) {
        BView* background = new BView(Bounds(), "background", B_FOLLOW_ALL, B_WILL_DRAW);
        background->SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
        AddChild(background);
        
        BStringView* helloText = new BStringView(BRect(20, 20, 280, 40), "hello", "Hello Haiku!");
        background->AddChild(helloText);
    }
};

class HelloWorldApp : public BApplication {
public:
    HelloWorldApp() : BApplication("application/x-vnd.HelloHaiku") {}

    void ReadyToRun() {
        HelloWorldWindow* window = new HelloWorldWindow();
        window->Show();
    }
};

int main() {
    HelloWorldApp app;
    app.Run();
    return 0;
}
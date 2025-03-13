// MainApp.h
#ifndef MAIN_APP_H
#define MAIN_APP_H

#include <Application.h>

class App : public BApplication {
public:
    App();
    virtual void ReadyToRun();
    virtual void AboutRequested();
};

#endif

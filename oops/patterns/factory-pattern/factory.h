#pragma once
#include <string>
#include <iostream>
using namespace std;

class Button {
    public:
    virtual ~Button() {}
    virtual void showButton() = 0;
};

class Menu {
    public:
    virtual ~Menu() {}
    virtual void showMenu() = 0;
};

class IOSButton : public Button {
    void showButton() override;
};

class AndroidButton : public Button {
    public:
    ~AndroidButton();
    void showButton() override;
};

class AndroidMenu : public Menu {
    public:
    ~AndroidMenu();
    void showMenu() override;
};

class IOSMenu : public Menu {
    public:
    ~IOSMenu();
    void showMenu() override;

};

//prototype
class UIFactory {
    public:
    virtual Button* createButton() = 0;
    virtual Menu* createMenu() = 0;
    virtual ~UIFactory() {}
};

class AndroidUIFactory : public UIFactory {
    public:
    Button* createButton() override;
    Menu* createMenu() override;
};

class IOSUIFactory : public UIFactory {
    Button* createButton() override;
    Menu* createMenu() override;
};

class Flutter {
    public:
    void refreshUI();
    void setTheme();
    UIFactory* createFactory(string platform);
};
// class Button {
//     virtual void showButton();
// };

// class Menu {
//     virtual void showMenu();
// };

// class UIFactory {
//     virtual Button createButton();
//     virtual Menu createMenu();
// };

// class Flutter {
//     void refreshUI();
//     void setTheme();
//     UIFactory createFactory(string platform);
// };

#include <bits/stdc++.h>
#include "factory.h"
using namespace std;

void Flutter::refreshUI() {
    cout << "Refreshing UI";
}

void Flutter::setTheme() {
    cout << "Setting theme";
}

UIFactory* Flutter::createFactory(string platform) {
    if(platform == "android") {
        return new AndroidUIFactory();
    } else {
        return new IOSUIFactory();
    }
}


int main() {

    Flutter *flutter = new Flutter();
    UIFactory *uiFactory = flutter->createFactory("ios");

    Button *button = uiFactory->createButton();
    button->showButton();

    Menu *menu = uiFactory->createMenu(); 
    menu->showMenu();


    return 0;
}
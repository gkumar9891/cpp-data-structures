#include "factory.h"

Button* IOSUIFactory::createButton() {
    return new IOSButton();
}

Menu* IOSUIFactory::createMenu() {
    return new IOSMenu();
}

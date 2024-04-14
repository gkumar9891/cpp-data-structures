#include "factory.h"

Button* AndroidUIFactory::createButton() {
    return new AndroidButton();
}

Menu* AndroidUIFactory::createMenu() {
    return new AndroidMenu();
}

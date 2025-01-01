#include "custommenu.h"

CustomMenu::CustomMenu() {

    this->setStyleSheet(
        "QMenu::item {"
        "   padding-left: 20px;"         // Left alignment for items
        "   min-width: 120px;"           // Minimum width of the menu items
        "   height: 20px;"               // Height of each menu item
        "}"
        "QMenu::item:selected {"
        "   background-color: #5A5A5A;" // Color of item when selected
        "   color: white;"               // Text color when selected
        "}");
}

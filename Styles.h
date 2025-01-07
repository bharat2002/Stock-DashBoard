#ifndef STYLES_H
#define STYLES_H

#define MenuStyle "QMenu::item { padding-left: 20px; min-width: 120px; height: 20px; padding-bottom:5px;} QMenu::item:selected { background-color: #5A5A5A; color: white; }"
#define CentralWidgetStyle \
"background-image: url(:/images/new_bear.jpg);" \
    "background-repeat: no-repeat;"\
    "background-position: center;"\
    "background-clip: content;"
#define LightModeStyle "background-color: white; color: black;"
#define DarkModeStyle "background-color: #2E2E2E; color: white;"
#define CloseButtonStyle \
    "QPushButton {" \
    "   background-color: red;" \
    "   color: white;" \
    "   border: none;" \
    "   padding: 0;" \
    "   font-size: 16px;" \
    "   font-weight: bold;" \
    "   text-align: center;" \
    "   width: 20px;" \
    "   height: 20px;" \
    "}" \
    "QPushButton:hover {" \
    "   background-color: darkred;" \
    "}"
#define DatabaseName "stock_dashboard"
#define IndexTableName "nifty_data"
#define HostName "localhost"

#endif // STYLES_H

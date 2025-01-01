#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Styles.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void closeEvent(QCloseEvent *event) override ;

private slots:
    void onButtonClicked();     // Slot for button click
    void openFile();            // Slot for File -> Open
    void saveFile();            // Slot for File -> Save
    void exitApp();             // Slot for File -> Exit
    void showAbout();           // Slot for Help -> About
    void refreshData();         // Slot for Tools -> Refresh
    void switchToDarkMode();    // Slot for Tools -> Dark Mode
    void switchToLightMode();   // Slot for Tools -> Light Mode
    void toggleSidebar();       // Slot for View -> Toggle Sidebar
private:
    Ui::MainWindow *ui;
    void setupMenu();           // Method to set up the menu
    void setupUI();             // Method to set up the UI elements
};

#endif // MAINWINDOW_H

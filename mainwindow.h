#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Styles.h"
#include <QMainWindow>
#include <QtSql/QSqlDatabase>

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
    QSqlDatabase MySqlDBConn;

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
    void addTabWithCloseButton(QWidget *widget, const QString &tabName);
    void addStockOverviewTab();
    void addSearchBarTab();
    void addLiveStockChartTab();
    void addNewsFeedTab();

private:
    Ui::MainWindow *ui;
    void setupUI();             // Method to set up the UI elements
    QTabWidget *tabWidget;
    void setupMenu();           // Method to set up the menu
    void setupDB();
};

#endif // MAINWINDOW_H

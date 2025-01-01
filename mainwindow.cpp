#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QAction>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Maximize the window on start
    this->showMaximized();

    // Setup UI elements
    setupUI();

    // Setup the menu bar
    setupMenu();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupMenu()
{
    // Create Menu Bar
    QMenuBar *menuBar = this->menuBar();
    // File Menu
    QMenu *fileMenu = (menuBar->addMenu(tr("&File")));
    fileMenu->setStyleSheet(MenuStyle);
    QAction *openAction = new QAction(tr("&Open"), this);
    QAction *saveAction = new QAction(tr("&Save"), this);

    QAction *exitAction = new QAction(tr("E&xit"), this);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    // Tools Menu
    QMenu *toolsMenu = menuBar->addMenu(tr("&Tools"));
    QAction *refreshAction = new QAction(tr("&Refresh Data"), this);
    QAction *darkModeAction = new QAction(tr("&Dark Mode"), this);
    QAction *lightModeAction = new QAction(tr("&Light Mode"), this);
    toolsMenu->setStyleSheet(MenuStyle);
    toolsMenu->addAction(refreshAction);
    toolsMenu->addSeparator();
    toolsMenu->addAction(darkModeAction);
    toolsMenu->addAction(lightModeAction);

    // View Menu
    QMenu *viewMenu = menuBar->addMenu(tr("&View"));
    QAction *toggleSidebarAction = new QAction(tr("&Toggle Sidebar"), this);
    viewMenu->addAction(toggleSidebarAction);

    viewMenu->setStyleSheet(MenuStyle);
    // Help Menu
    QMenu *helpMenu = menuBar->addMenu(tr("&Help"));
    helpMenu->setStyleSheet(MenuStyle);
    QAction *aboutAction = new QAction(tr("&About"), this);
    helpMenu->addAction(aboutAction);

    // Connect Menu Actions
    connect(openAction, &QAction::triggered, this, &MainWindow::openFile);
    connect(saveAction, &QAction::triggered, this, &MainWindow::saveFile);
    connect(exitAction, &QAction::triggered, this, &MainWindow::exitApp);
    connect(refreshAction, &QAction::triggered, this, &MainWindow::refreshData);
    connect(darkModeAction, &QAction::triggered, this, &MainWindow::switchToDarkMode);
    connect(lightModeAction, &QAction::triggered, this, &MainWindow::switchToLightMode);
    connect(toggleSidebarAction, &QAction::triggered, this, &MainWindow::toggleSidebar);
    connect(aboutAction, &QAction::triggered, this, &MainWindow::showAbout);
}

void MainWindow::setupUI()
{

    //change the default window name
    this->setWindowTitle("NSE Dashboard");

    //Add a logo
    // QPixmap LogoPixMap(":/images/dashboardlogo.jpg");
    QIcon DashBoardIcon(":/images/download.png");
    this->setWindowIcon(DashBoardIcon);
    // Create a central widget
    QWidget *centralWidget = new QWidget(this);

    // Apply the background to the central widget
    centralWidget->setStyleSheet(
        "background-image: url(:/images/new_bear.jpg);"
        "background-repeat: no-repeat;"
        "background-position: center;"
        "background-clip: content;"
        );

    // Set the central widget
    setCentralWidget(centralWidget);

}

// Slots for menu actions
void MainWindow::onButtonClicked()
{
    qDebug() << "Button clicked!";
    QMessageBox::information(this, "Info", "Button was clicked!");
}

void MainWindow::openFile()
{
    QMessageBox::information(this, "Open", "Open action triggered!");
}

void MainWindow::saveFile()
{
    QMessageBox::information(this, "Save", "Save action triggered!");
}

void MainWindow::exitApp()
{
    QApplication::quit();
}

void MainWindow::refreshData()
{
    QMessageBox::information(this, "Refresh", "Data refreshed!");
}

void MainWindow::switchToDarkMode()
{
    this->setStyleSheet("background-color: #2E2E2E; color: white;");
    QMessageBox::information(this, "Dark Mode", "Switched to Dark Mode!");
}

void MainWindow::switchToLightMode()
{
    this->setStyleSheet("background-color: white; color: black;");
    QMessageBox::information(this, "Light Mode", "Switched to Light Mode!");
}

void MainWindow::toggleSidebar()
{
    QMessageBox::information(this, "Toggle Sidebar", "Sidebar toggled!");
}

void MainWindow::showAbout()
{
    QMessageBox::about(this, "About", "This is a stock dashboard application.\nVersion 1.0");
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    QMessageBox messageBox(this);
    messageBox.setWindowTitle("Exit Application");
    messageBox.setText("Are you sure you want to exit?");
    messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    messageBox.setDefaultButton(QMessageBox::No);
    int result = messageBox.exec();
    if (result == QMessageBox::Yes) {
        QApplication::quit(); // Exit the application
    } else if (result == QMessageBox::No) {
        // No action is needed; simply return
        return;
    }
}

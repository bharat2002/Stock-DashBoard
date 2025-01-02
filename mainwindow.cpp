#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Styles.h"
#include <QDebug>
#include <QLineEdit>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QCloseEvent>
#include <QAction>
#include <QListWidget>
#include <QTableWidget>

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
    QAction *StockOverview = new QAction(tr("&Stock Overview"), this);
    QAction *SearchBar = new QAction(tr("&Search Bar"), this);
    QAction *LiveStock = new QAction(tr("&Live Stock"), this);
    toolsMenu->setStyleSheet(MenuStyle);
    toolsMenu->addAction(refreshAction);
    toolsMenu->addAction(StockOverview);
    toolsMenu->addAction(SearchBar);
    toolsMenu->addAction(LiveStock);
    toolsMenu->addSeparator();

    // View Menu
    QMenu *viewMenu = menuBar->addMenu(tr("&View"));
    QAction *toggleSidebarAction = new QAction(tr("&Toggle Sidebar"), this);
    QMenu *themeMenu = new QMenu(tr("&Theme"), this);
    QAction *actionLightMode = new QAction(tr("&Light Mode"), this);
    QAction *actionDarkMode = new QAction(tr("&Dark Mode"), this);
    themeMenu->addAction(actionLightMode);
    themeMenu->addAction(actionDarkMode);
    viewMenu->addMenu(themeMenu);
    viewMenu->setStyleSheet(MenuStyle);
    viewMenu->addAction(toggleSidebarAction);

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
    connect(actionDarkMode, &QAction::triggered, this, &MainWindow::switchToDarkMode);
    connect(actionLightMode, &QAction::triggered, this, &MainWindow::switchToLightMode);
    connect(toggleSidebarAction, &QAction::triggered, this, &MainWindow::toggleSidebar);
    connect(aboutAction, &QAction::triggered, this, &MainWindow::showAbout);
    connect(StockOverview, &QAction::triggered, this, &MainWindow::addStockOverviewTab);
    connect(LiveStock, &QAction::triggered, this, &MainWindow::addLiveStockChartTab);
    connect(SearchBar, &QAction::triggered, this, &MainWindow::addSearchBarTab);
}

void MainWindow::setupUI()
{
    //change the default window name
    this->setWindowTitle("NSE Dashboard");
    //Adding Tab Widgets
    tabWidget = new QTabWidget(this); //Tab Widget for Holding Tabs
    tabWidget->setTabPosition(QTabWidget::North);

    QIcon DashBoardIcon(":/images/download.png");
    this->setWindowIcon(DashBoardIcon);
    // Set the central widget
    setCentralWidget(tabWidget);

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
    this->setStyleSheet(LightModeStyle);
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
    QMessageBox::StandardButton reply = QMessageBox::critical(this,"Exit Application","Are you sure you want to exit?",QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        event->accept();
        QApplication::quit(); // Exit the application
    } else if (reply == QMessageBox::No) {
        // No action is needed; simply return
        event->ignore();
        return;
    }
}

void MainWindow::addTabWithCloseButton(QWidget *widget, const QString &tabName)
{
    // Add widget to tab and make it closable
    int index = tabWidget->addTab(widget, tabName);

    // Add close button to tab title
    QPushButton *closeButton = new QPushButton("X");
    closeButton->setFixedSize(20, 20);
    closeButton->setStyleSheet(CloseButtonStyle);
    tabWidget->tabBar()->setTabButton(index, QTabBar::RightSide, closeButton);
    tabWidget->tabBar()->setStyleSheet("QTabBar::tabButton{padding-left = 5px;}");
    // Connect close button to remove the tab
    connect(closeButton, &QPushButton::clicked, this, [this, index]() {
        tabWidget->removeTab(index);
    });

    tabWidget->setCurrentIndex(index); // Switch to the newly added tab
}

void MainWindow::addStockOverviewTab()
{
    QWidget *tab = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(tab);
    QTableWidget *table = new QTableWidget();
    table->setRowCount(5);
    table->setColumnCount(3);
    layout->addWidget(table);
    addTabWithCloseButton(tab, "Stock Overview");
}

void MainWindow::addSearchBarTab()
{
    QWidget *tab = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(tab);
    QLineEdit *searchBar = new QLineEdit();
    searchBar->setPlaceholderText("Enter Stock Name or Ticker");
    layout->addWidget(searchBar);
    addTabWithCloseButton(tab, "Search Bar");
}

void MainWindow::addLiveStockChartTab()
{
    QWidget *tab = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(tab);
    QPushButton *chartButton = new QPushButton("Show Live Stock Chart");
    layout->addWidget(chartButton);
    addTabWithCloseButton(tab, "Live Stock Chart");
}

void MainWindow::addNewsFeedTab()
{
    QWidget *tab = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(tab);
    QListWidget *newsFeed = new QListWidget();
    newsFeed->addItem("Breaking News on Stock Market...");
    layout->addWidget(newsFeed);
    addTabWithCloseButton(tab, "News Feed");
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

// Constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(m_editor);     // ViEditコントロールの位置セット
    onModeChanged();

    connect(m_editor, SIGNAL(editModeChanged()), this, SLOT(onModeChanged()));
}

// Destructor
MainWindow::~MainWindow()
{
    delete ui;
}

// Mode Changed Signal Receipt
void MainWindow::onModeChanged()
{
    QString text;
    switch(m_editor->m_viEngine->editMode()){
        case ViEngine::EditMode::CMD:
            text = "CMD";
            break;
        case ViEngine::EditMode::INSERT:
            text = "INSERT";
            break;
        default:
            text = "UnKnown";
            break;
    }
    statusBar()->showMessage(text);
}

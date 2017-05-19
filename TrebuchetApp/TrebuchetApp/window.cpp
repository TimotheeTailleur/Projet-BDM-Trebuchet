#include "window.h"
#include "ui_window.h"


Window::Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);

    // Connexion entre la webcam et le gl widget.

    connect(ui->webcamWidget, SIGNAL(getCoords(int,int)),ui->glWidget, SLOT(getCoords(int,int)));
}

Window::~Window()
{
    delete ui;
}

void Window::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
        close();
    else
        QWidget::keyPressEvent(e);
}

void Window::setRot(){
   /* int x = ui->webcamWidget->getInitialX();
    int y = ui->webcamWidget->getInitialY();

    x = x*20-10;
    y = y*20-10;

    ui->glWidget->rotate(x,y,20);*/
}


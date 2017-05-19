#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QKeyEvent>

namespace Ui {
class Window;
}

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = 0);
    ~Window();
protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::Window *ui;

private slots:
    void setRot();
};

#endif // WINDOW_H

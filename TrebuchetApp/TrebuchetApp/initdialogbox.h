#ifndef INITDIALOGBOX_H
#define INITDIALOGBOX_H

#include <QDialog>

namespace Ui {
class InitDialogBox;
}

class InitDialogBox : public QDialog
{
    Q_OBJECT

public:
    explicit InitDialogBox(QWidget* parent, QString *playerName,int *difficultyLevel,int *numberOfTargets);
    ~InitDialogBox();

    QString *playerName_;
    int *difficultyLevel_;
    int *numberOfTargets_;
private slots:
    void on_buttonBox_accepted();
private:
    Ui::InitDialogBox *ui;
};

#endif // INITDIALOGBOX_H

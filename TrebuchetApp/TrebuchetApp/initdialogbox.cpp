#include "initdialogbox.h"
#include "ui_initdialogbox.h"
#include <QDebug>

InitDialogBox::InitDialogBox(QWidget* parent, QString *playerName, int *difficultyLevel, int *numberOfTargets) :
    QDialog(parent),
    ui(new Ui::InitDialogBox)
{
    ui->setupUi(this);
    this->setModal(true);

    playerName_ = playerName;
    difficultyLevel_ = difficultyLevel;
    numberOfTargets_ = numberOfTargets;
}

InitDialogBox::~InitDialogBox()
{
    delete ui;
}

void InitDialogBox::on_buttonBox_accepted()
{
     *playerName_ = ui->playerNameEdit->text();
     *difficultyLevel_ = ui->diffLevelSpin->value();
     *numberOfTargets_ = ui->targetNumberEdit->text().toInt();
}



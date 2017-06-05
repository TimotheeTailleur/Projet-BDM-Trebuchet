#ifndef INITDIALOGBOX_H
#define INITDIALOGBOX_H

#include <QDialog>

namespace Ui {
class InitDialogBox;
}

/*
 * Classe d'une dialogBox s'affichant lors du lancement de l'application récupérant le nom du joueur
 * le niveau de difficulté souhaité (compris entre 1 et 3) ainsi que le nombre de cible.
 *
 * Si l'utilisateur n'accepte pas la dialogBox, les valeurs par défaut des paramètres du jeu sont :
 * difficulté = 1 et nbCibles = 5 (géré par la classe jeu).
 * */

class InitDialogBox : public QDialog
{
    Q_OBJECT

public:
    /*On effectue un passage par référence pour modifier directement les attributs du parent Window qui
     * seront passés en paramètres du constructeur.
     * */
    explicit InitDialogBox(QWidget* parent, QString *playerName,int *difficultyLevel,int *numberOfTargets);

    //Lors de l'appel au destructeur, on vide la mémoire occupée par l'ui
    ~InitDialogBox();

    QString *playerName_; //Nom Joueur
    int *difficultyLevel_; //niveau de difficulté
    int *numberOfTargets_; //Nombre de cibles
private slots:
    void on_buttonBox_accepted();
private:
    Ui::InitDialogBox *ui; //Ui simple composée de deux textEdits & une spinBox pour la difficulté
};

#endif // INITDIALOGBOX_H

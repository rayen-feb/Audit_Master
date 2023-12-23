#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include"entreprise.h"
#include"arduino.h"
namespace Ui {
class menu;
}

class menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);

    ~menu();

private slots:


    void on_pushButton_chercher_clicked();

    void on_pushButton_ajout_clicked();

    void on_pushButton_afficher_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_clicked();

    void on_confirme_ajout_accepted();

    void on_confirme_supression_clicked();

    void on_pushButton_2_clicked();

    void on_checkBox_nomup_stateChanged(int arg1);

    void on_checkBox_nomdown_stateChanged(int arg1);

    void on_checkBox_pays_up_stateChanged(int arg1);

    void on_checkBox_nombre_up_stateChanged(int arg1);

    void on_checkBox_date_stateChanged(int arg1);

    void on_commandLinkButton_2_clicked();

    void on_checkBox_nomup_clicked();

    void on_checkBox_nomdown_clicked();

    void on_checkBox_pays_up_clicked();

    void on_checkBox_pays_down_clicked();

    void on_checkBox_nombre_up_clicked();

    void on_checkBox_date_clicked();

    void on_commandLinkButton_3_clicked();

    void on_commandLinkButton_4_clicked();

    void on_confirme_recherche_clicked();

    void on_pushButton_confirmer_rechercher_clicked();

    void on_confirme_ajout_rejected();

    void on_pushButton_3_clicked();

    void on_exporterPDF_clicked();

    void on_confirmer_mod_clicked();

    void on_triNM_clicked();

    void on_confirme_ajout_2_accepted();

    void on_confirme_ajout_2_rejected();

    void on_confirme_modifier_accepted();

    void on_triNM_2_clicked();

    void on_triNM_3_clicked();

    void on_pushButton_statistiques_clicked();

    void on_commandLinkButton_5_clicked();

    void on_confirme_modifier_rejected();

    void on_triNM_4_clicked();

    void on_amrou10_9_clicked();

    void on_envoyer_email_clicked();

    void on_anuler_email_clicked();

    void notif(QString t,QString m);

    QByteArray intToQByteArray(int );
    void inputard();
    void outputard() ;

private:
    Ui::menu *ui;
    QString email_recipient;
    entreprise E ;
    Arduino Ard;
    QByteArray data1;
    QByteArray data;
    int temp;
    //Smtp S ;

};

#endif // MENU_H

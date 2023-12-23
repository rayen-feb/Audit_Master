#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "normes.h"
#include"arduino.h"
#include <QMainWindow>
#include"entreprise.h"
#include"rapport.h"
#include"rrr.h"
#include"normes.h"
#include"arduino.h"
#include"auditeur.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    int countNormes(const QString& );

    void on_pushButton_7_clicked();

    void on_stat();



    void on_logoutButton_clicked();

    void on_Plateforme_emp_3_clicked();

    void on_Plateforme_emp_2_clicked();

    void on_pushButton_ajout_5_clicked();

    void on_pushButton_ajout_entreprise_clicked();

    void on_pushButton_chercher_entreprise_clicked();

    void on_pushButton_afficher_entreprise_clicked();

    void on_pushButton_supprimer_entreprise_clicked();

    void on_pushButton_modifier_entreprise_clicked();

    void on_pushButton_statistiques_entreprise_clicked();

    void on_confirme_ajout_5_accepted();

    void on_commandLinkButton_18_clicked();

    void on_commandLinkButton_19_clicked();

    void on_commandLinkButton_20_clicked();

    void on_commandLinkButton_21_clicked();

    void on_commandLinkButton_22_clicked();

    void on_commandLinkButton_23_clicked();

    void on_commandLinkButton_24_clicked();

    void on_confirme_ajout_entre_accepted();

    void on_triNM_17_clicked();

    void on_confirme_ajout_entre_rejected();

    void on_pushButton_confirmer_rechercher_5_clicked();

    void on_pushButton_confirmer_rechercher_entre_clicked();

    void on_pushButton_19_clicked();

    void on_checkBox_nomup_entre_stateChanged(int arg1);

    void on_checkBox_pays_up_entre_clicked();

    void on_checkBox_nombre_up_entre_clicked();

    void on_checkBox_nomdown_entre_clicked();

    void on_checkBox_pays_down_entre_clicked();

    void on_checkBox_date_entre_clicked();

    void on_confirme_supression_entre_clicked();

    void on_confirmer_mod_entre_clicked();

    void on_envoyer_email_2_clicked();

    void on_anuler_email_2_clicked();

    void on_triNM_18_clicked();

    void on_triNM_19_clicked();

    void on_triNM_20_clicked();

    void on_pb_ajouter_clicked();

    void on_supp_clicked();

    void on_supp_rapport_clicked();

    void on_pb_modifier_clicked();

    void on_exporter_clicked();

    void on_le_chercher_clicked();

    void on_le_chercher_2_clicked();

    void on_le_chercher_3_clicked();

    void on_tri_2_clicked();

    void on_tri_3_clicked();

    void on_tri_4_clicked();

    void on_commandLinkButton_25_clicked();

    void on_pb_ajouter_2_clicked();

    void on_modefier_clicked();

    void on_pb_suppr_clicked();

    void on_pushButton_pdf_2_clicked();

    void on_pushButton_pdf_2_pressed();

    void on_generer_stat_clicked();

    void on_stat_femme_clicked();

    void on_pushButton_37_clicked();

    void on_checkBoxQuestion1A_stateChanged(int arg1);

    void on_Plateforme_emp_4_clicked();

    void on_Plateforme_emp_clicked();

    void on_commandLinkButton_26_clicked();

    void on_videoPlayerWidget_customContextMenuRequested(const QPoint &pos);

    void on_pushButton_statistiques_entreprise_2_clicked();

    void on_Plateforme_emp_5_clicked();
    void inputard() ;
    void outputard() ;

    void on_triNM_20_pressed();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::MainWindow *ui;
Normes N;
QString email_recipient;
entreprise E ;
//arduino Ard ;
QByteArray data1;
QByteArray data;
int temp;
Rapport R;
recaptcha *captchaDialog;
Ui::MainWindow *uii;
QVector<bool> answers;
std::vector<bool> correctAnswers = {true, true, false, true, false, false, true};

Auditeur A;
Arduino Ard;
QByteArray enteredID,key;


};

#endif // MAINWINDOW_H

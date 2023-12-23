#ifndef ENTREPRISE_H
#define ENTREPRISE_H
#include<QString>
#include<QSqlQuery>
#include"QSqlQueryModel"
//#include "./smtp/src/SmtpMime"
#include"./smtp.h"
#include"smtp.h"
#include"smtp.h"
#include <QSslSocket>
#include <QProcess>


class entreprise
{
public:
    entreprise();
    entreprise(int, QString,QString ,QString ,QString ,int ,int ,QString ,QString,QString  );
    int getid() ;
    QString getnom() ;
    QString getpays();
    QString getville() ;
    QString getadresse() ;
    int  getnumero() ;
    int getnombree() ;
    QString getemail() ;
    QString getdomaine();
    QString getdate();
    void setid(int);
    void  setnom(QString) ;
    void setville(QString);
    void setadresse(QString) ;
    void setnumero(int) ;
    void  setnombree(int);
    void setemail(QString);
    void setdomaine(QString);
    void setdate(QString);
    bool ajouter();
    QSqlQueryModel* afficher() ;
    bool supprimer(int);
    //modifier
    bool modifier();
    QSqlQueryModel * combo_box();
     //fonctions avancées
    QSqlQueryModel * recherche(int  );
    QSqlQueryModel * recherche_nom(const QString &);
    QSqlQueryModel * recherche_prix(const QString &);
    QSqlQueryModel * afficherdown_nom();
    QSqlQueryModel * afficherup_nom();
    QSqlQueryModel * afficherdown_pays();
    QSqlQueryModel * afficherup_pays();
    QSqlQueryModel * afficherup_date();

    QSqlQueryModel * afficherdown_nombree();
    QSqlQueryModel * afficherup_nombree();

    QSqlQueryModel * trier_nom_a();
    QSqlQueryModel * trier_nom_d();
    QSqlQueryModel * recherche(const QString &);

    int calculer(int );
    int calculernombre( ) ;



private :
    int id , numero, nombree;

    QString  nom , pays , ville , adresse , email , domaine ,date ;
};

#endif // ENTREPRISE_H

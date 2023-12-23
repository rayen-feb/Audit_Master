#ifndef AUDITEUR_H
#define AUDITEUR_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QStandardItemModel>
#include <QSqlTableModel>




class Auditeur
{
    public:
    Auditeur(){};
       Auditeur(int, int, QString, QString, QString, QString, QString,QByteArray,QString);
        int getid();
        int getnumero();
        QString getnom();
        QString getprenom();
        QString getsexe();
        QString getadresse();
        QString getclasseA();
        QByteArray getimage();
        QString getImagePath();
        void setid(int);
        void setnumero(int);
        void setnom(QString);
        void setprenom(QString);
        void setsexe(QString);
        void setadresse(QString);
        void setclasseA(QString);
        void setimage(QByteArray img) ;
        void setImagePath(QString path) ;
        bool existeID(int id_c);
        bool ajouter();
        QSqlQueryModel* afficher();
        bool supprimer(int id);
        bool modifier();
QSqlQueryModel *afficherrecherche (int);
QSqlQueryModel *afficherrecherche1 (QString& nom);
QSqlQueryModel *afficherrecherche2 (QString& sexe);
int getNombreAuditeursParClasse(QString classe);
int getNombreAuditeursParSexe(QString classe);






    private:
        int id,numero;
        QString nom, prenom, sexe,adresse,classe,imagePath;
         QByteArray image;
    };

#endif // AUDITEUR_H

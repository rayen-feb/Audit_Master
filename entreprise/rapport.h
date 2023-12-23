#ifndef RAPPORT_H
#define RAPPORT_H
#include <QString>
#include <QSqlQueryModel>
#include <QKeyEvent>
#include <QStandardItemModel>
#include <QMap>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include <QFileDialog>

class Rapport
{
public:
    Rapport();
    Rapport(int,QString,QString,int,QString,int);
    int getid(){return ID;}
    QString gettitre(){return Titre;}
    QString getobjectif(){return Objectif;}
    int getDateaudit(){return Dateaudit;}
    QString getResume(){return Resume;}
    int getEtat(){return Etat;}
    void setDateaudit(int);
    void setTitre(QString);
    void setObjectif(QString);
    void setId(int);
    void setResume(QString);
    void setEtat(int);
    ~Rapport(){};
    bool ajouter();
    bool existe(int);
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
    bool exporterPDF(const QString &fileName, QSqlQueryModel *model);
    bool envoyerMessage(const QString &contenu, const QString &);
    QSqlQueryModel* recherche(int ) ;
    QSqlQueryModel* recherche1(QString ) ;
    QSqlQueryModel* recherche2(QString ) ;
    QSqlQueryModel * tri();
    QSqlQueryModel *tri1();
    QSqlQueryModel *tri2();




private:
    int Dateaudit;
    QString Titre;
    QString Objectif;
    int ID;
    QString Resume;
    int Etat;

};

#endif // RAPPORT_H

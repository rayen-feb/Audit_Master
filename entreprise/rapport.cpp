#include "rapport.h"
#include <QSqlQuery>
#include <QString>
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QMessageBox>
#include <QDate>
#include <QStandardItemModel>
#include <QtPrintSupport/QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QtSql>
#include <QMap>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QFileDialog>

Rapport::Rapport()
{
    Dateaudit=0;
    Titre="";
    Objectif="";
    ID=0;
    Resume="";
    Etat=0;


}
Rapport::Rapport(int Dateaudit,QString Titre,QString Objectif,int ID,QString Resume,int Etat)
{
    this-> Dateaudit=Dateaudit;
    this->Titre=Titre;
    this->Objectif=Objectif;
    this->ID=ID;
    this->Resume=Resume;
    this->Etat=Etat;
}
void Rapport::setDateaudit(int Dateaudit )
{
    this->Dateaudit=Dateaudit;
}
void Rapport::setTitre(QString Titre)
{
    this ->Titre=Titre;
}
void Rapport::setObjectif(QString Objectif)
{
    this->Objectif=Objectif;
}
void Rapport::setId(int ID)
{
    this->ID=ID;
}
void Rapport::setResume(QString Resume)
{
    this->Resume=Resume;
}
void Rapport::setEtat(int Etat)
{
    this->Etat=Etat;
}
bool Rapport::ajouter()
{
    //bool test=false;
    QSqlQuery query;
    //QString ID= QString::number(ID);
        query.prepare("INSERT INTO RAPPORT (ID, Titre, Objectif,Dateaudit,Resume,Etat) "
                      "VALUES (:ID, :Titre, :Objectif, :Dateaudit, :Resume, :Etat)");
        query.bindValue(":ID", ID);
        query.bindValue(":Titre", Titre);
        query.bindValue(":Objectif", Objectif);
        query.bindValue(":Dateaudit", Dateaudit);
        query.bindValue(":Resume", Resume);
        query.bindValue(":Etat", Etat);
        return query.exec();

}
bool Rapport::supprimer(int ID)
{
    QSqlQuery query;
    QString id_string= QString::number(ID);
        query.prepare("Delete from RAPPORT where ID=:ID");
        query.bindValue(0, ID);
        return query.exec();

}
QSqlQueryModel* Rapport::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM RAPPORT");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Titre"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Objectif"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Dateaudit"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("Resume"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("Etat"));


    return model;
}
bool Rapport::existe(int ID) {
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);


    query.prepare("SELECT COUNT(*) FROM RAPPORT WHERE ID = :ID");
    query.bindValue(":ID", ID);


    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        return (count > 0);
    }


    return false;
}

bool Rapport::modifier()
{

    QSqlQuery query;
    QString id_string= QString::number(ID);
    query.prepare("UPDATE RAPPORT SET ID= :ID, TITRE = :Titre, OBJECTIF = :Objectif, DATEAUDIT = :Dateaudit ,RESUME= :Resume , ETAT= :Etat WHERE ID = :ID");
    query.bindValue(":ID", ID);
    query.bindValue(":TITRE", Titre);
    query.bindValue(":OBJECTIF", Objectif);
    query.bindValue(":DATEAUDIT", Dateaudit);
    query.bindValue(":RESUME", Resume);
    query.bindValue(":ETAT",Etat);

    return query.exec();
}
bool Rapport::exporterPDF(const QString &fileName, QSqlQueryModel *model) {
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);

        for (int row = 0; row < model->rowCount(); ++row) {
            for (int column = 0; column < model->columnCount(); ++column) {
                stream << model->data(model->index(row, column)).toString() << "\t";
            }
            stream << "\n";
        }

        file.close();
        return true;
    } else {
        QMessageBox::warning(nullptr, "Erreur", "Impossible d'ouvrir le fichier pour l'exportation PDF.");
        return false;
    }
}
QSqlQueryModel* Rapport::recherche(int ID)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QSqlQuery query;
    query.prepare("SELECT * FROM RAPPORT WHERE ID = :ID");
    query.bindValue(":ID", ID);
    query.exec();

    model->setQuery(query);
    return model;
}
QSqlQueryModel* Rapport::recherche1(QString TITRE)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QSqlQuery query;
    query.prepare("SELECT * FROM RAPPORT WHERE TITRE = :TITRE");
    query.bindValue(":TITRE", TITRE);
    query.exec();

    model->setQuery(query);
    return model;
}
QSqlQueryModel* Rapport::recherche2(QString OBJECTIF)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QSqlQuery query;
    query.prepare("SELECT * FROM RAPPORT WHERE OBJECTIF = :OBJECTIF");
    query.bindValue(":OBJECTIF", OBJECTIF);
    query.exec();

    model->setQuery(query);
    return model;
}
QSqlQueryModel *Rapport::tri()
         {
             QSqlQuery *q = new QSqlQuery();
             QSqlQueryModel *model = new QSqlQueryModel();
             q->prepare("SELECT * FROM RAPPORT ORDER BY ID");
             q->exec();
             model->setQuery(*q);

             return model;
}

QSqlQueryModel *Rapport::tri1()
         {
             QSqlQuery *q = new QSqlQuery();
             QSqlQueryModel *model = new QSqlQueryModel();
             q->prepare("SELECT * FROM RAPPORT ORDER BY TITRE");
             q->exec();
             model->setQuery(*q);

             return model;
}
QSqlQueryModel *Rapport::tri2()
         {
             QSqlQuery *q = new QSqlQuery();
             QSqlQueryModel *model = new QSqlQueryModel();
             q->prepare("SELECT * FROM RAPPORT ORDER BY OBJECTIF");
             q->exec();
             model->setQuery(*q);

             return model;
}






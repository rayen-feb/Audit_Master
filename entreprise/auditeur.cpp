#include "auditeur.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QImage>
#include <QFileDialog>
#include <QStandardItemModel>
#include <QLabel>
#include<QSqlRecord>
#include<QBuffer>
#include <QSqlTableModel>
#include <QSqlError>
#include <QItemDelegate>
#include <QTableView>



Auditeur::Auditeur(int ID,int NUMERO,QString NOM,QString PRENOM,QString SEXE,QString ADRESSE,QString CLASSE,QByteArray image,QString imagePath)
{this->id=ID;
this->numero=NUMERO;
this->nom=NOM;
this->prenom=PRENOM;
this->sexe=SEXE;
this->adresse=ADRESSE;
this->classe=CLASSE;
this->image=image;
this->imagePath = imagePath;
}
int Auditeur::getid(){return id;}
int Auditeur::getnumero(){return numero;}
QString Auditeur::getnom(){return nom;}
QString Auditeur::getprenom(){return prenom;}
QString Auditeur::getsexe(){return sexe;}
QString Auditeur::getadresse(){return adresse;}
QString Auditeur::getclasseA(){return classe;}
QByteArray Auditeur::getimage(){ return image;}
QString Auditeur:: getImagePath() { return imagePath; }
void Auditeur::setimage(QByteArray img) { image = img; }
void Auditeur:: setImagePath(QString path) { imagePath = path; }
void Auditeur::setid(int ID){this->id=ID;}
void Auditeur::setnumero(int NUMERO){this->numero=NUMERO;}
void Auditeur::setnom(QString NOM){this->nom=NOM;}
void Auditeur::setprenom(QString PRENOM){this->prenom=PRENOM;}
void Auditeur::setsexe(QString SEXE){this->sexe=SEXE;}
void Auditeur::setadresse(QString ADRESSE){this->adresse=ADRESSE;}
void Auditeur::setclasseA(QString CLASSE){this->classe=CLASSE;}



bool Auditeur::existeID(int id_c)
{
   QSqlQuery query;
   query.prepare("SELECT id FROM AUDITEURS WHERE id = :id");
   query.bindValue(":id", id);
   if (query.exec() && query.next()) {
       return true; // L'ID existe déjà
   }
   return false; // L'ID est unique
}
bool Auditeur::ajouter()
{
   if (existeID(id)) {
       return false; // L'ID existe déjà, l'ajout échoue
   }

   QSqlQuery query;
   QByteArray byteArray;
       // Charger l'image en mémoire
       if (!imagePath.isEmpty()) {
           QImage image(imagePath);
           if (image.isNull()) {
               qDebug() << "Impossible de charger l'image.";
               return false;
           }
           QBuffer buffer(&byteArray);
           buffer.open(QIODevice::WriteOnly);
           image.save(&buffer, "PNG");
           buffer.open(QIODevice::WriteOnly);
           image.save(&buffer, "PNG");
       }

   QString id_string = QString::number(id);
   QString numero_string = QString::number(numero);
   query.prepare("INSERT INTO AUDITEURS (NUMERO, ID, CLASSE, ADRESSE, PRENOM, NOM, SEXE, IMAGE) "
                 "VALUES (:numero, :id, :classe, :adresse, :prenom, :nom, :sexe, :image)");
   query.bindValue(":numero", numero_string);
   query.bindValue(":id", id_string);
   query.bindValue(":classe", classe);
   query.bindValue(":adresse", adresse);
   query.bindValue(":prenom", prenom);
   query.bindValue(":nom", nom);
   query.bindValue(":sexe", sexe);
   query.bindValue(":image", image);


   return query.exec();
}



QSqlQueryModel* Auditeur::afficher()
{
   QSqlQueryModel* model = new QSqlQueryModel();
   model->setQuery("SELECT * FROM AUDITEURS");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant "));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("Sexe"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("Numero"));
   model->setHeaderData(6, Qt::Horizontal, QObject::tr("Classe"));
   model->setHeaderData(7, Qt::Horizontal, QObject::tr("Image"));

   QTableView* view = new QTableView();
   view->setModel(model);

   // Utilisez QItemDelegate pour personnaliser l'affichage/édition de colonnes spécifiques
   QItemDelegate* delegate = new QItemDelegate(view);
   view->setItemDelegateForColumn(7, delegate);


   return model;
}

bool Auditeur::supprimer(int id)
{
   if (!existeID(id)) {
       return false; // L'ID n'existe pas, suppression échouée
   }

   QSqlQuery query;
   query.prepare("DELETE FROM AUDITEURS WHERE id = :id");
   query.bindValue(":id", id);

   return query.exec();
}

bool Auditeur::modifier()
{
   QSqlQuery query;
   QString id_string = QString::number(id);
   QString numero_string = QString::number(numero);
   if (!existeID(id)) {
       return false; // L'ID n'existe pas, suppression échouée
   }
   else{
   query.prepare("UPDATE AUDITEURS SET NUMERO = :numero, CLASSE = :classe, ADRESSE = :adresse, "
                 "PRENOM = :prenom, NOM = :nom, SEXE = :sexe WHERE ID = :id");
   query.bindValue(":numero", numero_string);
   query.bindValue(":classe", classe);
   query.bindValue(":adresse", adresse);
   query.bindValue(":prenom", prenom);
   query.bindValue(":nom", nom);
   query.bindValue(":sexe", sexe);
   query.bindValue(":id", id_string);
   query.bindValue(":image", image);


   return query.exec();
}}
QSqlQueryModel *Auditeur::afficherrecherche(int id)
{
   QSqlQueryModel *model = new QSqlQueryModel();
   QSqlQuery query;

   // Préparez la requête SQL en utilisant le paramètre lié pour l'ID de recherche.
   query.prepare("SELECT * FROM AUDITEURS WHERE id = :id");
   query.bindValue(":id", id);

   if (query.exec())
   {
       model->setQuery(query);
   }
   else
   {
       // Gérer les erreurs ici, par exemple, afficher un message d'erreur.
   }

   return model;
}

QSqlQueryModel *Auditeur::afficherrecherche1 (QString& nom)
{
   QSqlQueryModel *model = new QSqlQueryModel();
   QSqlQuery query;

   // Préparez la requête SQL en utilisant un paramètre lié pour le nom de recherche.
   query.prepare("SELECT * FROM AUDITEURS WHERE nom = :nom");
   query.bindValue(":nom", nom);

   if (query.exec())
   {
       model->setQuery(query);
   }
   else
   {
       // Gérer les erreurs ici, par exemple, afficher un message d'erreur.
   }

   return model;
}

QSqlQueryModel *Auditeur::afficherrecherche2(QString& sexe)
{
   QSqlQueryModel *model = new QSqlQueryModel();
   QSqlQuery query;

   // Préparez la requête SQL en utilisant le paramètre lié pour le sexe de recherche.
   query.prepare("SELECT * FROM AUDITEURS WHERE sexe = :sexe");
   query.bindValue(":sexe", sexe);

   if (query.exec())
   {
       model->setQuery(query);
   }
   else
   {
       // Gérer les erreurs si la requête échoue.
   }

   return model;
}


int Auditeur::getNombreAuditeursParClasse(QString classe)
{
   QSqlQuery query;
   query.prepare("SELECT COUNT(*) FROM AUDITEURS WHERE CLASSE = :classe");
   query.bindValue(":classe", classe);

   if (query.exec() && query.next()) {
       return query.value(0).toInt();
   }

   return -1; // Retourne -1 en cas d'erreur
}

int Auditeur :: getNombreAuditeursParSexe(QString sexe)
{

   QSqlQuery query;
   query.prepare("SELECT COUNT(*) FROM AUDITEURS WHERE SEXE = :sexe");
   query.bindValue(":sexe", sexe);

   if (query.exec() && query.next()) {
       return query.value(0).toInt();
   }

   return -1; // Retourne -1 en cas d'erreur
}


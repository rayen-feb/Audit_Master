#include "normes.h"
QVector<Normes> Normes::NormesHistory;
int Normes::lastGeneratedID = 0;
Normes::Normes()
{
    id=0;
    nom=" ";
    des=" ";
    date_n=" ";
    conformite=" ";
}
Normes::Normes(int id,QString nom,QString des,QString date_n,QString conformite)
{
    this->id=id;
    this->nom=nom;
    this->des=des;
    this->date_n=date_n;
    this->conformite=conformite;
}
int Normes:: getId() {
    return id;
}
QString Normes:: getNom() {
    return nom;
}
QString Normes:: getDes()  {
    return des;
}
QString Normes:: getdate_n() {
    return date_n;
}
QString Normes:: getconformite()  {
    return conformite;
}
int Normes ::getID() const  {

    return ID;
}
QString Normes ::getAction() const  {

    return action;
}
QDateTime Normes::getDateTime() const  {

    return date;
}
QString Normes ::getDetails() const  {

    return details;
}

void Normes:: setId(int newId ){
    id = newId;
}
void Normes:: setNom( QString newNom ) {
    nom = newNom;
}
void Normes:: setDes( QString newDes ) {
    des = newDes;
}
void Normes:: setdate_n(QString newdate) {
    date_n = newdate;
}
void Normes:: setconformite(QString newconf) {
    conformite = newconf;
}

bool Normes:: ajouter()
{

    QSqlQuery query;
    QString id_string=QString::number(id);
    query.prepare("INSERT INTO NORMES (id, nom,des , date_n,conformite) "
                  "VALUES (:id, :nom,  :des, :date_n, :conformite)");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":des", des);
    query.bindValue(":date_n", date_n);
    query.bindValue(":conformite", conformite);
    ID = generateUniqueID();
        action = "Ajout";
        date = QDateTime::currentDateTime();
        details = QString("ID: %1, Nom: %2, des: %3, Date: %4,Conformité: %5")
                   .arg(id)
                   .arg(nom)
                   .arg(des)
                   .arg(date.toString("yyyy-MM-dd"))
                   .arg(conformite);

        NormesHistory.append(*this);
        saveNormesHistoryToFile("C:/Users/MED LIWA/Desktop/history.json");
    return  query.exec();

}

QSqlQueryModel* Normes::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM NORMES");
    model->setHeaderData(0, Qt::Horizontal, QObject ::tr("id"));
    model->setHeaderData(1, Qt::Horizontal,QObject :: tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject ::tr("description"));
    model->setHeaderData(3, Qt::Horizontal,QObject :: tr("date_n"));
    model->setHeaderData(4, Qt::Horizontal, QObject ::tr("conformite"));
    qDebug()<<"wtf";
    return  model;
}

bool Normes::supprimer(int id)
{
    if (estDejaSupprime(id)) {
        return false;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM NORMES WHERE id = :id");
    query.bindValue(":id", id);

    ID = generateUniqueID();
        action = "Suppression";
        date = QDateTime::currentDateTime();
        details = QString("ID: %1, Nom: %2, des: %3, Date: %4,Conformité: %5")
                   .arg(id)
                   .arg(nom)
                   .arg(des)
                   .arg(date.toString("yyyy-MM-dd"))
                   .arg(conformite);

        NormesHistory.append(*this);
        saveNormesHistoryToFile("C:/Users/MED LIWA/Desktop/history.json");

    return query.exec();
}

bool Normes::estDejaSupprime(int id)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM NORMES WHERE id = :id");
    query.bindValue(":id", id);
    query.exec();

    if (query.next()) {
        int count = query.value(0).toInt();
        return (count == 0);
    }

    return false;
}

bool Normes::modifier()
{
    QString id_string = QString::number(id);
    QSqlQuery query;
    QString sqlQuery = "UPDATE NORMES SET ";
    QStringList updateFields;

    if (!nom.isEmpty()) {
        sqlQuery += "nom = :nom, ";
        updateFields << "nom";
    }
    if (!des.isEmpty()) {
        sqlQuery += "des = :des, ";
        updateFields << "des";
    }
    if (!date_n.isEmpty()) {
        sqlQuery += "date_n = :date_n, ";
        updateFields << "date_n";
    }
    if (!conformite.isEmpty()) {
        sqlQuery += "conformite = :conformite, ";
        updateFields << "conformite";
    }

    // Remove the trailing comma and space from the query string
    if (sqlQuery.endsWith(", ")) {
        sqlQuery.chop(2);
    }

    sqlQuery += " WHERE id = :ID";
    query.prepare(sqlQuery);

    query.bindValue(":ID", id);
    for (const QString& field : updateFields) {
        query.bindValue(":" + field, field == "nom" ? nom : field == "des" ? des : field == "date_n" ? date_n : conformite);
    }

    ID = generateUniqueID();
        action = "Modification";
        date = QDateTime::currentDateTime();
        details = QString("ID: %1, Nom: %2, des: %3, Date: %4,Conformité: %5")
                   .arg(id)
                   .arg(nom)
                   .arg(des)
                   .arg(date.toString("yyyy-MM-dd"))
                   .arg(conformite);

        NormesHistory.append(*this);
        saveNormesHistoryToFile("C:/Users/MED LIWA/Desktop/history.json");

    return query.exec();
}

QSqlQueryModel* Normes::tri()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT id, nom, des, date_n, conformite FROM NORMES ORDER BY id ASC"); // Sort by ID in ascending order
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("des"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_n"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("conformite"));

    return model;
}


QSqlQueryModel* Normes::recherche(QString id) {

    QSqlQueryModel* model = new QSqlQueryModel();

    QSqlQuery query;
    query.prepare("SELECT * FROM NORMES WHERE id = :ID");
    query.bindValue(":ID", id);
    query.exec();

    model->setQuery(query);
    return model;
}

bool Normes::saveNormesHistoryToFile(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Error opening file for writing: " << file.errorString();
        return false;
    }

    QJsonArray jsonArray;
    for (const Normes &norme : NormesHistory)
     {
         QJsonObject normeObject;
         normeObject["ID"] = norme.getID();
         normeObject["Action"] = norme.getAction();
         normeObject["Date"] = norme.getDateTime().toString("yyyy-MM-dd HH:mm:ss");
         normeObject["Details"] = norme.getDetails();

         jsonArray.append(normeObject);
     }
    QJsonDocument jsonDoc(jsonArray);
    file.write(jsonDoc.toJson());
    file.close();

    return true;
}
QJsonObject Normes::toJsonObject() const
{
    QJsonObject jsonObj;

    jsonObj["id"] = id;
    jsonObj["nom"] = nom;
    jsonObj["description"] = des;
    jsonObj["date"] = date_n;
    jsonObj["conformite"] = conformite;


    return jsonObj;
}

int Normes::generateUniqueID()
{

    QFile file("C:/Users/MED LIWA/Desktop");
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream in(&file);
        in >> lastGeneratedID;
        file.close();
    }


    int newID = ++lastGeneratedID;


    if (file.open(QIODevice::WriteOnly)) {
        QDataStream out(&file);
        out << lastGeneratedID;
        file.close();
    }

    return newID;
}






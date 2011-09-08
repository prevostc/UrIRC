#include <iostream>
#include <QtCore>
#include <QtSql>


void relModel()
{
  QSqlRelationalTableModel *model = new QSqlRelationalTableModel();
  
  model->setTable( "names" );
  model->setRelation( 0, QSqlRelation( "salaries", "id", "annual" ) );
  model->select();
  
  model->setHeaderData( 0, Qt::Horizontal, QObject::tr("Annual Pay") );
  model->setHeaderData( 1, Qt::Horizontal, QObject::tr("First Name") );
  model->setHeaderData( 2, Qt::Horizontal, QObject::tr("Last Name") );
}

void tabModel()
{
  QSqlTableModel *model = new QSqlTableModel();
  
  model->setTable( "names" );
  model->setFilter( "lastname = 'Doe'" );
  model->select();
  
  model->removeColumn( 0 );
}

void qryModel()
{
  QSqlQueryModel *model = new QSqlQueryModel();
  model->setQuery( "SELECT firstname, lastname FROM names" );
}


int waca( void )
{
  QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );

  db.setDatabaseName( "usimple.db" );
  
  if( !db.open() )
  {
    qDebug() << db.lastError();
    qFatal( "Failed to connect." );
  }
    
  qDebug( "Connected!" );
  
  QSqlQuery qry;

  qry.prepare( "CREATE TABLE IF NOT EXISTS names (id INTEGER UNIQUE PRIMARY KEY, firstname VARCHAR(30), lastname VARCHAR(30))" );
  qry.exec();
    
  qry.prepare( "INSERT INTO names (id, firstname, lastname) VALUES (1, 'John', 'Doe')" );
  qry.exec();

  qry.prepare( "INSERT INTO names (id, firstname, lastname) VALUES (2, 'Jane', 'Doe')" );
  qry.exec();

  qry.prepare( "INSERT INTO names (id, firstname, lastname) VALUES (3, 'James', 'Doe')" );
  qry.exec();

  qry.prepare( "INSERT INTO names (id, firstname, lastname) VALUES (4, 'Judy', 'Doe')" );
  qry.exec();

  qry.prepare( "INSERT INTO names (id, firstname, lastname) VALUES (5, 'Richard', 'Roe')" );
  qry.exec();

  qry.prepare( "INSERT INTO names (id, firstname, lastname) VALUES (6, 'Jane', 'Roe')" );
  qry.exec();

  qry.prepare( "INSERT INTO names (id, firstname, lastname) VALUES (7, 'John', 'Noakes')" );
  qry.exec();

  qry.prepare( "INSERT INTO names (id, firstname, lastname) VALUES (8, 'Donna', 'Doe')" );
  qry.exec();

  qry.prepare( "INSERT INTO names (id, firstname, lastname) VALUES (:id, :firstname, :lastname)" );
  qry.bindValue( ":id", 9 );
  qry.bindValue( ":firstname", "Ralph" );
  qry.bindValue( ":lastname", "Roe" );
  qry.exec();

  qry.prepare( "CREATE TABLE IF NOT EXISTS salaries (id INTEGER UNIQUE PRIMARY KEY, annual INTEGER)" );
  qry.exec();

  qry.prepare( "INSERT INTO salaries (id, annual) VALUES (1, 1000)" );
  qry.exec();

  qry.prepare( "INSERT INTO salaries (id, annual) VALUES (2, 900)" );
  qry.exec();

  qry.prepare( "INSERT INTO salaries (id, annual) VALUES (3, 900)" );
  qry.exec();

  qry.prepare( "INSERT INTO salaries (id, annual) VALUES (5, 1100)" );
  qry.exec();

  qry.prepare( "INSERT INTO salaries (id, annual) VALUES (6, 1000)" );
  qry.exec();

  qry.prepare( "INSERT INTO salaries (id, annual) VALUES (8, 1200)" );
  qry.exec();

  qry.prepare( "INSERT INTO salaries (id, annual) VALUES (9, 1200)" );
  qry.exec();

  relModel();
  tabModel();
  qryModel();
}





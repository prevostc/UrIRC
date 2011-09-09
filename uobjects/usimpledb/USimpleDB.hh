#ifndef USIMPLEDB_HH 
#define USIMPLEDB_HH 
 
// Include the UObject declarations. 
#include <urbi/uobject.hh> 
 
#include <iostream>
#include <QtSql>
 
/// A UObject wrapping a machine object. 
class USimpleDB : public urbi::Object
{ 
public: 
  // C++ contructor. 
  // @param name  name given to the instance. 
  USimpleDB(const std::string& name); 
 
  // Urbi constructor. 
  // @param dbname file name or ":memory:"
  // @return 0 on success. 
  int init(ufloat dbname); 
 
  // query wrapper
  ufloat query(std::string query); 
 
protected: 
  // database handler
  QSqlDatabase _db;

  // query handler
  QSqlQuery _query; 
}; 
#endif // ! USIMPLEDB_HH 

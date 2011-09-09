#include <USimpleDB.hh> 
 
USimpleDB::USimpleDB(const std::string& name) : urbi::UObject(name) {
	// Register the Urbi constructor.  
	// This is the only mandatory part of the C++ constructor.
	UBindFunction(USimpleDB, init); 
}
 
int USimpleDB::init(ufloat dbname) {
	// Bind the functions, i.e., declare them to the Urbi world
	// LOCK_INSTANCE Prevent parallel call to any function of this object.. 
	UBindThreadedFunction(USimpleDB, query, urbi::LOCK_INSTANCE); 
}

ufloat USimpleDB::query(std::string query) {
	return 42;
}
 

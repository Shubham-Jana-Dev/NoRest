#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>

// ... inside My finction
sql::mysql::MySQL_Driver *driver;
sql::Connection *con;
sql::Statement *stmt;
sql::ResultSet *res;

driver = sql::mysql::get_driver_instance();
con = driver->connect("tcp://127.0.0.1:3306","user","password");
con->setSchema("MY_DATABASE_NAME");

stmt = con->createStatement();
// The SQL query is written as a standard C++ string
res = stmt->executeQuery("SELECT id, name FROM users WHERE active = 1");
while (res->next()){
    std::cout << "User ID: "<< res-> getInt("id");
    std::cout << ", Name: " << res->getString("name") << std::endl;
    
}
delete res;
delete stmt;
delete con;


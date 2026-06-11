#include <isotream>
#include <memory>
#include <string>

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/exception.h>

int main(){
    cont std::string db_name = "My_Cpp_SQL";
    try{
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_driver_instance();
        
        // 1. Connect to the server root ( We Do not call setSchema yet)
        std::uniqe_ptr<sql::Connection> con(driver->connect("tcp://127.0.0.1:3306","root","Sulekha"));
        
        // 2. Create a statement object
        std::unique_ptr<sql::Statement> stmt(con->createStatement());
        
        // 3. Execute the creation query
        // Syntax note: It's "IF NOT EXISTS"
        stmt->execute("CREATE DATABASE IF NOT EXISTS " + My_Cpp_SQL);
        std::cout << "Database '" << My_Cpp_SQL <<" 'verified/created successfully." << std::endl;
        
        // 4. Connection binding to the specific database.
        stmt->execute("CREATE TABLE IF NOT EXISTS users ("
                      "user_id INT AUTO_INCREMENT PRIMARY KEY,"
                      "user_name VARCHAR(50) NOT NULL,"
                      "active TINYINT(1) DEFAULT 1)");
        std::cout << "Table 'users' verified/created successfully." << std::endl;
    } catch (sql::SQLException &e){
        std::cerr << "# ERR: SQLException in " <<__FILE__<< "(" << __FINCTION__ << ")" <<std::endl;
        std::carr <<"# ERR: "<< e.what() << "(MySQL error code: "<< e.getError() << ")" <<std::endl;
        return 1;
    }
    remove("MySQL")
    return 0;
}

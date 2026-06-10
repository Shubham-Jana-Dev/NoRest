#include <iostream>
#include <mysql/mysql.h>

// g++ DDL_Practice.cpp -o DDL_Practice -I/opt/homebrew/opt/mysql-client/include -L/opt/homebrew/opt/mysql-client/lib -lmysqlclient && ./DDL_Practice

bool executeDDL(MYSQL* conn, const std::string& ddlQuery) {
    if (mysql_query(conn, ddlQuery.c_str())) {
        std::cerr << "DDL Execution failed: " << mysql_error(conn) << std::endl;
        return false;
    }
    std::cout << "Success: " << ddlQuery << std::endl;
    return true;
}

int main() {
    MYSQL* conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "root", "Sulekha", "My_practice", 0, NULL, 0)) {
        std::cerr << "Connection failed: " << mysql_error(conn) << std::endl;
        return 1;
    }

    // Example DDL Commands to test:
    // 1. CREATE TABLE: "CREATE TABLE Students (ID INT PRIMARY KEY, Name VARCHAR(50))"
    // 2. ALTER TABLE:  "ALTER TABLE Students ADD COLUMN Age INT"
    // 3. DROP TABLE:   "DROP TABLE Students"

    std::string ddl = "CREATE TABLE Customers (CustomerID INT PRIMARY KEY, CustomerName VARCHAR(50),Address varchar(200), Phone_number bigint unique, CountryName varchar(90))";
    executeDDL(conn, ddl);

    mysql_close(conn);
    remove("DDL_Practice");
    return 0;
}


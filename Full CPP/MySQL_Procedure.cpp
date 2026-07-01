//
//  MySQL_Procedure.cpp
//
//  Created by Shubham Jana on 22/06/26.
//

#include <iostream>
#include <mysql.h>

int main() {
    // Initialize MySQL connection object
    MYSQL* conn = mysql_init(NULL);
    if (conn == NULL) {
        std::cerr << "MySQL initialization failed." << std::endl;
        return 1;
    }

    // Connect to the database
    if (mysql_real_connect(conn, "127.0.0.1", "user", "Sulekha", "My_practice", 3306, NULL, 0) == NULL) {
        std::cerr << "Connection Error: " << mysql_error(conn) << std::endl;
        mysql_close(conn);
        return 1;
    }

    // 1. Drop the procedure if it already exists
    if (mysql_query(conn, "DROP PROCEDURE IF EXISTS InsertHundredEntries")) {
        std::cerr << "Drop Procedure Error: " << mysql_error(conn) << std::endl;
    }

    // 2. Define the SQL command to create the procedure (fixed trailing comma typo)
    std::string createProc =
        "CREATE PROCEDURE InsertHundredEntries() "
        "BEGIN "
        "   DECLARE i INT DEFAULT 1; "
        "   WHILE i <= 100 DO "
        "       INSERT INTO student (student_id, roll, student_name) VALUES(i, CONCAT('1', i), CONCAT('STUDENT_', i)); "
        "       SET i = i + 1; "
        "   END WHILE; "
        "END;";

    // 3. Create the procedure
    if (mysql_query(conn, createProc.c_str())) {
        std::cerr << "Create Procedure Error: " << mysql_error(conn) << std::endl;
        mysql_close(conn);
        return 1;
    }

    // 4. Call the procedure
    if (mysql_query(conn, "CALL InsertHundredEntries()")) {
        std::cerr << "Execution Error: " << mysql_error(conn) << std::endl;
        mysql_close(conn);
        return 1;
    }

    std::cout << "Procedure created and executed successfully." << std::endl;

    // Clean up connection
    mysql_close(conn);
    return 0;
}

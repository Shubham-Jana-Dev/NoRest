#include <iostream>
#include <mysql/mysql.h>
// g++ MySQL_Join.cpp -o MySQL_Join -I/opt/homebrew/opt/mysql-client/include -L/opt/homebrew/opt/mysql-client/lib -lmysqlclient && ./MySQL_Join
int main(){
    MYSQL* conn = mysql_init(NULL);
    // Boilerplate: Connecting to your local MySQL
    if (!mysql_real_connect(conn, "localhost", "root", "Sulekha", "My_practice",0,NULL,0)){
        std::cerr << "Connection failed: "<< mysql_error(conn) << std::endl;
        return 1;
    }
    // my query here
    std::string query = "SELECT * FROM Employee inner join parents on Employee.City_name = parents.City;";
    if (mysql_query(conn, query.c_str())){
        std::cerr << "query failed: " << mysql_error(conn) << std::endl;
    } else {
        MYSQL_RES* res = mysql_store_result(conn);
        if (res){
            MYSQL_ROW row;
            // fetch each row and print it
            while ((row = mysql_fetch_row(res))){
                for(int i = 0; i < mysql_num_fields(res); i++){
                    std::cout << (row[i] ? row[i] :"NULL") << "\t";
                }
                std::cout << std::endl;
            }
            mysql_free_result(res);
        }
    }
    mysql_close(conn);
    remove("Delete_exe");
    return 0;
}

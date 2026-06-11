#include <iostream>
#include <mysql/mysql.h>
// g++ MYSQL_select_all.cpp -o MYSQL_select_all -I/opt/homebrew/opt/mysql-client/include -L/opt/homebrew/opt/mysql-client/lib -lmysqlclient && ./MYSQL_select_all
int main(){
    MYSQL* conn = mysql_init(NULL);
    // Boilerplate:
    if (!mysql_real_connect(conn, "localhost", "root", "Sulekha","My_practice", 0, NULL, 0)){
        std::cerr << "Connection failed: "<< mysql_error(conn) << std::endl;
        return 1;
    }
    // SQL query
    std::string query = "Select* from parents";
    if(mysql_query(conn, query.c_str())){
        std::cerr << "query failed: "<< mysql_error(conn) << std::endl;
    }else{
        MYSQL_RES* res = mysql_store_result(conn);
        if(res){
            MYSQL_ROW row;
            // fetch each row and print it
            while ((row = mysql_fetch_row(res))){
                for(int i = 0; i<mysql_num_fields(res); i++){
                    std::cout << (row[i] ? row[i]:"NULL")<< "\t";
                }
                std::cout << std::endl;
            }
            mysql_free_result(res);
        }
    }
    mysql_close(conn);
    remove("MySQL_select_all");
    return 0;
}


#include <iostream>
#include <mysql/mysql.h>
// g++ MySQL_rightjoin.cpp -o MySQL_rightjoin -I/opt/homebrew/opt/mysql-client/include -L/opt/homebrew/opt/mysql-client/lib -lmysqlclient && ./MySQL_rightjoin
int main(){
    MYSQL* conn = mysql_init(NULL);
    // Boilerplate
    if (!mysql_real_connect(conn, "localhost","root","Sulekha","My_practice",0,NULL,0)){
        std::cerr << "Connection failed: " << mysql_error(conn) << std::endl;
        return 1;
    }
    // QUERY
    std::string query = "select* from Employee right outer join parents on Employee.City_name = parents.City;";
    if (mysql_query(conn, query.c_str())){
        std::cerr << "query failed: "<< mysql_error(conn) << std::endl;
    } else{
        MYSQL_RES* res = mysql_store_result(conn);
        if(res){
            MYSQL_ROW row;
            // FETCH EACH ROW AND PRINT IT
            while ((row = mysql_fetch_row(res))){
                for (int i = 0; i <mysql_num_fields(res); i++){
                    std::cout << (row[i] ? row[i]: "NULL") << "\t";
                }
                std::cout << std::endl;
            }
            mysql_free_result(res);
        }
    }
    mysql_close(conn);
    return 0;
}


#include "Orders_Model.h"

using namespace std;

int Orders_Model(char order_number[1024], char order_date[1024], char customer_code[1024], char inventory_number[1024], char cargo_weight[1024], char distance[1024]) {
    char * istr,
            * end_str[1024],
            * customer_name = (char *) "",
            * car_brand_code = (char *) "",
            * car_brand = (char *) "";

    string old_str;
    string temp_str;
    string temp1_str;
    const char* new_str;
    int i = 0;

    // Получаем имя заказчика по введенному коду заказчика
    int m_customer_code_array[] = {1};
    old_str = get_file_value((char *) "Customers.txt", customer_code, 0, m_customer_code_array, 1);

    // Перевод string в char
    new_str = old_str.c_str();

    // Выделение первой части строки
    istr = strtok((char *) new_str, SEPARATION);

    // Выделение последующих частей
    i = 0;
    while (istr != NULL) {
        end_str[i] = istr;
        // Выделение очередной части строки
        istr = strtok(NULL, SEPARATION);
        i++;
    }

    // Присваение нужным переменным
    for (int j = 0; j < strlen((const char *) end_str); ++j) {
        switch (j){
            case 0:
                customer_name = end_str[j];
                break;
            default:break;
        }
    }

    // Получаем код марки авто по инвентарному номеру
    int m_inventory_number_array[] = {1};
    temp_str = get_file_value((char *) "Auto.txt", inventory_number, 0, m_inventory_number_array, 1);

    // Перевод string в char
    new_str = temp_str.c_str();

    // Выделение первой части строки
    istr = strtok((char *) new_str, SEPARATION);

    // Выделение последующих частей
    i = 0;
    while (istr != NULL) {
        end_str[i] = istr;
        // Выделение очередной части строки
        istr = strtok(NULL, SEPARATION);
        i++;
    }

    // Присваение нужным переменным
    for (int j = 0; j < strlen((const char *) end_str); ++j) {
        switch (j){
            case 0:
                car_brand_code = end_str[j];
                break;
            default:break;
        }
    }

    // Получаем марку авто по коду марки авто
    int m_car_brand_code_array[] = {1};
    temp1_str = get_file_value((char *) "Brand_directory.txt", car_brand_code, 0, m_car_brand_code_array, 1);

    // Перевод string в char
    new_str = temp1_str.c_str();

    // Выделение первой части строки
    istr = strtok((char *) new_str, SEPARATION);

    // Выделение последующих частей
    i = 0;
    while (istr != NULL) {
        end_str[i] = istr;
        // Выделение очередной части строки
        istr = strtok(NULL, SEPARATION);
        i++;
    }

    // Присваение нужным переменным
    for (int j = 0; j < strlen((const char *) end_str); ++j) {
        switch (j){
            case 0:
                car_brand = end_str[j];
                break;
            default:break;
        }
    }

    // Конечный вид строки
    char *str;
    str = strcat(order_number, SEPARATION),
            str = strcat(str, order_date),
            str = strcat(str, SEPARATION),
            str = strcat(str, customer_code),
            str = strcat(str, SEPARATION),
            str = strcat(str, customer_name),
            str = strcat(str, SEPARATION),
            str = strcat(str, inventory_number),
            str = strcat(str, SEPARATION),
            str = strcat(str, car_brand),
            str = strcat(str, SEPARATION),
            str = strcat(str, cargo_weight),
            str = strcat(str, SEPARATION),
            str = strcat(str, distance),
            str = strcat(str, SEPARATION);

    FILE * fo = fopen(DOCROOT"Files/Orders.txt", "a+");

    if(fo) {
        long file_size = 0;
        fseek(fo, 0, SEEK_END);
        file_size = ftell(fo);

        // Если размер файла > 0 , то переносим каретку на след. строку
        if(file_size != 0) {
            fputs("\n", fo);
        }

        // Добавляем сформированную строку
        fputs(str, fo);

        fclose(fo);

        return 1;
    }else{
        return 0;
    }
}
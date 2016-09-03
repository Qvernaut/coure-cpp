#include "Customers_Model.h"

int Customers_Model(char customer_code[1024], char customer_name[1024], char address[1024], char phone[1024]) {

    // Конечный вид строки
    char *str;
    str = strcat(customer_code, SEPARATION),
            str = strcat(str, customer_name),
            str = strcat(str, SEPARATION),
            str = strcat(str, address),
            str = strcat(str, SEPARATION),
            str = strcat(str, phone),
            str = strcat(str, SEPARATION);

    FILE * fo = fopen(DOCROOT"Files/Customers.txt", "a+");

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
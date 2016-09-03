#include "Brand_directory_Model.h"

int Brand_directory_Model(char car_brand_code[1024], char car_brand[1024], char freight[1024]) {

    // Конечный вид строки
    char * str;
    str = strcat(car_brand_code, SEPARATION),
            str = strcat(str, car_brand),
            str = strcat(str, SEPARATION),
            str = strcat(str, freight),
            str = strcat(str, SEPARATION);

    FILE * fo = fopen(DOCROOT"Files/Brand_directory.txt", "a+");

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
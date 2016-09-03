#include "Main_Model.h"

/*
 * Вывод содержимого файла построчно
 *
 * @return void
 */
void get_content(char * file) {
    char str[1024];
    char * estr;
    char files_root[1024] = DOCROOT"Files/";
    strcat(files_root, file);

    FILE * fo = fopen(files_root, "r");

    // Построчно считываем файл
    while(true) {

        estr = fgets(str, sizeof(str), fo);

        // Случай дохода до конца
        if (estr == NULL) {
            break;
        }

        printf ("\t%s", str);
    }

    printf("\n");

    fclose(fo);
}

/*
 * Проверка существования в файле определенного значения
 *
 * @param file файл
 * @param search искомое значение
 * @return void
 */
int check_file(char * file, char search[1024]) {
    char str[1024];
    char sep[10] = SEPARATION;
    char * estr;
    char * istr;

    char files_root[1024] = DOCROOT"Files/";
    strcat(files_root, file);

    FILE * fo = fopen(files_root, "r");

    while (true) {

        // Получаем строку
        estr = fgets(str, sizeof(str), fo);

        if( estr == NULL) {
            break;
        }

        // Выделение первой части строки
        istr = strtok(str, sep);

        // Выделение последующих частей
        while (istr != NULL) {

            // Сравнивание с искомой стракой
            if (!strcmp(search, istr)){

                fclose(fo);

                return 1;
            }

            // Выделение очередной части строки
            istr = strtok(NULL, sep);
        }

    }

    fclose(fo);

    return 0;
}

/*
 * Получает определенные значения из файла
 *
 * @param file файл
 * @param search искомое значение
 * @param pos позиция искомого значения
 * @param array массив с индексами нужных значений
 * @param размерность передаваемого массива
 * @return string строка содержащая искомые значения, разделены |
 */
std::string get_file_value(char * file, char search[1024], int pos, int array[], int count){
    char str[1024] = "",
            * estr,
            * istr;

    char demand_array[1024] = "";

    char files_root[1024] = DOCROOT"Files/";
    strcat(files_root, file);

    FILE * fo = fopen(files_root, "r");

    while (true) {

        estr = fgets(str, sizeof(str), fo);

        if(estr == NULL) {
            break;
        }

        // Выделение первой части строки
        istr = strtok(str, SEPARATION);

        // Выделение последующих частей
        int i = 0;
        bool trigger = false;

        while (istr != NULL) {

            if (!strcmp(search, istr) and i == pos){
                trigger = true;
            }

            if(trigger) {
                for (int j = 0; j < count; ++j) {
                    if(array[j] == i) {
                        strcat(demand_array, istr);
                        strcat(demand_array, SEPARATION);
                    }
                }
            }

            i++;

            // Выделение очередной части строки
            istr = strtok(NULL, SEPARATION);
        }

        if(trigger) {
            break;
        }
    }
    fclose(fo);

    return  demand_array;
}
#include "Calculation_Model.h"

using namespace std;

int Calculation_Model(char order_number[1024]) {
    char * istr,
            * end_str[1024];

    char * inventory_number = (char *) ""; // Инвентарный номер авто
    int cargo_weight = 0; // Масса груза
    int distance = 0; // Расстояние
    char * car_brand_code = (char *) ""; // Код марки авто
    int freight = 0; // Стоимость перевозки одного ткм

    string old_str;
    const char* new_str;
    int i = 0;

    // Заказы
    // Необходимые элементы
    int m_order_number_array[] = {4, 6, 7};
    old_str = get_file_value((char *) "Orders.txt", order_number, 0, m_order_number_array, 3);

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
                inventory_number = end_str[j];
                break;
            case 1:
                cargo_weight = atoi(end_str[j]);
                break;
            case 2:
                distance = atoi(end_str[j]);
                break;
            default:break;
        }
    }

    // Автомобили
    // Необходимые элементы
    int m_inventory_number_array[] = {1};
    old_str = get_file_value((char *) "Auto.txt", inventory_number, 0, m_inventory_number_array, 1);

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
                car_brand_code = end_str[j];
                break;
            default:break;
        }
    }

    // Справочник марок автомобилей
    // Необходимые элементы
    int m_car_brand_code_array[] = {2};
    old_str = get_file_value((char *) "Brand_directory.txt", car_brand_code, 0, m_car_brand_code_array, 1);

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
        switch (j) {
            case 0:
                freight = atoi(end_str[j]);
                break;
            default:
                break;
        }
    }

    // Расчет
    int result = cargo_weight * distance * freight;
    std::cout << result << std::endl;

    return 0;
}

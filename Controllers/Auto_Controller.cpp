#include "Auto_Controller.h"

using namespace std;

void Auto_Controller() {
    char inventory_number[1024] = "",
            car_brand_code[1024] = "";

    cout << "-------------------Справочник марок авто------------------" << endl;
    cout << "-Код марки авто|Марка авто|Стоимость перевозки одного ткм-" << endl;
    cout << "----------------------------------------------------------" << endl;

    // Получение списка справочника марок авто
    get_content((char *) "Brand_directory.txt");

    // Добавление инвентарного номера
    cout << "Инвентарный номер: ";
    cin >> inventory_number;

    // Добавление кода марки автомобиля
    cout << "Код марки автомобиля: ";
    cin >> car_brand_code;

    // Валидация кода марки автомобиля
    if(!check_file((char *) "Brand_directory.txt", car_brand_code)){
        cout << "ERROR - Введенный код марки авто не существует!" << endl;
    } else {
        // Вызов модели
        #include "../Models/Auto_Model.h"

        int debug = Auto_Model(inventory_number, car_brand_code);

        switch (debug) {
            case 0:
                cout << "Ошибка открытия файла" << endl;
                break;
            default:
                cout << "Данные успешно добавлены" << endl;
        }
    }
}
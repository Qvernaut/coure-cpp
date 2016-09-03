#include "Brand_directory_Controller.h"

using namespace std;

void Brand_directory_Controller() {
    char car_brand[1024] = "",
            freight[1024] = "",
            car_brand_code[1024] = "";

    // Добавление кода марки автомобиля
    cout << "Код марки автомобиля: ";
    cin >> car_brand_code;

    // Добавление Марки автомобиля
    cout << "Марка автомобиля: ";
    cin >> car_brand;

    // Добавление стоимости перевозки
    cout << "Стоимость перевоки одного ткм: ";
    cin >> freight;

    // Вызов модели
    #include "../Models/Brand_directory_Model.h"

    int debug = Brand_directory_Model(car_brand_code, car_brand, freight);

    switch (debug) {
        case 0:
            cout << "Ошибка открытия файла" << endl;
            break;
        default:
            cout << "Данные успешно добавлены" << endl;
    }
}
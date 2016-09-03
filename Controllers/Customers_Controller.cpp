#include "Customers_Controller.h"

using namespace std;

void Customers_Controller() {
    char customer_code[1024] = "",
            customer_name[1024] = "",
            address[1024] = "",
            phone[1024] = "";

    // Добавление кода заказчика
    cout << "Код заказчика: ";
    cin >> customer_code;

    // Добавление наименования заказчика
    cout << "Наименование заказчика: ";
    cin >> customer_name;

    // Добавление адреса
    cout << "Адрес: ";
    cin >> address;

    // Добавление телефона
    cout << "Телефон: ";
    cin >> phone;

    // Вызов модели
    #include "../Models/Customers_Model.h"
    int debug = Customers_Model(customer_code, customer_name, address, phone);

    switch (debug) {
        case 0:
            cout << "Ошибка открытия файла" << endl;
            break;
        default:
            cout << "Данные успешно добавлены" << endl;
    }
}
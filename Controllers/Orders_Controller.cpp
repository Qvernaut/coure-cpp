#include "Orders_Controller.h"

using namespace std;

void Orders_Controller() {
    char order_number[1024] = "",
            order_date[1024] = "",
            customer_code[1024] = "",
            inventory_number[1024] = "",
            cargo_weight[1024] = "",
            distance[1024] = "";

    cout << "---------------------Заказчики----------------------" << endl;
    cout << "-Код заказчика|Наименование заказчика|Адрес|Телефон-" << endl;
    cout << "----------------------------------------------------" << endl;
    get_content((char *) "Customers.txt");

    cout << "---------------Автомобили--------------" << endl;
    cout << "-Инвентарый номер|Код марки автомобиля-" << endl;
    cout << "---------------------------------------" << endl;
    get_content((char *) "Auto.txt");

    // Добавление номера заказа
    cout << "Номер заказа: ";
    cin >> order_number;

    // Добавление даты заказа
    cout << "Дата заказа: ";
    cin >> order_date;

    // Добавление код заказчика
    cout << "Код заказчика: ";
    cin >> customer_code;

    // Добавление инвентарного номера
    cout << "Инвентарный номер: ";
    cin >> inventory_number;

    // Добавление массы груза
    cout << "Масса груза: ";
    cin >> cargo_weight;

    // Добавление расстояния
    cout << "Расстояние: ";
    cin >> distance;

    // Валидация пользователя
    if(!check_file((char *) "Customers.txt", customer_code)){
        cout << "ERROR - Введенный пользователь не существует!" << endl;

     // Валидация инвентарного номера
    }else if(!check_file((char *) "Auto.txt", inventory_number)){
        cout << "ERROR - Введенный инвентарный номер не существует!" << endl;
    }else{
        // Вызов модели
        #include "../Models/Orders_Model.h"
        int debug = Orders_Model(order_number, order_date, customer_code, inventory_number, cargo_weight, distance);

        switch (debug) {
            case 0:
                cout << "Ошибка открытия файла" << endl;
                break;
            default:
                cout << "Данные успешно добавлены" << endl;
        }
    }
}
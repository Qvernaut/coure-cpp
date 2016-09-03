#include "Calculation_Controller.h"

using namespace std;

void Calculation_Controller() {
    char order_number[1024] = "";

    // Номер заказа
    cout << "Номер заказа: ";
    cin >> order_number;

    // Валидация номера заказа
    if(!check_file((char *) "Orders.txt", order_number)){
        cout << "ERROR - Введенного номера заказа не существует!" << endl;
    } else {
        // Вызов модели
        #include "../Models/Calculation_Model.h"
        Calculation_Model(order_number);
    }
}

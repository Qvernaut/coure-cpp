#include "main.h"

using namespace std;

int main() {
    setlocale (LC_ALL, "rus");

    // Вызов меню
    menu();

    return 0;
}

int menu() {
    int selection; // Номер пункта меню

    cout << "___________________________________________" << endl;
    cout << "********|-----------MENU----------|********" << endl;
    cout << "* 1. Добавление                           *" << endl;
    cout << "* 2. Просмотр заказов                     *" << endl;
    cout << "* 3. Расчет                               *" << endl;
    cout << "* 4. Выход                                *" << endl;
    cout << "*******************************************" << endl;
    cout << "Пункт меню: ";
    cin >> selection;

    // Действия пунктов меню
    switch (selection) {

        // Добавление
        case 1:

            // Подпункты
            while(true) {
                cout << "1. Справочник марок" << endl;
                cout << "2. Автомобиль" << endl;
                cout << "3. Заказчики" << endl;
                cout << "4. Заказы" << endl;
                cout << "5. Назад" << endl;
                cout << "6. Выход" << endl;
                cout << "Пункт меню: ";

                cin >> selection;

                switch (selection) {
                    case 1:
                        action((char *) "Brand directory");
                        break;
                    case 2:
                        action((char *) "Auto");
                        break;
                    case 3:
                        action((char *) "Customers");
                        break;
                    case 4:
                        action((char *) "Orders");
                        break;
                    case 5:
                        menu();
                        return 0;
                    case 6:
                        return 0;
                    default:
                        cout << "ERROR - Такого пункта меню не существует" << endl;
                        menu();
                }
            }

        // Просмотор заказов
        case 2:
            cout << "---------------------------------------------------------Заказы--------------------------------------------------------" << endl;
            cout << "-Номер заказа|Дата заказа|Код заказчика|Имя заказчика|Инвентарный номер авто|Марка авто|Масса груза(тн)|Расстояние(км)-" << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
            get_content((char *) "Orders.txt");

            menu();

            break;

        // Расчет
        case 3:
            action("Calculation");
            menu();
            break;
        case 4:
            return 0;
        default:
            cout << "ERROR - Такого пункта меню не существует" << endl;
            menu();
    }

    return 0;
}

/*
 * Перенаправляет на контроллер в соответствии с выбранным действием
 *
 * @param controller_name имя контроллера
 * @return void
 */
void action(const char *const controller_name) {

    if(!strcmp(controller_name, "Brand directory")) {
        #include "Controllers/Brand_directory_Controller.h"
        Brand_directory_Controller();
        while (repeated()) {
            Brand_directory_Controller();
        }
    }
    else if(!strcmp(controller_name, "Auto")){
        #include "Controllers/Auto_Controller.h"
        Auto_Controller();
        while (repeated()) {
            Auto_Controller();
        }
    }
    else if(!strcmp(controller_name, "Customers")){
        #include "Controllers/Customers_Controller.h"
        Customers_Controller();
        while (repeated()) {
            Customers_Controller();
        }
    }
    else if(!strcmp(controller_name, "Orders")){
    #include "Controllers/Orders_Controller.h"
        Orders_Controller();
        while (repeated()) {
            Orders_Controller();
        }
    }
    else if(!strcmp(controller_name, "Calculation")){
    #include "Controllers/Calculation_Controller.h"
        Calculation_Controller();
        while (repeated()) {
            Calculation_Controller();
        }
    }
}

/*
 * Перевызывает контроллер с условием (да/нет)
 *
 * @return int true/false (выбор пользователя)
 */
int repeated() {
    char t_selection[1024] = "";

    cout << "Повторить? (y/n): ";
    cin >> t_selection;
    if(!strcmp(t_selection, "y") or
        !strcmp(t_selection, "Y") or
        !strcmp(t_selection, "yes") or
        !strcmp(t_selection, "YES") or
        !strcmp(t_selection, "д") or
        !strcmp(t_selection, "Д") or
        !strcmp(t_selection, "да") or
        !strcmp(t_selection, "ДА")){
        return 1;
    }
    else{
        return 0;
    }
}
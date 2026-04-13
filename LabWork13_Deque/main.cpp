#include "DequeAndDataStructure.h"
#include "DequeAndDataStructure.h"
#include <iostream>

using namespace std;

int main() {

    setlocale(LC_ALL, "RU");

    Deque myDeque;
    init(&myDeque);

    int choice;
    do {
        cout << "\n========== МЕНЮ УПРАВЛЕНИЯ ДЕКОМ ==========" << endl;
        cout << "1. Добавить в начало (pushFront)" << endl;
        cout << "2. Добавить в конец (pushBack)" << endl;
        cout << "3. Извлечь из начала (popFront)" << endl;
        cout << "4. Извлечь из конца (popBack)" << endl;
        cout << "5. Просмотреть первый элемент (front)" << endl;
        cout << "6. Просмотреть последний элемент (back)" << endl;
        cout << "7. Вывести весь дек (printDeque)" << endl;
        cout << "8. Очистить дек (clear)" << endl;
        cout << "0. Выход" << endl;
        cout << "-------------------------------------------" << endl;

        choice = getValidatedInt("Выберите действие: ", 0, 8);

        switch (choice) {
        case 1:
            pushFront(&myDeque, inputAirport());
            cout << "Рейс успешно добавлен в начало." << endl;
            break;
        case 2:
            pushBack(&myDeque, inputAirport());
            cout << "Рейс успешно добавлен в конец." << endl;
            break;
        case 3:
            if (!isEmpty(&myDeque)) {
                cout << "Извлечен элемент из начала:" << endl;
                printAirport(popFront(&myDeque));
            }
            else cout << "Ошибка: Дек пуст!" << endl;
            break;
        case 4:
            if (!isEmpty(&myDeque)) {
                cout << "Извлечен элемент из конца:" << endl;
                printAirport(popBack(&myDeque));
            }
            else cout << "Ошибка: Дек пуст!" << endl;
            break;
        case 5:
            if (!isEmpty(&myDeque)) {
                cout << "Первый элемент в деке: ";
                printAirport(front(&myDeque));
            }
            else cout << "Дек пуст!" << endl;
            break;
        case 6:
            if (!isEmpty(&myDeque)) {
                cout << "Последний элемент в деке: ";
                printAirport(back(&myDeque));
            }
            else cout << "Дек пуст!" << endl;
            break;
        case 7:
            printDeque(&myDeque);
            break;
        case 8:
            clear(&myDeque);
            break;
        case 0:
            clear(&myDeque); 
            cout << "Программа завершена." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
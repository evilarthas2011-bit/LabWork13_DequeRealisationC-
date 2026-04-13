#include "DequeAndDataStructure.h"

using namespace std;
void init(Deque* d) {
    d->head = d->tail = nullptr;
    d->size = 0;
}

bool isEmpty(const Deque* d) {
    return d->head == nullptr;
}

void pushFront(Deque* d, Airport value) {
    Node* newNode = new Node{ value, d->head, nullptr };
    if (isEmpty(d)) d->tail = newNode;
    else d->head->prev = newNode;
    d->head = newNode;
    d->size++;
}


void pushBack(Deque* d, Airport value) {
    Node* newNode = new Node{ value, nullptr, d->tail };
    if (isEmpty(d)) d->head = newNode;
    else d->tail->next = newNode;
    d->tail = newNode;
    d->size++;
}


Airport popFront(Deque* d) {
    Node* temp = d->head;
    Airport data = temp->data;
    d->head = d->head->next;
    if (d->head) d->head->prev = nullptr;
    else d->tail = nullptr; 
    delete temp;
    d->size--;
    return data;
}


Airport popBack(Deque* d) {
    Node* temp = d->tail;
    Airport data = temp->data;
    d->tail = d->tail->prev;
    if (d->tail) d->tail->next = nullptr;
    else d->head = nullptr;
    delete temp;
    d->size--;
    return data;
}


void clear(Deque* d) {
    if (isEmpty(d)) return;
    cout << "\n--- Последовательная очистка дека ---" << endl;
    while (!isEmpty(d)) {
        Airport a = popFront(d);
        cout << "Удален рейс №" << a.number << " в " << a.destination << endl;
    }
}


void printAirport(const Airport& a) {
    cout << "Рейс №" << a.number << " [" << a.type << "] -> " << a.destination << endl;
}


int getValidatedInt(string prompt, int minVal, int maxVal) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= minVal && value <= maxVal) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cout << "Ошибка! Введите число в диапазоне от " << minVal << " до " << maxVal << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

Airport inputAirport() {
    Airport a;
    a.number = getValidatedInt("Номер рейса (1-9999): ", 1, 9999);

    cout << "Тип рейса: ";
    getline(cin, a.type);
    cout << "Пункт назначения: ";
    getline(cin, a.destination);

    cout << "Ввод даты и времени:" << endl;
    a.timeo.year = getValidatedInt("  Год (2024-2030): ", 2024, 2030);
    a.timeo.month = getValidatedInt("  Месяц (1-12): ", 1, 12);
    a.timeo.day = getValidatedInt("  День (1-31): ", 1, 31);
    a.timeo.hour = getValidatedInt("  Час (0-23): ", 0, 23);
    a.timeo.min = getValidatedInt("  Минута (0-59): ", 0, 59);

    return a;
}

Airport front(const Deque* d) {
    return d->head->data;
}


Airport back(const Deque* d) {
    return d->tail->data;
}

void printDeque(const Deque* d) {
    if (isEmpty(d)) {
        cout << "Дек пуст!" << endl;
        return;
    }
    cout << "\n--- Содержимое дека (всего элементов: " << d->size << ") ---" << endl;
    Node* current = d->head;
    int index = 1;
    while (current != nullptr) {
        cout << index++ << ". ";
        printAirport(current->data);
        current = current->next;
    }
    cout << "------------------------------------------" << endl;
}
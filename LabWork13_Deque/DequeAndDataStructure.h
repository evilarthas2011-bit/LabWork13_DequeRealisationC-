#pragma once

#include <iostream>
#include <string>
#include <limits>

using namespace std;

// 1. Твои структуры данных из ЛР №9
struct Time {
    int year, month, day, hour, min;
};

struct Airport {
    int number;
    string type;
    string destination;
    Time timeo, timei;
};


struct Node {
    Airport data;
    Node* next; // Указатель на следующий элемент
    Node* prev; // Указатель на предыдущий элемент
};


struct Deque {
    Node* head;
    Node* tail;
    int size;
};


void init(Deque* d);
bool isEmpty(const Deque* d);
void pushFront(Deque* d, Airport value);
void pushBack(Deque* d, Airport value);
Airport popFront(Deque* d);
Airport popBack(Deque* d);
Airport front(const Deque* d);
Airport back(const Deque* d);
void clear(Deque* d);
void printDeque(const Deque* d);

int getValidatedInt(string prompt, int minVal, int maxVal);
void printAirport(const Airport& a);
Airport inputAirport();
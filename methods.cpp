#include <iostream>
#include <fstream>
#include "list.h"
#include "methods.h"

using namespace std;

int getVariant(int count) {
    int variant;
    string s; // строка для считывания введённых данных
    cin >> s; // считываем строку
    // пока ввод некорректен, сообщаем об этом и просим повторить его
    while (sscanf(s.c_str(), "%d", &variant) != 1 || variant < 1 || variant > count) {
        cout << "Неправильно введено число. Повторите попытку: "; // выводим сообщение об ошибке
        cin >> s; // считываем строку повторно
    }
    return variant;
}

int getVariant() { 
    string answer; // строка для чтения
    int n; // итоговое целое число

    cin >> answer;
    // пока не будет считано целое число
    while (sscanf(answer.c_str(), "%d", &n) != 1) {
        cout << ("Неправильно введено число. Повторите попытку: "); // выводим сообщение об ошибке
        cin >>answer; // и заново считываем строку
    }

    return n; // возвращаем корректное целое число
}


void printMenu() {
    cout << "Что вы хотите?" << endl;
    cout << "1. Добавить авиабилет в список" << endl;
    cout << "2. Вывести список авиабилетов" << endl;
    cout << "3. Удалить выбранный авиабилет" << endl;
    cout << "4. Поиск" << endl;
    cout << "5. Изменить авиабилет" << endl;
    cout << "6. Выход" << endl;
    cout << ">";
}

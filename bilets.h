#ifndef BILET_H
#define BILET_H
#include <iostream>

using namespace std;
class Bilet {
public:
    Bilet();
    Bilet(int day,string month, int price,  string first_place, string second_place);

    int GetDay();
    string GetMonth();
    int GetPrice();
    string GetFirst();
    string GetSecond();
    Bilet * next();

    void setDay(int day);
    void setMonth(string month);
    void setPrice(int price);
    void setFirst(string first_place);
    void setSecond(string second_place);
    void setNext(Bilet * next);

private:
    int _day;
    string _month; 
    int _price; 
    string _first_place; 
    string _second_place;
    Bilet * _next;
};

#endif // TEST_H

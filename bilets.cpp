#include "bilets.h"

using namespace std;
Bilet::Bilet(){
    int _day = 0;
    string _month = ""; 
    int _price = 0; 
    string _first_place = ""; 
    string _second_place = "";
    Bilet * _next = NULL;
}

Bilet::Bilet(int day,string month, int price, string first_place, string second_place){
        _day = day;
        _month = month;
        _price = price;
        _first_place = first_place;
        _second_place = second_place;
        _next = NULL;
    }

int Bilet::GetDay(){
    return _day;
}

string Bilet::GetMonth(){
    return _month;
}

int Bilet:: GetPrice(){
    return _price;
}
string Bilet:: GetFirst(){
    return _first_place;
}
string Bilet:: GetSecond(){
    return _second_place;
}

Bilet *Bilet::next() {
    return _next;
}


void Bilet::setNext(Bilet *next){
    if(_next != next)
        _next = next;
}
void Bilet:: setDay(int day){
    if(_day != day)
        _day = day;
}

void Bilet:: setMonth(string month){
    if(_month != month) 
        _month = month;
}

void Bilet:: setPrice(int price){
    if(_price != price) 
        _price = price;
}
void Bilet:: setFirst(string first_place){
    if(_first_place != first_place) 
        _first_place = first_place;
}
void Bilet:: setSecond(string second_place){
    if(_second_place != second_place)
        _second_place = second_place;
}
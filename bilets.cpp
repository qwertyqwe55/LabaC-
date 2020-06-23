#include "bilets.h"
#include <fstream>
#include <iostream>

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

void print(Bilet& bilet){
    cout << "День: " << bilet.GetDay() << endl;
	cout << "Месяц: " << bilet.GetMonth() << endl;
    cout << "Цена: " << bilet.GetPrice() << endl;
    cout << "Место отбытия:" << bilet.GetFirst() << endl;
	cout << "Место прибытия: " << bilet.GetSecond() << endl;
}
ostream& operator<< (ostream &out, Bilet &bilet){
	out << "День: " << bilet.GetDay() << endl;
	out << "Месяц: " << bilet.GetMonth() << endl;
    out << "Цена: " << bilet.GetPrice() << endl;
    out << "Место отбытия:" << bilet.GetFirst() << endl;
	out << "Место прибытия: " << bilet.GetSecond() << endl;
	return out;
}
istream& operator>> (istream &in, Bilet &bilet){
	cout << "День: ";
    in >> bilet._day;
	cout << "Месяц: ";
	in >> bilet._month;
	cout << "Цена: ";
    in >> bilet._price;
	cout << "Место отбытия: ";
	in >> bilet._first_place;
	cout << "Место прибытия: ";
	in >> bilet._second_place;

    return in;	
}
ofstream& operator<< (ofstream &fout, Bilet &bilet){
	fout << bilet._day << endl;
	fout << bilet._month << endl;
    fout << bilet._price << endl;
	fout << bilet._first_place << endl;
	fout << bilet._second_place << endl;
    return fout;	
}
ifstream& operator>> (ifstream &fin, Bilet &bilet){
	fin >> bilet._day;
	fin >> bilet._month;
    fin >> bilet._price;
	fin >> bilet._first_place;
	fin >> bilet._second_place;
    return fin;	
}
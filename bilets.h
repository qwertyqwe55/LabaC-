#ifndef BILET_H
#define BILET_H
#include <iostream>
#include <fstream>
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

    friend ostream& operator<< (ostream &out, Bilet &student);
	friend istream& operator>> (istream &in, Bilet &student);
	friend ofstream& operator<< (ofstream &fout, Bilet &student);
	friend ifstream& operator>> (ifstream &fin, Bilet &student);
    void setDay(int day);
    void print();
    void setMonth(string month);
    void setPrice(int price);
    void setFirst(string first_place);
    void setSecond(string second_place);
    void setNext(Bilet * next);


    int _day;
    string _month; 
    int _price; 
    string _first_place; 
    string _second_place;

private:

    Bilet * _next;
};


#endif // TEST_H

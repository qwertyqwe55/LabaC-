#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "bilets.h"
using namespace std;

class List {
public:
    List();
    ~List();
    int size();
    void changed(int n);
    void add(int day,string month, int price, string first_place, string second_place);
    void add(Bilet* temp);
    void remove(int n);
    void print();
		friend ostream& operator<< (ostream &out, List &list);
    friend ofstream& operator<< (ofstream &fout, List &list);
		friend ifstream& operator>> (ifstream &fin, List &list);
    void removeAll();
    void printOne(int n);
    void popHead();
    void File_out_List(string filename);
    void File_in_List(string filename);
    void search(int day,string month, int price, string first_place, string second_place);
  Bilet *head;
private:
   // Bilet *head;
    int _size;
};

#endif // LIST_H

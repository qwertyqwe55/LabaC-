#ifndef LIST_H
#define LIST_H

#include "bilets.h"
using namespace std;

class List {
public:
    List();
    ~List();
    int size();
    void changed(int n);
    void add(int day,string month, int price, string first_place, string second_place);
    void remove(int n);
    void add();
    void removeAll();
    void File_out_List(string filename);
    void File_in_List(string filename);
    void search(int day,string month, int price, string first_place, string second_place);

private:
    Bilet *head;
    int _size;
};

#endif // LIST_H

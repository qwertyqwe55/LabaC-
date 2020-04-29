#include "list.h"
#include <fstream>
#include "methods.h"
using namespace std;

List::List() {
    head = NULL;
    _size = 0;
}

List::~List() {
    while (head != NULL) {
        Bilet *temp = head->next();
        delete head;
        head = temp;
    }
}

int List::size() {
    return _size;
}

// Перегрузка методов вывода и ввода 
void List::add(int day,string month, int price, string first_place, string second_place) {
    Bilet *temp = new Bilet(day, month,  price, first_place, second_place);
    temp->setNext(head);
    head = temp;  
    _size++;
}

void List::add(){
    setlocale(LC_ALL, "rus");
    Bilet *temp = head;
    int i = 1;
    if(temp == NULL){
        cout << "Билетов не найдено";
    }else
    {
    while(temp != 0){
      cout << " Билет№" << i;
      cout << " День вылета: " << temp ->GetDay(); 
      cout << " |Месяц вылета: " + temp -> GetMonth();
      cout << " |Цена: " << temp -> GetPrice(); 
      cout << " |Место отправления: " + temp -> GetFirst();
      cout << " |Место прибытия: " + temp -> GetSecond() << endl;
      temp = temp -> next();
      i++;
    }
    }
}


void List::remove(int n) {
    Bilet *temp = head;
     if (n == 0)
  {
     Bilet* newHead = head->next();
     delete head;
     head = newHead;
     _size--;
     return;
  }else if (head == NULL || n > _size){
        cout << "Неправильно введен номер";
        return;
    }else{
    for (int i = 0; i < n - 1; i++)
         temp = temp->next();

    Bilet * delEl = temp->next();
    temp->setNext(delEl->next());
    _size--;
    delete delEl;
  }
}

void List::removeAll(){
    Bilet *temp = head;
    while(temp->next() != NULL){
        Bilet *del = temp->next();
        temp->setNext(del -> next());
        _size --;
        delete del;
    }
    Bilet* newHead = head->next();
     delete head;
     head = newHead;
     _size--;
}


void List:: File_out_List(string filename){
        ofstream ofs;
        ofs.open(filename);
        Bilet *temp = head;
        while(temp != NULL){
         if(temp->next() == NULL){
            ofs << temp -> GetDay() << endl;
            ofs << temp -> GetMonth() << endl;
            ofs << temp -> GetPrice() << endl;
            ofs << temp -> GetFirst() << endl;
            ofs << temp -> GetSecond();
         }else{
             ofs << temp -> GetDay() << endl;
            ofs << temp -> GetMonth() << endl;
            ofs << temp -> GetPrice() << endl;
            ofs << temp -> GetFirst() << endl;
            ofs << temp -> GetSecond() << endl;
         }
     temp = temp -> next();
        }
        ofs.close();
    }

void List::File_in_List(string filename){
    setlocale(LC_ALL, "rus");
        ifstream ifs(filename);
       if(ifs.fail()){
            cout <<"Файл не обнаружен. Будет создан файл с указанным именем";
            ofstream ofs;
            ofs.open(filename);
            ofs.close();
            ifs.close();
  	  }else{
        ifs.close();
        ifs.open(filename);
        while(!ifs.eof()){
         int day;
	     string month;
	     int price;
         string first_place;
         string second_place;
    
            ifs >> day;
            ifs >> month;
            ifs >> price;
            ifs >> first_place;
            ifs >> second_place;
         if(day > 0 && day <= 31){ 
        Bilet *temp = new Bilet(day, month,  price, first_place, second_place);
         temp->setNext(head);
         head = temp;
         _size++;
         }
        }
        ifs.close();
    }
}

void List::search(int day,string month, int price, string first_place, string second_place){
        setlocale(LC_ALL, "rus");
        Bilet *temp = head;
        int i = 1;
        int prov = 0;
        while(temp != NULL){
              int day1 = temp ->GetDay();
              string month1 = temp -> GetMonth();
	          int price1 = temp -> GetPrice();
              string first_place1 = temp -> GetFirst();
              string second_place1 = temp ->GetSecond();
            if(day == day1 || month == month1 || price == price1 || first_place == first_place1|| second_place == second_place1){
                cout << " Билет№" << i;
                cout << " День вылета: " << day1; 
                cout << " |Месяц вылета: " + month1;
                cout << " |Цена: " << price1; 
                cout << " |Место отправления: " + first_place1;
                cout << " |Место прибытия: " + second_place1 << endl;
                prov = 1;
            } 
            temp = temp -> next();
            i++;
        }
         if(prov == 0)
             cout << "Билетов не найдено" << endl;
    }

    // Метод для изменения билета
    void List::changed(int n){
        Bilet *temp = head;
        int day;
        string month;
        int price;
        string first_place;
        string second_place;
        for (int i = 0; i < n ; i++)
            temp = temp->next();
		    cout << "Введите новый день вылета: ";
		    day = getVariant(31);
		    cout << "Введите новый месяц вылета: ";
		    cin >> month; 
    		cout << "Введите новую цену билета: ";
    		price = getVariant();
    		cout << "Введите новое место отправления: ";
    		cin >> first_place;
    		cout << "Введите новое место прибытия: ";
    		cin >> second_place;
        temp -> setDay(day);
        temp -> setMonth(month);
        temp -> setPrice(price);
        temp -> setFirst(first_place);
        temp -> setSecond(second_place);
        }    
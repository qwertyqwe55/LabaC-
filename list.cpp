#include "list.h"
#include <fstream>
#include "methods.h"
#include "bilets.h"
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
    

void List::add(int day,string month, int price, string first_place, string second_place) {
    Bilet *temp = new Bilet(day, month,  price, first_place, second_place);
    temp->setNext(head);
    head = temp;  
    _size++;
}

void List::print(){
    setlocale(LC_ALL, "rus");
    Bilet *temp = head;
    int i = 1;
    if(temp == NULL){
        cout << "Билетов не найдено";
    }else
    { 
    while(temp != 0){
      cout << temp;  
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
void List::printOne(int n) {
    Bilet *temp = head;
     if (n == 0)
  {
    cout << "День: " << temp -> GetDay() << endl;
	cout << "Месяц: " << temp -> GetMonth() << endl;
    cout << "Цена: " << temp -> GetPrice() << endl;
    cout << "Место отбытия:" << temp -> GetFirst() << endl;
	cout << "Место прибытия: " << temp -> GetSecond() << endl;
    }else{
    for (int i = 0; i < n - 1; i++)
         temp = temp->next();

    Bilet * bilet = temp->next();
    cout << "День: " << bilet ->GetDay() << endl;
	cout << "Месяц: " << bilet ->GetMonth() << endl;
    cout << "Цена: " << bilet->GetPrice() << endl;
    cout << "Место отбытия:" << bilet->GetFirst() << endl;
	cout << "Место прибытия: " << bilet->GetSecond() << endl;
    
  }
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
		    cin >> day;
		    cout << "Введите новый месяц вылета: ";
		    cin >> month; 
    		cout << "Введите новую цену билета: ";
    		cin >> price;
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

 void List::popHead(){
	Bilet* temp = head->next();
	delete head;
	head = temp;
	_size--;
}
void List::add(Bilet* temp){
	temp->setNext(head);
	head = temp;
	_size++;
}
 
ostream& operator<< (ostream &out, List &list){
	Bilet* temp = list.head;
    if(list.size() == 0){
            cout << "Билетов не найдено"<<endl;
    }else{
	for(int i = 0; i < list.size(); i++){
		out << "Номер авиабилета: " << i+1 << endl;
		out << *temp;
		out << endl;
		temp = temp->next();
	}
    }
	return out;
}
ofstream& operator<< (ofstream &fout, List &list){
	Bilet* temp = list.head;
	while(temp != NULL){
		fout << *temp;
		temp = temp->next();
    }
	return fout;
}
ifstream& operator>> (ifstream &fin, List &list){
	
	do{
		Bilet* temp = new Bilet;
		fin >> *temp;
		list.add(temp);

	} while(!fin.eof());
	list.popHead();
	return fin;
}
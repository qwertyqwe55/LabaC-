#include <iostream>
#include "methods.h"
#include "list.h"
#include "search.h"

void search(List list){
        int day1;
	    string month1;
	    int price1;
        string first_place1;
        string second_place1;
    	cout << "1.Поиск по дню" << endl;
		cout << "2.Поиск по месяцу" << endl;
		cout << "3.Поиск по цене" << endl;
		cout << "4.Поиск по месту отправления" << endl;
		cout << "5.Поиск по месту прибытия" << endl;
		cout << ">";
		int varik = getVariant(5);
		switch(varik){
		case 1:
			cout << "Введите день: ";
			cin >> day1;
			list.search(day1,"",0,"","");
			break;
		case 2:
			cout << "Введите месяц: ";
			cin >> month1;
			list.search(0,month1,0,"","");
			break;
		case 3:
			cout << "Введите цену: ";
			cin >> price1;
			list.search(0,"",price1,"","");
			break;
		case 4:
			cout << "Введте место отправления: ";
			cin >> first_place1;
			list.search(0,"",0,first_place1,"");
			break;
		case 5:
			cout << "Введите место прибытия: ";
			cin >> second_place1;
			list.search(0,"",0,"",second_place1);
			break;
    }
}
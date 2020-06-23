#include <iostream>
#include <fstream>
#include "list.h"
#include "methods.h"
#include "search.h"
#include "bilets.h"

using namespace std;
void removeAll(List list){
	for(int i = 0; i < list.size(); i++){
			list.remove(i);
		}
}


int main(int arg, char **args) {
    setlocale(LC_ALL, "rus");
    int variant; // выбранный пункт меню
    int size = 0; // количество элементов массива
    ofstream ofs;
    int proverka = 1;
    if (arg > 2 ) {
		cout << "Аргументы не введены" << endl;
		return 1;
	}
	
    string filename = args[1];
    
    List list;

	ifstream ifs(filename);
    if(ifs.fail()){
            cout <<"Файл не обнаружен. Будет создан файл с указанным именем";
            ofstream ofs;
            ofs.open(filename);
            ofs.close();
			ifs.close();
	}else{
    	ifs >> list;
		ifs.close();
	}
	Bilet* temp;
	do {
        printMenu();
		
		variant = getVariant(7);

        switch (variant) {
            case 1:
			temp = new Bilet;
			cin >> *temp;
			list.add(temp);
			break;
        	case 2:
        	 cout << list;
            break;
            case 3:
        cout << "Введите номер элемента, который хотите удалить"<<endl;
        int n;
        cin >> n;
        list.remove(n-1);
                break;
        case 5:
            cout << "Введите номер элемента, который хотите изменить"<<endl;
            int a;
            cin >> a;
            list.changed(a-1);
		break;
		case 6:
			int num;
			cout << " Введите номер авиабилета, который хотите вывести" << endl;
			cin >> num;
			list.printOne(num-1);
			break;
	    case 4:
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
        break;
		}
     } while (variant != 7);

	ofstream ofss;
	ofss.open(filename);

    ofss << list;
	ofss.close();

    return 0;
}
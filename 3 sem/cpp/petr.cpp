#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>

//#include <windows.h>

using namespace std;

struct flight{
	int flightNumber;
	char planeType;
	int departureTimeHour;
	int departureTimeMinute;
	int arrivalTimeHour;
	int arrivalTimeMinute;
};

class schedule{
public:
	void control(){
		bool off = false;
		int set;
		while(!off){
			cout << "\nВыберите вариант действия:\n";
			cout << "\t1) Добавить значение\n\t2) Удалить значение\n\t3) Отсортировать значения\n";
			cout << "\t4) Показать все записи в расписании\n\t5) Добавить 20 случайных значений\n\t6) Выйти из программы\n\t7) Рассчет времени\n";
			cout << "Введите выбранный номер: ";
			cin >> set;
			switch(set){
				case 1: addValue(); break;
				case 2: removeValue(); break;
				case 3: sortValues(); break;
				case 4: showAll(); break;
				case 5: addRandValue(); break;
				case 6: off = true; break;
				case 7: testTime(); break;
				default: cout << "\nВведен неверный номер, повторите ввод\n"; break;
			}
		}
	}
private:
	vector<flight>::iterator it;
	vector<flight> listOfFlights;

	void addValue(){
		flight *mem = new flight;
		cout << "Введите номер нового рейса(число):";
		cin >> mem->flightNumber;
		
		do{
			cout << "Введите тип самолета(P - пассажирский/G - грузовой):";
			cin >> mem->planeType;
			if(mem->planeType != 'G' && mem->planeType != 'P') cout << "\nНеобходимо ввести P или G\n\n";
		}while(mem->planeType != 'G' && mem->planeType != 'P');

		do{
			cout << "Введите час отбытия:";
			cin >> mem->departureTimeHour;
			if(mem->departureTimeHour < 0 || mem->departureTimeHour > 24) cout << "Значение часа отбытия может быть от 0 до 24\n";
		}while(mem->departureTimeHour < 0 || mem->departureTimeHour > 24);

		do{
		cout << "Введите минуту отбытия:";
		cin >> mem->departureTimeMinute;
		if(mem->departureTimeMinute < 0 || mem->departureTimeMinute > 60) cout << "Значение минуты отбытия может быть от 0 до 60\n";
		}while(mem->departureTimeMinute < 0 || mem->departureTimeMinute > 60);
		
		do{
		cout << "Введите час прибытия:";
		cin >> mem->arrivalTimeHour;
		if(mem->arrivalTimeHour < 0 || mem->arrivalTimeHour > 24) cout << "Значение часа прибытия может быть от 0 до 24\n";
		}while(mem->arrivalTimeHour < 0 || mem->arrivalTimeHour > 24);
		
		do{
		cout << "Введите минуту прибытия:";
		cin >> mem->arrivalTimeMinute;
		if(mem->arrivalTimeMinute < 0 || mem->arrivalTimeMinute > 60) cout << "Значение минуты прибытия может быть от 0 до 60\n";
		}while(mem->arrivalTimeMinute < 0 || mem->arrivalTimeMinute > 60);
		
		listOfFlights.push_back(*mem);
		delete mem;
	}

	void removeValue(){
		int mem, count = 0, value;
		flight *check = new flight[listOfFlights.size()];
		cout << "Введите номер рейса:";
		cin >> mem;
		for (it = listOfFlights.begin(); it < listOfFlights.end(); it++){
			if (it->flightNumber == mem) check[count++] = *it;
		}
		if (count == 0) cout << "\nСовпадений не найдено\n";
		if (count == 1){
			for (it = listOfFlights.begin(); it < listOfFlights.end(); it++){
				if (it->flightNumber == mem){
					listOfFlights.erase(it);
					break;
				}
			}
		}
		if (count > 1){ 
			for (int i = 0; i < count; i++){
				cout << i << ")\t" << check[i].flightNumber << " - " << check[i].planeType << " - " << check[i].departureTimeHour << ":" << check[i].departureTimeMinute 
				<< " - " << check[i].arrivalTimeHour << ":" << check[i].arrivalTimeMinute << "\n";
			}
			cout << "Укажите, какой именно рейс вы хотите удалить?(введите номер слева):";
			cin >> value;
			if(value<0 || value >= count) cout << "\nНеправильно указан номер\n";
			else {
				for (it = listOfFlights.begin(); it < listOfFlights.end(); it++){
					if (it->flightNumber == mem){
						if (value == 0) {
							listOfFlights.erase(it);
							break;
						}
						else value--;
					} 
				}
			}
		}
	}

	void sortValues(){
		ifstream input;
		ofstream output;
		int count = 0, countNow = 0, countOut;
		string filePath;
		char countStr[10], countStr2[10];
		flight mem;
		vector<flight> comp1, comp2;
		vector<flight>::iterator it;
		for (it = listOfFlights.begin(); it < listOfFlights.end(); it++){
			sprintf(countStr, "%d", count);
			string str(countStr);
			filePath = str + ".txt";
			output.open(filePath.c_str());
			output << it->flightNumber << " " << it->planeType << " " << it->departureTimeHour << " " << it->departureTimeMinute 
				<< " " << it->arrivalTimeHour << " " << it->arrivalTimeMinute << "\n";
			output.close();
			count++;
		}


		while(count > 1){
			countOut = 0;
			countNow = 0;
			for (int i = 0; i < count; ){



//Sleep(500);



				comp1.clear();
				comp2.clear();
				sprintf(countStr2, "%d", i);
				string str(countStr2);
				filePath = str + ".txt";
				input.open(filePath.c_str());
				while(input.good()){
					input >> mem.flightNumber >> mem.planeType >> mem.departureTimeHour >> mem.departureTimeMinute >> mem.arrivalTimeHour >> mem.arrivalTimeMinute;
					comp1.push_back(mem);
				}
				input.close();
				remove(filePath.c_str());
				comp1.pop_back();
				i++;
				sprintf(countStr2, "%d", i);
				string str2(countStr2);
				filePath = str2 + ".txt";
				input.open(filePath.c_str());


				if(input.is_open()){
					while(input.good()){
						input >> mem.flightNumber >> mem.planeType >> mem.departureTimeHour >> mem.departureTimeMinute >> mem.arrivalTimeHour >> mem.arrivalTimeMinute;
						comp2.push_back(mem);
					}
					input.close();
					remove(filePath.c_str());
					comp2.pop_back();
					i++;
					merge(comp1, comp2, countOut++);
				}


				else{
					sprintf(countStr2, "%d", countOut++);
					string str3(countStr2);
					filePath = str3 + ".txt";
					output.open(filePath.c_str());
					for(it = comp1.begin(); it < comp1.end(); it++){
						output << it->flightNumber << " " << it->planeType << " " << it->departureTimeHour << " " << it->departureTimeMinute 
				<< " " << it->arrivalTimeHour << " " << it->arrivalTimeMinute << "\n";
					}
					output.close();
				}
				countNow++;
			}
			count = countNow;
		}

//end of while
		input.open("0.txt");
		listOfFlights.clear();
		while(input.good()){
			input >> mem.flightNumber >> mem.planeType >> mem.departureTimeHour >> mem.departureTimeMinute >> mem.arrivalTimeHour >> mem.arrivalTimeMinute;
			listOfFlights.push_back(mem);
		}
		input.close();
		remove("0.txt");
		listOfFlights.pop_back();
	}

	void merge(vector<flight> a, vector<flight> b, int count){
		vector<flight>::iterator m1, m2;
		m1 = a.begin();
		m2 = b.begin();
		vector<flight> res;
		int countA = a.size(), countB = b.size();

		while (true){
			if(countA == 0 && countB == 0) break;
			else {
				if (countA == 0){
					res.push_back(*m2);
					m2++;
					countB--;
				}
				else if(countB == 0){
					res.push_back(*m1);
					m1++;
					countA--;
				}
				else{
					if (m1->flightNumber < m2->flightNumber){
						res.push_back(*m1);
						m1++;
						countA--;
					}
					else{
						res.push_back(*m2);
						m2++;
						countB--;
					}
				}
			}
		}

		ofstream of;
		char countStr[10];
		sprintf(countStr, "%d", count);
		string str(countStr);
		string filePath = str + ".txt";
		of.open(filePath.c_str());
		for (m1 = res.begin(); m1 < res.end(); m1++)
		{
			of << m1->flightNumber << " " << m1->planeType << " " << m1->departureTimeHour << " " << m1->departureTimeMinute 
				<< " " << m1->arrivalTimeHour << " " << m1->arrivalTimeMinute << "\n";
		}
		of.close();
	}

	void showAll(){
		cout << "\nНомер рейса - Тип самолета - Время отбытия - Время прибытия\n-----------------------------------------------------------\n";
		for(it = listOfFlights.begin(); it < listOfFlights.end(); it++) {
			cout << it->flightNumber << " - " << it->planeType << " - " << it->departureTimeHour << ":" << it->departureTimeMinute 
				<< " - " << it->arrivalTimeHour << ":" << it->arrivalTimeMinute << "\n";
		}
	}

	void addRandValue(){
		flight mem;
		for(int i = 0; i < 20; i++){
			long long x;
			asm("rdtsc" : "=A"(x));
			srand(x);
			mem.flightNumber = rand()%100;
			if(rand()%2 == 1) mem.planeType = 'G';
			else mem.planeType = 'P';
			mem.departureTimeHour = rand()%24;
			mem.departureTimeMinute = rand()%60;
			mem.arrivalTimeHour = rand()%24;
			mem.arrivalTimeMinute = rand()%60;
			listOfFlights.push_back(mem);
		}
	}

	void testTime(){
		unsigned long long time1;
		unsigned long long time2;
		asm("rdtsc" : "=A"(time1));
		sortValues();
		asm("rdtsc" : "=A"(time2));
		cout << "\nВремя сортировки: " << time2-time1 << " тактов процессора\n";
	}
};

int main(int argc, char const *argv[]){
	schedule ex;
	ex.control();
	return 0;
}
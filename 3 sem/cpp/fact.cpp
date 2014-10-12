#include <iostream>
#include <cstdlib>
using namespace std;

struct test {
	int digit;
	int module;
};

class fact{
public:
	void start(int size){
		for(int i = 1; i < 3000; ++i){
			hello[i].digit = -1;
			hello[i].module = 0;
		}
		hello[0].digit = 1;
		hello[0].module = 0;
		answer(size);
		printFact();
	}
	void answer(int size){
		int count, countMod;
		for(int i = 2; i < size+1; ++i){
			count = 0;
			for (int j = 0; hello[j].digit != -1; j++){
				hello[j].digit *= i;
				hello[j].module = hello[j].digit / 10;
				hello[j].digit %= 10;
				count = j;
			}

			for (int k = 0; k < count+1; ++k){
				countMod = k+1;
				while (hello[k].module != 0){
					if (hello[k].digit > 9){
						hello[k].module += hello[k].digit / 10;
						hello[k].digit %= 10;
					}
					if (hello[countMod].digit == -1) hello[countMod].digit++;
					hello[countMod].digit += hello[k].module % 10;
					hello[k].module /= 10;
					countMod++;
				}
			}
		}
	}
	void printFact(){
		int countPr;
		for (int i = 0; hello[i].digit != -1; ++i) countPr = i;
		for (countPr; countPr >= 0; --countPr) cout << hello[countPr].digit;
	}
protected:
	test hello[3000];
};

int main(int argc, char const *argv[])
{
	fact Fact;
	Fact.start(atoi(argv[1]));
	return 0;
}
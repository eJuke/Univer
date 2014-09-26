#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

struct hello{
	int digit;
	int module;
};

class fact{
public:
	void start(){
		cout << "Enter the number that u want to fact: ";
		cin >> size;
		answer();
	}
private:
	vector <hello> result;
	hello pp;
	pp.digit = 1;
	pp.module = 0;
	int size;
	result.push_back(pp);
	void answer(){
		for (int now = 2; now < size + 1; ++now){

		}
	}
};

int main(int argc, char const *argv[])
{
	fact Fact;
	Fact.start();
	return 0;
}
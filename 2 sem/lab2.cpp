#include <iostream>
using namespace std;
//-<answer's_function>--------------------------
bool CommCompare(char answer[]){
	int n=0;
	for (int i=0; answer[i]!='\0'; i++) n=i;
	if (answer[0]=='{' && answer[n]=='}') return true;
	if ((answer[0]=='(' && answer[1]=='*') && (answer[n-1]=='*' && answer[n]==')')) return true;
	else return false;
}
//-<test_driver>--------------------------------
int main(int argc, char* argv[]){
	int set=1, size=0;
	bool flag = true;
	char* driver = new char[128];
	char* testMass;
	cout << "This program checks whether the input strings is a comment in Turbo Pascal 7.0\n";
	do{
		for (int i=0; i<128; i++) driver[i]='\0';
		if (set==1){
			cout << "Enter the string:";
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cin.getline(driver,128);
			for (int i=0; driver[i]!='\0'; i++)	size=i+1;		
			testMass = new char[size];
			for(int i=0; i<size+1; i++) testMass[i]=driver[i];		
			if(CommCompare(testMass)) cout << "It's a comment on Turbo Pascal 7.0\n";
			else cout << "Nope. It's not a comment!\n";
			delete testMass;
		}
		else cout << "Repeat please\n";
		cout << "Continue testing? (1 - yes, 2 - no):";
		cin >> set;
		if (set==2) flag = false;	
	}while(flag);
}
#include <iostream>
using namespace std;
struct for_lab
{
    char inp_string[256];
    char end_symbol;
    int res[129];
    int answer() {
        int count=0, iter=1;
        for (int i=0; i<129; i++) res[i]=0;
        for(int i=0; inp_string[i]!=end_symbol; i++){
            if (inp_string[i]=='.') {res[0]++; iter++;}
            else res[iter]++;
            count=i;
        }
        for(int i=iter+1;i<129; i++) res[i]=-1;
        if (inp_string[count]!='.') res[0]++;
    }
};
int main(){
    while(true){
        char set;
        cout << "Begin the test? (y - for YES/n - for NO):";
        cin.get(set);
        if (set=='N' || set=='n') break;
        for_lab test;
        cout << "Enter the character of string end:";
        cin >> test.end_symbol;
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cin.sync();
        cout << "Enter the string:\n";
        cin.getline(test.inp_string, 256);
        test.answer();
        cout << "The number of sentences:" << test.res[0];
        cout << "\nNumber of symbols in sentences:\n";
        for(int i=1; test.res[i]!=-1; i++) cout << test.res[i] << '\n';
    }
}

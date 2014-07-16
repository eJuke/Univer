#include <iostream>

struct for_lab
{
    int lenght;
    char inp_string[256];
    int result[2];
    void answer() {
        result[0]=0, result[1]=0;
        for (int i=0; i<lenght; i++){
            if (inp_string[i]==inp_string[i+1]){
                for (int j=i+2; j<lenght; j++){
                    if (inp_string[i]==inp_string[j])
                        if (inp_string[j]==inp_string[j+1]){
                            result[0]=i+1;
                            result[1]=j+1;
                        }
                }
            }
        }
    }
};

int main(){
    while(true){
        char set;
        std::cout << "Begin the test? (N/n - for NO; Other symbols - for YES):";
            std::cin.clear();
            std::cin.ignore(std::cin.rdbuf()->in_avail());
            std::cin.sync();
        std::cin.get(set);
        if (set=='N' || set=='n') break;
        for_lab test;
        std::cout << "Enter the string lenght:";
        std::cin >> test.lenght;
            std::cin.clear();
            std::cin.ignore(std::cin.rdbuf()->in_avail());
            std::cin.sync();
        std::cout << "Enter the string:\n";
        std::cin.getline(test.inp_string, test.lenght);
        test.answer();
        std::cout << "Answer:\n";
        if (test.result[0]==test.result[1] && test.result[1]==0) std::cout << "I can't find those numbers\n";
        else   std::cout << "I=" << test.result[0] << "J=" << test.result[1] <<"\n";
    }
}
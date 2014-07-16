#include <iostream>
#include <string>
using namespace std;

//-<�������_��������>-----------------------
struct schedule 
{
string destination;
int t_number;
string time;
};

//-<�஢�ઠ_�ࠢ��쭮��_����������_�६���>---
bool TimeCheck(string train_c){
	int e = atoi(train_c.c_str());
	if (e>24) return false;
	train_c = train_c.substr(3, 2);
	e=atoi(train_c.c_str());
	if (e>60) return false;
	else return true;}
//-<����_�-��_�������>--------------------------
int GetTrainCount(){
	int t_count; 
	cout << "������ �-�� �������:";
	cin >> t_count;
	return t_count;}
//-<ᬥ��_���祭��(���_���஢��)>-------------
void StringSwap(string &t1, string &t2){
	string buffer = t1;
	t1 = t2;
	t2 = buffer;
}
void IntSwap(int &t1, int &t2){
	int buffer = t1;
	t1 = t2;
	t2 = buffer;
}
//-<���஢��>---------------------------------
void TrainSort(schedule *trainInfo, int trainCount){
	for(int f=0; f<trainCount-1; f++){
		if(stricmp(trainInfo[f].time.c_str(), trainInfo[f+1].time.c_str())>0) {
			{	StringSwap(trainInfo[f].time, trainInfo[f+1].time);
				StringSwap(trainInfo[f].destination, trainInfo[f+1].destination);
				IntSwap(trainInfo[f].t_number, trainInfo[f+1].t_number);}
			if(f!=0) f=f-2;}
	}
}
//-<����>---------------------------------------
void TrainFill(schedule *trainInfo , int trainCount){
	cout << "\n������ �६� ��ࠢ�����: \n";
	for (int i=0; i<trainCount; i++){
		cin >> trainInfo[i].time;
		if(!TimeCheck(trainInfo[i].time)){cout << "������ ����: \n"; i--;}}
	cout << "\n������ ᮮ⢥�����騥 �㭪�� �����祭�� � ����� �������: \n";
	for (int i=0; i<trainCount; i++){
		cout << trainInfo[i].time << "   ";
		cin >> trainInfo[i].destination >> trainInfo[i].t_number;}
}
//-<�뢮�>--------------------------------------
void TrainOut(schedule *trainInfo, int trainCount){
	cout << endl << "-�����஢���� ᯨ᮪--------------------------------------" << endl;
	for (int i=0; i<trainCount; i++){
		cout << trainInfo[i].t_number << "\t" << trainInfo[i].destination << "\t" << trainInfo[i].time << endl;}
}
//-<����>--------------------------------------
void TrainSearch(schedule *trainInfo, int trainCount){
	cout << "\n���� ������� �� ����� �����祭��. ������ ��த:\t";
	string x;
	cin >> x;
	bool searchFlag = false;
	cout << "-<�������� ���᪠>-----------------------------------\n";
	for(int i=0; i<trainCount; i++){
		if (stricmp(x.c_str(), trainInfo[i].destination.c_str())==0){	
			searchFlag = true;
			cout << trainInfo[i].t_number << "\t" << trainInfo[i].destination << "\t" << trainInfo[i].time << endl;}
	}
	if (!searchFlag) cout << "������� ���!";
}

int main(){
	const int trainCount=GetTrainCount();
	schedule trainInfo[trainCount];
	TrainFill(trainInfo, trainCount);
	TrainSort(trainInfo, trainCount);
	TrainOut(trainInfo, trainCount);
	TrainSearch(trainInfo, trainCount);
}
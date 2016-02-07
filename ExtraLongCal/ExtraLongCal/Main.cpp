#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector> //���I�z��
#include <sstream>

using namespace std;

//-----Declare Prototype-----
void initialize();
int input();
void displayprep();
void show();
void add();
string padding();
bool IsInteger(const string& str);

//-----Declare Global Constants-----
#define MAXDIGIT 30 //�ő�\����

//-----Declare Global Variables-----
string sInput = "";
string sOutput = "";
string sAnswer = "";
vector<string> elements;
int maxdnow = ""; //���݂܂ł̍ő�����

void initialize() {
	system("cls"); //Console Clear
	cout << "Extra Long Calculator" << endl;
	cout << "<<COPYRIGHT HERE>>" << endl;



}

int main() {
	initialize();
	input();
	cout << sInput << endl;
	input();

	return 0;
}

//user-made functions
int input() {
	for (;;) {
		cout << "�����������l����͂��Ă�������" << endl;
		cin >> sInput; //Input

		//Validation
		////# of Digits check
		if (sInput.size() > 70) {
			cout << "�������傫�����܂��i�ő包��:" << MAXDIGIT << ")" << endl;
			continue;
		}
		////All digits int check
		if (IsInteger(sInput) == false) {
			cout << "�����݂̂���͂��Ă�������" << endl;
			continue;
		}
		elements.push_back(sInput);
		displayprep();

	}
}

void displayprep () {
	
}


/*!
* �����񂪐����l��\���Ă��邩�𒲂ׂ�
* @param[inout] str ������
* @return �����l�Ȃ�true
*/
inline bool IsInteger(const string& str) {
	if (str.find_first_not_of("0123456789 \t") != string::npos) {
		return false;
	}

	return true;
}
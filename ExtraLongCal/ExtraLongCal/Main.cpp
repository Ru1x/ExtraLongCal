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
string padding(int length, string sContent);
bool IsInteger(const string& str);

//-----Declare Global Constants-----
#define MAXDIGIT 30 //�ő�\����

//-----Declare Global Variables-----
string sInput = "";
string sOutput = "";
string sAnswer = "";
vector<string> elements;
int maxd = 0; //���݂܂ł̍ő�����

void initialize() {
	system("cls"); //Console Clear
	cout << "Extra Long Calculator" << endl;
	cout << "<<COPYRIGHT HERE>>" << endl;



}

int main() {
	initialize();
	input();

	return 0;
}

//user-made functions
int input() {
	for (;;) {
		cout << "�����������l����͂��Ă�������" << endl;
		cin >> sInput; //Input

		//Validation
		////Empty Validation
		if (sInput == "") {
			cout << "�������l����͂��Ă�������" << endl;
			continue;
		}
		////# of Digits check
		if (sInput.size() > MAXDIGIT) {
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
		break;
	}
	return 0;
}

void displayprep () {
	if (sInput.length() > maxd) {
		maxd = sInput.length();
	} 
	for (int i = 0; i < elements.size(); ++i) {
		padding(maxd, elements[i]);
	}
}

void add() {
	
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

/*!
* �����������v�ł���悤�ɐ擪�ɔ��p�X�y�[�X��ǉ�����
* @param[inout] str ������ sContent
*               int ������ length
* @return str ������
*/
string padding(int length, string sContent) {

	stringstream output;
	for (int i = 0; i < length - sContent.length(); i++) {
		output << " ";
	}

	output << sContent;

	return output.str();
}
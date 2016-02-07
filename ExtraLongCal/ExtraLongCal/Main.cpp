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
void display();
void add();
string padding(int length, string sContent);
bool IsInteger(const string& str);

//-----Declare Global Constants-----
#define MAXDIGIT 30 //�ő�\����
#define CHARNUM 48 // �����R�[�h�ϊ��p

//-----Declare Global Variables-----
string sInput = "";
string sOutput = "";
string sAnswer = "";
vector<string> elements;
int iMaxd = 0; //���݂܂ł̍ő�����
int iCount = 0; //����

void initialize() {
	system("cls"); //Console Clear
	cout << "Extra Long Calculator" << endl;
	cout << "<<COPYRIGHT HERE>>" << endl;



}

int main() {
	initialize();
	input();
	add();
	input();
	add();
	display();
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
	if (sInput.length() > iMaxd) {
		iMaxd = sInput.length();
	} 
	for (int i = 0; i < elements.size(); ++i) {
		padding(iMaxd, elements[i]);
	}
}

void add() {
	if (iCount == 0) { iCount++; sAnswer = sInput; return; }
	string sNewAnswer = "";
	int iCountUp = 0;
	int iDifference = 0;
	int iBuffer = 0;
	if (sInput.length() > sAnswer.length()) { //���݂܂ł̍��v���A�����͂����l�̂ق����傫����
		iDifference = sInput.length() - sAnswer.length();
		for (int i = sAnswer.length()-1; i >= 0;i--) {
			iBuffer = int(sAnswer[i])-CHARNUM + int(sInput[i + iDifference])-CHARNUM + iCountUp;
			cout << int(sAnswer[1]) << endl;
			cout << int(sInput[1 + iDifference]) << endl;
			iCountUp = 0;
			if (iBuffer >= 10) {
				iCountUp = 1;
				iBuffer = iBuffer - 10;
			}
			sNewAnswer = to_string(iBuffer) + sNewAnswer;
		}
		sNewAnswer = to_string(stoi(sInput.substr(0, iDifference)) + iCountUp) + sNewAnswer;
		sAnswer = sNewAnswer;
		iCount++;
		//TODO sNewAnswer�K�v�Ȃ�����
	}
}

void display() {
	system("cls");
	for (int i = 0; i < elements.size(); ++i) {
		cout << elements[i] << endl;
	}
	cout << sAnswer << endl;
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
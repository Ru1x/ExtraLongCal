#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;

//Prototype Declaration
void initialize();
int input();
void showprep();
void show();
void add();
string padding();
bool IsInteger(const string& str);

//-----Declare Global Variables-----
string sInput = "";
string sOutput = "";

void initialize() {
	system("cls"); //Console Clear
	cout << "Extra Long Calculator" << endl;
	cout << "<<COPYRIGHT HERE>>" << endl;



}

int main() {
	initialize();
	cout << "" << endl;
	input();

	return 0;
}

//user-made functions
int input() {
	cout << "�����������l����͂��Ă�������" << endl;
	cin >> sInput; //Input

				   ////Validation
				   //Int Check �����m�F
	if (IsInteger(sInput) == true) {}
	//Digit Check �����m�F


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
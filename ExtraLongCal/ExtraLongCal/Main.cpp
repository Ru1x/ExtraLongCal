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
	cout << "足したい数値を入力してください" << endl;
	cin >> sInput; //Input

				   ////Validation
				   //Int Check 整数確認
	if (IsInteger(sInput) == true) {}
	//Digit Check 桁数確認


}


/*!
* 文字列が整数値を表しているかを調べる
* @param[inout] str 文字列
* @return 整数値ならtrue
*/
inline bool IsInteger(const string& str) {
	if (str.find_first_not_of("0123456789 \t") != string::npos) {
		return false;
	}

	return true;
}
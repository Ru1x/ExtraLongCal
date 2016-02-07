#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector> //動的配列
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
#define MAXDIGIT 30 //最大可能桁数

//-----Declare Global Variables-----
string sInput = "";
string sOutput = "";
string sAnswer = "";
vector<string> elements;
int maxd = 0; //現在までの最多桁数

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
		cout << "足したい数値を入力してください" << endl;
		cin >> sInput; //Input

		//Validation
		////Empty Validation
		if (sInput == "") {
			cout << "何か数値を入力してください" << endl;
			continue;
		}
		////# of Digits check
		if (sInput.size() > MAXDIGIT) {
			cout << "桁数が大きすぎます（最大桁数:" << MAXDIGIT << ")" << endl;
			continue;
		}
		////All digits int check
		if (IsInteger(sInput) == false) {
			cout << "整数のみを入力してください" << endl;
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

/*!
* 文字数を合致できるように先頭に半角スペースを追加する
* @param[inout] str 文字列 sContent
*               int 文字数 length
* @return str 文字列
*/
string padding(int length, string sContent) {

	stringstream output;
	for (int i = 0; i < length - sContent.length(); i++) {
		output << " ";
	}

	output << sContent;

	return output.str();
}
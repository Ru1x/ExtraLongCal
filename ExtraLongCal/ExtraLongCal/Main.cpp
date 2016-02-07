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
void display();
void add();
string padding(int length, string sContent);
bool IsInteger(const string& str);
void linedraw(char, int);

//-----Declare Global Constants-----
#define MAXDIGIT 70 //最大可能桁数
#define CHARNUM 48 // 文字コード変換用

//-----Declare Global Variables-----
string sInput = "";
string sOutput = "";
string sAnswer = "";
vector<string> elements;
int iMaxd = 0; //現在までの最多桁数
int iCount = 0; //口数

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
		cout << "Input data:";
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
	for (int i = 0; i < elements.size(); ++i) {
		elements[i] = padding(MAXDIGIT+1, elements[i]);
	}
}

void add() {
	if (iCount == 0) { iCount++; sAnswer = sInput; return; }
	string sNewAnswer = "";
	int iCountUp = 0;
	int iDifference = 0;
	int iBuffer = 0;
	if (sInput.length() >= sAnswer.length()) { //現在までの合計より、今入力した値のほうが大きい時
		iDifference = sInput.length() - sAnswer.length();
		for (int i = sAnswer.length()-1; i >= 0;i--) {
			iBuffer = int(sAnswer[i])-CHARNUM + int(sInput[i + iDifference])-CHARNUM + iCountUp;
			iCountUp = 0;
			if (iBuffer >= 10) {
				iCountUp = 1;
				iBuffer = iBuffer - 10;
			}
			sNewAnswer = to_string(iBuffer) + sNewAnswer; //頭に答えをくっつける（1桁ずつ）
		}
		if (sInput.length() > sAnswer.length()) {
			sNewAnswer = to_string(stoi(sInput.substr(0, iDifference)) + iCountUp) + sNewAnswer; //余剰分処理
		}
		sAnswer = sNewAnswer;
		iCount++;
		return;
		//TODO sNewAnswer必要ないかも
	}

	if(sInput.length() < sAnswer.length()) {
		iDifference = sAnswer.length() - sInput.length();
		for (int i = sInput.length() - 1; i >= 0;i--) {
			iBuffer = int(sInput[i]) - CHARNUM + int(sAnswer[i + iDifference]) - CHARNUM + iCountUp;
			iCountUp = 0;
			if (iBuffer >= 10) {
				iCountUp = 1;
				iBuffer = iBuffer - 10;
			}
			sNewAnswer = to_string(iBuffer) + sNewAnswer;
		}
		sNewAnswer = to_string(stoi(sAnswer.substr(0, iDifference)) + iCountUp) + sNewAnswer;
	}
}

void display() {
	system("cls");
	for (int i = 0; i < elements.size()-1; ++i) {
		cout << elements[i] << endl;
	}
	string buffer;
	buffer = elements[elements.size() - 1];//最後をバッファに移動
	buffer.erase(buffer.begin());//最初の文字を消去
	buffer = "+" + buffer;
	cout << buffer << endl;
	linedraw('-', MAXDIGIT + 1);

	cout << padding(MAXDIGIT+1,sAnswer) << endl;
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

void linedraw(char c, int length) /* 仮引数ｃに渡された文字をlength回出力 */
{
	int i;
	for (i = 0; i<length; i++)
		cout << c;
	cout << '\n';
	return;
}
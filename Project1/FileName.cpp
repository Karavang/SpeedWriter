#include <iostream>
#include <string>
#include <cstring>
#include <windows.h>
#include <vector>
using namespace std;


void SetColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void PrintWithColor(const string& text, int matchedLength) {
	for (size_t i = 0; i < text.length(); ++i) {
		if (i < matchedLength) {
			SetColor(10); // Салатовый цвет (светло-зеленый)
		}
		else {
			SetColor(15); // Белый цвет
		}
		cout << text[i];
	}
	SetColor(15); 
}

int main() {
	vector<char> strrr;
	cout << "Enter text"<<endl;
	string input;
	getline(cin, input);	
	for (char ch : input) {
		strrr.push_back(ch);
	}
	strrr.push_back('\0');
	SetColor(10);
	system("CLS");
	cout <<  strrr.data()  << endl;
	system("pause");
}
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <chrono>
#include <iomanip> 

using namespace std;
using namespace std::chrono;


void SetColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void PrintWithColor(const string& text, int matchedLength) {
    system("CLS"); 
    for (size_t i = 0; i < text.length(); ++i) {
        if (i < matchedLength) {
            SetColor(10); 
        }
        else {
            SetColor(15); 
        }
        cout << text[i];
    }
    SetColor(15); 
    cout << endl;
}

int main() {
    string input;

   
    do {
        cout << "Enter text: ";
        getline(cin, input);

        if (input.empty()) {
            cout << "No text entered. Please enter some text." << endl;
        }
    } while (input.empty());

    vector<char> strrr(input.begin(), input.end());
    strrr.push_back('\0');

    int matchedLength = 0;
    auto start = high_resolution_clock::time_point();
    bool started = false;

    
    PrintWithColor(input, matchedLength);

    while (matchedLength < input.length()) {
        if (_kbhit()) { 
            char ch = _getch(); 
            if (!started) {
                start = high_resolution_clock::now(); 
                started = true;
            }
            if (ch == input[matchedLength]) {
                matchedLength++; 
            }
            PrintWithColor(input, matchedLength); 
        }
    }

    auto end = high_resolution_clock::now(); 
    duration<double> diff = end - start; 

    cout << "Completed" << endl;
    cout << fixed << setprecision(2) << "Time taken: " << diff.count() << "s." << endl; 

    system("pause");
    return 0;
}

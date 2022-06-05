#include <iostream>
#include <fstream>
#include <Windows.h>
#include <conio.h>
using namespace std;


void movecursor(int x, int y) {
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}


int main() {
	string password = "1111";
	ifstream fin;
	fin.open("amogus.txt");
	if (!fin.is_open()) {
		cout << "Can't open graphic interface file.";
	}
	else {
		char ch;
		string str;
		int y = 0;
		while (fin.get(ch)) {
			if (ch == '\n') {
				cout << str;
				reverse(str.begin(), str.end());
				movecursor(90, y);
				cout << str;
				y++;
				str.clear();
			}
			else {
				str += ch;
			}
		}
	}
	char inp = 10;
	while (1) {
		movecursor(0, 19);
		if ((int)inp > 47) {
			inp -= 48;
		}
		int flag = (int)inp;
		if (inp == -1) {
			inp = _getch();
			flag = (int)inp - 48;
		}
		switch (flag) {
		case 10: { // start menu
			fin.close();
			fin.open("startmenu.txt");
			if (!fin.is_open()) {
				cout << "Can't open graphic interface file.";
			}
			else {
				char ch;
				string str;
				int y = 0;
				while (fin.get(ch)) {
					if (ch == '\n') {
						movecursor(30, y);
						y++;
					}
					else {
						cout << ch;
					}
				}
			}
			fin.close();
			inp = -1;
			continue;
		}
		case 1: { // change password
			fin.open("changepassword1.txt");
			if (!fin.is_open()) {
				cout << "Can't open graphic interface file.";
			}
			else {
				char ch;
				string str;
				int y = 0;
				while (fin.get(ch)) {
					if (ch == '\n') {
						movecursor(30, y);
						y++;
					}
					else {
						cout << ch;
					}
				}
				movecursor(57, 10);
				str.clear();
				while (str.size() < 4) { // password request
					ch = _getch();
					if (ch == '\b') {
						if (str.size() > 0) {
							str.pop_back();
							cout << ch << '-' << ch;
							continue;
						}
						else {
							continue;
						}
					}
					else if (ch == '\x1b') {
						inp = 10;
						break;
					}
					else {
						str += ch;
						cout << '*';
					}
				}
				fin.close();
				if (ch == '\x1b') continue;
				if (str == password) { // if right
					fin.open("changepassword2.txt");
					if (!fin.is_open()) {
						cout << "Can't open graphic interface file.";
					}
					else {
						char ch;
						string str;
						int y = 0;
						while (fin.get(ch)) {
							if (ch == '\n') {
								movecursor(30, y);
								y++;
							}
							else {
								cout << ch;
							}
						}
						movecursor(57, 10);
						str.clear();
						while (str.size() < 4) { // new password request
							ch = _getch();
							if (ch == '\b') {
								if (str.size() > 0) {
									str.pop_back();
									cout << ch << '-' << ch;
									continue;
								}
								else {
									continue;
								}
							}
							else if (ch == '\x1b') {
								inp = 10;
								break;
							}
							else {
								str += ch;
								cout << '*';
							}
						}
						fin.close();
						if (ch == '\x1b') continue;
						password = str;
						inp = 10;
						continue;
					}
				}
				else { // if wrong
					movecursor(52, 11);
					cout << "Wrong password";
					movecursor(47, 12);
					cout << "Press any key to continue";
					inp = 1;
					_getch();
					continue;
				}
			}
			continue;
		}
		case 27: {
			return 0;
		}
		default: continue;
		}
	}
	return 0;
}
#include "ciphers.h"

void Prog() {
	int cipher = 1;
	string line, key;
	while (cipher) {

		cout << "Выберите шифр: " << endl;
		cout << "<1> для выбора шифра Атбаш " << endl;
		cout << "<2> для выбора шифра Виженера " << endl;
		cout << "<3> для выбора шифра “Тарабарская грамота” " << endl;
		cout << "<0> для выхода из программы " << endl;
		cin >> cipher;
		switch (cipher) {
		case 1:
			line = line_get(cipher, key);
			Atbash(line);
			cout << "----------------------------------------" << endl;
			break;
		case 2:
			line = line_get(cipher, key);
			Vizh(line, key);
			cout << "----------------------------------------" << endl;
			break;
		case 3:
			line = line_get(cipher, key);
			Tar(line);
			cout << "----------------------------------------" << endl;
			break;
		case 0:
			break;
		};
	}
}



string line_get(int cipher, string& key) {
	int method = 0;
	int a = 0;
	string line, path;
	ifstream in;
		cout << "Введите путь к файлу: " << endl;
		cin >> path;
		in.open(path);
		while (true) {
			while (!in.eof()) {
				if (a == 1) {
					getline(in, key);
					break;
				}
				getline(in, line);
				a++;
			}
			if ((checker(line)) && (checker(key))) break;
		}
		in.close();
		}
		return line;
	}


bool checker(const string& text) {
	for (auto& c : text) {
		if (c < 32 || c > 126) {
			cout << "Повторите ввод" << endl;
			return 0;
		}
	}
	return 1;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string s;
	cout << "Пароль: ";
	cin >> s;
	if (s == "123456") {
		Prog();
	}
	else {
		cout << "Неверный пароль: " << endl;
		return 0;
	}
	system("pause");
	return 0;
}


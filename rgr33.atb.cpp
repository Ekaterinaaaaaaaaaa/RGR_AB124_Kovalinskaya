#include "ciphers.h"

// функция кодирования/декодирования
string code_atbash(string text) {


	for (auto& c : text) {
		if (islower(c))
		{
			c = 26 - (c - 'a' + 1) + 'a';
		}
		else if (isupper(c))
		{
			c = 26 - (c - 'A' + 1) + 'A';
		}
	}
	return text;
}



void Atbash(string line) {
	int choice = 0;
	string path;
	ofstream out;

	cout << "Исходный текст: " << line << endl;
	string code = code_atbash(line);
	cout << "Зашифрованный или расшифрованный текст: " << code << endl;

	cout << "Хотите сохранить результат в файле? (1 - Да, 2 - Нет)" << endl;
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "Введите путь к файлу: " << endl;
		cin >> path;
		out.open(path);
		out << code;
		out.close();
		break;
	case 2:
		cout << endl;
		break;
	default:
		cout << "Вернитесь к началу " << endl;

	}

}
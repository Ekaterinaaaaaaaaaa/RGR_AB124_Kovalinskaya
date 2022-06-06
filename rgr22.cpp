#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int i = 0, j = 0, k;
    char ABC[] = { 'А','Б','В','Г','Д','Е','Ж','З','И',
                'Й','К','Л','М','Н','О','П','Р','С',
                'Т','У','Ф','Х','Ц','Ч','Ш','Щ','Ъ',
                'Ы','Ь','Э','Ю','Я','_','.',',','0',
                '1','2','3','4','5','6','7','8','9' };
    char size[80];
    cout << endl;
    for (i = 0; i < size; i++)
    {
        if (i == ' ') size[i] = ' ';
        else {
            for (j = 0; j < 45; j++)
            {
                if (size[i] == ABC[j])
                {
                    if (j >= 45)
                        size[i] = ABC[i - 45];
                    else
                        size[i] = ABC[j + k];
                    break;
                }
            }
        }

    }
    cout << "закодированное сообщение: " << endl;
    cout << size << endl;
    return 0;
}
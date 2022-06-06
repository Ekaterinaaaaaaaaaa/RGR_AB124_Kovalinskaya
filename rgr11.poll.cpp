#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
const char POLYBIUS[5][5] = {
    { 'A', 'B', 'C' , 'D', 'E'},
    { 'F', 'G', 'H' , 'I', 'K'},
    { 'L', 'M', 'N' , 'O', 'P'},
    { 'Q', 'R', 'S' , 'T', 'U'},
    { 'V', 'W', 'X' , 'Y', 'Z'}
};
const char smallPOLYBIUS[5][5] = {
    { 'a', 'b', 'c' , 'd', 'e'},
    { 'f', 'g', 'h' , 'i', 'k'},
    { 'l', 'm', 'n' , 'o', 'p'},
    { 'q', 'r', 's' , 't', 'u'},
    { 'v', 'w', 'x' , 'y', 'z'}
};

vector<int> polibius_encrypt(string c) {
    vector<int> encr;
    for (int ret = 0; ret < c.size(); ret++)
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++) {
                if (c[ret] == POLYBIUS[i][j]) {
                    encr.push_back((i + 1) * 10 + j + 1);
                }
                if (c[ret] == smallPOLYBIUS[i][j]) {
                    encr.push_back((i + 1) * 10 + j + 1);
                }
            }

    return encr;

}
vector<char> polibius_decrypt(vector<int> vec) {
    vector<char> decr;
    for (int ret = 0; ret < vec.size(); ret++)
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++) {
                if (vec[ret] == (i + 1) * 10 + j + 1) {
                    decr.push_back(smallPOLYBIUS[i][j]);
                }
            }

    return decr;

}

template<class T>
auto choise(bool cry, T* thing) {
    if (cry = true)
        return polibius_encrypt(thing);
    else
        return polibius_decrypt(thing);
}
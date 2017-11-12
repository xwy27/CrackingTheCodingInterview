#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::getline;

void replace(string &s) {
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ' ') {
            s.replace(i,1,"%20");
        }
    }
}

int main () {
    string s;
    getline(cin,s);
    replace(s);
    cout << s << endl;
}

//The question becomes simple because of using C++
//The simple algorithm:
//1. count the number of space
//2. extend the string size
//3. operate the string from the end position
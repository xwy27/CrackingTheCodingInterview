#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::getline;

void reverse(char* p) {
    char* ptr = p;
    char c;
    
    if (p) {
        while (*ptr) {
            ++ptr;
        }
        --ptr;
        
        while (p != ptr) {
            c = *p;
            *p++ = *ptr;
            *ptr-- = c;
        }
    }
}

int main () {
    char a[100];
    cin.getline(a,100);
    reverse(a);
    cout << a << endl;
}
//Figure out the meaning of string roatation first
//If s2 is the rotation of s1, then s2 is the substring of s1+s1

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;

bool isSubstring (string &s1, string &s2) {
    return (s1.find(s2) != -1);
}

bool isRotation(string &s1, string &s2) {
    int len = s1.length();
    if (len > 0 && len == s2.length()) {
        string ss = s1 + s1;
        return isSubstring(ss,s2);
    }
    return false;
}

int main () {
    string s1,s2;
    cin >> s1;
    cin >> s2;
    if (isRotation(s1,s2)) {
        cout << s2 << " is a rotation of " << s1 << endl;
    } else {
        cout << s2 << " is not a rotation of " << s1 << endl;
    }
}
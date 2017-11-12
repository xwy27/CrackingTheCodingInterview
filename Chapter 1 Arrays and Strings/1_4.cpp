#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;

bool anagrams(string &s1, string &s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    if (len1 != len2)   return false;
    
    int start = 0, end = len1-1;
    while (start < end) {
        if (s1[start++] != s2[end--]) {
            return false;
        }
    }
    return true;
}

int main () {
    string s1, s2;
    cin >> s1;
    cin >> s2;
    cout << (anagrams(s1,s2) ? "Anagrams" : "Not Anagrams") << endl;
}

//One interesting answer is to decide if two sorted strings are same
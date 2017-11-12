#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;

void remove(string &s) {
    if (s.empty())  return;
    int len = s.length();
    if (len < 2) return;
    
    bool arr[256] = {0};
    arr[s[0]] = true;
    int tail = 1;
    
    for (int i = 1; i < len; ++i) {
        if (!arr[s[i]]) {
            s[tail++] = s[i];
            arr[s[i]] = true;
        }
    }

    s.erase(tail);
}

int main () {
    string s;
    cin >> s;
    remove(s);
    cout << s << endl;
}

//The meaning of 'no additional buffer' decides
//If array with const size is not allowed, using the following function


/* void remove(string &s) {
    if (s.empty())  return;
    int len = s.length();
    if (len < 2)    return;
    
    int tail = 1;
    for (int i = 1; i < len; ++i) {
        int j = 0;
        for (; j < tail; ++j) {
            if (s[j] == s[i]) {
                break;
            }
        }
        if (j == tail) {
            s[tail++] = s[i];
        }
    }

    s.erase(tail);
} */

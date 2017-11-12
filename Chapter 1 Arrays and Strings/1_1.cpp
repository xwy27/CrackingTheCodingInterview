//The complexity of judging one by others is O(n^2)
//The complexity of sorting string is O(nlogn) 
//The complexity of methond below is O(n)
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::cin;

bool uniqueString (string &s) {
    bool arr[256] = {0};
    int pos = 0;
    for (int i = 0; i < s.length(); ++i) {
        pos = s[i];
        if (!arr[pos]) {
            arr[pos] = true;
        } else {
            return false;
        }
    }
    return true;
}

int main () {
    string s;
    cin >> s;
    if (uniqueString(s)) {
        cout << "Unique" << endl;
    } else {
        cout << "Not unique" << endl;
    }
}
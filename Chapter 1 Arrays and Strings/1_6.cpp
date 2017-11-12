/* Algorithm 
    Rotate the matrix one layer by one layer from outside to inside
    For each layer, rotate elements one by one clockwisely
*/

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void rotate(int** matrix, int n) {
    for (int i = 0; i < n / 2; ++i) {
        int start = i;
        int last = n - i - 1;
        for (int j = start; j < last; ++j) {
            int count = j - start;
            int temp = matrix[start][j];
            //leftLast -> leftTop
            matrix[start][j] = matrix[last-count][start];
            //rightLast -> leftLast
            matrix[last-count][start] = matrix[last][last-count];
            //rightTop -> rightLast
            matrix[last][last-count] = matrix[j][last];
            //leftTop -> rightTop
            matrix[j][last] = temp;
        }
    }
}

int main () {
    int n;
    while ((cin >> n) && (n % 2)) {
        cout << "matrix size must be odd." << endl;
    }
    
    int** matrix = new int* [n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int [n];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    rotate(matrix, n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        delete []matrix[i];
    }
    delete []matrix;
}
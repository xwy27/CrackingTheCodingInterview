/* Algorithm
    1.Record the row and column position of zero element
    2.Map search the matrix and turn element to zero if its column or row has zero element

    Tip:If just map search the matrix, may turn matrix to be 0s.
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void setZero(int** matrix, int row, int col) {
    bool* rowArr = new bool [row];
    bool* colArr = new bool [col];
    
    for (int index = 0; index < row; ++index)   rowArr[index] = false;
    for (int index = 0; index < col; ++index)   colArr[index] = false;

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (!matrix[i][j]) {
                rowArr[i] = colArr[j] = true;
            }
        }
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (rowArr[i] || colArr[j]) {
                matrix[i][j] = 0;
            }
        }
    }
    delete []rowArr;
    delete []colArr;
}

int main () {
    int row, col;
    cout << "Row:";
    cin >> row;
    cout << "Col:";
    cin >> col;
    
    int** matrix = new int* [row];
    for (int i = 0; i < row; ++i) {
        matrix[i] = new int [col];
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cin >> matrix[i][j];
        }
    }

    setZero(matrix, row, col);
    
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < row; ++i) {
        delete []matrix[i];
    }
    delete []matrix;
}
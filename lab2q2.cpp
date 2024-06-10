#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<bool>> Matrix;

// Function to print the matrix
void printMatrix(const Matrix &matrix) {
    for (const auto &row : matrix) {
        for (bool val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// Function to perform Join (OR) operation
Matrix join(const Matrix &A, const Matrix &B) {
    int rows = A.size();
    int cols = A[0].size();
    Matrix result(rows, vector<bool>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] || B[i][j];
        }
    }
    return result;
}

// Function to perform Meet (AND) operation
Matrix meet(const Matrix &A, const Matrix &B) {
    int rows = A.size();
    int cols = A[0].size();
    Matrix result(rows, vector<bool>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] && B[i][j];
        }
    }
    return result;
}

// Function to perform Boolean Product
Matrix booleanProduct(const Matrix &A, const Matrix &B) {
    int rows = A.size();
    int cols = B[0].size();
    int inner = B.size();
    Matrix result(rows, vector<bool>(cols, false));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            for (int k = 0; k < inner; ++k) {
                result[i][j] = result[i][j] || (A[i][k] && B[k][j]);
            }
        }
    }
    return result;
}

int main() {
    // Example matrices
    Matrix A = {
        {true, false, true},
        {false, true, false},
        {true, true, false}
    };

    Matrix B = {
        {false, true, false},
        {true, false, true},
        {false, false, true}
    };

    cout << "Matrix A:" << endl;
    printMatrix(A);
    cout << endl;

    cout << "Matrix B:" << endl;
    printMatrix(B);
    cout << endl;

    Matrix joinResult = join(A, B);
    cout << "Join (A OR B):" << endl;
    printMatrix(joinResult);
    cout << endl;

    Matrix meetResult = meet(A, B);
    cout << "Meet (A AND B):" << endl;
    printMatrix(meetResult);
    cout << endl;

    Matrix booleanProductResult = booleanProduct(A, B);
    cout << "Boolean Product (A * B):" << endl;
    printMatrix(booleanProductResult);
    cout << endl;

    return 0;
}


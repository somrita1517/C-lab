#include <iostream>
#include <vector>
using namespace std;

using Matrix = vector<vector<int>>;

Matrix readMatrix(int rows, int cols, const string& name) {
    Matrix matrix(rows, vector<int>(cols));

    cout << "Enter elements of " << name << " (" << rows
         << " x " << cols << "):\\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

void displayMatrix(const Matrix& matrix) {
    for (const auto& row : matrix) {
        for (int value : row)
            cout << value << "\\t";
        cout << endl;
    }
}

Matrix addMatrices(const Matrix& a, const Matrix& b) {
    int rows = static_cast<int>(a.size());
    int cols = static_cast<int>(a[0].size());
    Matrix result(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = a[i][j] + b[i][j];

    return result;
}

Matrix subtractMatrices(const Matrix& a, const Matrix& b) {
    int rows = static_cast<int>(a.size());
    int cols = static_cast<int>(a[0].size());
    Matrix result(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = a[i][j] - b[i][j];

    return result;
}

Matrix multiplyMatrices(const Matrix& a, const Matrix& b) {
    int rows = static_cast<int>(a.size());
    int common = static_cast<int>(b.size());
    int cols = static_cast<int>(b[0].size());
    Matrix result(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            for (int k = 0; k < common; k++)
                result[i][j] += a[i][k] * b[k][j];

    return result;
}

Matrix transposeMatrix(const Matrix& a) {
    int rows = static_cast<int>(a.size());
    int cols = static_cast<int>(a[0].size());
    Matrix result(cols, vector<int>(rows, 0));

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[j][i] = a[i][j];

    return result;
}

int main() {
    int choice;
    cout << "MATRIX OPERATIONS\\n";
    cout << "1. Addition\\n";
    cout << "2. Subtraction\\n";
    cout << "3. Multiplication\\n";
    cout << "4. Transpose\\n";
    cout << "Enter your choice: ";
    cin >> choice;

    int r1, c1, r2, c2;
    Matrix a, b, result;

    switch (choice) {
        case 1:
        case 2:
            cout << "Enter rows and columns of both matrices: ";
            cin >> r1 >> c1 >> r2 >> c2;

            if (r1 <= 0 || c1 <= 0 || r2 != r1 || c2 != c1) {
                cout << "Addition/subtraction requires equal dimensions.\\n";
                break;
            }

            a = readMatrix(r1, c1, "Matrix A");
            b = readMatrix(r2, c2, "Matrix B");

            if (choice == 1) {
                result = addMatrices(a, b);
                cout << "Addition result:\\n";
            } else {
                result = subtractMatrices(a, b);
                cout << "Subtraction result:\\n";
            }
            displayMatrix(result);
            break;

        case 3:
            cout << "Enter rows and columns of Matrix A: ";
            cin >> r1 >> c1;
            cout << "Enter rows and columns of Matrix B: ";
            cin >> r2 >> c2;

            if (r1 <= 0 || c1 <= 0 || r2 <= 0 || c2 <= 0 || c1 != r2) {
                cout << "Multiplication not possible: columns of A must equal rows of B.\\n";
                break;
            }

            a = readMatrix(r1, c1, "Matrix A");
            b = readMatrix(r2, c2, "Matrix B");
            result = multiplyMatrices(a, b);
            cout << "Multiplication result:\\n";
            displayMatrix(result);
            break;

        case 4:
            cout << "Enter rows and columns of the matrix: ";
            cin >> r1 >> c1;

            if (r1 <= 0 || c1 <= 0) {
                cout << "Invalid matrix dimensions.\\n";
                break;
            }

            a = readMatrix(r1, c1, "Matrix");
            result = transposeMatrix(a);
            cout << "Transpose of the matrix:\\n";
            displayMatrix(result);
            break;

        default:
            cout << "Invalid choice.\\n";
    }

    return 0;
}

/*
SAMPLE OUTPUT 1 (ADDITION):

MATRIX OPERATIONS
1. Addition
2. Subtraction
3. Multiplication
4. Transpose
Enter your choice: 1
Enter rows and columns of both matrices: 2 2 2 2
Enter elements of Matrix A (2 x 2):
1 2
3 4
Enter elements of Matrix B (2 x 2):
5 6
7 8
Addition result:
6       8
10      12

SAMPLE OUTPUT 2 (SUBTRACTION):

Enter your choice: 2
Enter rows and columns of both matrices: 2 2 2 2
Enter elements of Matrix A (2 x 2):
5 6
7 8
Enter elements of Matrix B (2 x 2):
1 2
3 4
Subtraction result:
4       4
4       4

SAMPLE OUTPUT 3 (MULTIPLICATION):

Enter your choice: 3
Enter rows and columns of Matrix A: 2 2
Enter rows and columns of Matrix B: 2 2
Enter elements of Matrix A (2 x 2):
1 2
3 4
Enter elements of Matrix B (2 x 2):
5 6
7 8
Multiplication result:
19      22
43      50

SAMPLE OUTPUT 4 (TRANSPOSE):

Enter your choice: 4
Enter rows and columns of the matrix: 2 3
Enter elements of Matrix (2 x 3):
1 2 3
4 5 6
Transpose of the matrix:
1       4
2       5
3       6
*/

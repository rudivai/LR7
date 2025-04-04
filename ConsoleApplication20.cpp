#include <iostream>
#include <vector>

using namespace std;

// Функція для введення розміру матриці (без обмежень на розмір)
void inputMatrixSize(int& M, int& N) {
    cout << "Enter the number of rows: ";
    cin >> M;
    cout << "Enter the number of columns: ";
    cin >> N;

    // Перевірка на коректне введення
    while (M <= 0 || N <= 0) {
        cout << "Matrix size must be greater than zero. Try again.\n";
        cout << "Enter the number of rows: ";
        cin >> M;
        cout << "Enter the number of columns: ";
        cin >> N;
    }
}

// Функція для введення елементів матриці
void inputMatrix(vector<vector<int>>& matrix, int M, int N) {
    cout << "Enter the elements of the matrix by rows:" << endl;
    matrix.resize(M, vector<int>(N)); // Задаємо розмір матриці
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j]; // Введення кожного елементу
        }
    }
}

// Функція для виведення матриці
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

// Завдання 1: Обчислити добуток елементів кожного стовпця
void task1() {
    int M, N;
    inputMatrixSize(M, N); // Введення розміру матриці
    vector<vector<int>> matrix;
    inputMatrix(matrix, M, N); // Введення елементів

    // Ініціалізація вектора добутків (по одному на кожен стовпець)
    vector<int> column_products(N, 1);

    // Обчислення добутків
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < M; i++) {
            column_products[j] *= matrix[i][j];
        }
    }

    // Виведення результатів
    cout << "Product of the elements of each column:" << endl;
    for (int prod : column_products) {
        cout << prod << " ";
    }
    cout << endl;
}

// Завдання 2: Дублювати стовпець з мінімальним елементом та вивести оновлену матрицю після початкової
void task2() {
    int M, N;
    inputMatrixSize(M, N); // Введення розміру
    vector<vector<int>> matrix;
    inputMatrix(matrix, M, N); // Введення елементів

    // Виведення початкової матриці
    cout << "Original matrix:" << endl;
    printMatrix(matrix);

    // Пошук мінімального елементу вручну
    int minElement = matrix[0][0];
    int minColumn = 0;

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < M; i++) {
            if (matrix[i][j] < minElement) {
                minElement = matrix[i][j];
                minColumn = j;
            }
        }
    }

    // Дублювання стовпця з мінімальним елементом
    for (int i = 0; i < M; i++) {
        matrix[i].insert(matrix[i].begin() + minColumn + 1, matrix[i][minColumn]);
    }

    // Виведення матриці після дублювання
    cout << "Matrix after duplicating the column with the minimum element:" << endl;
    printMatrix(matrix);
}

// Меню з вибором дій
void menu() {
    while (true) {
        int choice;
        cout << "Menu:\n";
        cout << "1. Task 1: Calculate the product of the elements of each column\n";
        cout << "2. Task 2: Duplicate the column with the minimum element\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 3) break; // Вихід з програми

        switch (choice) {
        case 1:
            task1(); // Завдання 1
            break;
        case 2:
            task2(); // Завдання 2
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    }
}

// Головна функція
int main() {
    menu(); // Запуск меню
    return 0;
}
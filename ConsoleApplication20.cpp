#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Константи для мінімального та максимального розміру матриці
const int MIN_SIZE = 1, MAX_SIZE = 20;

// Функція для введення розміру матриці (кількість рядків та стовпців)
void inputMatrixSize(int& M, int& N) {
    do {
        // Введення кількості рядків
        cout << "Enter the number of rows (from 1 to 20): ";
        cin >> M;
        // Введення кількості стовпців
        cout << "Enter the number of columns (from 1 to 20): ";
        cin >> N;

        // Перевірка, чи введений розмір знаходиться в допустимих межах
        if (M < MIN_SIZE || M > MAX_SIZE || N < MIN_SIZE || N > MAX_SIZE) {
            cout << "Error! Matrix size must be between 1 and 20. Try again.\n";
        }
    } while (M < MIN_SIZE || M > MAX_SIZE || N < MIN_SIZE || N > MAX_SIZE);
}

// Функція для введення елементів матриці
void inputMatrix(vector<vector<int>>& matrix, int M, int N) {
    cout << "Enter the elements of the matrix by rows:" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
}

// Функція для виведення елементів матриці
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

// Завдання 1: Обчислення добутку елементів кожного стовпця
void task1() {
    int M, N;
    inputMatrixSize(M, N);  // Введення розміру матриці
    vector<vector<int>> matrix(M, vector<int>(N));  // Створення матриці
    inputMatrix(matrix, M, N);  // Введення елементів матриці

    vector<int> column_products(N, 1);  // Вектор для зберігання добутків стовпців
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < M; i++) {
            column_products[j] *= matrix[i][j];  // Обчислення добутку елементів стовпця
        }
    }

    // Виведення добутків елементів кожного стовпця
    cout << "Product of the elements of each column:" << endl;
    for (int prod : column_products) {
        cout << prod << " ";
    }
    cout << endl;
}

// Завдання 2: Дублювання стовпця, що містить мінімальний елемент
void task2() {
    int M, N;
    inputMatrixSize(M, N);  // Введення розміру матриці
    vector<vector<int>> matrix(M, vector<int>(N + 1));  // Створення матриці з додатковим стовпцем для дублювання
    inputMatrix(matrix, M, N);  // Введення елементів матриці

    // Пошук мінімального елемента та стовпця, в якому він знаходиться
    int minElement = numeric_limits<int>::max();
    int minColumn = 0;
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < M; i++) {
            if (matrix[i][j] < minElement) {
                minElement = matrix[i][j];
                minColumn = j;  // Збереження індексу стовпця з мінімальним елементом
            }
        }
    }

    // Дублювання стовпця з мінімальним елементом
    for (int i = 0; i < M; i++) {
        for (int j = N; j > minColumn; j--) {
            matrix[i][j] = matrix[i][j - 1];  // Зсув елементів праворуч
        }
    }

    // Виведення матриці після дублювання стовпця
    cout << "Matrix after duplicating the column with the minimum element:" << endl;
    printMatrix(matrix);
}

// Меню для вибору завдання
void menu() {
    while (true) {
        int choice;
        cout << "Menu:\n";
        cout << "1. Task 1: Calculate the product of the elements of each column\n";
        cout << "2. Task 2: Duplicate the column with the minimum element\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 3) break;  // Вихід з програми

        // Обробка вибору користувача
        switch (choice) {
        case 1:
            task1();  // Виконання завдання 1
            break;
        case 2:
            task2();  // Виконання завдання 2
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    }
}

// Головна функція
int main() {
    menu();  // Виклик функції меню
    return 0;
}
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

// Функция для выполнения LU-разложения матрицы
void luDecomposition(const std::vector<std::vector<double>>& matrix, std::vector<std::vector<double>>& L, std::vector<std::vector<double>>& U) {
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        // Расчет элементов матрицы L
        for (int j = 0; j < n; j++) {
            if (j < i) {
                L[j][i] = 0;
            } else if (j == i) {
                L[j][i] = 1;
            } else {
                L[j][i] = matrix[j][i];
                for (int k = 0; k < i; k++) {
                    L[j][i] -= L[j][k] * U[k][i];
                }
            }
        }

        // Расчет элементов матрицы U
        for (int j = 0; j < n; j++) {
            if (j < i) {
                U[i][j] = 0;
            } else {
                U[i][j] = matrix[i][j] / L[i][i];
                for (int k = 0; k < i; k++) {
                    U[i][j] -= ((L[i][k] * U[k][j]) / L[i][i]);
                }
            }
        }
    }
}

// Функция для вычисления определителя матрицы с помощью LU-разложения
double calculateDeterminant(const std::vector<std::vector<double>>& matrix) {
    int n = matrix.size();
    std::vector<std::vector<double>> L(n, std::vector<double>(n));
    std::vector<std::vector<double>> U(n, std::vector<double>(n));

    luDecomposition(matrix, L, U);

    double determinant = 1;
    for (int i = 0; i < n; i++) {
        determinant *= U[i][i];
    }

    return determinant;
}

int main() {
    std::string filename = "matrix.txt";
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open file: " << filename << std::endl;
        return 1;
    }

    int n;
    file >> n;
    std::vector<std::vector<double>> matrix(n, std::vector<double>(n, 0.0));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            file >> matrix[i][j];

    file.close();

    double determinant = calculateDeterminant(matrix);

    std::cout << "Determinant: " << determinant << std::endl;
    std::fstream output("output.txt");
    output<<determinant;
    output.close();
    return 0;
}
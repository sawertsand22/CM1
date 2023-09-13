#include <QCoreApplication>
#include <iostream>
#include <fstream>
#
#include <vector>

// Функция для чтения матрицы и правой части СЛАУ из файла
void readMatrixFromFile(const std::string& filename, std::vector<std::vector<double>>& matrix, std::vector<double>& b) {
    std::fstream file("input.txt");
    if (file.is_open()) {
        std::cout<<"Opened"<<std::endl;
        int n;
        file >> n; // Размерность матрицы и количество уравнений

        // Инициализация матрицы и правой части
        matrix.resize(n, std::vector<double>(n));
        b.resize(n);

        // Чтение матрицы и правой части из файла
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                file >> matrix[i][j];
            }
            file >> b[i];
        }
        file.close();
    }
    else
        std::cout<<"ERROR"<<std::endl;
}

// Функция для вывода решения СЛАУ
void printSolution(const std::vector<double>& solution) {
    std::cout << "Solution: ";
    for (const auto& x : solution) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

// Метод Гаусса для решения СЛАУ
void gaussElimination(std::vector<std::vector<double>>& matrix, std::vector<double>& b) {
    const int n = matrix.size();

    for (int i = 0; i < n - 1; ++i) {
        // Поиск главного элемента
        int maxRow = i;
        for (int j = i + 1; j < n; ++j) {
            if (std::abs(matrix[j][i]) > std::abs(matrix[maxRow][i])) {
                maxRow = j;
            }
        }

        // Обмен строк
        matrix[i].swap(matrix[maxRow]);
        std::swap(b[i], b[maxRow]);

        if (matrix[i][i] == 0) {
            // Матрица вырождена, нет уникального решения
            return;
        }

        // Прямой ход метода Гаусса
        for (int j = i + 1; j < n; ++j) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k < n; ++k) {
                matrix[j][k] -= factor * matrix[i][k];
            }
            b[j] -= factor * b[i];
        }
    }

    // Обратный ход метода Гаусса
    std::vector<double> solution(n);
    for (int i = n - 1; i >= 0; --i) {
        double sum = 0;
        for (int j = i + 1; j < n; ++j) {
            sum += matrix[i][j] * solution[j];
        }
        solution[i] = (b[i] - sum) / matrix[i][i];
    }

    printSolution(solution);
}




int main()
{
   // QCoreApplication a(argc, argv); int argc, char *argv[]
    std::vector<std::vector<double>> matrix;
    std::vector<double> b;

    // Задайте путь к файлу с матрицей и правой частью СЛАУ
    std::string filename = "input.txt";
    readMatrixFromFile(filename, matrix, b);

    gaussElimination(matrix, b);

    return 0;
}

#include <iostream>
#include <fstream>
#include <vector>



void printL(const std::vector<std::vector<double>>& matrix) {
    int n = matrix.size();
    std::cout << std::endl << "Our  matrix L" << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void printU(const std::vector<std::vector<double>>& matrix) {
    int n = matrix.size();
    std::cout << std::endl << "Our  matrix U" << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Функция для выполнения LU-разложения матрицы
void luDecomposition(const std::vector<std::vector<double>>& matrix, std::vector<std::vector<double>>& L, std::vector<std::vector<double>>& U) {
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        // Расчет элементов матрицы L
        for (int j = 0; j < n; j++) {
            //Выше диаогонали равняем 0
            if (j < i) {
                L[j][i] = 0;
                printL(L);
                //По условнию задано единичная диагональ у L
            } else if (j == i) {
                L[j][i] = 1;
                printL(L);
            } else {
                //Даем значения изначально выше диагональной чтоб было не 0
                L[j][i] = matrix[j][i];
                printL(L);
                for (int k = 0; k < i; k++) {
                    std::cout<<"L["<<j<<"]["<<i<<"]-= "<<L[j][k]<<"*"<<U[k][i]<<" k= "<<k<<" i= "<<i<<" j= "<<j<<std::endl;
                    L[j][i] -= L[j][k] * U[k][i];
                    printL(L);

                }

            }


        }
        std::cout<<std::endl;
        // Расчет элементов матрицы U
        for (int j = 0; j < n; j++) {
            //Ниже диаогонали равняем 0
            if (j < i) {
                U[i][j] = 0;
                printU(U);
            } else {
                U[i][j] = matrix[i][j] / L[i][i];
                printU(U);
                for (int k = 0; k < i; k++) {
                    std::cout<<"U["<<i<<"]["<<j<<"]-= "<<L[i][k]<<"*"<<U[k][j]<<"/"<<L[i][i]<<" k= "<<k<<" i= "<<i<<" j= "<<j<<std::endl;
                    U[i][j] -= ((L[i][k] * U[k][j]) / L[i][i]);
                    printU(U);
                }

            }


        }

    }
    std::cout<<std::endl<<"Our l decomposited"<<std::endl;
    std::cout<<std::endl;
    for(int i=0;i<n;i++) {
        for (int j = 0; j < n; ++j) {
            std::cout << L[i][j] << " ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl<<"Our U decomposited"<<std::endl;
    std::cout<<std::endl;
    for(int i=0;i<n;i++) {
        for (int j = 0; j < n; ++j) {
            std::cout << U[i][j] << " ";
        }
        std::cout<<std::endl;
    }
}

// Функция для вычисления определителя матрицы с помощью LU-разложения
double calculateDeterminant(const std::vector<std::vector<double>>& matrix) {
    int n = matrix.size();
    //Create the L & U vector for decompositing
    std::vector<std::vector<double>> L(n, std::vector<double>(n));
    std::vector<std::vector<double>> U(n, std::vector<double>(n));
    std::cout<<std::endl<<"Our l "<<std::endl;
    std::cout<<std::endl;
    for(int i=0;i<n;i++) {
        for (int j = 0; j < n; ++j) {
            std::cout << L[i][j] << " ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl<<"Our U "<<std::endl;
    std::cout<<std::endl;
    for(int i=0;i<n;i++) {
        for (int j = 0; j < n; ++j) {
            std::cout << U[i][j] << " ";
        }
        std::cout<<std::endl;
    }
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
    std::cout<<"Our Matrix"<<std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            file >> matrix[i][j];
            std::cout << matrix[i][j] << " ";
        }
        std::cout<<std::endl;
    }

    file.close();
    //Calculating det
    double determinant = calculateDeterminant(matrix);

    std::cout << "Determinant: " << determinant << std::endl;
    std::fstream output("output.txt");
    output<<determinant;
    output.close();
    return 0;
}

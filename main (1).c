#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define N 15 // Розмір одномірного масиву
#define ROWS 6 // Рядки двовимірного масиву
#define COLS 6 // Стовпці двовимірного масиву

int main() {
    srand(time(NULL));
    
    // ==========================================
    // ЗАВДАННЯ 1 (Варіант 3)
    // ==========================================
    printf("=== ZAVDANNJA 1 ===\n");
    double d[N];
    
    // Заповнення випадковими числами (наприклад, від 1 до 20, щоб уникнути ділення на 0)
    printf("Pochatkovyj masiv d:\n");
    for (int i = 0; i < N; i++) {
        d[i] = (double)(rand() % 20 + 1);
        printf("%.2f ", d[i]);
    }
    printf("\n\n");
    
    // Перетворення за формулою d[i] = exp(i / d[i])
    for (int i = 0; i < N; i++) {
        d[i] = exp((double)i / d[i]);
    }
    
    printf("Peredovlenyj masiv d:\n");
    for (int i = 0; i < N; i++) {
        printf("%.2f ", d[i]);
    }
    printf("\n\n");
    
    // Знаходження суми елементів, порядковий номер яких ділиться на 3 (індекси 0, 3, 6, 9...)
    double sum = 0;
    for (int i = 0; i < N; i++) {
        if (i % 3 == 0) {
            sum += d[i];
        }
    }
    printf("Suma elementiv, indeks yakyh dilytysya na 3 = %.4f\n\n", sum);
    
    // ==========================================
    // ЗАВДАННЯ 2 (Варіант 3)
    // ==========================================
    printf("=== ZAVDANNJA 2 ===\n");
    int a[ROWS][COLS];
    
    // Заповнення двовимірного масиву за умовою:
    // a[i][j] = ij (тобто i * 10 + j або i * j, зазвичай мається на увазі добуток розрядів або i*j; 
    // інтерпретуємо 'ij' як i * 10 + j або i * j. Візьмемо стандартне i*j для цифр або i*10+j. 
    // Покладемо за умовою: якщо i >= j -> i*10+j (або i*j), в іншому випадку ji -> j*10+i. Зробимо i*j для безпеки або класичне значення).
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i >= j) {
                a[i][j] = i * 10 + j; // або i * j
            } else {
                a[i][j] = j * 10 + i; // ji
            }
        }
    }
    
    printf("Dvovymirnyj masyv a[%d][%d]:\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%4d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // Пошук квадратної матриці 3x3 з мінімальною сумою діагональних елементів
    int best_row = 0, best_col = 0;
    double min_diag_sum = 1e9;
    
    for (int r = 0; r <= ROWS - 3; r++) {
        for (int c = 0; c <= COLS - 3; c++) {
            // Головна діагональ + побічна діагональ підматриці 3x3
            int diag_sum = a[r][c] + a[r+1][c+1] + a[r+2][c+2] + 
                           a[r][c+2] + a[r+1][c+1] + a[r+2][c];
                           
            if (diag_sum < min_diag_sum) {
                min_diag_sum = diag_sum;
                best_row = r;
                best_col = c;
            }
        }
    }
    
    printf("Kvadratna matrycya 3x3 z minimalnoiu suмою diagonaley (pocatkovyj indeks [%d][%d]):\n", best_row, best_col);
    for (int i = best_row; i < best_row + 3; i++) {
        for (int j = best_col; j < best_col + 3; j++) {
            printf("%4d ", a[i][j]);
        }
        printf("\n");
    }
    printf("Minimalna suma diagonaley = %.0f\n", min_diag_sum);
    
    return 0;
}
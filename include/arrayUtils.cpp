#include "arrayUtils.h"
#include <iostream>

void print2DArray(int arr[][4], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << arr[i][j] << ",";
        }
        std::cout << std::endl;
    }
}

void initialize2DArray(int arr[][4], int rows) {
    int value = 11;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 4; j++) {
            arr[i][j] = value++;
        }
    }
}
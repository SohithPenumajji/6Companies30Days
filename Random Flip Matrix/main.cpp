#include <iostream>
#include <cstdlib>
#include <ctime>

class Solution {
public:
    Solution(int m, int n) {
        rows = m;
        cols = n;
        total_zeros = m * n;
        matrix = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new int[cols]();
        }
        srand(time(0));
    }

    int* flip() {
        int randIndex = rand() % total_zeros;
        int originalRandIndex = randIndex;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == 0) {
                    if (randIndex == 0) {
                        flipCell(i, j);
                        return new int[]{i, j};
                    }
                    randIndex--;
                }
            }
        }

        return nullptr; 
    }

    void reset() {
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
        matrix = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new int[cols]();
        }
        total_zeros = rows * cols;
    }

    ~Solution() {
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

private:
    int rows;
    int cols;
    int total_zeros;
    int** matrix;

    void flipCell(int i, int j) {
        matrix[i][j] = 1;
        total_zeros--;
    }
};

int main() {
    Solution solution(3, 1);
    int* result1 = solution.flip();
    int* result2 = solution.flip();
    int* result3 = solution.flip();
    solution.reset();
    int* result4 = solution.flip();

    std::cout << "Output: [null, [" << result1[0] << ", " << result1[1] << "], [" << result2[0] << ", " << result2[1] << "], [" << result3[0] << ", " << result3[1] << "], null, [" << result4[0] << ", " << result4[1] << "]]" << std::endl;

    delete[] result1;
    delete[] result2;
    delete[] result3;
    delete[] result4;

    return 0;
}


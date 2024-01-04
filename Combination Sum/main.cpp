#include <iostream>

using namespace std;

const int MAX_SIZE = 9;

void findCombinations(int k, int n, int start, int current[], int currentIndex, int result[][MAX_SIZE], int& resultIndex) {
    if (k == 0 && n == 0) {
        for (int i = 0; i < currentIndex; ++i) {
            result[resultIndex][i] = current[i];
        }
        ++resultIndex;
        return;
    }

    for (int i = start; i <= 9 && i <= n; ++i) {
        current[currentIndex] = i;
        findCombinations(k - 1, n - i, i + 1, current, currentIndex + 1, result, resultIndex);
    }
}

int main() {
    int k = 3, n = 7;
    int result[1000][MAX_SIZE]; // lets assume 100 combinations
    int resultIndex = 0;
    int current[MAX_SIZE];

    findCombinations(k, n, 1, current, 0, result, resultIndex);

    cout << "Valid combinations for k = " << k << " and n = " << n << " are:" << endl;
    for (int i = 0; i < resultIndex; ++i) {
        cout << "[";
        for (int j = 0; j < k; ++j) {
            cout << result[i][j] << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}


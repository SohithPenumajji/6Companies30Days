#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int m, n;

    bool isValid(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int** highestPeak(int** isWater, int m, int n, int* returnSize, int** returnColumnSizes) {
        this->m = m;
        this->n = n;

        int** height = new int*[m];
        for (int i = 0; i < m; ++i) {
            height[i] = new int[n];
            fill_n(height[i], n, -1);
        }

        queue<pair<int, int>> q;

      
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j] == 1) {
                    height[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            for (int k = 0; k < 4; ++k) {
                int ni = curr.first + (k == 0) - (k == 1);
                int nj = curr.second + (k == 2) - (k == 3);

                if (isValid(ni, nj) && height[ni][nj] == -1) {
                    height[ni][nj] = height[curr.first][curr.second] + 1;
                    q.push({ni, nj});
                }
            }
        }

        *returnSize = m;
        *returnColumnSizes = new int[m];
        fill_n(*returnColumnSizes, m, n);

        return height;
    }
};

int main() {
    Solution solution;
    int m = 2, n = 2;
    int** isWater = new int*[m];
    for (int i = 0; i < m; ++i) {
        isWater[i] = new int[n];
    }

   

    int returnSize;
    int* returnColumnSizes;
    int** result = solution.highestPeak(isWater, m, n, &returnSize, &returnColumnSizes);

    cout << "Output:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

  
    for (int i = 0; i < m; ++i) {
        delete[] isWater[i];
        delete[] result[i];
    }
    delete[] isWater;
    delete[] result;

    return 0;
}


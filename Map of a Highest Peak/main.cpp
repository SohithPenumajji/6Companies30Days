#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    int numWays(int startPos, int endPos, int k) {
        int maxPos = max(startPos, endPos) + k + 1;
        vector<vector<int>> dp(k + 1, vector<int>(2 * maxPos + 1, 0));

        dp[0][startPos + maxPos] = 1;

        for (int i = 1; i <= k; ++i) {
            for (int j = 0; j <= 2 * maxPos; ++j) {
                if (dp[i - 1][j] > 0) {
                    
                    if (j - 1 >= 0) {
                        dp[i][j - 1] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
                    }

                    
                    if (j + 1 <= 2 * maxPos) {
                        dp[i][j + 1] = (dp[i][j + 1] + dp[i - 1][j]) % MOD;
                    }
                }
            }
        }

        return dp[k][endPos + maxPos];
    }
};

int main() {
  

    Solution solution;
    int startPos = 1, endPos = 2, k = 3;
    int result = solution.numWays(startPos, endPos, k);

    cout << "Output: " << result << endl;

    return 0;
}


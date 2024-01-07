#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countDistinctSubarrays(int nums[], int n, int k, int p) {
        int prefixCount[n + 1] = {0};
        unordered_map<int, int> countMap;

        int result = 0;
        int prefixSum = 0;
        countMap[0] = 1; // initializing empty array

        for (int i = 0; i < n; ++i) {
            prefixSum = (prefixSum + nums[i]) % p;
            prefixCount[i + 1] = prefixSum;

            int validPrefix = (prefixSum - k + p) % p;
            result += countMap[validPrefix];

            countMap[prefixSum]++;
        }

        return result;
    }
};

int main() {
    Solution solution;
    int nums[] = {2, 3, 3, 2, 2};
    int n = sizeof(nums) / sizeof(nums[0]);
    int k = 2, p = 2;

    int result = solution.countDistinctSubarrays(nums, n, k, p);

    cout << "Output: " << result << endl;

    return 0;
}


#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1000; 
const int MAX_M = 10;   

int processQueries(char nums[MAX_N][MAX_M], int queries[MAX_N][2], int result[MAX_N]) {
    int n = MAX_N;
    int m = MAX_M;

    pair<string, int> trimmedNums[MAX_N];

    for (int i = 0; i < n; ++i) {
        trimmedNums[i].second = i;
    }

    for (int q = 0; q < n; ++q) {
        int k = queries[q][0];
        int trim = queries[q][1];

        for (int i = 0; i < n; ++i) {
            int len = m - trim;
            copy(nums[i] + len, nums[i] + m, trimmedNums[i].first.begin());
            trimmedNums[i].first[len] = '\0';
        }

        sort(trimmedNums, trimmedNums + n);

        result[q] = trimmedNums[k - 1].second;
    }

    return n;
}

int main() {
    char nums[MAX_N][MAX_M] = {"102", "473", "251", "814"};
    int queries[MAX_N][2] = {{1, 1}, {2, 3}, {4, 2}, {1, 2}};
    int result[MAX_N];

    int count = processQueries(nums, queries, result);

    cout << "Output: [";
    for (int i = 0; i < count; ++i) {
        cout << result[i];
        if (i < count - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}


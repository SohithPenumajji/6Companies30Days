#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int* highAccessEmployees(char*** access_times, int n, int* m) {
        unordered_map<string, int*> accessMap;

        for (int i = 0; i < n; ++i) {
            string employee(access_times[i][0]);
            int time = stoi(access_times[i][1]);
            
            if (accessMap.find(employee) == accessMap.end()) {
                accessMap[employee] = new int[1000];
                m[i] = 0;
            }
            
            accessMap[employee][m[i]++] = time;
        }

        int* result = new int[1000];
        int resultIndex = 0;

        for (const auto& entry : accessMap) {
            int* accessTimes = entry.second;
            if (hasHighAccess(accessTimes, m[resultIndex])) {
                result[resultIndex++] = stoi(entry.first);
            }
        }

        return result;
    }

    ~Solution() {
        for (auto& entry : accessMap) {
            delete[] entry.second;
        }
    }

private:
    bool hasHighAccess(int* accessTimes, int size) {
        if (size < 3) {
            return false;
        }

        sort(accessTimes, accessTimes + size);

        for (int i = 0; i < size - 2; ++i) {
            if (accessTimes[i + 2] - accessTimes[i] <= 60) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution solution;
    int n = 5;
    int m[5] = {0};
    char*** access_times = new char**[n];
    for (int i = 0; i < n; ++i) {
        access_times[i] = new char*[2];
        access_times[i][0] = new char[2];
        access_times[i][1] = new char[5];
    }
    access_times[0][0][0] = 'a'; access_times[0][0][1] = '\0'; access_times[0][1][0] = '0'; access_times[0][1][1] = '5'; access_times[0][1][2] = '4'; access_times[0][1][3] = '9'; access_times[0][1][4] = '\0';
    access_times[1][0][0] = 'b'; access_times[1][0][1] = '\0'; access_times[1][1][0] = '0'; access_times[1][1][1] = '4'; access_times[1][1][2] = '5'; access_times[1][1][3] = '7'; access_times[1][1][4] = '\0';
    access_times[2][0][0] = 'a'; access_times[2][0][1] = '\0'; access_times[2][1][0] = '0'; access_times[2][1][1] = '5'; access_times[2][1][2] = '3'; access_times[2][1][3] = '2'; access_times[2][1][4] = '\0';
    access_times[3][0][0] = 'a'; access_times[3][0][1] = '\0'; access_times[3][1][0] = '0'; access_times[3][1][1] = '6'; access_times[3][1][2] = '2'; access_times[3][1][3] = '1'; access_times[3][1][4] = '\0';
    access_times[4][0][0] = 'b'; access_times[4][0][1] = '\0'; access_times[4][1][0] = '0'; access_times[4][1][1] = '5'; access_times[4][1][2] = '4'; access_times[4][1][3] = '0'; access_times[4][1][4] = '\0';

    int* result = solution.highAccessEmployees(access_times, n, m);

    cout << "Output: [";
    for (int i = 0; i < result[0]; ++i) {
        cout << result[i + 1] << ", ";
    }
    cout << "]" << endl;

    for (int i = 0; i < n; ++i) {
        delete[] access_times[i][0];
        delete[] access_times[i][1];
        delete[] access_times[i];
    }
    delete[] access_times;
    delete[] result;

    return 0;
}


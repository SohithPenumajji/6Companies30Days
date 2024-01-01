#include <iostream>
#include <climits>

using namespace std;

bool check(int num, int divisor, int uniqueCnt, const int Arr[]) {
    for (int i = 0; i < uniqueCnt; i++) {
        if (Arr[i] % divisor == 0 || Arr[i] >= num) {
            return false;
        }
    }
    return true;
}

int Min_Max(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
    int low = 1;
    int high = INT_MAX;


    int arr1[100];
    int arr2[100];


    for (int i = 0; i < uniqueCnt1; i++) {
        arr1[i] = i + 1;
    }

    for (int i = 0; i < uniqueCnt2; i++) {
        arr2[i] = i + uniqueCnt1 + 1; // Start from a value greater than uniqueCnt1
    }

    while (low < high) {
        int mid = low + (high - low) / 2;
        if (check(mid, divisor1, uniqueCnt1, arr1) && check(mid, divisor2, uniqueCnt2, arr2)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return low;
}

int main() {
    int divisor1 = 2;
    int divisor2 = 7;
    int uniqueCnt1 = 1;
    int uniqueCnt2 = 3;

    int result = Min_Max(divisor1, divisor2, uniqueCnt1, uniqueCnt2);
    cout << "Minimum Possible Maximum Integer: " << result << endl;

    return 0;
}


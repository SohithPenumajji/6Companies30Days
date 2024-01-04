#include <iostream>
#include <algorithm>

using namespace std;

string findMinNumber(const string& pattern) {
    int n = pattern.length() + 1;
    int nums[n];

    
    for (int i = 0; i < n; ++i) {
        nums[i] = i + 1;
    }

    string result;
    result += '0' + (pattern[0] == 'I');

    for (int i = 0; i < n - 1; ++i) {
        if (pattern[i] == 'I') 
        {
            result += '0' + (i + 2);
        } 
        else
        {
          reverse(nums + i, nums + i + 2);
          result += '0' + nums[i + 1];
        }
    }

    return result;
}

int main() {
    string pattern = "IDID"; // Replace with your own pattern
    string minNumber = findMinNumber(pattern);

    cout << "Minimum number for the pattern " << pattern << " is: " << minNumber << endl;

    return 0;
}


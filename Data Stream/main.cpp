#include <iostream>
#include <deque>

using namespace std;

class DataStream {
private:
    int value;
    int k;
    std::deque<int> stream;

public:
    DataStream(int val, int k_val) : value(val), k(k_val) {}

    bool consec(int num) {
        stream.push_back(num);

        if (stream.size() < k) {
            return false;
        }

        if (stream.size() > k) {
            stream.pop_front();
        }

        for (int i : stream) {
            if (i != value) {
                return false;
            }
        }

        return true;
    }
};

int main() {
   

    DataStream ds(4, 3);

    cout << "Output: [null, " << boolalpha;
    cout << ds.consec(4) << ", ";
    cout << ds.consec(4) << ", ";
    cout << ds.consec(4) << ", ";
    cout << ds.consec(3) << "]" << endl;

    return 0;
}


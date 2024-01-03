#include <iostream>

using namespace std;

struct Array
{
    int A[12];
    int a_size;
    int length;
};

int Missing(struct Array arr)
{
    int n = arr.length + 1;
    int sum_of_elements = n * (n + 1) / 2;

    int actual_sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        actual_sum += arr.A[i];
    }

    return sum_of_elements - actual_sum;
}

void Repeating(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] == arr.A[i + 1])
        {
            int j = i + 1;
            while (arr.A[j] == arr.A[i])
            {
                j++;
            }
            cout << arr.A[i] << " repeats " << j - i << " times" << endl;
            i = j - 1;
        }
    }
}

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 6, 6, 8, 9, 10, 11, 12}, 12, 12};

    cout << "Repeating element count: ";
    Repeating(arr);
    cout << "Missing element: " << Missing(arr) << endl;

    return 0;
}


#include <iostream>

using namespace std;

int main()
{
    char str[] =  "aaaabbbccc";
    for(int i=0; str[i]!='\0'; i++)
    {
        int cnt = 1;
        if(str[i] != -1)
        {
            for(int j=i+1; str[j]!='\0'; j++)
            {
                if(str[i] == str[j])
                {
                    cnt++;
                    str[j] = -1;
                    }
            }

            cout << str[i] << cnt;
        }

    }
    return 0;
}


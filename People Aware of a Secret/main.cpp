#include <iostream>

using namespace std;

const int MOD = 1000000007; // for modulo operation

int ppl_knows_secret(int n, int delay, int forget)
{

    int ppl_cnt[n+1];
    fill(ppl_cnt, ppl_cnt+n+1, 0);

    ppl_cnt[1] = 1;

    int day;
    for(day=2; day<=n; day++)
    {
        int learned_this_day = ppl_cnt[day - delay] - ppl_cnt[max(0, day - forget - 1)];
        learned_this_day = (learned_this_day % MOD) % MOD;

        ppl_cnt[day] = (ppl_cnt[day - 1] + learned_this_day) % MOD;
    }

    return ppl_cnt[n];


}

int main()
{
    int n =5;
    int delay = 2;
    int forget = 1;

    int result;
    result = ppl_knows_secret(n, delay, forget);

    cout <<"The number of people knowing the secret on this day " << n <<" is : "  << result << endl;

    return 0;
}


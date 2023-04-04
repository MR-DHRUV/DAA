#include <bits/stdc++.h>
using namespace std;

void linearCongruentialMethod(long long int Xo, long long int m, long long int a, long long int c, long long int n, long long int maxR)
{
    long long int last = Xo;

    for (int i = 1; i < n; i++)
    {
        // Follow the linear congruential method
        last = ((last * a) + c) % m;

        // to bound our ans in range [0, maxR-1]
        last = last % maxR;

        cout << last << endl;
    }
}

// Driver Code
int main()
{
    long long int Xo = 5784;  // Seed value
    long long int m = 759571; // Modulus parameter
    long long int a = 39;     // Multiplier term
    long long int c = 9747;   // Increment term

    int n = 100000;

    linearCongruentialMethod(Xo, m, a, c, n, 500000);

    return 0;
}

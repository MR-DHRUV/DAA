#include <bits/stdc++.h>
using namespace std;

/*
    The Midsquare method:
    Start with a four-digit positive integer Z0
    Compute z*z to obtain an integer with up to eight digits
    Take the middle four digits for the next four-digit number
*/

// Problem: Generated numbers tend to 0

// algo

void genRandomUsingMidSq(int n, int seed)
{
    long long int last = seed;

    for (int i = 0; i < n; i++)
    {
        // calc square
        long long int sq = last * last;

        if (sq == 0)
        {
            break;
        }

        // eval mid 4 nums
        vector<int> digits(8, 0);
        int j = 7;

        while (sq > 0)
        {
            digits[j--] = sq % 10;
            sq /= 10;
        }

        j = 2;
        last = 0;

        for (int k = 0; k < 4; k++)
        {
            last = last * 10 + digits[j++];
        }

        cout<<last<<endl;
    }
}

int main()
{   
    // disable default 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // set our properties
    #ifndef IO_FROM_FILE
    freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\input.txt","r",stdin);
    freopen("C:\\Users\\Dhruv\\OneDrive\\Documents\\CPP + DSA\\output.txt","w",stdout);
    #endif

    genRandomUsingMidSq(100000,7182);

    /*
        5811
        7677
        9363
        6657
        3156
        9603
        2176
        7349
        78
        60
        36
        12
        1
        0
    */

   // result same as documentation

    return 0;
}
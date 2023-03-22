#include <bits/stdc++.h>
using namespace std;

class MatchString
{
public:
    void operator()(string pattern, string text, int m, int n)
    {
        for (int i = 0; i <= n - m; i++)
        {

            int j;

            for (j = 0; j < m; j++)
                if (text[i + j] != pattern[j])
                    break;

            // check if we have completed the pattern or not
            if (j == m)
            {
                cout << "The pattern was found at the index: " << i << endl;
                return;
            }
        }

        cout << "No match found!" << endl;
    }
};

int main()
{
    // disable default
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

// set files as default io stream
#ifndef IO_FROM_FILE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    string text, pattern;
    cin >> text >> pattern;

    MatchString obj;

    obj(pattern, text, pattern.size(), text.size());

    return 0;
}

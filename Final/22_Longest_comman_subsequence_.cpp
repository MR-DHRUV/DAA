#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int i, int j, string &text1, string &text2, vector<vector<int>> &dp)
    {
        if (i == text1.length() || j == text2.length())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        // if match
        if (text1[i] == text2[j])
        {
            return dp[i][j] = 1 + solve(i + 1, j + 1, text1, text2, dp);
        }

        // no match: I have 2 options either i will move i or j
        int ans = solve(i + 1, j, text1, text2, dp);
        ans = max(ans, solve(i, j + 1, text1, text2, dp));

        return dp[i][j] = ans;
    }

    int solveTab(string &text1, string &text2)
    {
        vector<vector<int>> dp(2, vector<int>(text2.length() + 1, 0));

        for (int i = text1.length() - 1; i >= 0; i--)
        {
            for (int j = text2.length() - 1; j >= 0; j--)
            {
                if (text1[i] == text2[j])
                {
                    dp[0][j] = 1 + dp[1][j + 1];
                }
                else
                {
                    // no match: I have 2 options either i will move i or j
                    dp[0][j] = dp[1][j];
                    dp[0][j] = max(dp[0][j], dp[0][j + 1]);
                }
            }

            dp[1] = dp[0];
        }

        return dp[0][0];
    }

public:
    string printLCS(string text1, string text2)
    {
        vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));

        for (int i = text1.length() - 1; i >= 0; i--)
        {
            for (int j = text2.length() - 1; j >= 0; j--)
            {
                if (text1[i] == text2[j])
                {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    // no match: I have 2 options either i will move i or j
                    dp[i][j] = dp[i + 1][j];
                    dp[i][j] = max(dp[i][j], dp[i][j + 1]);
                }
            }
        }

        // Now to obtain the LCS we will reverse engineer using the dp array
        // dp[0][0] is our ans so we'll start from there
        // dp[0][0] means that the max ans is from some further dp value so move to it or from current
        /*
            "abcde" "bdgek"
            3 2 1 1 0
            3 2 1 1 0
            2 2 1 1 0
            2 2 1 1 0
            1 1 1 1 0

            here we can see that dp[0][0] is from dp[1][0] and s1[1] == s2[0] like this keep bulding string

            // if we have matching character include it in string otherwise move to i+1 ot j+1 as our ans will be from there
            // we may have multiple lcs but this methoda makes only one of them
        */

        string ans;
        int i = 0, j = 0;

        while (i < text1.length() && j < text2.length())
        {
            if (text1[i] == text2[j])
            {
                ans.push_back(text1[i]);
                i++;
                j++;
            }
            else
            {
                // move to dp locations
                if (dp[i + 1][j] > dp[i][j + 1])
                {
                    i++;
                }
                else
                {
                    j++;
                }
            }
        }

        return ans;
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        return solve(0, 0, text1, text2, dp);
    }
};

int main()
{
    string s1 = "abcdefghijklmnopqrstuvwxyz", s2 = "zyxwvutsrqponmlkjihgfedcba";
    Solution obj;
    cout << obj.printLCS(s1, s2);

    return 0;
}
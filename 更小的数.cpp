#include <bits/stdc++.h>
using namespace std;

vector<vector<bool> > hs;
vector<vector<bool> > dp;
string str;

bool f(int i, int j)
{
    if (i >= j)
        return false;
    if (!hs[i][j])
    {
        if (str[i] < str[j])
        {
            hs[i][j] = true;
            dp[i][j] = false;
        }
        if (str[i] > str[j])
        {
            hs[i][j] = true;
            dp[i][j] = true;
        }
        if (str[i] == str[j])
        {
            dp[i][j] = f(i + 1, j - 1);
            hs[i][j] = true;
        }
    }
    return dp[i][j];
}

int main()
{

    cin >> str;
    int n = str.size();
    hs.resize(n, vector<bool>(n, false));
    dp.resize(n, vector<bool>(n, false));
    int res = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (f(i, j))
                res++;
    cout << res;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

string pat = "sad";
string txt = "sbdsadbutsad";
int temp;

// 二维数组方法
class kmp
{
private:
    //
    string pat;
    // dp数组存放状态转移，dp[转移前状态][转移方式]=转移后状态。
    vector<vector<int>> dp;
    int s;

public:
    // dp数组只与模式串有关，所以class的构建使用pat。
    kmp(string pat)
    {
        // 初始化
        this->pat = pat;
        s = pat.size();
        dp.resize(s, vector<int>(256, 0));

        // 构建dp过程
        dp[0][pat[0]] = 1; // dp初始化
        int temp = 0;      // 影子初始化，从零开始走

        // dp从1开始走，影子去匹配目标前缀
        for (int i = 1; i < s; i++)
        {
            for (int j = 0; j < 256; j++)
                dp[i][j] = dp[temp][j]; // 回溯到上个影子变量的状态转移。
            dp[i][pat[i]] = i + 1;      // 如果匹配，则状态推进。
            temp = dp[temp][pat[i]];    // 影子同时匹配
        }
    }
    int search(string txt)
    {
        int s = pat.size();
        int n = txt.size();
        temp = 0;
        for (int i = 0; i < n; i++)
        {
            temp = dp[temp][txt[i]];
            if (temp == s)
                return i - s + 1;
        }
        return -1;
    }
};

int main()
{
    kmp test2(pat);
    cout << test2.search(txt) << endl;
}
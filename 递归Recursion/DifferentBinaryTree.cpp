/*

给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> dp;
    int f(int n)
    {
        if (dp[n] == -1)
        {
            int sum = 0;
            for (int i = 0; i < n; i++)
                sum += f(i) * f(n - 1 - i);
            dp[n] = sum;
        }
        return dp[n];
    }

public:
    int numTrees(int n)
    {
        dp.resize(n + 1, -1);
        dp[1] = 1;
        dp[0] = 1;
        f(n);
        return dp[n];
    }
};

int main()
{
    Solution test;
    cout<<test.numTrees(50);
}
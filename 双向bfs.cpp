/*

leetcode127单词接龙

字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列 beginWord -> s1 -> s2 -> ... -> sk：

每一对相邻的单词只差一个字母。
 对于 1 <= i <= k 时，每个 si 都在 wordList 中。注意， beginWord 不需要在 wordList 中。
sk == endWord
给你两个单词 beginWord 和 endWord 和一个字典 wordList ，返回 从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0 。

输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
输出：5
解释：一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。



*/

#include <bits/stdc++.h>
using namespace std;

bool isok(string s1, string s2)
{
    int n = s1.size();
    if (s2.size() != n)
        return false;
    bool f = false;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == s2[i])
            continue;
        if (!f)
            f = true;
        else
            return false;
    }
    return f;
}

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    int n = wordList.size();
    bool f1[n] = {false};
    bool f2[n] = {false};

    bool k = false;
    for (int i = 0; i < n; i++)
    {
        if (wordList[i] == beginWord)
            f1[i] = true;
        if (wordList[i] == endWord)
        {
            f2[i] = true;
            k = true;
        }
    }
    if (!k)
        return 0;

    queue<string> q1;
    q1.push(beginWord);
    queue<string> q2;
    q2.push(endWord);
    int res1 = 1;
    int res2 = 1;
    int s;
    while (!q1.empty() && !q2.empty())
    {
        s = q1.size();

        for (int i = 0; i < s; i++)
        {
            string temp = q1.front();

            // cout << res1 << " " << temp << endl;
            q1.pop();

            for (int j = 0; j < n; j++)
                if (!f1[j] && isok(temp, wordList[j]))
                {
                    q1.push(wordList[j]);
                    f1[j] = true;
                    if (f2[j])
                        return res1 + res2;
                }
        }
        res1++;
        s = q2.size();
        for (int i = 0; i < s; i++)
        {
            string temp = q2.front();

            // cout << res2 << " " << temp << endl;
            q2.pop();

            for (int j = 0; j < n; j++)
                if (!f2[j] && isok(temp, wordList[j]))
                {
                    q2.push(wordList[j]);
                    f2[j] = true;
                    if (f1[j])
                        return res1 + res2;
                }
        }
        res1++;
    }
    return 0;
}

int main()
{
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    cout << ladderLength("hit", "cog", wordList) << endl;
}
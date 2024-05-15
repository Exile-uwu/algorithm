/*

prim算法寻找最小生成树

输入 g[n][n]

输出 res

*/

#include <iostream>
using namespace std;

const int n = 8, INF = 0x3f3f3f3f;

int d[n];
bool s[n];

int g[n][n];

// prim算法
int prim(int cur) {

  int res = 0;

  // 循环n次，可以将n个点加入树
  for (int i = 1; i < n; i++) {

    // 当前点以及加入树,并刷新所有点到树的距离
    s[cur] = true;
    for (int j = 0; j < n; j++)
      d[j] = min(d[j], g[cur][j]);

    // 寻找未加入的，距离最小的点
    cur = -1;
    int temp = INF;
    for (int j = 0; j < n; j++)
      if (!s[j] && d[j] < temp) {
        temp = d[j];
        cur = j;
      }

    // 如果没找到，直接返回，说明不连通
    if (cur == -1)
      return -1;

    // res记录长度
    res += d[cur];
  }
  return res;
}

int main() {

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      g[i][j] = INF;
      d[i] = INF;
      s[i] = false;
    }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin >> g[i][j];
      if (g[i][j] == 0 && i != j)
        g[i][j] = INF;
    }

  // 表示从0开始
  int res = prim(0);
  cout << res << endl;
  return 0;
}

/*

测试样例：

0 9 3 0 0 0 0 9

9 0 8 1 4 0 0 0

3 8 0 9 0 0 0 0

0 1 9 0 3 0 0 5

0 4 0 3 0 7 0 6

0 0 0 0 7 0 5 2

0 0 0 0 0 5 0 4

9 0 0 5 6 2 4 0

*/
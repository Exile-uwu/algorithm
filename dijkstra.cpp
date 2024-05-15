/*

dijkstra算法求最短路径

输入 g[n][n]

输出 最短路径

*/

#include <iostream>
using namespace std;

const int n = 8, INF = 0x3f3f3f3f;

int d[n];
bool s[n];

int g[n][n];

// dijkstra算法
//  缺省值-1，不填就找全部的，写在d[n]中
int dijkstra(int cur, int end = -1) {

  // 起点距离设为0
  d[cur] = 0;

  for (int i = 1; i < n; i++) {

    // 将cur加入最优
    s[cur] = true;
    // 更新距离
    for (int j = 0; j < n; j++)
      d[j] = min(d[j], d[cur] + g[cur][j]);

    // 找最短距离
    int temp = INF;
    cur = end;
    for (int j = 0; j < n; j++)
      if (!s[j] && d[j] < temp) {
        temp = d[j];
        cur = j;
      }

    // 找到end或者不连通
    if (cur == end)
      return d[end];
  }
  return d[end];
}

int main() {

  // 对变量初始化
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      d[i] = INF;
      s[i] = false;
      if (g[i][j] == 0 && i != j)
        g[i][j] = INF;
    }

  // 输入
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin >> g[i][j];
      if (g[i][j] == 0 && i != j)
        g[i][j] = INF;
    }

  // 到0的最短距离
  int res = dijkstra(0, n - 1);
  cout << res;
  // cout<<res[n-1];

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
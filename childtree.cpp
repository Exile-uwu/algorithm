/*

子树大小

输入 n,m,k（节点个数、m叉树、第k个节点）

输出 子树大小

*/

#include <iostream>
using ll = long long;
using namespace std;

ll n, m, k;

// dfs法
ll dfs(ll k) {

  // 如果超出范围，返回0
  if (k > n)
    return 0;

  // res=1是本身
  int res = 1;
  // 子节点左向右遍历
  for (int i = k * m - m + 2; i <= k * m + 1; i++)
    res += dfs(i);

  return res;
}

// 子节点角标，右减左
ll childtree() {

  ll l = k, r = k;
  ll cnt = 0;

  // 左节点还在范围内时，循环。
  while (l <= n) {
    cnt += min(n, r) - l + 1;
    l = l * m - m + 2;
    r = r * m + 1;
  }

  return cnt;
}

int main() {
  cin >> n >> m >> k;
  cout << childtree() << endl;
  cout << dfs(k) << endl;
}

/*

样例：

15616 5 4

*/
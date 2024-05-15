/*


ranking 名次排序

输入 每个人的分数

输出 目标的名次

*/

#include <iostream>
using namespace std;

const int n = 8;
int s[n];
int r[n];


int ranking(int cur = -1) {

  //对任意两个都比较，低分的排名增加1
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
      if (s[i] > s[j])
        r[j]++;
      else
        r[i]++;
      
  return r[cur];
}

int main() {

  for (int i = 0; i < n; i++)
    cin >> s[i];

  int res = ranking(n - 1);
  cout << res;
  // cout<<r[n-1];

  return 0;
}

/*

测试样例：

5 7 6 8 3 1 4 9

*/
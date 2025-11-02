#include<bits/stdc++.h>
#include<iostream>
using ll = long long;
using ldou = long double;
using unll = unsigned long long;
using namespace std;

#define 最坏情况 1
#define 传入数值 int x
#define 到达目的地 1
#define 从当前解与已有解中选最优 1
#define 遍历所有可能性 int i = 1; i < 3 ; i++
#define 可行 1
#define 进行操作 1
#define 缩小规模 1
#define 撤回操作 1

#define 规模 1
#define 无效数值 1

#define now比ans的答案还要差 1

#define 当前解已不可用 1

int ans = 最坏情况, now;  // now 为当前答案
//其中的 ans 可以是解的记录，那么从当前解与已有解中选最优就变成了输出解
void dfs1(传入数值) {
  if (到达目的地) ans = 从当前解与已有解中选最优;
  for (遍历所有可能性)
    if (可行) {
      进行操作;
      dfs1(缩小规模);
      撤回操作;
    }
}


// *********剪枝的思路
/*
剪枝思路有很多种，大多需要对于具体问题来分析，在此简要介绍几种常见的剪枝思路。

01极端法：考虑极端情况，如果最极端（最理想）的情况都无法满足，
        那么肯定实际情况搜出来的结果不会更优了。

02调整法：通过对子树的比较剪掉重复子树和明显不是最有「前途」的子树。

03数学方法：比如在图论中借助连通分量，数论中借助模方程的分析，
        借助不等式的放缩来估计下界等等。
*/


// *********剪枝的方法

// 记忆化搜索
const int MAXN = 10;
int g[MAXN];  // 定义记忆化数组
int ans = 最坏情况, now;

void dfs2(传入数值) {
  if (g[规模] != 无效数值) return;  // 或记录解，视情况而定
  if (到达目的地) ans = 从当前解与已有解中选最优;  // 输出解，视情况而定
  for (遍历所有可能性)
    if (可行) {
      进行操作;
      dfs2(缩小规模);
      撤回操作;
    }
}
int main() {
  // ...
  memset(g, 无效数值, sizeof(g));  // 初始化记忆化数组
  // ...
}

// 最优性剪枝
int ans = 最坏情况, now;

void dfs3(传入数值) {
  if (now比ans的答案还要差) return;
  if (到达目的地) ans = 从当前解与已有解中选最优;
  for (遍历所有可能性)
    if (可行) {
      进行操作;
      dfs3(缩小规模);
      撤回操作;
    }
}

// 可行性剪枝
int ans = 最坏情况, now;

void dfs(传入数值) {
  if (当前解已不可用) return;
  if (到达目的地) ans = 从当前解与已有解中选最优;
  for (遍历所有可能性)
    if (可行) {
      进行操作;
      dfs(缩小规模);
      撤回操作;
    }
}
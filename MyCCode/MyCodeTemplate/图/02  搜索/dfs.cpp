#include <bits/stdc++.h>
using namespace std;

// base
class t01 
{
    /*
        DFS 最显著的特征在于其 递归调用自身。同时与 BFS 类似，
            DFS 会对其访问过的点打上访问标记，在遍历图时跳过已打过标记的点，
            以确保 每个点仅访问一次。符合以上两条规则的函数，便是广义上的 DFS。

        具体地说，DFS 大致结构如下：

        DFS(v) // v 可以是图中的一个顶点，也可以是抽象的概念，如 dp 状态等。
            在 v 上打访问标记
            for u in v 的相邻节点
                if u 没有打过访问标记 then
                    DFS(u)
    */

   /*
        该算法通常的时间复杂度为 O(n+m)，空间复杂度为 O(n)，其中 n 表示点数，m 表示边数。
   */

  /*
    在 Windows 上，通常的方法是在 编译选项 中加入 -Wl,--stack=1000000000，
        表示将栈空间限制设置为 1000000000 字节。
  */
};

// 实现方法
class t02 
{

    vector<vector<int>> adj;  // 邻接表
    vector<bool> vis;         // 记录节点是否已经遍历

    void dfs(int s) {
        stack<int> st;
        st.push(s);
        vis[s] = true;

        while (!st.empty()) 
        {
            int u = st.top(); st.pop();

            for (int v : adj[u]) 
                if (!vis[v]) {
                    vis[v] = true;  // 确保栈里没有重复元素
                    st.push(v);
                }

        }
    }

};

class t03
{
    vector<vector<int>> adj;  // 邻接表
    vector<bool> vis;         // 记录节点是否已经遍历

    void dfs(const int u) {
        vis[u] = true;
        for (int v : adj[u])
            if (!vis[v]) dfs(v);
    }
};

/*拓展
    DFS 序列
        DFS 序列是指 DFS 调用过程中访问的节点编号的序列。
        我们发现，每个子树都对应 DFS 序列中的连续一段（一段区间）。

    括号序列
        DFS 进入某个节点的时候记录一个左括号 (，退出某个节点的时候记录一个右括号 )。
        每个节点会出现两次。相邻两个节点的深度相差 1。
*/
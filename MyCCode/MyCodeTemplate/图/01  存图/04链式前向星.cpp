#include <bits/stdc++.h>
using namespace std;

class t04
{
    /*
        本质上是用链表实现的邻接表

        复杂度
            查询是否存在 u 到 v 的边：O(d+(u))。
            遍历点 u 的所有出边：O(d+(u))。
            遍历整张图：O(n+m)。
            空间复杂度：O(m)。

        应用
            存各种图都很适合，但不能快速查询一条边是否存在，也不能方便地对一个点的出边进行排序。

            优点是边是带编号的，有时会非常有用，而且如果 cnt 的初始值为奇数，存双向边时 i ^ 1 即是 i 的反边（常用于 网络流）。
    */
public:
    int n, m;
    vector<bool> vis;
    vector<int> head, nxt, to;

    void add(int u, int v) {
    nxt.push_back(head[u]);
    head[u] = to.size();
    to.push_back(v);
    }

    bool find_edge(int u, int v) {
    for (int i = head[u]; ~i; i = nxt[i]) {  // ~i 表示 i != -1
        if (to[i] == v) {
        return true;
        }
    }
    return false;
    }

    void dfs(int u) {
    if (vis[u]) return;
    vis[u] = true;
    for (int i = head[u]; ~i; i = nxt[i]) dfs(to[i]);
    }

    int main() {
    cin >> n >> m;

    vis.resize(n + 1, false);
    head.resize(n + 1, -1);

    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }

    return 0;
    }
};
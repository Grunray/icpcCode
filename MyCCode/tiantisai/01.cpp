#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;

using ll = long long;
using unll = unsigned long long;

const int N = 1e5 + 10;

int n, m;

vector<int> adj[N];

map<int, int> big;
int sq[1500][150];


int in[N];

int topo() {
    vector<int> L;
    queue<int> q;

    for(int i = 1; i <= n; i++) {
        if(in[i] == 1) q.push(i);
    }

    while(!q.empty()) {
        int u = q.front(); q.pop();
        L.push_back(u);

        for(int v : adj[u]) {
            if(--in[v] == 1) {
                q.push(v);
            }
        }
    }

    return L.size();

}

// void dfs(int u, map<int, int> now) {
    
//     if(now.count(u)) {
//         if(big.size() < now.size()) big = now;
//         // for(auto it : big) {
//         //     cout << it.first << ' ';
//         // }cout << '\n';
//         now.clear();
//         return;
//     }

//     for(int v : adj[u]) {
        
//         now[v] = 1;
//         dfs(v, now);
//         // now.erase(v);
//     }

// }

void solve() {

   cin >> n >> m;

    // 最大环和次大环
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;

        if(sq[u][v]) continue;
        in[u]++;
        in[v]++;
        sq[u][v] = sq[v][u] = 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int x = topo();



    // for(int i = 1; i <= n; i++) {
    //     // now.clear();
    //     dfs(i, {});
    //     //if(!big.count(i)) big[i] = 1;
    // }

    if(x == n) x = 0;

    cout << n - x << ' ' << n - x * 2 << '\n';

}

signed main() {

    int T = 1;
    cin >> T;

    while(T--) {
        solve();
    }


    return 0;
}
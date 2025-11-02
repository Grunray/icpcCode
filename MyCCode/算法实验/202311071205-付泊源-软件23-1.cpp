#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>

#define look_time cout << (clock() - Time) * 1.0 / CLOCKS_PER_SEC << '\n'

using namespace std;


class TraceLog
{
public:
};
TraceLog logging;

class MinCostShorestPath {
private:
    int n;
private:
    vector<vector<int> > adj;
private:
    const int INF = 0x3f3f3f;
public:
    int MinOutSum;
private:
    int resCost;
private:
    vector<int> resPath;
    vector<int> minOutOfNode;

private:
    struct NODE
    {
        int now;
        int nowCost;
        int otherCost;
        int minCost;
        vector<int> nowPath;
        // map<int, int> has;

        bool operator < (const NODE& node) const {
            return minCost > node.minCost;
        }
    };
    


public:
    MinCostShorestPath(int n, vector<vector<int> > adj) 
        : n(n), adj(adj)
    {
        for(int i = 0; i < n; i++)
            adj[i][i] = INF;
        // for(int i = 1; i<= n; i++) {
        //     for(int j = 1; j <= n; j++) {
        //         cout << adj[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }

        minOutOfNode.resize(n, INF);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                minOutOfNode[i] = min(minOutOfNode[i], adj[i][j]);
            }
        }

        for(int i = 0; i < n; i++) {
            MinOutSum += minOutOfNode[i];
        }
        // cout << '\n';
    }


public:
    void bfs(NODE st) {
        priority_queue<NODE> pq;
        pq.push(st);

        resCost = INF;

        while(!pq.empty()) {
            auto now = pq.top(); pq.pop();

            if(now.minCost >= resCost) 
                continue;
            
            if(now.now == n - 1) {
                // cout << now.now << ' ' << n << '\n';1
                int last = adj[now.nowPath.back()][0];
                if(last != INF) {
                    int tempCost = now.nowCost + last;
                    if (resCost > tempCost) {
                        resCost = tempCost;
    
                        resPath = now.nowPath;
                    }
                }
                continue;
            }

            for(int i = 0; i < n; i++) {
                
                if(find(now.nowPath.begin(), now.nowPath.end(), i) != now.nowPath.end()) continue;
                if(adj[now.nowPath.back()][i] == INF)
                    continue;

                NODE temp;
                temp.now = now.now + 1;
                temp.nowCost = now.nowCost + adj[now.nowPath.back()][i];
                temp.otherCost = now.otherCost - minOutOfNode[now.nowPath.back()];
                temp.minCost = temp.nowCost + temp.otherCost;
                temp.nowPath = now.nowPath;
                temp.nowPath.push_back(i);

                if(temp.minCost < resCost) {
                    pq.emplace(temp);
                }
                


            }

        }
        

        
    }


public:
    void resPrint() {

        if(resCost == INF) {
            cout << "Error : 图不联通！！！" << '\n';
            return;
        }
        
        cout << "最优路径为：";
        for(const int &x : resPath)
            cout << x + 1 << " -> ";
        cout << (*resPath.begin()) + 1 << '\n';

        cout << "最小花费为：" << resCost << '\n';
    }



};


void solve() {


    int n; cin >> n;

    vector<vector<int> > adj(n + 1, vector<int>(n + 1));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> adj[i][j];

    MinCostShorestPath mcsp(n, adj);

    mcsp.bfs({0, 0, mcsp.MinOutSum, mcsp.MinOutSum, {0}});

    mcsp.resPrint();

    
}


signed main()
{
    // freopen("wrt.in", "r", stdin);
	// freopen("out.out", "w", stdout);

	signed T = 1;
    // cin >> T;
	while (T--) {
		solve();
	}

    return 0;
}
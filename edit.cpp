#include <bits/stdc++.h>
#define DEB2(x, y) cout << "#x: " << x << " " \
                        << " #y: " << y << endl;
#define DEB(x) cout << "#x: " << x << endl;
#define DEBFL(x, n)                    \
    for (int i = 0; i < x.size(); i++) \
        cout << x[i] << " ";           \
    cout << endl;
#define fo(i, n) for (int i = 0; i < n; i++)
#define MOD (int)(1e9 + 7)
typedef long long int llt;

using namespace std;

vector<int> minimumTime(int n, vector<vector<int>> &edges, vector<int> &disappear)
{
    // adjacency list rep of the graph O(n+e)
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < edges.size(); i++)
    {
        g[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        g[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }

    vector<bool> vis(n, false);
    vector<int> dist(n, INT_MAX);
    // min heap, where pair entry is {distance, node}.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 0});
    // O(nlog(e))
    while (!pq.empty())
    {
        pair<int, int> distNodePair = pq.top();
        pq.pop();
        int node = distNodePair.second;
        int distance = distNodePair.first;
        if (!vis[node])
        {
            vis[node] = true;
            dist[node] = distance;
            for (int i = 0; i < g[node].size(); i++)
            {
                if (!vis[g[node][i].first] && dist[node] + g[node][i].second < disappear[g[node][i].first])
                {
                    pq.push({dist[node] + g[node][i].second, g[node][i].first});
                }
            }
        }
    }

    // left over vertices which are not visited, dist to be marked -1
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dist[i] = -1;
        }
    }
    return dist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 3;
    vector<vector<int>> edges{{0, 1, 2}, {1, 2, 1}, {0, 2, 4}};
    vector<int> dissapear{1, 2, 5};
    vector<int> res = minimumTime(n, edges, dissapear);
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
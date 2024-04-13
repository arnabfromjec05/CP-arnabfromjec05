#include <bits/stdc++.h>
typedef long long int llt;

using namespace std;

/**
 * Minimum time to reach any vertex v from 0th vertex.
 * Using Dijkstra's shortest path algo.
 */
vector<int> minimumTime(int n, vector<vector<int>> &edges)
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
                if (!vis[g[node][i].first])
                {
                    pq.push({dist[node] + g[node][i].second, g[node][i].first});
                }
            }
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
    vector<int> res = minimumTime(n, edges);
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
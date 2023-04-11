#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, m;
vector<pair<int, int>> adj[105];
int dist[105];

vector<int> get_min_cost_houses()
{
    memset(dist, -1, sizeof(dist));

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
        dist[i] = 0;
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (pair<int, int> v : adj[u])
        {
            if (dist[v.first] == -1 || dist[v.first] > dist[u] + v.second)
            {
                dist[v.first] = dist[u] + v.second;
                q.push(v.first);
            }
        }
    }

    int min_dist = INF;
    vector<int> min_houses;

    for (int i = 1; i <= n; i++) {
        if (dist[i] != -1)
         {
            if (dist[i] < min_dist)
            {
                min_dist = dist[i];
                min_houses = {i};
            }
            else if (dist[i] == min_dist)
            {
                min_houses.push_back(i);
            }
        }
    }

    return min_houses;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> min_cost_houses = get_min_cost_houses();

    cout << "Houses with minimum cost: ";
    for (int house : min_cost_houses)
    {
        cout << house << " ";
    }
    cout << endl;

    return 0;
}

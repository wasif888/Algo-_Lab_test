#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    int len = graph.size();
    vector<int> colors(len, 0);
    for (int i = 0; i < len; i++)
    {
        if (colors[i] == 1 || colors[i] == -1)
        {
            continue;
        }
        queue<int> que;
        que.push(i);
        colors[i] = 1;
        while (!que.empty())
        {
            int cur = que.front();
            que.pop();
            for (int next : graph[cur])
            {
                if (colors[next] == 0) {
                    colors[next] = -colors[cur];
                    que.push(next);
                }
                if (colors[next] == colors[cur]) return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool is_bipartite = isBipartite(graph);

    if (is_bipartite) {
        cout << "Yes, the graph is bipartite.\n";
    } else {
        cout << "No, the graph is not bipartite.\n";
    }

    return 0;
}

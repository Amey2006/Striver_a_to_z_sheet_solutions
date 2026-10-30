class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> g(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            g[u].emplace_back(v, w);
        }

        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(k + 1, INF));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        dist[0][1] = 0;
        pq.emplace(0, 0, 1);

        while (!pq.empty()) {
            auto [d, u, cur] = pq.top();
            pq.pop();

            if (u == n - 1) {
                return d;
            }

            if (d > dist[u][cur]) {
                continue;
            }

            for (auto& [v, w] : g[u]) {
                int nxt = (labels[v] != labels[u]) ? 1 : cur + 1;
                int nd = d + w;

                if (nxt <= k && nd < dist[v][nxt]) {
                    dist[v][nxt] = nd;
                    pq.emplace(nd, v, nxt);
                }
            }
        }

        return -1; 
    }
};
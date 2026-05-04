#include <queue>
#include <list>

typedef std::pair<int, int> pii;

std::vector<int>
dijkstra(int V, int start, const std::vector<std::list<pii>> &adj)
{
    std::vector<int> dist(V, 1e9);
    dist[start] = 0;

    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

/*
Для достижения сложности O((V+E)logV) используем std::priority_queue. Она позволяет быстро извлекать вершину с
минимальным весом.
*/

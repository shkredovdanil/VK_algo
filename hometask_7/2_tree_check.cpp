#include <vector>
#include <list>

bool
isTree(int V, const std::vector<std::pair<int, int>> &edges)
{
    if (edges.size() != V - 1) {
        return false;
    }

    std::vector<std::list<int>> adj(V);
    for (auto &edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    std::vector<bool> visited(V, false);
    auto dfs = [&](auto &self, int v) -> void {
        visited[v] = true;
        for (int n : adj[v]) {
            if (!visited[n]) {
                self(self, n);
            }
        }
    };

    dfs(dfs, 0);
    for (bool v : visited) {
        if (!v) {
            return false;
        }
    }

    return true;
}

/*
Граф считается деревом, если он связный и не содержит циклов. В неориентированном графе с V вершинами это эквивалентно
проверке отсутствия циклов и наличию ровно V−1 ребер.
*/

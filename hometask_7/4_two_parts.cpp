#include <vector>
#include <list>
#include <queue>

bool
isBipartite(int V, const std::vector<std::list<int>> &adj)
{
    std::vector<int> color(V, -1);

    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            std::queue<int> q;
            q.push(i);
            color[i] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

/*
Используем алгоритм покраски в два цвета (0 и 1). Если при обходе сосед вершины уже покрашен в тот же цвет, граф не
может быть двудольным.
*/

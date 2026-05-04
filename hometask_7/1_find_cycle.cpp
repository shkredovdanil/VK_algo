#include <vector>
#include <list>

class Graph
{
    int V;
    std::vector<std::list<int>> adj;

    bool
    hasCycleUtil(int v, std::vector<bool> &visited, std::vector<bool> &recStack)
    {
        visited[v] = true;
        recStack[v] = true;

        for (int neighbor : adj[v]) {
            if (!visited[neighbor] && hasCycleUtil(neighbor, visited, recStack)) {
                return true;
            } else if (recStack[neighbor]) {
                return true;
            }
        }

        recStack[v] = false;
        return false;
    }

  public:
    Graph(int V) : V(V), adj(V) {}
    void
    addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    bool
    hasCycle()
    {
        std::vector<bool> visited(V, false);
        std::vector<bool> recStack(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i] && hasCycleUtil(i, visited, recStack)) {
                return true;
            }
        }
        return false;
    }
};

/*
Для обнаружения цикла в ориентированном графе мы используем массив recStack. Если в процессе обхода мы
натыкаемся на вершину, которая уже проходили, значит, мы нашли цикл.
*/

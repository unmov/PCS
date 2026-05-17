#include "graph.hpp"
#include <queue>
#include <stack>
#include <map>

//CONTENITORE FIFO
class fifo {
private:
    std::queue<int> q;
public:
    fifo() = default;
    void put(int val) { q.push(val); }
    int get() { int val = q.front(); q.pop(); return val; }
    bool empty() const { return q.empty(); }
};

//CONTENITORE LIFO
class lifo {
private:
    std::stack<int> s;
public:
    lifo() = default;
    void put(int val) { s.push(val); }
    int get() { int val = s.top(); s.pop(); return val; }
    bool empty() const { return s.empty(); }
};

template <typename Container>
unidirected_graph graph_visit(const unidirected_graph& G, int source, Container& c) {
    unidirected_graph tree;
    std::set<int> visited;
    std::map<int, int> parent;

    c.put(source);

    while (!c.empty()) {
        int u = c.get();

        
        if (visited.find(u) == visited.end()) {
            visited.insert(u);

            
            if (u != source && parent.find(u) != parent.end()) {
                tree.add_edge(unidirected_edge(parent[u], u));
            }

          
            for (int v : G.neighours(u)) {
                if (visited.find(v) == visited.end()) {
                    c.put(v);
                    parent[v] = u; 
                }
            }
        } 
	}
    return tree;
}

void dfs_helper(const unidirected_graph& G, int u, std::set<int>& visited, unidirected_graph& tree) {
    visited.insert(u);
    for (int v : G.neighours(u)) {
        if (visited.find(v) == visited.end()) {
            tree.add_edge(unidirected_edge(u, v));
            dfs_helper(G, v, visited, tree);
        }
    }
}

unidirected_graph recursive_dfs(const unidirected_graph& G, int source) {
    unidirected_graph tree;
    std::set<int> visited;
    dfs_helper(G, source, visited, tree);
    return tree;
}

//DIJKSTRA
unidirected_graph dijkstra(const unidirected_graph& G, int source) {
    unidirected_graph tree;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    
    std::map<int, int> dist;
    std::map<int, int> parent;
    std::set<int> visited;
	
    for (int n : G.all_nodes()) {
        dist[n] = 1e9; 
    }

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited.find(u) != visited.end()) continue;
        visited.insert(u);

        if (u != source && parent.find(u) != parent.end()) {
            tree.add_edge(unidirected_edge(parent[u], u));
        }

        for (int v : G.neighours(u)) {
            int weight = 1; 
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    return tree;
}
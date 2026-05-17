#include <iostream>
#include <string>
#include "graph.hpp"
#include "algoritmi.hpp"

// Funzione per stampare i grafi in formato DOT per GraphViz
void print_dot(const unidirected_graph& G, const std::string& name) {
    std::cout << "graph " << name << " {\n";
    for (const auto& e : G.all_edges()) {
        std::cout << "    " << e.from() << " -- " << e.to() << ";\n";
    }
    std::cout << "}\n\n";
}

int main() {
    unidirected_graph G;
    G.add_edge(unidirected_edge(1, 2));
    G.add_edge(unidirected_edge(1, 3));
    G.add_edge(unidirected_edge(2, 4));
    G.add_edge(unidirected_edge(3, 4));
    G.add_edge(unidirected_edge(4, 5));
    G.add_edge(unidirected_edge(3, 6));

    std::cout << "\nGRAFO ORIGINALE\n";
    print_dot(G, "G");

    // Test BFS
    fifo q;
    unidirected_graph bfs_tree = graph_visit(G, 1, q);
    std::cout << "\nALBERO BFS\n";
    print_dot(bfs_tree, "BFS");

    // Test DFS (Iterativa)
    lifo s;
    unidirected_graph dfs_iterative_tree = graph_visit(G, 1, s);
    std::cout << "\nALBERO DFS (Iterativa LIFO)\n";
    print_dot(dfs_iterative_tree, "DFS_Iter");

    // Test DFS (Ricorsiva)
    unidirected_graph dfs_recursive_tree = recursive_dfs(G, 1);
    std::cout << "\nALBERO DFS (Ricorsiva)\n";
    print_dot(dfs_recursive_tree, "DFS_Rec");

    // Test Dijkstra
    unidirected_graph dijkstra_tree = dijkstra(G, 1);
    std::cout << "\nALBERO DIJKSTRA\n";
    print_dot(dijkstra_tree, "Dijkstra");

    return 0;
}
#include <iostream>
#include "graph.hpp"

int main() {

    //Test della classe unidirected_edge
    unidirected_edge e1(10, 5); 
    unidirected_edge e2(5, 10);
    unidirected_edge e3(5, 20);

    std::cout << "Arco e1 (costruito come 10,5): " << e1 << "\n";
    std::cout << "Arco e2 (costruito come 5,10): " << e2 << "\n";
    std::cout << "e1 == e2? " << (e1 == e2 ? "Si" : "No") << " (Atteso: Si)\n";
    std::cout << "e1 < e3? " << (e1 < e3 ? "Si" : "No") << " (Atteso: Si)\n";

    //Test della classe unidirected_graph
    unidirected_graph g1;
    g1.add_edge(e1);
    g1.add_edge(e3); 
    g1.add_edge(unidirected_edge(10, 20)); 

    std::cout << "\nGRAFO g1\n";
    std::cout << "Nodi presenti: ";
    for (int n : g1.all_nodes()) std::cout << n << " ";
    std::cout << "\nArchi presenti: ";
    for (const auto& edge : g1.all_edges()) std::cout << edge << " ";
    std::cout << "\n";

    //Test costruttore di copia
    unidirected_graph g_copy(g1);
    std::cout << "\nCOPIA DEL GRAFO\n";
    std::cout << "Archi nella copia: ";
    for (const auto& edge : g_copy.all_edges()) std::cout << edge << " ";
    std::cout << "\n";

    //Test neighours()
    std::cout << "\nVicini del nodo 5 in g1: ";
    for (int v : g1.neighours(5)) std::cout << v << " ";
    std::cout << "\n";

    //Test numerazione archi (edge_number e edge_at)
    int id = g1.edge_number(e1);
    std::cout << "\nL'arco " << e1 << " ha ID: " << id << "\n";
    std::cout << "L'arco all'ID " << id << " e': " << g1.edge_at(id) << "\n";

    //Test operatore differenza (G - G')
    unidirected_graph g2;
    g2.add_edge(e1);

    unidirected_graph diff = g1 - g2;
    std::cout << "\nDIFFERENZA (g1 - g2)\n";
    std::cout << "Archi in diff: ";
    for (const auto& edge : diff.all_edges()) std::cout << edge << " ";
    std::cout << " (Atteso: {5,20} e {10,20})\n";

    return 0;
}
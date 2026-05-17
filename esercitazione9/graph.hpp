#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

class unidirected_edge {
private:
    int _u;
    int _v;

public:
    unidirected_edge(int n1, int n2) : _u(std::min(n1, n2)), _v(std::max(n1, n2)) {}

    int from() const { return _u; } 
    int to() const { return _v; } 

    bool operator<(const unidirected_edge& other) const {
        if (_u != other._u) return _u < other._u;
        return _v < other._v;
    }

    bool operator==(const unidirected_edge& other) const { return _u == other._u && _v == other._v; }

    friend std::ostream& operator<<(std::ostream& os, const unidirected_edge& e) {
        os << "{" << e._u << ", " << e._v << "}";
        return os;
    }
};


class unidirected_graph {
private:
    std::set<int> _nodes; 
    std::vector<unidirected_edge> _edges_by_id;
    std::map<unidirected_edge, int> _id_by_edge; 
    std::map<int, std::set<int>> _adj; 

public:
    unidirected_graph() = default; 
    unidirected_graph(const unidirected_graph& other) = default; 

    std::set<int> neighours(int node) const { return _adj.at(node); } 

    void add_edge(const unidirected_edge& e) { 
        if (_id_by_edge.find(e) == _id_by_edge.end()) {
            _id_by_edge[e] = _edges_by_id.size();
            _edges_by_id.push_back(e);
            _nodes.insert(e.from());
            _nodes.insert(e.to());
            _adj[e.from()].insert(e.to());
            _adj[e.to()].insert(e.from());
        }
    }

    std::vector<unidirected_edge> all_edges() const { return _edges_by_id; } 
    std::set<int> all_nodes() const { return _nodes; } 

    int edge_number(const unidirected_edge& e) const { return _id_by_edge.at(e); }

    unidirected_edge edge_at(int number) const { return _edges_by_id[number]; }

    unidirected_graph operator-(const unidirected_graph& other) const {
        unidirected_graph diff;
        for (const auto& e : _edges_by_id) {
            if (other._id_by_edge.find(e) == other._id_by_edge.end()) {
                diff.add_edge(e);
            }
        }
        return diff;
    }
};

#endif
#pragma once

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

namespace BAKATAN {

//https://qiita.com/Nachia/items/d420c08b333296f54526
//https://github.com/atcoder/ac-library/blob/master/atcoder/internal_csr.hpp

template <typename E>
class static_graph {
    int n, m;
    std::vector<int> start;
    std::vector<E> elist;

    class static_graph_internal {
        int v; static_graph<E>* G;
        public:
        static_graph_internal(const int& i, static_graph<E>* G_) : v(i), G(G_) {}
        E operator[](const int& j) const {return G->elist[G->start[v] + j];}
        size_t size() {return size_t(G->start[v + 1] - G->start[v]);}
    };

    public:
    static_graph (const int& n_, const int& m_) : n(n_), m(m_) {}
    static_graph (const int& n_, const std::vector<std::pair<int, E>>& edges) 
        : n(n_), m(edges.size()), start(n_ + 1), elist(edges.size()) {init(edges);}
    void init(const std::vector<std::pair<int, E>>& edges) {
        for (auto e : edges) start[e.first + 1]++;
        for (int i = 1; i <= n; i++) start[i] += start[i - 1];
        auto counter = start;
        for (auto e : edges) elist[counter[e.first]++] = e.second;
    }

    static_graph_internal operator[](const int& i) {return static_graph_internal(i, this);}
    size_t size() const {return size_t(n);}

    //隣接リストとの型変換
    operator std::vector<std::vector<E>>() const {
        std::vector<std::vector<E>> G(start.size() - 1);
        for (int i = 0; i < n; i++) {
            for (int j = start[i]; j < start[i + 1]; j++) G[i].emplace_back(elist[j]);
        }
        return G;
    }
    static_graph (std::vector<std::vector<E>>& G)
        : n(G.size()), start(G.size() + 1) {
        for (int i = 0; i < n; i++) m += G[i].size();
        elist.resize(m);
        for (int i = 0; i < n; i++) {
            start[i + 1] = start[i] + G[i].size();
            for (int j = 0; j < G[i].size(); j++) elist[start[i] + j] = G[i][j];
        }
    }
};

} //namespace BAKATAN
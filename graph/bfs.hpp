#pragma once

#include <queue>
#include <vector>
#include "template/constant.hpp"

namespace BAKATAN {

std::vector<long long> bfs(const int& s, std::vector<std::vector<long long>>& G) {
    std::vector<long long> dist(G.size(), INF); dist[s] = 0;
    std::queue<int> Q; Q.push(s);
    while (!Q.empty()) {
        int pos = Q.front(); Q.pop();
        for (int i = 0; i < G[pos].size(); i++) {
            if (dist[G[pos][i]] == INF) {
                dist[G[pos][i]] = dist[pos] + 1;
                Q.push(G[pos][i]);
            }
        }
    }
    return dist;
}

} //namespace BAKATAN
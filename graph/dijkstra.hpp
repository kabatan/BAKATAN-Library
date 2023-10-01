#pragma once

#include <vector>
#include <queue>
#include <utility>
#include "template/constant.hpp"

namespace BAKATAN {

std::vector<long long> dijikstra (const int& s, 
    const std::vector<std::vector<std::pair<long long, long long>>>& G) {
    std::vector<long long> dist(G.size(), INF); dist[s] = 0;
    std::priority_queue<std::pair<long long, long long>,
        std::vector<std::pair<long long, long long>>, 
            std::greater<std::pair<long long, long long>>> Q;
    Q.push(std::make_pair(0, s));
    std::vector<bool> flag(G.size(), false);
    while (!Q.empty()) {
        int pos = Q.top().second; Q.pop();
        if (flag[pos]) continue;
        flag[pos] = true;
        for (int i = 0; i < G[pos].size(); i++) {
            if (dist[G[pos][i].first] > dist[pos] + G[pos][i].second) {
                dist[G[pos][i].first] = dist[pos] + G[pos][i].second;
                Q.push(std::make_pair(dist[G[pos][i].first], G[pos][i].first));
            }
        }
    }
    return dist;
}

} //namespace BAKATAN


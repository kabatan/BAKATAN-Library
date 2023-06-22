#include <bits/stdc++.h>
using namespace std;

#include "GitHub/BAKATAN-Library/data structure/dsu.hpp"

int main() {
    int N,Q; cin>>N>>Q;
    BAKATAN::dsu g(N);
    while (Q--) {
        int t,u,v; cin>>t>>u>>v;
        if (t==0) g.merge(u,v);
        else cout<<g.same(u,v)<<endl;
    }
}

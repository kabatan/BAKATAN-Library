#pragma once

namespace BAKATAN {

//https://qiita.com/ret2home/items/299f67e6a52390c4bcec
//まだverifyしていない

template<typename T>
struct splay_tree {
    struct node {
        T val; 
        node *l, *r;
    };
    node *root = nullptr;
    int siz = 0;

    void rightrotate(node *x) {
        node *y = x->l;
        x->l = y->r; y->r = x; 
        x = y; return;
    }
    void leftrotate(node *x) {
        node *y = x->r;
        x->r = y->l; y->l = x; 
        x = y; return;
    }
    void splay(node *x, const T& v) {
        if (root == nullptr || root->val == v) return;
        if (v < x->val) {
            splay(x->l, v); rightrotate(x); return;
        }
        else {
            splay(x->r, v); leftrotate(x); return;
        }
    }
    node* find(const T& v) {
        splay(root, v);
        if (root == nullptr || root->val != v) return nullptr;
        return root;
    }
    bool count(const T& v) {
        return find(v) == nullptr ? false : true;
    }
    void insert(node *x, const T& v) {
        if (x = nullptr) {x->val = v; x->l = x->r = nullptr;}
        if (v < x->val) insert(x->l, v);
        else insert(x->r, v);
        return;
    }
    void insert(const T& v) {
        if (!find(v)) {insert(root, v); siz++;}
    }
    void erase(node *x, const T& v) {

    }
};

} //namespace BAKATAN
#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__
//problem: directed graph with very large amount of nodes
// knowledge: only read pass by reference and new insight about vector<set<int>>(find is faster than set<pair<int,int>>)
// Your code here
#include<set>
#include<vector>
using namespace std;

class SparseGraph{
public:
    SparseGraph(): v(3){
        // Your code here
        n=3;
        
    }

    SparseGraph(int n_in):v(n_in) {
        // Your code here
        n=n_in;
        
    }

    SparseGraph(const SparseGraph& G) : v(G.v){
        // Your code here
        n=G.n;
        
    }

    void AddEdge(int a, int b) {
        // Your code here
         v[a].insert(b);

    }

    void RemoveEdge(int a, int b) {
        // Your code here
        if(v[a].find(b)!=v[a].end()) v[a].erase(b);
    }

    bool DoesEdgeExist(int a, int b) const {
        // Your code here
        
        return v[a].count(b)==1;
    }

    SparseGraph Transpose() const {
        // Your code here
        SparseGraph S(n);
        for(int i=0;i<v.size();i++){
            for(auto &x:v[i]){
                S.AddEdge(x,i);
            }
        }
        return S;
    }

protected:
    // Your code here
    long long n;
    // set<pair<long long,long long>> s; slow if n is very very large because it may be kept n*n elements so it is slow to find insert erase
    vector<set<long long>> v;
};
#endif // __SPARSE_GRAPH_H__


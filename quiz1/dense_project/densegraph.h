#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__
//problem: directed graph n nodes and G(V,E)
//solution: use set to fast find erase and cannot use map because of duplicate key
// Your code here
#include <vector>
#include<set>

using namespace std;
class DenseGraph{
public:
    DenseGraph() {
        // Your code here
        n=3;
    }

    DenseGraph(int n_in) {
        // Your code here
        n=n_in;
    }

    DenseGraph(const DenseGraph& G) {
        // Your code here
        n=G.n;
        for(auto x:G.s){
            s.insert(x);
        }
    }

    void AddEdge(int a, int b) {
        // Your code here

        if(s.find({a,b})==s.end()){
            s.insert({a,b});
        }
        
    }

    void RemoveEdge(int a, int b) {
        // Your code here
        if(s.find({a,b})!=s.end()) s.erase({a,b});
    }

    bool DoesEdgeExist(int a, int b) const {
        // Your code here
        // m.find(a) can be m.end() crash, can be shorter
        // if((*(m.find(a))).second==b){
            
        //     return true;
        
        // }else{
        //     return false;
        // }
        if(s.find({a,b})!=s.end()) return true;
        else return false;
    }

    DenseGraph Transpose() const {
        // Your code here
        DenseGraph G;
        G.n=n;
        for(auto x:s){
            G.s.insert({x.second,x.first});
        }
        return G;
        
        
    }

protected:
    int n;
    // Your code here
    set<pair<int,int>> s;
};
#endif // __DENSE_GRAPH_H__

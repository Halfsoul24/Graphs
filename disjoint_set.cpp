#include<bits/stdc++.h>
using namespace std;

vector<int> dsuj;

int find(int src){
    
    if(dsuj[src]==-1){
        return src;
    }
    return find(dsuj[src]);
}

void union(fromP, toP){
    
    fromP = find(fromP);
    
    toP = find(toP);
    
    dsuj[fromP] = toP;
}

isCycle(vector<pair<int, int>> edge_list){
    
    psir<int, int > p;
    for( p: edge_list){
        
        int fromP = find(p.first);
        int toP = find(p.second);
        
        if(fromP==toP){
            return true;
        }
        
        union(fromP,toP);
    }
    return false;
}
main(){
    int n,m;
    
    cin>>n>>m;
    
    vector<vector<int> adj(n);
    dsuj.resize(n,-1);
    
    
    vector<pair<int,int>> edge_list;
    
    for(int i=0; i<m; i++){
        
        int from, to;
        cin>>from>to;
        
        edge_list.push_back({from,to});
    }
    
    
    if(isCycle(edge_list)){
        cout<< true;
    }
    
    else{
        cout<<false;
    }
}


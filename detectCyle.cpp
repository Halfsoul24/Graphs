// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    
    bool is_cycle(int src, vector<int> adj[], vector<int> visited, vector<int> stack){
        
        // visited(src,0);
        // stack(src,0);
        
        stack[src]=true;
        vector<int>:: iterator it;
        
        if(!visited[src]){
            
            visited[src]=true;
            
            for(auto it: adj[src]){
                
                if(!visited[it] && is_cycle(it, adj, visited, stack)){
                    return true;
                }
                
                if(stack[it]){
                    return true;
                }
            }
            
           
        }
        // stack[src]=false;
        return false;
    }
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	vector<int> stack(V,0);
	   	vector<int> visited(V,0);
	   	
	   	bool cycle = false;
	   //	stack[V] = true;
	   //	cout<<stack[V]<<endl;
	   	for(int i=0; i<V; i++){
	   	    for(auto it: adj[i]){
	   	        
	   	        if(!visited[it] && is_cycle(it,adj,visited,stack)){
	   	            cycle = true;
	   	            
	   	        }
	   	    }
	   	}
	   	if(cycle) return true;
	   	return false;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends

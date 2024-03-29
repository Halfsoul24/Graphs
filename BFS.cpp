// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

int const N= 1e5+6;
int vis[N];
class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    queue<int> q;
	    vector<int> vec;
	    q.push(0);
	    for(int i=0; i<N; i++){
	        vis[i]=0;
	    }
	    vis[0]=1;
	    
	    while(!q.empty()){
	        
	        int node = q.front();
	        q.pop();
	        
	        vec.push_back(node);
	        
	        vector<int> :: iterator it;
	        for(it = adj[node].begin(); it!=adj[node].end(); it++){
	            
	            if(!vis[*it]){
	                vis[*it]=1;
	                
	                q.push(*it);
	            }
	        }
	    }
	    return vec;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    // 		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;

vector<int>best_first_search(vector<vector<int>>&vec,int vertices,int edges,int source,int dest){
  
  //Creating the Adjacency List:
  unordered_map<int,list<pair<int,int>>>adj;
  
  for(int ind=0;ind<vec.size();ind++){
    int u=vec[ind][0];
    int v=vec[ind][1];
    int cost=vec[ind][2];
    adj[u].push_back({v,cost});
    adj[v].push_back({u,cost});
  }
  
  vector<int>dist(vertices,1e9);
  vector<int>parent(vertices);
  for(int ind=0;ind<vertices;ind++){
    parent[ind]=ind;
  }
  
  
  set<pair<int,int>>st;
  dist[source]=0;
  st.insert(make_pair(0,source));
  while(!st.empty()){
    
    //Fetch the top Nodes
    auto top=*(st.begin());
    int nodeDistance=top.first;
    int topNode=top.second;
    
    //Remove the Top Node from the set
    st.erase(st.begin());
    
    for(auto neighbour:adj[topNode]){
      if(nodeDistance+neighbour.second<dist[neighbour.first]){
        
        auto record=st.find(make_pair(dist[neighbour.first],neighbour.first));
        
        if(record!=st.end()){
          //This means we found the record and then erase it 
          st.erase(record);
        }
        
        //Distance Update
        dist[neighbour.first]=nodeDistance+neighbour.second;
        st.insert(make_pair(dist[neighbour.first],neighbour.first));
        parent[neighbour.first]=topNode;
      }
      //cout<<neighbour.first<<" "<<topNode;
      
    }
    
    
  }
  
  cout<<"The Effective Cost To Reach Destination :"<<dist[dest]<<endl;
  cout<<"_______________________________________________________"<<endl;
  cout<<"Path Taken To Reach Destination :";
  
  /*for(int ind=0;ind<vertices;ind++){
    cout<<parent[ind]<<" ";
  }*/
  int node=dest;
  cout<<dest<<" ";
  while(parent[node]!=node){
    cout<<parent[node]<<" ";
    node=parent[node];
  }
  return dist;
}


int main(){
  int vertex;
  cout<<"Enter The Number of Vertex :";
  cin>>vertex;
  unordered_map<int,list<int>>adjList;
  int edges;
  cout<<"Enter The Number of Edges You Want To Enter :";
  cin>>edges;
  vector<vector<int>>vec;//This will store the edges
  for(int ind=0;ind<edges;ind++)
  {
    
    int u,v,cost;
    cout<<"Enter The Nodes between which edge to be made and Cost of that Edge:";
    cin>>u>>v>>cost;
    vector<int>edge={u,v,cost};
    vec.push_back(edge);
  }
  
  int source,dest;
  cout<<"Enter The Source And Destination: ";
  cin>>source>>dest;
  vector<int>path=best_first_search(vec,vertex,edges,source,dest);
  
  
  
  
}
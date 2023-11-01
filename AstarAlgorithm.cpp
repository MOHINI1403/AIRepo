#include <bits/stdc++.h>
using namespace std;
void AStarAlgorithm(unordered_map<char,list<pair<char,int>>>&adj,unordered_map<char,int>&heuristic,char source,char dest,unordered_map<char,int>&dist,unordered_map<char,char>&parent){
    unordered_map<char,int>pathCost;
    pathCost[source]=0;
    //unordered_map<char,char>parent;
    
    priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>>pq;
    pq.push({0,source});
    while(!pq.empty()){
        char node=pq.top().second;
        int nodeVal=pq.top().first;
        
        pq.pop();
        for(auto neighbour:adj[node]){
            char neighbourNode=neighbour.first;
            int edgeWt=neighbour.second;
            int heuristicVal=heuristic[neighbourNode];
            pq.push({pathCost[node]+edgeWt+heuristicVal,neighbourNode});
            if(pathCost[node]+heuristicVal+edgeWt<dist[neighbourNode]){
                dist[neighbourNode]=heuristicVal+edgeWt+pathCost[node];
                pathCost[neighbourNode]=pathCost[node]+edgeWt;
                //pq.push({heuristicVal+edgeWt,neighbourNode});
                parent[neighbourNode]=node;
            }
        }
    }
    cout<<"Effective cost to React Dest: "<<pathCost[dest]+heuristic[dest];
    cout<<"Desired Path Taken To Reach the Solution: ";
    cout<<dest<<" ";
    char node=dest;
    while(parent[node]!=node){
        cout<<parent[node]<<" ";
        node=parent[node];
    }
    cout<<endl;
    
    
}
int main(){
    bool choice=true;
    cout<<"The Vertex are Uppercase Characters: ";
    set<char>edgeSet;
    unordered_map<char,list<pair<char,int>>>adj;
    //Taking the edge Inputs:
    while(true){
        char u,v;
        cout<<"Enter the Starting Edge and Ending Edge: ";
        cin>>u>>v;
        int cost;
        cout<<"Enter the Cost of the Edge: ";
        cin>>cost;
        adj[u].push_back({v,cost});
        edgeSet.insert(u);
        edgeSet.insert(v);
        char opt;
        
        cout<<"Do you want to add more edges 'y' or 'n': ";
        cin>>opt;
        if(opt=='n'){
            choice=false;
            break;
        }
    }
    //Now you have to take the heuristic value for all the edges
    unordered_map<char,int>heuristic;
    unordered_map<char,int>dist;
    
    unordered_map<char,char>parent;
    for(auto it:edgeSet){
        char vertex=(it);
        int val;
        cout<<"Enter the Heuristic Value for :"<<vertex<<" ";
        cin>>val;
        heuristic[vertex]=val;
        dist[vertex]=1e9;
        parent[vertex]=vertex;
    }
    char source,dest;
    cout<<"Enter The Source And Destination Vertex: ";
    cin>>source>>dest;
    //Call for the main A* Function 
    AStarAlgorithm(adj,heuristic,source,dest,dist,parent);
    
    return 0;
}

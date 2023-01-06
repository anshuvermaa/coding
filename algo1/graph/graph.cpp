#include<bits/stdc++.h>
using namespace std;
// in graph there is no parent conccept so we have to pass starting index from where
// we want the graph should be printed 

// DFS approach -> first print smaller child -> this is recursive one
void printDFS(vector<vector<int> >v,int sv,vector<bool> &visited){
cout<<sv<<endl;
visited[sv] = true;
int n=v.size();
for(int i=0;i<n;i++){
    if(v[sv][i] && visited[i]==false){
        printDFS(v,i,visited);
    }
}
}
// print DFS will print connected as well as disconnected graph
// printDFS will print only connected graphs
void DFS(vector<vector<int> >v){
    int n=v.size();
    vector<bool> visited(n,false);
    int count=0;
    // checking which node is visited or not if not then start printing from that
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            count++;
            printDFS(v,i,visited);
        }
    }
    cout<<"Number of connected components are "<<count<<endl;

}

// BFS approach-> level order triversal

void printBFS(vector<vector<int> >v,int sv,vector<bool> &visited){
    int n=v.size();
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while(!q.empty()){
    //    cv-> current vertex
    int cv=q.front();
    q.pop();
    cout<<cv<<endl;
    for(int i=0;i<n;i++){
        if(v[cv][i] && visited[i]==false){
            q.push(i);
            visited[i]=true;
        }
    }

    
    }
}

void BFS(vector<vector<int> >v){
    int n=v.size();
    vector<bool> visited(n,false);
    // checking which node is visited or not if not then start printing from that
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            printBFS(v,i,visited);
        }
    }


}


// kruskal algo
// problem-> there are A island and there are M bridges connecting them. each bridge has some cost attacked to it
// We need to find bridges with minimum cost such that island are connected to the
// it is gauranteed that input data will contain at least one possible  scenario in which all island are connected


// here labeling start with 1 not 0
 
void makeSet(int N,int parent[]){
    for(int i=1;i<=N;i++){
        parent[i] =i;
    }
}
// find fnction return representative element for the set
int find(int i,int parent[]){
    while(parent[i]=!i){
         i==parent[i];
    }
    return i;
    
}
bool comp(vector<int>a,vector<int>b){
    return a[2]<b[2];
}

int kruskalAlgo(int N,vector<vector<int>> &edges){
    sort(edges.begin(),edges.end(),comp);   // sorting edgest on the bases of age

    int parent[N+1];
    makeSet(N,parent);
    int cost=0;
    for(int i=0;i<edges.size();i++){
        int s=edges[i][0];
        int d=edges[i][1];
        int rs=find(s,parent);
        int rd=find(d,parent);
        if(rs!=rd){
            cost+=edges[i][2];
            parent[rs]=rd;   // union
        }
         

    }
    return cost;

}




int main(){
    // matrix implitation with graph
    int n,e;
    // n-> no. of nodes, e-> no of edges
    cin>>n>>e;
    vector<vector<int>> matrix(n,vector<int>(n,0));
    for(int i=1;i<=e;i++){
        int w;
        int fv,sv;
        cin>>fv>>sv;
        cin>>w;
        matrix[fv][sv]=w;
        matrix[sv][fv]=w;
    }
    vector<bool> visited(n,false);
    cout<<"DFS"<<endl;
    DFS(matrix);     // DFS
    cout<<"BFS"<<endl;
    BFS(matrix);     // BFS
    cout<<"kuskal alo"<<endl;
    
    cout<<kruskalAlgo(5,matrix);

    return 0;
}
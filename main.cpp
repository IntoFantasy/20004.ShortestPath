#include <iostream>
#include<queue>
#include<climits>
using namespace std;
const int MAX=1e7;

int n,m,s,t,cnt;
int dist[MAX];
struct edge{
    int to;
    int weight;
    int next;
}edges[MAX];
int head[MAX];
void add_edge(int u, int v, int w){
    edges[cnt].to=v;
    edges[cnt].weight=w;
    edges[cnt].next=head[u];
    head[u]=cnt++;
}
void init(){
    for(int i=0;i<=n;++i) head[i]=-1;
    for(int i=0;i<=n;++i) dist[i]=INT_MAX;
    cnt=0;
}

int main() {
    cin>>n>>m>>s>>t;
    init();
    int u,v,w;
    for(int i=0;i<m;++i){
        cin>>u>>v>>w;
        add_edge(u,v,w);
        add_edge(v,u,w);
    }
    deque<int> bfs;
    dist[s]=0;
    bfs.push_back(s);
    while(!bfs.empty()){
        int temp=bfs.front();
        bfs.pop_front();
        for(int i=head[temp];i!=-1;i=edges[i].next){
            if(dist[edges[i].to]>dist[temp]+edges[i].weight) {
                dist[edges[i].to] = dist[temp] + edges[i].weight;
                if (edges[i].weight == 0)
                    bfs.push_front(edges[i].to);
                else
                    bfs.push_back(edges[i].to);
            }
        }
    }
    cout<<dist[t];
}

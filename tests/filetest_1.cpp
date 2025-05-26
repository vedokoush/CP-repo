#include<bits/stdc++.h>
#define ll long long
#define task ""
using namespace std;
const ll N=1e6+11;
ll vis[N],n,m,par[N],s,t,dist1[N],dist2[N],par2[N],vis2[N],meet=0,res=-1,check=0;
vector<ll> a[N],b,c;
void trace1(ll u,ll p)
{
    b.push_back(u);
    if(u==p) return;
    trace1(par[u],p);
}
void trace2(ll u,ll p)
{
    c.push_back(u);
    if(u==p) return;
    trace2(par2[u],p);
}
void bfs1(ll s){
    queue<ll> q;
    q.push(s);
    vis[s]=1;
    dist1[s]=0;
    while(!q.empty()){
        ll u=q.front();
        q.pop();
        for(auto v:a[u]){
            if(!vis[v]){
                par[v]=u;
                dist1[v]=dist1[u]+1;
                vis[v]=1;
                q.push(v);
            }
        }
    }
}
void bfs2(ll s){
    queue<ll> q;
    q.push(s);
    vis2[s]=1;
    dist2[s]=0;
    while(!q.empty()){
        ll u=q.front();
        q.pop();
        for(auto v:a[u]){
            if(!vis2[v]){
                par2[v]=u;
                dist2[v]=dist2[u]+1;
                vis2[v]=1;
                q.push(v);
            }
        }
    }
}
void solve(){
    cin>>n>>m;
    for(ll i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        a[u].push_back(v);
    }
    for(ll i=1;i<=n;i++){
        sort(a[i].begin(),a[i].end());
    }
    memset(dist1,-1,sizeof dist1);
    memset(dist2,-1,sizeof dist2);
    bfs1(1);
    bfs2(n);
    for(ll i=1;i<=n;i++){
        if(dist1[i]==dist2[i]&&vis[i]&&vis2[i]){
            if(res==-1||dist1[i]<res){
                res=dist1[i];
                meet=i;
            }
        }
    }
    if(res==-1){
        cout<<-1;
        return;
    }
    trace1(meet,1);
    reverse(b.begin(),b.end());
    cout<<res<<endl;
    for(auto x: b) cout<<x<<" ";
    cout<<endl;
    trace2(meet,n);
    reverse(c.begin(),c.end());
    for(auto x:c) cout<<x<<" ";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
}


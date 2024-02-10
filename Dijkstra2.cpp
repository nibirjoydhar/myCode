#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 200010;

ll n,ar[N],br[N],x[N];
vector<pair<ll,ll>>g[N];

void Dijkstra()
{
    typedef long long ll;
    const ll INF = 1e18 + 10;

    ll source = 1,destination=n; // Let source = 1

    vector<bool> vis(N, false);
    vector<ll> dis(N, INF);
    vector<ll> p(N, -1);//for path


    set<pair<ll, ll>> st;

    st.insert({0, source}); // distance of source 1 is 0
    dis[source] = 0;
    while (st.size() > 0)
    {
        auto pr = *st.begin();
        ll cur = pr.second;
        ll curw = pr.first;

        st.erase(st.begin());
        if (vis[cur])
            continue;
        vis[cur] = true;
        
        for (auto child : g[cur])
        {
            ll cnode = child.first;
            ll cw = child.second;
            if (curw + cw < dis[cnode])
            {
                dis[cnode] = curw + cw;
                st.insert({curw + cw, cnode});
                p[cnode]=cur;//for path
            }
        }
    }

    //path resort from source to destination
    vector<int> path;
    for (int v = destination; v != source; v = p[v])
        path.push_back(v);
    path.push_back(source);
    reverse(path.begin(), path.end());


    //print distance
    for(int i=1;i<=n;i++){
        cout<<"Distance from "<<source<<" to "<<i<<" is "<<dis[i]<<endl;
    }
    cout<<"Path : ";
    for(auto p:path){
        cout<<p<<' ';
    }cout<<endl;
    cout<<dis[n]<<endl;

}      
void Solve(){
    static int cs=1;
    //cout<<"Case "<<cs++<<": ";
    ll a, b, sum=0, cnt=0, ans=0;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>ar[i]>>br[i]>>x[i];
        g[i].push_back({i+1,ar[i]});
        g[i].push_back({x[i],br[i]});

    }
    Dijkstra();
   
}
            
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int tc=1;
    //cin >> tc;
    while(tc--){
        Solve();
    }
    return 0;
}
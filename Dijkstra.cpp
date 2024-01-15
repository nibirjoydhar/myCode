#include <bits/stdc++.h>
using namespace std;

void Dijkstra()
{
    typedef long long ll;
    const int N = 1e5 + 10;
    const int INF = 1e9 + 10;

    ll n, m; // node and edge
    vector<pair<ll, ll>> g[N];

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int w, x, y;
        cin >> x >> y >> w;
        g[x].push_back({y, w});
        g[y].push_back({x, w}); // comment this line in case of directed graph
    }
    vector<ll> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
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


    //print
    for(int i=1;i<=n;i++){
        cout<<"Distance from "<<source<<" to "<<i<<" is "<<dis[i]<<endl;
    }
    cout<<"Path : ";
    for(auto p:path){
        cout<<p<<' ';
    }cout<<endl;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    while (t--)
        Dijkstra();
    return 0;
}

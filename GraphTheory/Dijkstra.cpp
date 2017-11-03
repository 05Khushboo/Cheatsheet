//correct
void Dijkstra(int n)
{
  // distance array : dist, visited array : vis, 
  // graph : graph, set : pq
  set<pair<ll,ll> > pq;
  for(int i = 0;i<=n;i++) dist[i] = 1E9, vis[i] = 0;
  dist[1] = 0; 
  pq.insert({0,1});
  while(!pq.empty())
  {
    pair<int,int> p = *pq.begin();
    pq.erase(pq.begin());
    int u = p.second;
    if(vis[u]) continue;
    vis[u] = 1;
    for(auto k : graph[u])
    {
      if(dist[k.first]>(dist[u]+k.second))
      {
        dist[k.first] = dist[u] + k.second;
        pq.insert({dist[k.first],k.first});
      }
    }
  }
//   for(int i = 2;i<=n;i++) cout<<dist[i]<<" ";
}


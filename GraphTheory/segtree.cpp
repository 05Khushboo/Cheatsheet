// tree array : tree, Array : arr
void build(int k, int st, int en)
{
  //correct
  if(st==en) tree[k] = arr[k];
  else
  {
    int mid = (st+en)/2;
    build(2*k+1,st,mid);
    build(2*k+2,mid+1,en);
    tree[k] = tree[2*k+1] + tree[2*k+2];
  }
}
void update(int k, int st, int en, int idx, int value)
{
  // correct
  if(st>en||st>idx||en<idx) return ;
  if(st==en&&st==idx) tree[k] = value;
  else
  {
    int mid = (st+en)/2;
    update(2*k+1,st,mid,idx,value);
    update(2*k+2,mid+1,en,idx,value);
  }
}
int query(int k, int st, int en, int L, int R)
{
  // correct
  if(st>en||L>R||L>en||st>R) return -1;
  if(st==L&&en==R) return tree[k];
  int mid = (st+en)/2;
  if(R<=mid) return query(2*k+1,st,mid,L,R);
  if(L>mid) return query(2*k+2,mid+1,en,L,R);
  int ans = query(2*k+1,st,mid,L,mid) + query(2*k+2,mid+1,en,mid+1,R);
  return ans;
}
void updaterange(int k, int st, int en, int L, int R, int diff)
{
  // incomplete and incorrect
  if(st>en||L>R||L>en||st>R) return ;
  if(st==L&&en==R) tree[k]+=diff;
  else
  {
    int mid = (st+en)/2;
    if(R<=mid) updaterange(2*k+1,st,mid,L,R,diff);
    else if(L>mid) updaterange(2*k+2,mid+1,en,L,R,diff);
    else
    {
      update(2*k+1,st,mid,L,mid,diff);
      update(2*k+2,mid+1,en,mid+1,R);
    }
  }
}

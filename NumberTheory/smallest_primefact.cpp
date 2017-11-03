//correct
map<int,int> pfact_spf(int n)
{
  vector<int>sprime = smallest_prime_factors(n);
  map<int,int>smallest_pfact_freq;
  while(n>1)
  {
    smallest_pfact_freq[sprime[n]]+=1;
    n=n/sprime[n];
  }
 return smallest_pfact_freq;
}
vector<int> smallest_fact(int n)
{
  vector<int>smallest_fac(n+1);
  for(int i=1;i<=n;i++)
    smallest_fac[i] = i;
  for(int i=2;i<=n;i++)
  {
    if(smallest_fac[i]==i)
    {
      for(int j=i;j<=n;j+=i)
      {
        if(smallest_fac[j]>i)
          smallest_fac[j]=i;
      }
    }
  }
  return smallest_fac;
}






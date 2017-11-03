//correct
vector<int> fact(int n)
{
  vector<int>facts;
  for(int i=1;i<=sqrt(n);i++)
  {
    if(n%i==0)
    {
      facts.push_back(i);
      if(i!=n/i)
        facts.push_back(n/i);
    }
   return facts;
}

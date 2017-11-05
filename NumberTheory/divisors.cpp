//correct
vector<int> get_divisors(int n)
{
  // requires: sqrt
  vector<int>divisors;
  for(int i=1;i<=sqrt(n);i++)
  {
    if(n%i==0)
    {
      divisors.push_back(i);
      if(i!=n/i)
        divisors.push_back(n/i);
    }
   return divisors;
}

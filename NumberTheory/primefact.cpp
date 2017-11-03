//correct
vector<int> pfact_unique(int n)
{
  vector<int>primes = sieve_of_erathothesis(n);
 vector<int>pfacts;
 for(int prime:primes)
 {
   if(n%prime==0)
     pfacts.push_back(prime);
 }
 return pfacts;
}



















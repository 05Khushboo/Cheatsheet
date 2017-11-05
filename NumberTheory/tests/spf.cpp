#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;

vector<int> smallest_prime_factors;

map<int, int> get_prime_factors_freq(int n){
  map<int, int> prime_factors_freq;
  while(n > 1){
    prime_factors_freq[smallest_prime_factors[n]]+=1;
    n=n/smallest_prime_factors[n];
  }
 return prime_factors_freq;
}

vector<int> get_smallest_prime_factors(int n) {
  vector<int>smallest_prime_factors(n+1);
  for(int i=1;i<=n;i++)
    smallest_prime_factors[i] = i;
  for(int i=2;i<=n;i++) {
    if(smallest_prime_factors[i]==i) {
      for(int j=i;j<=n;j+=i) {
        if(smallest_prime_factors[j]>i)
          smallest_prime_factors[j]=i;
      }
    }
  }
  return smallest_prime_factors;
}

int main(void){
  smallest_prime_factors = get_smallest_prime_factors(1e6); // use it outside the function, just once
  int t, n;
  cin >> t;
  while(t--){
    cin >> n;
    map<int, int> prime_factors_freq = get_prime_factors_freq(n);
    for(pair<int, int> cPair: prime_factors_freq){
      cout << cPair.first << " " << cPair.second << endl;
    }
  }
}

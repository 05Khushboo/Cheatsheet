const long long MOD = 1e9 + 7;
const long long P = 29;

long long pow_mod(long long a, long long b){
  if(b == 0) return 1;
  if(b == 1) return a % MOD;
  if(b%2)
    return a * pow_mod(a, b-1) % MOD;
  long long x = pow_mod(a, b/2);
  return x*x % MOD;
}

long long get_hash(string a){
  // takes a string
  // returns a integer value representing its hash
  long long power = a.length()-1;
  long long hash = 0;
  for(long long i = 0; i < a.length(); i++){
    hash = (hash + (a[i]-'a'+1)*pow_mod(P, power)) % MOD;
    power--;
  }
  return hash;
}

vector<long long> rabin_karp(string pat, string txt){
  // takes a pattern and a text string
  // returns a vector of indices where pattern occurs
  vector<long long> inds;
  if(pat.length() > txt.length()) return inds;
  long long hash = get_hash(txt.substr(0, pat.length()));
  long long pat_hash = get_hash(pat);
  if(hash == pat_hash) inds.push_back(0);
  long long power = pat.length() - 1;
  for(long long i = pat.length(); i < txt.length(); i++){
    long long tod = (txt[i-pat.length()] - 'a' + 1) * pow_mod(P, power) % MOD;
    hash = (hash - tod + MOD ) % MOD;
    hash = hash * P % MOD;
    hash = (hash + (txt[i]-'a'+1)) % MOD;
    if(hash == pat_hash) inds.push_back(i-pat.length());
  }
  return inds;
}

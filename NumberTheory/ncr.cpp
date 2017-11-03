//correct
void ncr(int n,int r, int mod)
{
  // function : inv_modulus, factorial array : fact
  int val =  (long long)fact[n] * inv_modulus(fact[n-r],mod) % mod;
  val = (long long) val * inv_modulus(fact[r],mod) % mod;
  return val;
}

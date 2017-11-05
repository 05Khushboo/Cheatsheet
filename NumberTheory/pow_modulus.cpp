// correct
int power(int x, int y, int mod)
{
  // verified
    int res = 1;    
    x = x % mod;
    while (y > 0) {
        if (y & 1) res = (long long)res*x % mod;
        y = y>>1; 
        x = (long long)x*x % mod;
    }
    return res;
}
int inv_modulus(int x, int mod)
{
  return power(x,mod-2,mod);
}

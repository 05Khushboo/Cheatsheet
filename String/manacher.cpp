const int N = 1e5+1;
char str[N], nstr[2*N];

// n is length of str
int longest_palidromic_substring(int n){ // correct
  for(int i = 0; i <= 2*n; i++) nstr[i] = (i%2) ? str[i/2] : '#';
  n = strlen(nstr);
  int P[n];
  int C = 0, R = -1, rad;
  for(int i = 0; i < n; i++){
    if(i <= R) rad = R-i < P[2*C-i] ? R-i : P[2*C-i];
    else rad = 0;
    while(i+rad < n && i-rad >= 0 && nstr[i+rad] == nstr[i-rad]) rad++;
    P[i] = rad;
    if(i+rad-1 > R)  C = i, R = i+rad-1;
  }
  int max_res = 1;
  for(int i = 0; i < n; i++)
    if(P[i]-1 > max_res)
      max_res = P[i]-1;
  return max_res;
}

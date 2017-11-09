//correct
string longest_palindrome_substring(string s)
{
  string t = "#";
  for(int i = 0;i<s.size();i++) t.push_back(s[i]), t.push_back('#');
  int n = t.size(); 
  int p[n];
  int C = 0, R = 0;
  int maxradius = 0, centerindex = 1;
  for(int i  = 1;i<(n-1);i++)
  {
    p[i] = (R>i) ? min(p[2*C-i],R - i) : 0;
    while((i + 1 + p[i])<n && (i-1-p[i]) >= 0 &&t[i+ 1 + p[i]] == t[i - 1 - p[i]]) p[i]++;
    if((i+ p[i] )> R)
    {
      C = i;
      R = i + p[i];
    }
    if(p[i]>maxradius)
    {
      maxradius = p[i];
      centerindex = i;
    }
  }
  int Rightboundary = centerindex + maxradius;
  int Leftboundary = centerindex - maxradius;
  Leftboundary = t[Leftboundary]!='#' ? Leftboundary : Leftboundary + 1;
  string ans = "";
  for(int i = Leftboundary;i<n && i<=Rightboundary;i+=2) ans+=t[i];
  return ans;
}



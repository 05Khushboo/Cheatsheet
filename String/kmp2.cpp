vector<int> computelps(string str){
  int l = str.length();
  int i=1, j=0;
 vector<int> lps(l);
  lps[0] = 0;
  while(i<l){
    if(str[i] == str[j])
      lps[i++] = ++j;
    else{
      if(j>0) j = lps[j-1];
      else{
        lps[i++] = 0;
      }
    }
  }
  return lps;
}

vector<int>calc_index(string pat,string text){
  vector<int>index;
  string str = pat + '!' + text;
  int l = str.length();
  vector<int> lps = computelps(str);
  for(int i=0;i<l;i++){
    if(lps[i]==pat.length())
      index.push_back(i-2*k);
  }
 return index; 
}

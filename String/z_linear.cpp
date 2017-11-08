vector<int> z_array(string pat){
  int l = 0, r = 0;
  vector<int> z(pat.length(), 0);
  for(int i = 1; i < pat.length(); i++){
    if(i > r){
      l = r = i;
      while(r < pat.length() && pat[r-l] == pat[r]) r++;
      z[i] = r-- - l;
    }else{
      int k = i - l;
      if(z[k] < r-i+1) z[i] = z[k];
      else{
        l = i;
        while(r < pat.length() && pat[r-l] == pat[r]) r++;
        z[i] = r-- - l;
      }
    }
  }
  return z;
}

vector<int> z_linear(string pat, string txt){
  string concat = pat + "$" + txt;
  vector<int> z_vec = z_array(concat);
  vector<int> inds;
  for(int i = 0; i < z_vec.size(); i++){
    if(z_vec[i] == pat.length()){
      inds.push_back(i-pat.length()-1);
    }
  }
  return inds;
}


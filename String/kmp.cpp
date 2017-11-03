//correct
void computeLPSArray(string pat,int *lps)
{
	int len = 0;
	lps[0] = 0; 
	int i = 1, M = pat.size();
	while (i < M) {
		if (pat[i] == pat[len]) lps[i++] = ++len;
		else {
			if (len != 0) len = lps[len-1];
			else lps[i++] = 0;
		}
	}
}
vector<int> KMPsearch(string pat, string txt)
{
	int M = pat.size();
	int N = txt.size();
	int lps[M];
	vector<int> indexes;
	computeLPSArray(pat, M, lps);
	int i = 0;  // index for txt[]
	int j  = 0;  // index for pat[]
	while (i < N) {
		if (pat[j] == txt[i]) j++, i++;
		if (j == M) {
			indexes.push_back((i-j));
			j = lps[j-1];
		}
		else if (i < N && pat[j] != txt[i]) {
			if (j != 0) j = lps[j-1];
			else i = i+1;
		}
	}
}

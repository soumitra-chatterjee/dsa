class Solution{
    const int MOD = 1e9 + 7;
  public:

    int countSubseq(string &s) 
    {
        int len = s.length();
        long long int na = 0, nb = 0, nc = 0;
        
		for(int i = 0; i < len; i++) {
            if(s[i] == 'a') {
                na = (2*na + 1) % MOD;
            }
            else if(s[i] == 'b') {
                nb = (2*nb + na) % MOD;
            }
            else {
                nc = (2*nc + nb) % MOD;
            }
        }
        return nc;
    }
};

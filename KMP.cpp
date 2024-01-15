//LeetCode solution https://leetcode.com/contest/weekly-contest-380/problems/find-beautiful-indices-in-the-given-array-ii/
class Solution {
public:
    #define pb push_back
    #define ll long long
    
    void computeLPSArray(string pat, int M, int* lps)
    {
        // length of the previous longest prefix suffix
        int len = 0;

        lps[0] = 0; // lps[0] is always 0

        // the loop calculates lps[i] for i = 1 to M-1
        int i = 1;
        while (i < M) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else // (pat[i] != pat[len])
            {
                // This is tricky. Consider the example.
                // AAACAAAA and i = 7. The idea is similar
                // to search step.
                if (len != 0) {
                    len = lps[len - 1];

                    // Also, note that we do not increment
                    // i here
                }
                else // if (len == 0)
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    vector<ll> KMPSearch(string pat, string txt)
    {
        vector<ll>v;
        int M = pat.size();
        int N = txt.size();

        // create lps[] that will hold the longest prefix suffix
        // values for pattern
        int lps[M];

        // Preprocess the pattern (calculate lps[] array)
        computeLPSArray(pat, M, lps);

        int i = 0; // index for txt[]
        int j = 0; // index for pat[]
        while ((N - i) >= (M - j)) {
            if (pat[j] == txt[i]) {
                j++;
                i++;
            }

            if (j == M) {
                v.pb(i-j);
                j = lps[j - 1];
            }

            // mismatch after j matches
            else if (i < N && pat[j] != txt[i]) {
                // Do not match lps[0..lps[j-1]] characters,
                // they will match anyway
                if (j != 0)
                    j = lps[j - 1];
                else
                    i = i + 1;
            }
        }
        return v;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<ll>ap,bp;
        // kmp vill return a vector of matching index
        ap=KMPSearch(a,s);
        bp=KMPSearch(b,s);

   
        vector<int>ans;
        for(ll i=0;i<ap.size();i++){
            ll r=lower_bound(bp.begin(),bp.end(),ap[i])-bp.begin();
            ll dif=1e9;
            if(r!=bp.size()){
                dif=abs(ap[i]-bp[r]);
            }
            if(r!=0){
                dif=min(dif,abs(ap[i]-bp[(r-1)]));
            }
            if(dif<=k)
                ans.pb(ap[i]);
        }
        return ans;
    }
};
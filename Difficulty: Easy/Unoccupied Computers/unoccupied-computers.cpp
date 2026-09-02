class Solution {
  public:
    int solve(int n, string s) {
        // code here
        int m=s.size();
        int cnt=0;
        unordered_map<char,int> mpp;
        set<char> st;
        for(int i=0;i<m;i++)
        {
            if(mpp.find(s[i])!=mpp.end())
            {
                 mpp[s[i]]--;
                 if(mpp[s[i]]==0) mpp.erase(s[i]);
            }
            else 
            {
                if(mpp.size()<n)
                {
                if(st.find(s[i])==st.end()) mpp[s[i]]++;
                }
                else
                {
                    st.insert(s[i]);
                }
            }
        }
        return st.size();

    }
};
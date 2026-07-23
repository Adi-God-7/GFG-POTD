class Solution {
  public:
    bool canRepresentBST(vector<int> &arr) {
        stack<int> st;
        int lb=-1;
        
        for(int val:arr){
            if(val<lb){
                return false;
            }
            
            while(!st.empty() && val>st.top()){
                lb=st.top();
                st.pop();
            }
            st.push(val);
        }
        return true;
    }
};
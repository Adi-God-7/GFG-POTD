class Solution {
public:
    vector<vector<int>> levelSort(vector<int>& arr) {

        vector<vector<int>> ans;

        int n=arr.size();
        int idx=0;
        int ls=1;

        while(idx<n){
            vector<int> level;

            for (int i=0;i<ls && idx<n;i++){
                level.push_back(arr[idx++]);
            }

            sort(level.begin(),level.end());

            ans.push_back(level);

            ls*= 2;
        }

        return ans;
    }
};
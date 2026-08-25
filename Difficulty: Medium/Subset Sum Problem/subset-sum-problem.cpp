class Solution {
  public:
    bool isSubsetRec(vector<int>& arr,int n, int sum) {
        // code here
        int t[n+1][sum+1];
        if(sum==0) return true;
        
        if(n==0) return false;
        
        if(arr[n-1]<=sum){
            return isSubsetRec(arr,n-1,sum-arr[n-1]) || isSubsetRec(arr,n-1,sum);
        }
        else{
            return isSubsetRec(arr,n-1,sum);
        }
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        return isSubsetRec(arr, arr.size(), sum);
    }
};
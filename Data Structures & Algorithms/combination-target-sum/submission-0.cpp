class Solution {
private:
    void findCombination(int indx,int tar,vector<int>& arr,vector<int>& ds,vector<vector<int>>& ans){
        if(indx == arr.size()){
            if(tar==0){
                ans.push_back(ds);
            }
            return;
        }
        if(arr[indx]<=tar){
            ds.push_back(arr[indx]);
            findCombination(indx,tar-arr[indx],arr,ds,ans);
            ds.pop_back();
        }

        findCombination(indx+1,tar,arr,ds,ans);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0,target,nums,ds,ans);
        return ans;
    }
};

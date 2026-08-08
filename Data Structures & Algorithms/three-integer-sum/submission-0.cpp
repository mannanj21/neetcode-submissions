class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>> ans;

        for(int i = 0; i < n; i++){
            int l = i + 1;
            int r = n - 1;
            int first = nums[i];
            while(l < r){
                int sum = first;
                sum += nums[l] + nums[r];
                if(sum == 0){
                    ans.insert({first, nums[l], nums[r]});
                    l++;
                    r--;
                    while(l < r && nums[l] == nums[l-1]) l++;
                    while(l < r && nums[r] == nums[r+1]) r--;
                }
                else if(sum > 0){
                    r--;
                    while(l < r && nums[r] == nums[r+1]) r--;
                } else{
                    l++;
                    while(l < r && nums[l] == nums[l-1]) l++;
                }
            }
        }

        vector<vector<int>> res;
        for(auto& st : ans){
            res.push_back(st);
        }

        return res;
    }
};

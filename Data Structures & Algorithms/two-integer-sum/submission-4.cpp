class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // int n = nums.size();
        // for (int i = 0; i < n-1; i++){
        //     for(int j = i+1; j < n; j++){
        //         if (nums[i] + nums[j] == target){
        //             return vector<int>{i, j};
        //         }
        //     }
        // }

        std:map<int, int> hashMap;
        std::vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            if (hashMap.find(diff) != hashMap.end()){
                result.push_back(hashMap[diff]);
                result.push_back(i);
                sort(result.begin(), result.end());
                return result;
            } else {
                hashMap[nums[i]] = i;
            }
        }
        return std::vector<int>{-1, -1};
    }
};

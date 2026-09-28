class Solution {
public:

    std::vector<int> usingSortedVectorPair(std::vector<int>& nums, int k){
        std::unordered_map<int, int> hashMap;
        for(auto& x : nums){
            hashMap[x]++;
        }

        std::vector<pair<int, int>> frequencyPair;
        for(auto& keyValue : hashMap){
            frequencyPair.push_back({keyValue.first, keyValue.second});
        }

        std::sort(frequencyPair.begin(), frequencyPair.end(), [](const auto& a, const auto& b) {
        return a.second > b.second; });

        std::vector<int> result;
        for(int i = 0; i < k; i++){
            result.push_back(frequencyPair[i].first);
        }

        return result;
    }

    std::vector<int> usingBucketSort(std::vector<int>& nums, int k){
        unordered_map<int, int> count;
        for(int num: nums){
            count[num]++;
        }

        vector<vector<int>> freq(nums.size() + 1);

        for(const auto& entry : count){
            freq[entry.second].push_back(entry.first);
        }

        vector<int> result;
        for(int i = freq.size() - 1; i > 0; i--){
            for(int n : freq[i]){
                result.push_back(n);
                if (result.size() == k){
                    return result;
                }
            }
        }

        return result;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        //return usingSortedVectorPair(nums, k);
        return usingBucketSort(nums, k);
    }
};

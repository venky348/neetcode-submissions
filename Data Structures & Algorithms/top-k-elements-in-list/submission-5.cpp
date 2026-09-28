class Solution {
public:

    vector<int> usingSortedVectorPair(std::vector<int>& nums, int k){
        std::unordered_map<int, int> hashMap;
        for(auto& x : nums){
            hashMap[x]++;
        }

        std::vector<pair<int, int>> frequencyPair;
        for(auto& keyValue : hashMap){
            frequencyPair.push_back({keyValue.first, keyValue.second});
        }

        std::sort(frequencyPair.begin(), frequencyPair.end(), [](const auto& a, const auto& b) {
        return a.second > b.second; // Ascending order
    });

        std::vector<int> result;
        for(int i = 0; i < k; i++){
            result.push_back(frequencyPair[i].first);
        }

        return result;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        return usingSortedVectorPair(nums, k);
    }
};

#include <set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> uniqueNumbers;
        for(const int& num : nums){
            if (uniqueNumbers.find(num) == uniqueNumbers.end()){
                uniqueNumbers.insert(num);
            } else {
                return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    bool isAnagram(std::string s1, std::string s2){
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }

    std::vector<std::vector<std::string>> bruteForceApproach(std::vector<std::string>& strs) {
        int n = strs.size();
        std::vector<bool> visited(n, false);
        std::vector<std::vector<std::string>> result;

        for(int i = 0; i < n; i++) {
            std::vector<std::string> currentAnagrams;
            if (!visited[i])
                currentAnagrams.push_back(strs[i]);
            visited[i] = true;
            for (int j = i+1; j < n; j++){
                if (i!=j && !visited[j] && isAnagram(strs[i], strs[j])){
                    visited[j] = true;
                    currentAnagrams.push_back(strs[j]);
                }
            }
            if (!currentAnagrams.empty())
                result.push_back(currentAnagrams);
        }

        return result;
    }

    std::vector<std::vector<std::string>> betterApproach(std::vector<std::string>& strs){
        std::vector<std::pair<std::string, std::string>> strsCopy;
        for(auto str : strs){
            std::string s1 = str;
            sort(s1.begin(), s1.end());
            std::string s2 = str;
            strsCopy.push_back({s1, s2});
        }
        
        std::map<std::string, std::vector<std::string>> hashMap;
        for(auto strPair : strsCopy){
            std::string s1 = strPair.first;
            std::string s2 = strPair.second;
                hashMap[s1].push_back(s2);
        }

        std::vector<std::vector<std::string>> result;
        for(auto mapPair : hashMap){
            std::vector<std::string> temp = mapPair.second;
            sort(temp.begin(), temp.end());
            result.push_back(temp);
        }

        return result;
    }

    std::array<int, 26> getFrequencyCount(std::string str){
        std::array<int, 26> frequencyCount{};
        for(auto character : str){
            frequencyCount[int(character - 'a')]++;
        }
        return frequencyCount;
    }

    std::vector<std::vector<std::string>> optimisedApproach(std::vector<std::string>& strs){
        std::map<std::array<int, 26>, std::vector<std::string>> hashMap;
        for(auto str : strs){
            hashMap[getFrequencyCount(str)].push_back(str);
        }

        std::vector<std::vector<std::string>> result;

        for(auto currentKeyValue : hashMap){
            std::vector<std::string> temp = currentKeyValue.second;
            sort(temp.begin(), temp.end());
            result.push_back(temp);
        }
        
        return result;

    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //return bruteForceApproach(strs);
        //return betterApproach(strs);
        return optimisedApproach(strs);
    }
};

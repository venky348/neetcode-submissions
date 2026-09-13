class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()){
            return false;
        }

        int freqCount[26] = {0};
        for(auto alphabet : s){
            freqCount[int(alphabet - 'a')]++;
        }

        for(auto alphabet : t){
            freqCount[int(alphabet - 'a')]--;
        }

        for (auto count : freqCount){
            if (count != 0)
                return false;
        }

        return true;
    }
};

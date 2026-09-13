class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        } else {
            std::array<int, 26> frequencyCount{};

            for(const char& character : s) {
                frequencyCount[int(character - 'a')]++;
            }

            for(const char& character : t) {
                frequencyCount[int(character - 'a')]--;
            }

            for(const int& count : frequencyCount) {
                if (count != 0) {
                    return false;
                }
            }

            return true;
        }
    }
};

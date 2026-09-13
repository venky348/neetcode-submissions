class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())\
            return false;
        else {
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());

            int sizeOfAnagram = s.length();

            for(int i = 0; i < sizeOfAnagram; i++){
                if (s[i] != t[i])
                    return false;
            }

            return true;
        }
    }
};

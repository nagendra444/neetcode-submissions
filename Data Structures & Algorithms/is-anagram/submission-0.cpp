class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> map;
        for(auto ch:s){
            map[ch]++;
        }
        for(auto ch:t){
            if(map.find(ch) == map.end()) return false;
            if(map[ch]==0) return false;
            map[ch]--;
        }
        return true;
    }
};

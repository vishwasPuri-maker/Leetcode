class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<int> se;
        for(int i=0 ; i<s.size() ; i++){
            if(se.find(s[i]) != se.end() ){
                return s[i];
            }
            else{
                se.insert(s[i]);
            }
        }
        return ' ';
    }
};
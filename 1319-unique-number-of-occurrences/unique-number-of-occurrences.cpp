class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> map;

        for(int i=0 ; i<arr.size() ; i++){
            map[arr[i]]++;
        }

        unordered_set<int> s;
        for(auto x : map){
            if(s.count(x.second)){
                return false;
            }
            s.insert(x.second);
        }
        return true;
    }
};
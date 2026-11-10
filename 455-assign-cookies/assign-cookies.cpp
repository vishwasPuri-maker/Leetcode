class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0 ;
        int gl = 0;
        int sl = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(gl<g.size() && sl<s.size()){
            if(s[sl]>=g[gl]){
                count++;
                gl++;
                sl++;
            }
            else{
                sl++;
            }
        }
        return count;
    }
};
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int srow = 0;
        int scol = 0 ;
        int endrow = m-1;
        int endcol = n-1;
        vector<int> ans;

        while(srow<=endrow && scol<=endcol){
            for(int j = scol ; j<=endcol ; j++){
                ans.push_back(mat[srow][j]);
            }

            for(int i = srow+1 ; i<=endrow ; i++){
                ans.push_back(mat[i][endcol]);
            }

            for(int j = endcol-1 ; j>=scol ; j--){
                if(srow == endrow){
                    break;
                }
                ans.push_back(mat[endrow][j]);
            }

            for(int i = endrow-1 ; i>=srow+1 ; i--){
                if(scol == endcol){
                    break;
                }
                ans.push_back(mat[i][scol]);
            }
            srow++;
            endrow--;
            scol++;
            endcol--;
        }
        return ans;
    }
};
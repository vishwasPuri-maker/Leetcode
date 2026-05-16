class Solution {
public:
    int leveles(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+max(leveles(root->left),leveles(root->right));
    }
    void nthLevel(TreeNode* root, int curr , int level, vector<int>& v){
        if(root==NULL){
            return;
        }
        if(curr==level){
            v.push_back(root->val);
            // cout<<endl;
        }
        nthLevel(root->left,curr+1,level,v);
        nthLevel(root->right,curr+1,level,v);
    }
    void lOrder(TreeNode* root,vector<vector<int>>& ans){
        int n=leveles(root);
        for(int i=1;i<=n;i++){
            vector<int> v;  // Here we are pushing the value to the vector 
            nthLevel(root,1,i,v);
            ans.push_back(v);   // Here we are pushing vector to the another vector which we return in answer according to question 
            cout<<endl;
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        lOrder(root,ans);
        return ans;
    }
};
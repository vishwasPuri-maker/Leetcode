class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> childs;

        for(auto &d : descriptions){
            int parent = d[0];
            int child = d[1];
            int isLeft = d[2];

            if(mp.find(parent) == mp.end())
                mp[parent] = new TreeNode(parent);

            if(mp.find(child) == mp.end())
                mp[child] = new TreeNode(child);

            if(isLeft)
                mp[parent]->left = mp[child];
            else
                mp[parent]->right = mp[child];

            childs.insert(child);
        }

        for(auto &d : descriptions){
            int parent = d[0];

            if(childs.find(parent) == childs.end()){
                return mp[parent];
            }
        }

        return nullptr;   
    }
};
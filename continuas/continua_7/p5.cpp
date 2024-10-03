struct TreeNode{
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
}

class Solution {
public:

    TreeNode* insert(TreeNode* node, val){
        if(node == nullptr) return new TreeNode(val);
        if(node->val < val) node->right = insert(node->right, val);
        else node->left = insert(node->left,val);
    }
    int numOfWays(vector<int>& nums) {
        const long long mod = 1e9+7;
        long long comb[1005][1005];
        for(int i=0;i<1001;i++){
            for(int j=0;j<=i;j++){
                if(i==0){
                    comb[i][j] = 1;
                    continue;
                }
                if(j==0 | j==i){
                    comb[i][j] = 1;
                    continue;
                }

                comb[i][j] = (comb[i-1][j-1] + comb[i-1][j])%mod;
            }
        }

        root = new TreeNode();

        
        return 0;
    }
};

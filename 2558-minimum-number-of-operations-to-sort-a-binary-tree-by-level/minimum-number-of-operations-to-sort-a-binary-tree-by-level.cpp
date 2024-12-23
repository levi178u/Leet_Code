/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int swaps(vector<int > &t){

        map< int ,int > mp;

        int n=t.size();

        int ops=0 , c=0;

        vector< int > a;

        for(auto &i : t){
            

            mp[i]=c;

            a.push_back(i);
            c++;

            
        }

        sort(a.begin(), a.end());

        for(int i=0;i<n ;i++){

            if(t[i] != a[i]){
               t[ mp[a[i]] ] = t[i];
                mp[t[i]] = mp[a[i]];

                mp[a[i]] = i;

                t[i] = a[i];

                ops++;
            }
        }

        return ops;
    }


    int minimumOperations(TreeNode* root) {
        
        int ans=0;

        queue< TreeNode*> q;
        q.push(root);

        while(! q.empty()){

            int n=q.size();

            vector<int > temp;

            while(n--){

                TreeNode * node = q.front();
                temp.push_back(node-> val);
                q.pop();

                if(node->left != 0){
                    q.push(node->left);
                }

                if(node->right != 0){
                    q.push(node->right);
                }
            }
            // for(auto &i : temp){

            //     cout<<i<<" ";
            // }

            ans += swaps(temp);
        }

        return ans;
    }
};
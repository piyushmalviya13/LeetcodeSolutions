/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void postorder(TreeNode* root, vector <int> &post) {
        if(root == NULL) {
            return;
        }
        if(root->left) postorder(root->left, post);
        if(root->right) postorder(root->right, post);
        post.push_back(root->val);
        return;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector <int> post;
        postorder(root, post);
        string ans = "";
        
        for(auto i:post) {
            ans += to_string(i);
            ans += ',';
        }
        //cout<<ans.substr(0, ans.size()-1);
        return ans.substr(0, ans.size()-1);
    }
    
    TreeNode* createTree(vector <int>post) {
        if(post.size() == 0) return NULL;
        
        int n = post.size();
        
        TreeNode* newNode = new TreeNode(post[n-1]);
        
        vector <int> one, two;
        
        for(int i = 0;i<n-1;i++) {
            if(post[i] < post[n-1]) {
                one.push_back(post[i]);
            }
            else {
                two.push_back(post[i]);
            }
        }
        
        newNode->left = createTree(one);
        newNode->right = createTree(two);
        
        return newNode;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector <int> post;
        //cout<<data<<"\n";
        int n = data.size();
        int x = 0;
        int i = 0;
        
        while(i != n) {
            if(data[i] == ',') {
                post.push_back(x);
                i++;
                x = 0;
                continue;
            }
            else if(i == n-1) {
                x = x*10 + (data[i] - '0');
                post.push_back(x);
                i++;
                break;
            }
            x = x*10 + (data[i] - '0');
            i++;
        }
        
        // for(auto j:post) {
        //     cout<<j<<" ";
        // }
        
        TreeNode *root = createTree(post);
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	public:
		vector<int> inorderTraversal(TreeNode *root) {

			vector<int> result;

			if ( !root)
				return result;

			stack<TreeNode *> st;

			TreeNode * temp = root;

			while ( !st.empty() || temp) {

				if (temp) {
					st.push(temp);
					temp = temp->left;
				}
				else {    
					temp = st.top();
					st.pop();
					result.push_back(temp->val);

					temp = temp->right;
				}

												            }
								            
								            return result;
									        }
};

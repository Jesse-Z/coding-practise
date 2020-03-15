/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-14 
*/
#include<bits/stdc++.h>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Codec {
public:
    // split string for seperator c
    void SplitString(const string& s, vector<string>& v, const string& c) {
        string::size_type pos1, pos2;
        pos2 = s.find(c);
        pos1 = 0;
        while(std::string::npos != pos2) {
            v.push_back(s.substr(pos1, pos2-pos1));
            pos1 = pos2 + c.size();
            pos2 = s.find(c, pos1);
        }
        if(pos1 != s.length()) {
            v.push_back(s.substr(pos1));
        }
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        deque<TreeNode*> q;
        string code;
        // code+='[';
        q.emplace_back(root);
        while(!q.empty()){
            TreeNode *curr = q.front();
            q.pop_front();
            if(curr){
                code+=to_string(curr->val);
                code+=' ';
                q.emplace_back(curr->left);
                q.emplace_back(curr->right);
            }
            else
                code+="null ";
        }
        code.erase(code.end()-1);
        // code+=']';
        // cout<<code<<endl;
        return code;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> stack;
        string sep=" ";
        SplitString(data, stack, sep);
        if(stack[0] == "null")
            return nullptr;
        TreeNode *root = new TreeNode(stoi(stack[0]));
        int i = 1;
        vector<TreeNode*> parents={root};
        vector<TreeNode*> children;
        while (i < stack.size()){
            if(!children.empty()){
                parents = children;
                children.clear();
            }
            for(auto parent : parents){
                if(i < stack.size() and stack[i]!="null"){
                    parent->left = new TreeNode(stoi(stack[i]));
                    children.emplace_back(parent->left);
                }
                ++i;
                if(i < stack.size() and stack[i]!="null"){
                    parent->right = new TreeNode(stoi(stack[i]));
                    children.emplace_back(parent->right);
                }
                ++i;
            }
        }
        return root;
    }
};
int main(){
    
    return 0;
}


// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
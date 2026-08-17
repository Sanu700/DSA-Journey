class Codec {
public:

    // Serialize: Tree → String
    void serializeHelper(TreeNode* root, string& s) {

        if(!root) {
            s += "#,";
            return;
        }

        s += to_string(root->val) + ",";

        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    string serialize(TreeNode* root) {

        string s;
        serializeHelper(root, s);

        return s;
    }


    // Deserialize: String → Tree
    TreeNode* deserializeHelper(vector<string>& nodes, int& index) {

        if(nodes[index] == "#") {
            index++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(nodes[index]));
        index++;

        root->left = deserializeHelper(nodes, index);
        root->right = deserializeHelper(nodes, index);

        return root;
    }

    vector<string> split(string s) {

        vector<string> nodes;
        string temp;

        for(char c : s) {

            if(c == ',') {
                nodes.push_back(temp);
                temp = "";
            }
            else {
                temp += c;
            }
        }

        return nodes;
    }


    TreeNode* deserialize(string data) {

        vector<string> nodes = split(data);

        int index = 0;

        return deserializeHelper(nodes, index);
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////
// good implementation with class instead of vector
////////////////
// Time Complexity: O(n*2000), n is num of calls
// Space Complexity: O(n*2000)
///////////////////////////////////////////////////////////////////////////////////////////////
namespace my{
    class TreeNode{
        private:
            bool end;
            vector<TreeNode*> child;
        public:
            TreeNode(){
                this->end = false;
                child.resize(26,NULL);
            }

            void setEnd(){
                this->end = true;
            }

            void setNode(char ch){
                child[ch-'a'] = new TreeNode();
            }

            bool isEnd(){
                return this->end;
            }

            bool isNode(char ch){
                return child[ch-'a'] != NULL;
            }

            TreeNode* getNode(char ch){
                return child[ch-'a'];
            }
    };
}

class Trie {
private:
    my::TreeNode* root;
public:
    Trie() {
        root = new my::TreeNode();
    }
    
    void insert(string word) {
        my::TreeNode* p = root;
        for(int i = 0; i < word.size(); i++){
            char ch = word[i];
            if(p->isNode(ch)){
                p = p->getNode(ch);
            }else{
                p->setNode(ch);
                p = p->getNode(ch);
            }
        }
        p->setEnd();
    }
    
    bool search(string word) {
        my::TreeNode* p = root;
        for(int i = 0; i < word.size(); i++){
            char ch = word[i];
            if(p->isNode(ch)){
                p = p->getNode(ch);
            }else{
                return false;
            }
        }
        return p->isEnd();
    }
    
    bool startsWith(string prefix) {
        my::TreeNode* p = root;
        for(int i = 0; i < prefix.size(); i++){
            char ch = prefix[i];
            if(p->isNode(ch)){
                p = p->getNode(ch);
            }else{
                return false;
            }
        }
        return true;
    }
};
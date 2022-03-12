///////////////////////////////////////////////////////////////////////////////////////////////
// not hard but a little bit tedious
////////////////
// Time Complexity: O(n^2)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        vector<Node*> v;
        vector<int> nex_idx;
        Node *i = head;
        while (i){
            Node* n = new Node(i->val);
            if (v.size()) v[v.size()-1]->next = n;
            v.push_back(n);
            Node* random = i->random;
            int num = 0;
            while (random){
                random = random->next;
                num++;
            }
            nex_idx.push_back(num);
            i = i->next;
        }
        v[v.size()-1]->next = NULL;
        for (int i=0 ; i<v.size() ; i++){
            if (nex_idx[i]){
                Node *idx = v[i];
                v[i]->random = v[v.size()-nex_idx[i]];
            }else{
                v[i]->random = NULL;
            }
        }
        return v[0];
    }
};
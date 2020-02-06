class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>hash_map;
        Node *original = head,*clone = NULL;
        
        while(original != NULL){
            Node* temp = new Node(original->val);
            hash_map[original] = temp;
            original = original->next;
        }
        
        original = head;
        while(original != NULL){
            hash_map[original]->next = hash_map[original->next];
            hash_map[original]->random = hash_map[original->random];
            original=original->next;
        }
        clone = hash_map[head];
        return clone;
    }
};
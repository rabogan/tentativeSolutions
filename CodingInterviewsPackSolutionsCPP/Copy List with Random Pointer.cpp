class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* result = nullptr;
        Node* newResult = nullptr;
        unordered_map<Node*,Node*>myMap;
        
        for(Node* tempHead = head; tempHead; tempHead = tempHead->next){
            Node* newNode = new Node(tempHead->val);
            newNode->random = tempHead->random;
            myMap[tempHead] = newNode;
            
            if(!result)
                result = newNode;
            else
                newResult->next = newNode;
            
            newResult = newNode;
        }
        
        for(Node* tempHead = result; tempHead; tempHead = tempHead->next){
            tempHead->random = myMap[tempHead->random];
        }
        
        return result;
    }
};

/*
SOLUTION:
The O(N) solution provided here is done with careful sketching out of the nodes!
The basic plan:
1)  Build copies of the nodes (new nodes), and have their 'random' pointers point to the
same node in the original linked list
2)  As you do this, use an unordered_map to keep a record of the ORIGINAL NODE TO COPY NODE
This means (when we clear up where the random pointers will be pointing to) that we can easily
adjust the random pointer, using something like:
copyNode->random->next = myMap[copyNode->random->next];   The map should map the old node to the new one!
3)  Don't forget that you'll need to maintain the 'next pointer' as normal in the Linked List too!



// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

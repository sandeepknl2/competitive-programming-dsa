class Solution {
public:
    bool hasCycle(ListNode* head) {
        vector<ListNode*> seen;

        ListNode* temp = head;
        while (temp != NULL) {
            for (auto node : seen) {
                if (node == temp) return true;
            }
            seen.push_back(temp);
            temp = temp->next;
        }
        return false;
    }
};


optimized

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // // store visited nodes
        // unordered_set<ListNode*> visited; 

        // ListNode* temp = head;
        // while (temp != NULL) {
        //     // if already visited, cycle found
        //     if (visited.count(temp)) {
        //         return true;
        //     }
        //     // mark this node as visited
        //     visited.insert(temp);

        //     // move forward
        //     temp = temp->next;
        // }

        // return false; // reached NULL → no cycle
           if (!head || !head->next) return false;
         ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            return true;
        }
        return false;
    }
};
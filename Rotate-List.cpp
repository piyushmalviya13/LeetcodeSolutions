/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0) return head;
        
        int len  = 0;
        ListNode *tmp = head;
        
        while(tmp != NULL) {
            len++;
            tmp = tmp->next;
        }
        
        if(k == len || len == 1) {
            return head;
        }
        
        k %= len;
        
        k = len - k;
        
        tmp = head;
        ListNode *sp = tmp;
        k--;
        
        while(k>0) {
            tmp = tmp->next;
            sp = tmp;
            k--;
        }
        
        tmp = head;
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }
        
        tmp->next = head;
        head = sp->next;
        sp->next = NULL;
        
        return head;
    }
};

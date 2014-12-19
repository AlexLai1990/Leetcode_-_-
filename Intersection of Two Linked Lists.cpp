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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL && headB == NULL || (headA == NULL || headB == NULL) )
            return NULL; 
            
        int len_a = getLength(headA);
        int len_b = getLength(headB);
        // keep List A's length <= List B
        if  (len_a > len_b)
            return getIntersectionNode(headB, headA);
        
        int dif = len_b - len_a;
        ListNode *m_res = NULL;
        for (int i = 0; i < dif; i++) {
            headB = headB->next;
        }
        while (headA != NULL && headB != NULL) {
            if (headA != headB) {
                headA = headA->next;
                headB = headB->next;
            }
            else {
                m_res = headA;
                break;
            }
        }
        return m_res;
    }
    
    int getLength(ListNode *head) {
        int count = 0;
        while (head != NULL) {
            count++;
            head = head->next;
        }
        return count;
    }
     
};
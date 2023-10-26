class Solution {
public:
    int length(ListNode *head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;

        //step1
        int lenA = length(headA), lenB = length(headB);

        //step2
            while(lenA>lenB){
                headA = headA->next;
                lenA--;
            }
        
         while(lenA<lenB){
                headB = headB->next;
                lenB--;
            }
        
        
        //step 3
        while(headA && headB){
            if(headA==headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};

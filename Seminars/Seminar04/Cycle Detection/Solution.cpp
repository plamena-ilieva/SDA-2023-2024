bool has_cycle(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* fast = head;
    SinglyLinkedListNode* slow = head;
    while(fast != nullptr && slow != nullptr && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) {
            return true;
        }
    }
    
    return false;

}

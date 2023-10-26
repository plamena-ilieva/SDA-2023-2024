SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    
    if (llist == nullptr || llist->next == nullptr) 
        return llist;
        
    SinglyLinkedListNode* curr = llist;
    SinglyLinkedListNode* prev = nullptr;

    while (curr != nullptr) {
        SinglyLinkedListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;    
    }
    
    return prev;
}

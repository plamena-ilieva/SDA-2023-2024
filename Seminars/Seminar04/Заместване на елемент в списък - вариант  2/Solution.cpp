void SinglyLinkedList::replace(int X)
{
	
    if (size == 0) {
        return; }
    
        
    Node* iter = head;
    int position = 0;
    while(position++ != X) {
        iter = iter->next;
        if(iter == nullptr) {
            return;
        }
    }
    int data = iter->value;
    iter = head;
    
    while(iter->next != nullptr) {
        if (iter->value == data) {
            iter->value = iter->next->value;
        }
        iter = iter->next;
    }
    
}

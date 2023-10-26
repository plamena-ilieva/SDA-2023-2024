void SinglyLinkedList::replace(int X)
{
    if (size == 0)
        return;
    
    Node* iter = head;
    while(iter != nullptr) {
      while(iter->value != X) {
        iter = iter->next;
        if(!iter) {
            return;
        }
      }
    
      size += X-1;
      iter->value = 1;
      bool isCurrTail = false;
      if (iter->next == nullptr) {
        isCurrTail = true;
      }
      Node* iterNext = iter->next;
      
      for(int i = 1; i < X; i++) {
        Node* curr = new Node(1);
        iter->next = curr;
        iter = iter->next;
      }
      iter->next = iterNext;
      if (isCurrTail) {
        tail = iter;
      }
      
      iter = iter->next;
    }
}

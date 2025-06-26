SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    if (llist == NULL) return NULL;

    if (position == 0) {
        SinglyLinkedListNode* temp = llist;
        llist = llist->next;
        free(temp);
        return llist;
    }

    SinglyLinkedListNode* current = llist;
    for (int i = 0; i < position - 1 && current->next != NULL; i++) {
        current = current->next;
    }

    if (current->next != NULL) {
        SinglyLinkedListNode* temp = current->next;
        current->next = temp->next;
        free(temp);
    }

    return llist;
}

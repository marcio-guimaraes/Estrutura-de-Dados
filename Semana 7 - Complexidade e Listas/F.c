SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* anterior = NULL;
    SinglyLinkedListNode* atual = head;
    SinglyLinkedListNode* proximo = NULL;

    while (atual != NULL) {
        proximo = atual->next;
        atual->next = anterior;
        anterior = atual;
        atual = proximo;
    }

    return anterior;
}

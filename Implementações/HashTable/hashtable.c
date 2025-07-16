#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

static int hash_function(int key, int size)
{
    return (key % size + size) % size;
}

static Node *create_node(int key, int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        perror("Erro de alocacao para o no");
        exit(EXIT_FAILURE);
    }
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

HashTable *create_hashtable(int size)
{
    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
    if (ht == NULL)
    {
        return NULL;
    }

    ht->size = size;
    ht->table = (Node **)calloc(ht->size, sizeof(Node *));
    if (ht->table == NULL)
    {
        free(ht);
        return NULL;
    }

    return ht;
}

void free_hashtable(HashTable *ht)
{
    if (ht == NULL)
        return;

    for (int i = 0; i < ht->size; i++)
    {
        Node *current = ht->table[i];
        while (current != NULL)
        {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(ht->table);
    free(ht);
}

void insert_item(HashTable *ht, int key, int value)
{
    if (ht == NULL)
        return;

    int index = hash_function(key, ht->size);
    Node *current = ht->table[index];

    while (current != NULL)
    {
        if (current->key == key)
        {
            current->value = value;
            return;
        }
        current = current->next;
    }

    Node *new_node = create_node(key, value);
    new_node->next = ht->table[index];
    ht->table[index] = new_node;
}

int search_item(HashTable *ht, int key)
{
    if (ht == NULL)
        return -1;

    int index = hash_function(key, ht->size);
    Node *current = ht->table[index];

    while (current != NULL)
    {
        if (current->key == key)
        {
            return current->value;
        }
        current = current->next;
    }

    return -1;
}

void remove_item(HashTable *ht, int key)
{
    if (ht == NULL)
        return;

    int index = hash_function(key, ht->size);
    Node *current = ht->table[index];
    Node *prev = NULL;

    while (current != NULL && current->key != key)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        return;
    }

    if (prev == NULL)
    {
        ht->table[index] = current->next;
    }
    else
    {
        prev->next = current->next;
    }

    free(current);
}

void print_hashtable(HashTable *ht)
{
    if (ht == NULL)
    {
        printf("Tabela Hash nula.\n");
        return;
    }

    printf("--- Tabela Hash ---\n");
    for (int i = 0; i < ht->size; i++)
    {
        printf("Indice [%d]: ", i);
        Node *current = ht->table[i];
        if (current == NULL)
        {
            printf("Vazio\n");
        }
        else
        {
            while (current != NULL)
            {
                printf("[Chave: %d, Valor: %d] -> ", current->key, current->value);
                current = current->next;
            }
            printf("NULL\n");
        }
    }
    printf("---------------------\n");
}

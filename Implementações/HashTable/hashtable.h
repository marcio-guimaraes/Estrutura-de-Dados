#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct Node
{
    int key;
    int value;
    struct Node *next;
} Node;

typedef struct HashTable
{
    int size;
    Node **table;
} HashTable;

HashTable *create_hashtable(int size);

void free_hashtable(HashTable *ht);

void insert_item(HashTable *ht, int key, int value);

int search_item(HashTable *ht, int key);

void remove_item(HashTable *ht, int key);

void print_hashtable(HashTable *ht);

#endif // HASHTABLE_H

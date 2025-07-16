#include <stdio.h>
#include "hashtable.h"

int main()
{
    int table_size = 11;
    HashTable *ht = create_hashtable(table_size);

    if (ht == NULL)
    {
        printf("Falha ao criar a Tabela Hash.\n");
        return 1;
    }

    printf("Tabela Hash criada com tamanho %d.\n", table_size);

    printf("\nInserindo itens...\n");
    insert_item(ht, 1, 10);
    insert_item(ht, 12, 20);
    insert_item(ht, 2, 30);
    insert_item(ht, 23, 40);
    insert_item(ht, 5, 50);

    print_hashtable(ht);

    printf("\nBuscando itens...\n");
    int key_to_find = 12;
    int result = search_item(ht, key_to_find);
    if (result != -1)
    {
        printf("Valor para a chave %d encontrado: %d\n", key_to_find, result);
    }
    else
    {
        printf("Chave %d nao encontrada.\n", key_to_find);
    }

    key_to_find = 99;
    result = search_item(ht, key_to_find);
    if (result != -1)
    {
        printf("Valor para a chave %d encontrado: %d\n", key_to_find, result);
    }
    else
    {
        printf("Chave %d nao encontrada.\n", key_to_find);
    }

    printf("\nRemovendo item com chave 12...\n");
    remove_item(ht, 12);
    print_hashtable(ht);

    printf("\nBuscando item removido (chave 12)...\n");
    result = search_item(ht, 12);
    if (result != -1)
    {
        printf("Valor para a chave %d encontrado: %d\n", 12, result);
    }
    else
    {
        printf("Chave %d nao encontrada.\n", 12);
    }

    printf("\nLiberando Tabela Hash...\n");
    free_hashtable(ht);
    printf("Memoria liberada com sucesso.\n");

    return 0;
}

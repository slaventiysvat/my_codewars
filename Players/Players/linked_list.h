#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_MAX 20


typedef struct _list {
    struct _list* next;
    int           data;
} list_t;

//list_t glist_buff[SIZE_MAX] = { 0 };

list_t* create_list(int N);
list_t* free_list(list_t* list, int N);
list_t* reverse(list_t* head);
void print_list(list_t* head);
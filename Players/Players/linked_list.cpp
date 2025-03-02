#include "linked_list.h"

list_t* create_list(int N) {


    srand((unsigned)time(NULL));
    if (N <= 0) {

        //List is Empty
        list_t* list_out = NULL;

        return list_out;

    }
    list_t* list_out = (list_t*)malloc(sizeof(list_t));
    list_out->data = rand() % 100;
    list_out->data = 1;
    list_out->next = NULL;
    list_t* head = list_out;
    for (int i = 0; i < N - 1; i++) {

        list_out->next = (list_t*)malloc(sizeof(list_t));
        list_out = list_out->next;
        list_out->data = rand() % 100;
        //list_out->data = i*2+1;
        list_out->next = NULL;

    }


    return head;

}
//Free List
list_t* free_list(list_t* list, int N) {

    if (list == NULL) {

        //List is Empty
        return list;

    }
    if (list->next == (list_t*)(0xdddddddd) || list == NULL) {
        printf("List is Emplty \n");
        return list;

    }
    list_t* current_list = list;
    list_t* next_list = list->next;

    if (current_list->next == NULL) {
        free(current_list);
        return list;

    }
    for (int i = 0; i < N; i++) {

        free(current_list);
        current_list = next_list;
        if (current_list->next == NULL) {
            free(current_list);
            return list;

        }
        next_list = next_list->next;
    }

    return list;

}
/** Reverse a linked list
  * input: pointer to list head
  * output: pointer to a reversed list head  */
list_t* reverse(list_t* head) {

    // write code

    if (head == NULL) {

        return NULL;//"List is Emplty"

    }

    if (head->next == (list_t*)(0xdddddddd) || head == NULL) {
        printf("List is Emplty \n");
        return head;

    }
    if (head->next == NULL) {
        return head;//We have only one element

    }
    else {

        int counter = 1;
        list_t* ctale = head;
        while (ctale->next != NULL) {
            //Size of List
            ctale = ctale->next;
            counter++;
        }
        int N = counter - 1;
        int* list_array = (int*)malloc(sizeof(int) * counter);
        ctale = head;
        list_t* ctale_prev = ctale;
        list_array[counter - 1] = (int)(ctale);
        N = N - 1;
        for (int i = N; i > -1; i--) {

            list_array[i] = (int)(ctale->next);
            ctale_prev = ctale;
            ctale = ctale->next;

        }

        list_t* chead = head;
        chead = ctale;
        chead->next = (list_t*)(list_array[1]);
        chead = chead->next;
        N = counter;
        for (int i = 2; i < N; i++) {

            chead->next = (list_t*)(list_array[i]);
            chead = chead->next;
        }

        chead->next = NULL;
        free(list_array);
        return ctale;

    }

}
void print_list(list_t* head) {

    // write code
    int counter = 1;
    list_t* current = head;

    if (!head || head == NULL) {
        printf("List is Emplty \n");
        return;

    }

    if (head->next == (list_t*)(0xdddddddd) || head == NULL) {
        printf("List is Emplty \n");
        return;

    }

    if (current->next == NULL) {

        printf("num of [i] = %d element is = %d \n", counter, current->data);
        return;

    }
    else {

        while (current->next != NULL) {

            printf("num of [i] = %d element is = %d \n", counter, current->data);
            current = current->next;
            counter++;
        }
        if (current->next == NULL) {

            printf("num of [i] = %d element is = %d \n", counter, current->data);
            return;
        }

    }
}

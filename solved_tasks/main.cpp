#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include "linked_list.h"

int main() {

    list_t* filled_list_1 = create_list(0);
    printf("------------list(0)------------\n");
    print_list(filled_list_1);
    /*list_t* reversed_list = reverse(filled_list_1);
    printf("-----------revesred list(0)-----\n");
    print_list(reversed_list);
    printf("------------list(1)------------\n");
    list_t* filled_list_2 = create_list(1);
    print_list(filled_list_2);
    list_t* reversed_list2 = reverse(filled_list_2);
    printf("-----------revesred list(1)-----\n");
    print_list(reversed_list2);
    printf("------------list(2)------------\n");
    list_t* filled_list_3 = create_list(2);
    print_list(filled_list_3);
    list_t* reversed_list3 = reverse(filled_list_3);
    printf("-----------revesred list(2)-----\n");
    print_list(reversed_list3);
    printf("------------list(50)------------\n");
    list_t* filled_list_4 = create_list(50);
    print_list(filled_list_4);
    list_t* reversed_list4 = reverse(filled_list_4);
    printf("-----------revesred list(50)-----\n");
    print_list(reversed_list4);*/


    printf("-----------free resources--------\n");
    free_list(filled_list_1, 0);
    print_list(filled_list_1);
    //printf("------------list(0)------------\n");
    //free_list(filled_list_2, 1);
    //print_list(filled_list_2);
    //printf("------------list(1)------------\n");
    //free_list(filled_list_3, 2);
    //print_list(filled_list_3);
    //printf("------------list(2)------------\n");
    //free_list(filled_list_4, 50);
    //print_list(filled_list_4);
    //printf("------------list(50)------------\n");

	_getch();
	return 0;
	 
}



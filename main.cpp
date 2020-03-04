#include <stdio.h>
#include "node1.h"
#include "check_lists.h"
#include <iostream>     // Provides cout.
#include <cstdlib>  // provides NULL

using namespace std;
using namespace main_savitch_5;


void list_print(node *head_ptr){
	node *temp = head_ptr;
	while (temp != NULL){
		cout << temp -> data() << " ";
		temp = temp -> link();
	}
	cout << endl;
} 

int main(int argc, char **argv)
{
	node *list1 = NULL;
	node *previous = NULL;
	double data1 [5] = {12.9, 89.8, 67.7, 45.6, 23.5};
	for (int i = 0; i < 5; i++){
		if (list1 == NULL){
			list_head_insert(list1, data1[i]);
			previous = list1;
		} else {
			list_insert(previous, data1[i]);
			previous = previous -> link();
		}
	}
	list_print(list1);
	check_list1(list1);
	
	
	node *list2_head = NULL;
	node *list2_tail = NULL;
	list_head_insert(list2_head, 23.5);
	list2_tail = list2_head;
	double data2 [5] = {45.6, 67.7, -123.5, 89.8, 12.9};
	for (int i = 0; i < 5; i++){
		list_insert(list2_tail, data2[i]);
		list2_tail = list2_tail -> link();
	}
	list_print(list2_head);
	check_list2(list2_head);
	
	
	node *list3_head = NULL;
	node *list3_tail = NULL;
	list_copy(list1, list3_head, list3_tail);
	list_print(list3_head);
	check_list1(list3_head);
	cout << list3_tail -> data() << endl;
	
	list_head_remove(list2_head);
	list_print(list2_head);
	check_list2B(list2_head);
	
	node *temp = list2_head;
	for (int i = 0; i < 1; i++){
		temp = temp -> link();
	}
	list_remove(temp);
	list_print(list2_head);
	check_list2C(list2_head);
	
}


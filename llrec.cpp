#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
	//terminating case, no more nodes to filter through in initial list
	if (head == NULL){
			smaller = NULL;
			larger = NULL;
	    return;
	}
	//initial list value is greater than pivot
	//set larger list pointer to point at current head node
	//recursively call function with head->next and larger->next
	if(head->val > pivot){
	    larger = head;
	    llpivot(head->next, smaller, larger->next, pivot);
	}
	//initial list value is less than or equal to pivot
	//set smaller list pointer to point at current head node
	//recursively call function with head->next and smaller->next
	else{
	    smaller = head;
	    llpivot(head->next, smaller->next, larger, pivot);
	}
}


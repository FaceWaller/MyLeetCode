#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>


struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* createList(int * arr,int arrSize){
	
	if (arrSize == 0) {
		return NULL;
	}
	
	struct ListNode * head = malloc(sizeof(struct ListNode));;
	struct ListNode * cur = head;
	
	for (int i = 0; i<arrSize; i++) {
		
		struct ListNode * temp = malloc(sizeof(struct ListNode));
		temp->val = *(arr+i);
		temp->next = NULL;
		cur->next = temp;
		cur = cur->next;
		
	}
	
	struct ListNode * res = head->next;
	free(head);
	return res;
}


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	
	struct ListNode* head1 = l1;
	struct ListNode* head2 = l2;
	
	if(head1 == NULL){
		return head2;
	}else if (head2 == NULL){
		return head1;
	}
	
	
	struct ListNode* resHead = malloc(sizeof(struct ListNode));
	struct ListNode* temp = resHead;
	
	while (head1 != NULL && head2 != NULL) {
		if (head1->val < head2->val) {
			temp->next = head1;
			head1=head1->next;
		}else{
			temp->next = head2;
			head2=head2->next;
		}
		temp = temp->next;
	}
	
	if(head1 != NULL){
		temp->next = head1;
	}else if (head2 != NULL){
		temp->next = head2;
	}

	struct ListNode* res = resHead->next;
	free(resHead);
	
	
	return res;

}
void printList(struct ListNode* head){
	struct ListNode * cur = head;
	while (cur != NULL) {
		printf("%d\n",cur->val);
		cur=cur->next;
	}
}

int main(int argc, char *argv[]) {
	int arr1[] = {1,2,4};
	int arr2[] = {1,3,4};
	
	struct ListNode* head1 = createList(arr1,sizeof(arr1)/sizeof(int));
	struct ListNode* head2 = createList(arr2,sizeof(arr2)/sizeof(int));

	printList(head1);
	printList(head2);

	struct ListNode* res = mergeTwoLists(head1, head2);
	printList(res);
	
}


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
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	
	
	struct ResPListNode {
		struct ListNode * curNodeP;
		struct ResPListNode * next;
	};
	
	struct ListNode * cur = head;
	
	
	struct ResPListNode * resHead = malloc(sizeof(struct ResPListNode));
	resHead->curNodeP=NULL;
	struct ResPListNode * resCur = resHead;
	for (int i = 0; i<n; i++) {
		struct ResPListNode * temp = malloc(sizeof(struct ResPListNode));
		temp -> curNodeP = NULL;
		temp -> next = NULL;
		resCur -> next = temp;
		resCur = temp;
	}
	resCur -> next = resHead;
	
	
	while (cur != NULL) {
		resCur->curNodeP = cur;
		resCur = resCur->next;
		cur = cur->next;
	}
	
	
	
	
	if(resCur->curNodeP == NULL){
		//        printf("把头删了");
		struct ListNode * freeNode = resCur->next->curNodeP;
		head = freeNode->next;
		free(freeNode);
	}else{
		printf("%s",resCur->curNodeP);
		//resCur是准备删除的节点的前一个
		struct ListNode * preNode = resCur->curNodeP;
		struct ListNode * freeNode = preNode->next;
		preNode->next = freeNode->next;
		free(freeNode);
	}
	
	
	
	
	
	for (int i =0; i<=n; i++) {
		struct ResPListNode * resFreeNode = resCur;
		resCur = resFreeNode->next;
		free(resFreeNode);
	}
	
	return head;
}
struct ListNode* createList(int * arr,int arrSize){
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

void printList(struct ListNode* head){
	struct ListNode * cur = head;
	while (cur != NULL) {
		printf("%d\n",cur->val);
		cur=cur->next;
	}
}


int main(int argc, char *argv[]) {
	
	int arr[] = {1};
	struct ListNode * head = createList(arr,sizeof(arr)/sizeof(int));
	printList(head);
	
	head = removeNthFromEnd(head,1);
	printList(head);

}


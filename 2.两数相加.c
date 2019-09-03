//
//  main.c
//  test
//
//  Created by Alan on 2018/5/27.
//  Copyright © 2018年 Alan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* createNode(int num){
	struct ListNode * cur = (struct ListNode *)malloc(sizeof(struct ListNode));
	cur -> val = num;
	return cur;
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	
	struct ListNode * l3 = (struct ListNode *)malloc(sizeof(struct ListNode));
	
	struct ListNode * cur = l3;//当前节点
	int carry = 0;
	
	if (l1 == NULL) {
		return l2;
	}
	if (l2 == NULL) {
		return l1;
	}
	
	
	while (l1 != NULL || l2 != NULL) {
		cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		cur=cur->next;
		
		int sum = 0,a,b;
		a = (l1 != NULL)?l1->val:0;
		b = (l2 != NULL)?l2->val:0;
		
		sum = a + b + carry;
		carry = sum/10;
		
		cur->val = sum%10;
		
		
		if (l1 != NULL) {
			l1 = l1->next;
		}
		if (l2 != NULL) {
			l2 = l2->next;
		}
	}
	
	if (carry > 0) {
		cur->next=(struct ListNode *)malloc(sizeof(struct ListNode));
		cur=cur->next;
		cur->val=carry;
	}
	cur->next=NULL;
	return l3->next;
	
}

void printList(struct ListNode * ll){
	struct ListNode * cur = ll;
	while (cur) {
		printf("%d",cur->val);
		cur = cur->next;
	}
	putchar(10);
}

int main(int argc, const char * argv[]) {
	
	struct ListNode * l1_1 = createNode(2);
	struct ListNode * l1_2 = createNode(4);
	struct ListNode * l1_3 = createNode(3);
	l1_1->next = l1_2;
	l1_2->next = l1_3;
	l1_3->next = NULL;
	
	
	struct ListNode * l2_1 = createNode(5);
	struct ListNode * l2_2 = createNode(6);
	struct ListNode * l2_3 = createNode(4);
	l2_1->next = l2_2;
	l2_2->next = l2_3;
	l2_3->next = NULL;
	
	
	struct ListNode * l3 = addTwoNumbers(l1_1, l2_1);
	
	
	printList(l1_1);
	printList(l2_1);
	printList(l3);

	
	putchar(10);
	
	return 0;
}

#题意:链表数字相加 

class ListNode:
	def __init__(self, x):
		self.val = x
		self.next = None

class Solution:
	# @return a ListNode
	def addTwoNumbers(self, l1, l2):
		if l1 is None:
			return l2
		elif l2 is None:
			return l1
		else:          
			carry = 0
			ret =ListNode(0)
			ret_Last = ret
			
			while(l1 or l2):
				sum = 0
				if(l1):
					sum = l1.val
					l1 = l1.next
				if(l2):
					sum += l2.val
					l2 = l2.next
				sum += carry
				ret_Last.next = ListNode(sum%10)
				ret_Last = ret_Last.next
				carry = (sum >= 10)
			if(carry):
				ret_Last.next =ListNode(1)
			ret_Last = ret.next
			del ret
			return ret_Last

if __name__ == '__main__':
	print ("----------------- start -----------------")

	l1_1 = ListNode(2)
	l1_2 = ListNode(4)
	l1_3 = ListNode(3)
	l1_1.next = l1_2
	l1_2.next = l1_3

	l2_1 = ListNode(5)
	l2_2 = ListNode(6)
	l2_3 = ListNode(5)
	l2_1.next = l2_2
	l2_2.next = l2_3

	l3_1 = Solution().addTwoNumbers(l1_1,l2_1)
	while l3_1 != None:
		print(l3_1.val)
		l3_1 = l3_1.next

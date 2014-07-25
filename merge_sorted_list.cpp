tion for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   private :		
   void move(ListNode ** temp1, ListNode **temp2)
   {
	  while((*temp1)->next &&  (*temp2)->val > ((*temp1)->next)->val ) {
	      *temp1 = (*temp1)->next;	  
	  }

	  ListNode * n1 = (*temp1)->next;
	  ListNode * n2 = (*temp2)->next ;
	  (*temp1)->next = *temp2;
	  (*temp2)->next = n1;
	  *temp2 = n2;
   }

	public:
		ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {

                    if(!l1)
		        return l2;
		    if(!l2)
			 return l1;

		    if( !l1 && !l2)
			    return NULL;

		    ListNode *temp1 = l1;
		    ListNode *temp2 = l2;
		    ListNode *head;

		    if(l2->val >= l1->val){
			head = l1;
		    }
		    else {
			    head = l2;
		    }

		    while( temp1!= NULL && temp2!=NULL){

			 if( temp2->val >= temp1->val)   
			 {	 
			   move(&temp1, &temp2);	 
			 } 
			 else
		         {
			   move(&temp2, &temp1);
			 }

		    }

		   return head;    
		}
 
};



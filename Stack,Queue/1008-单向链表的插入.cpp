struct ListNode {
  int data;
  ListNode *next;
};

class List {
public:
  List() {
    head = new ListNode;
    head->next = NULL;
  }
 
  ~List() {
    ListNode* curNode;
    while( head->next ) {
      curNode = head->next;
      head->next = curNode->next;
      delete curNode;
    }       
    delete head;
  }
    
 	void List::insert(int toadd, int pos);
 
  // Data field
  	ListNode *head; //head指向虚拟头结点，head-next指向第一个实际结点
}; 


void List::insert(int toadd, int pos) {
	
}


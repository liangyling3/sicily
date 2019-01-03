struct ListNode
{
  int data;
  ListNode *next;
};

class List
{
public:
  List()
  {
    head = new ListNode;
    head->next = NULL;
  }
 
  ~List()
  {
    ListNode* curNode;
    while( head->next )
    {
      curNode = head->next;
      head->next = curNode->next;
      delete curNode;
    }       
    delete head;
  }
  //在链表第pos(pos>0)个结点之前插入新结点，新结点的值为toadd
    //链表实际结点从1开始计数。
    //调用时需保证pos小等于链表实际结点数 
    void insert(int toadd, int pos);
 
  // Data field
  ListNode *head; //head指向虚拟头结点，head-next指向第一个实际结点
};

void List::insert(int toadd, int pos) {
  int count = 0;
  ListNode * p = head;
  while (count != pos-1) {
    p = p->next;
    count ++;
  }
  ListNode * node = new ListNode;
  node->next = p->next;
  p->next = node;
  node->data = toadd;
}

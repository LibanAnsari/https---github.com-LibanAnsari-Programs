#include <bits/stdc++.h>
using namespace std;

struct node
{
  int data;
  struct node *next;
  node(int x)
  {
    data = x;
    next = NULL;
  }
};

bool areIdentical(struct node *head1, struct node *head2)
{
  // Code here
  bool res = true;
  while (head1 != NULL and head2 != NULL)
  {
    if (head1->data != head2->data)
    {
      res = false;
      break;
    }
    head1 = head1->next;
    head2 = head2->next;
  }
  if (head1 != NULL or head2 != NULL)
  {
    res = false;
  }
  return res;
}

int main(int argc, char const *argv[])
{
  node *head1 = new node(5);
  head1->next = new node(10);
  
  node *head2 = new node(5);
  head2->next = new node(15);
  
  cout << areIdentical(head1,head2);
  // 0

  return 0;
}


#include<bits/stdc++.h>
using ll = long long;
using ldou = long double;
using unll = unsigned long long;
using namespace std;

//****************************//
#define 传入数值 int x
#define 终止条件 1
#define 最小子问题解 1
#define 缩小规模 1
int func(传入数值) {
  if (终止条件) return 最小子问题解;
  return func(缩小规模);
}

//**************递归的缺点
struct Node
{
  Node* next;
};
// 典型的递推遍历框架
int size(Node *head) {
  int size = 0;
  for (Node *p = head; p != nullptr; p = p->next) size++;
  return size;
}
// 我就是要写递归，递归天下第一 // 会消耗额外空间
int size_recursion(Node *head) {
  if (head == nullptr) return 0;
  return size_recursion(head->next) + 1;
}
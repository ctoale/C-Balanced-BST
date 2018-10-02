#include <iostream>
using namespace std;
struct BSTreeNode
{
int data;
struct BSTreeNode* left;
struct BSTreeNode* right;
};
struct BSTreeNode* newBSTreeNode(int data);
struct BSTreeNode* BalanceTreeArray(int Array[], int start, int end)
{
if (start > end)
return NULL;

int mid = (start + end)/2;
struct BSTreeNode *root = newBSTreeNode(Array[mid]);
root->left = BalanceTreeArray(Array, start, mid-1);
root->right = BalanceTreeArray(Array, mid+1, end);

return root;
}
void PO(struct BSTreeNode* node){
if (node == NULL)
return;
cout<<node->data<<" ";
PO(node->left);
PO(node->right);
}
struct BSTreeNode* newBSTreeNode(int data){
struct BSTreeNode* node = new BSTreeNode;
node->data = data;
node->left = NULL;
node->right = NULL;

return node;
}
int main(){
  
int Array[50];
int n;
cout<<"This program will produce a balanced binary search tree, given a sorted list of elements. \n";
cout<<"\nEnter the number of elements: ";
cin>>n;
cout<<"Enter sorted list of elements: ";
for(int i=0;i<n;i++)
{
cin>>Array[i];
}
  
struct BSTreeNode *root = BalanceTreeArray(Array, 0, n-1);
cout<<"\nThe balanced binary search tree is: \n";
PO(root);
cout<<endl;
return 0;
}
#pragma once
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
#include<stdbool.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;
void Swap(HPDataType* a, HPDataType* b);
void HPInit(HP* php);
void HPDestory(HP* php);
void AdjustUp(HPDataType*a,int child);
void AdjustDown(HPDataType* a, int n, int parent);
void HPPush(HP* php, HPDataType x);
void HPPop(HP* php);
HPDataType HPTop(HP* php);
bool HPEmpty(HP* php);
void HeapSort(int* a, int n);

typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;
BTNode* BuyNode(BTDataType x);
void PrevOrder(BTNode* root);
void InOrder(BTNode* root);
BTNode* CreatBinaryTree();
int TreeHeight(BTNode* root);
int TreeLevelKSize(BTNode* root, int k);
bool isUnivalTree(BTNode* root);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
bool isSameTree(BTNode* p, BTNode* q);
bool _isSymmetric(BTNode* p, BTNode* q);
bool isSymmetric(BTNode* root);
int* PreOrderTraversal(BTNode* root, int* returnSize);
bool isSubtree(BTNode* root, BTNode* subRoot);
BTNode* BinaryTreeCreate(BTDataType* a, int* pi);




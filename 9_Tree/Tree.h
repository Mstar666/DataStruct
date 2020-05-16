#ifndef _TREE_H_
#define _TREE_H_

typedef void Tree;
typedef void TreeNode;

//������
Tree* Tree_Create();

//�����Ѵ��ڵ���
void Tree_Destroy(Tree* tree);

//����Ѵ��ڵ���
void Tree_Clear(Tree* tree);

//�����в�����
int Tree_Insert(Tree* tree, TreeNode* node, int pos);

//ɾ������posλ�õĽ��
TreeNode* Tree_Delete(Tree* tree, int pos);

//�õ�����posλ�õĽ��
TreeNode* Tree_Get(Tree* tree, int pos);

//�������ĸ��ڵ�
TreeNode* Tree_Root(Tree* tree);

//�������ĸ߶�
int Tree_Height(Tree* tree);

//�������Ľ����
int Tree_Count(Tree* tree);

//�������Ķ�
int Tree_Degress(Tree* tree);

#endif

#ifndef _TREE_H_
#define _TREE_H_

typedef void Tree;
typedef void TreeNode;

//创建树
Tree* Tree_Create();

//销毁已存在的树
void Tree_Destroy(Tree* tree);

//清空已存在的树
void Tree_Clear(Tree* tree);

//向树中插入结点
int Tree_Insert(Tree* tree, TreeNode* node, int pos);

//删除树中pos位置的结点
TreeNode* Tree_Delete(Tree* tree, int pos);

//得到树中pos位置的结点
TreeNode* Tree_Get(Tree* tree, int pos);

//返回树的根节点
TreeNode* Tree_Root(Tree* tree);

//返回树的高度
int Tree_Height(Tree* tree);

//返回树的结点数
int Tree_Count(Tree* tree);

//返回树的度
int Tree_Degress(Tree* tree);

#endif

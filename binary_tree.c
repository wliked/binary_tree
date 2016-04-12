//*************************************************************
//*
//* Copyright (c) 2016 : wang liang
//* License : Distributed under the GNU General Public License
//* created on : 4/10/2016,  by wang liang (wliked@outlook.com)
//* 
//*************************************************************

//node defination of binary tree
struct BinaryTreeNode 
{
	int val;
	BinaryTreeNode* LNode;
	BinaryTreeNode* RNode;
}
 
//ouput value of binary tree node 
void print_btree_node_value(const BinaryTreeNode* btreenode)
{
	printf("%d\n",btreenode->val);
} 

//preorder traversal;implement by recursion 
void preorder_traversal(const BinaryTreeNode* treeroot)
{
	if( NULL==treeroot )
	{
	   return;
	}	
	else
	{
	    print_btree_node_value(treeroot);
		preorder_traversal(treeroot->LNode);
        preorder_traversal(treeroot->RNode);		
	}
}

//inorder traversal;implement by recursion 
void inorder_traversal(const BinaryTreeNode* treeroot)
{
	if( NULL==treeroot )
	{
	   return;
	}	
	else
	{
		inorder_traversal(treeroot->LNode);
	    print_btree_node_value(treeroot);
        inorder_traversal(treeroot->RNode);		
	}
}

//postorder traversal;implement by recursion 
void postorder_traversal(const BinaryTreeNode* treeroot)
{
	if( NULL==treeroot )
	{
	   return;
	}	
	else
	{
		postorder_traversal(treeroot->LNode);
        postorder_traversal(treeroot->RNode);
        print_btree_node_value(treeroot);		
	}
}
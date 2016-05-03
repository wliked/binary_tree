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
    if ( NULL==treeroot )
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
    if ( NULL==treeroot )
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
    if ( NULL==treeroot )
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


// reconstruct binary tree with given preorder and inorder sequence
BinaryTreeNode* reconstruct_btree_with_preorder_inorder(int* preorder, int* inorder, int length)
{
    if (NULL == preorder || NULL==inorder || length)
        return NULL;
    return construct_root(preorder, preorder+length-1, inorder, inorder+length-1);
}

//recusively reconstruct node of binary tree
BinaryTreeNode* construct_root(int* preorderstart,int* preorderend,int* inorderstart,int* inorderend)
{
    if (NULL==preorderstart ||NULL==preorderend||NULL==inorderstart||NULL==inorderend)
        return NULL;

    int root_value=preorderstart[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->val=root_value;
    root->LNode=root->RNode=NULL;
     
    if(preorderstart==preorderend)
         return root;

    int* rootinorder =inorderstart;
    while(rootinorder<inorderend && *rootinorder!= root_value)
		++rootinorder;
	
    if(rootinorder ==inorderend&& *rootinorder!=root_value)
              throw std::exception("invalid input");

    int left_child_length = rootinorder-inorderstart; //left child nodes numbers that needs to be recusively call construct_root();
    int right_child_length=inorderend-rootinorder;   //right child nodes numbers that needs to be recusively call construct_root();

    if(left_child_length>0)
        root->LNode=construct_root(preorderstart+1, preorderstart+left_child_length,inorderstart,rootinorder-1);

    if(right_child_length>0)
	root->RNode=construct_root(preorderstart+left_child_length+1,preorderend, rootinorder+1,inorderend);

    return root;
    	
}


#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef int KEY_VALUE;
#define M 6  //6阶b树，6有个子节点，自身是一块，可以存储5个节点
#define DEGREE (M/2)  //6阶b树，6有个子节点，自身是一块，可以存储5个节点
struct btree_node
{
    KEY_VALUE* keys;  // 是指一块数据，比如AB，而不是某一个
    struct btree_node **childrens;
    int num;   //记录一块里面目前存有多少个节点
    int leaf; //是否是叶子节点，内存对齐
};

struct btree
{
   struct btree_node* root;
};

struct btree_node* btree_create_node(struct btree* T)
{

}

//分裂节点, 父节点x的第i个节点进行分裂(1分3)
void btree_split_child(struct btree* T, struct btree_node* x, int i)
{
    //T是根节点，x是父节点，i是要分裂的节点
    struct btree_node* y=x->childrens[i];

    // 1、创建新的节点
    struct btree_node* z = (btree_node *)malloc(sizeof(btree_node));
    
    // 2、该节点的前半部分的key值进行copy给z
    for(int j = 0; j < DEGREE-1; j++)
    {
        z[j].keys = y[j].keys;
    }
    //判断不是叶子节点，把子节点进行copy
    if(y->leaf == 0) 
    {
        for(int j = 0; j < DEGREE; j++)
        {
            z[j].childrens = y[j].childrens; 
        }
    }

}

void btree_insert_nonfull(struct btree* T, struct btree_node* x, KEY_VALUE key)
{   
    int i=x->num;
    //找到叶子节点（递归）
    if(x->leaf == 1)
    {

    }
    else
    {   
        //找到子节点
        while(i >= 0 && x->keys[i] > key )
        {
            i--;
        }
        //判断子节点是否满，满则分裂
        if(x->childrens[i+1]->num == M-1)
        {
            btree_split_child(T, x, i+1);
            if(key )
        }
        //插入
        btree_insert_nonfull(T,  x->childrens[i+1], key);
    }
}



//根节点单独处理(1分2)
void btree_insert(struct btree* T, KEY_VALUE key)
{
    struct btree_node* r=T->root;
    //根节点达到最大的key数量
    if(r->num == M-1)
    {   
        struct btree_node* node = (btree_node *)malloc(sizeof(btree_node));
        T->root = node;
        node->childrens[0] = r;

        btree_split_child(T, node, 0);
    }
    else
    {
        
    }

}


/*
   Thsi file contains the basic operation on tree 
*/




int   basic_tree_insert(BASIC_TREE_NODE **proot,BASIC_TREE_NODE*pdata,BASIC_TREE_NODE**pParent,uint32_t dataNodeSize,
                       uint32_t* flags)
{
    uint8_t *tempPtr = NULL ;
    BASIC_TREE_NODE *ptempNode = NULL ;
    if(NULL == pdata || NULL == proot)
           return COMMON_FAILURE;

    /*New Node*/
    if(NULL == *root)
    {
        *proot = (BASIC_TREE_NODE *) pdata;
        *proot->left= NULL ;
        *proot->right =NULL ;
        *flags | =NODE_INSERTED;
         return COMMON_SUCCESS;
    }

    ptempNode = *proot;
    if(ptempNode->key < pdata->key)
        basic_tree_insert(&(ptempNode->right),pdata,dataNodeSize);
    else if(ptempNode->key >  pdata->key)
        basic_tree_insert(&(ptempNode->left),pdata,dataNodeSize);

    if(NODE_INSERTED & flags)
    {
        *pParent = ptempNode;
         *flags &=~NODE_INSERTED;
    }
    return COMMON_SUCCESS;

}
/*REcursively searching for an element in binary tree*/
void basic_tree_search_recursive(BASIC_TREE_NODE * root , BASIC_TREE_NODE **pdata , uint64_t key , uint32_t nodeSize, uint8_t *st)
{

    if(key > root->key)
        basic_tree_search_recursive(root->right , pdata, key);
    else if(key < root->key)
    {
         basic_tree_search_recursive(root->left,pdata, key);
    }
    else 
    { 
             memcpy(*pdata,root,nodeSize);
             *st = COMMON_SUCCESS
    } 
   
    return ;
}

/*Non recursive searching of the elements in binary tree */

void basic_tree_search_nonrecursive(BASIC_TREE_NODE * root , BASIC_TREE_NODE **pdata , uint64_t key , uint32_t nodeSize, uint8_t *st)
{
      BASIC_TREE_NODE *ptemp = NULL ;
      BASIC_TREE_NODE *ptempChild = NULL ;
      
      *st = COMMON_FAILURE ;

      ptemp = root ;   

      while (NULL != ptemp)
      {
           if(key > ptemp->key)
                ptemp = ptemp->left;
           else if(key < ptemp->key)
                ptemp = ptemp->right;
           else if(key == ptemp->key)
           {
             memcpy(*pdata,ptemp,nodeSize);
             *st = COMMON_SUCCESS
             break;
           }
      }  
     
      return ;

}

/*API which will be collecting all the leafs */

void  basic_tree_get_leafs(BASIC_TREE_NODE * root , uint32_t array[] , uint32_t arraySize,uint32_t *populated )
{
      if(NULL == root)
         return ;
      basic_tree_get_leafs(root->left);
      if(NULL == root->left  && NULL == root->right)
      {
         array[*populated]=root->key;
         *populated+=1;
      }
      basic_tree_get_leafs(root->right);
      return ;       
} 

/*API for deleting the node */

BASIC_TREE_NODE* basic_tree_delete_Node(BASIC_TREE_NODE ** root)
{
      if(*root == NULL)
         return NULL ;

      
 
}

/*API to calculate the height of the tree*/



void getTreeHeight(BASIC_TREE_NODE *t, *h)
{
    if(NULL ==t)
    {
          *h =0;
    }
}


/*API to check if a tree is height balanced or not*/

int checkIfTreeBal(BASIC_TREE_NODE *t,uint32_t *h)
{
    if(NULL == t)
    { 
         return 1;
    }

   
}

/*API which will be cloning a tree*/

int cloneTree(BASIC_TREE_NODE *t , BASIC_TREE_NODE *dt ,BASIC_TREE_NODE **d, uint8_t lr, int *retVal )
{
    if(NULL == t)
        *d = NULL ;

    if(NULL == *d)
    {   
        *d = (BASIC_TREE_NODE *)malloc (sizeof(BASIC_TREE_NODE ));
        if(NULL == *d)
        {
            return -1;
        }
        memset(*d,0, sizeof(BASIC_TREE_NODE));
        *d->key = t->key;
        dt =*d ;
    }   
    
    if(1==lr)
    {
         dt->left = (BASIC_TREE_NODE *) malloc (sizeof(BASIC_TREE_NODE));
         if(NULL == dt->left)
         {
            *retval= -1;
            return -1;
         }
         memset(dt->left,0,sizeof(BASIC_TREE_NODE));
         dt->key = t->key;
         dt=dt->left; 
    }
    else 
    {
         dt->right = (BASIC_TREE_NODE *) malloc (sizeof(BASIC_TREE_NODE));
         if(NULL == dt->right)
         {
            *retval= -1;
            return -1;
         }
         memset(dt->right,0,sizeof(BASIC_TREE_NODE));
         dt->key = t->key;
         dt =dt->right;
    }

    cloneTree(t->left, dt,d,1);
    cloneTree(t->right, dt,d,0);
    
    retuen 0;  
}


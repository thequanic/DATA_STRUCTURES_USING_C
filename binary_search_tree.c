#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node*left;
    struct node*right;
}node;


node * new_node(int value);
//creates new node
node * insert(node*root,int value); 
//inserts element in tree seeing the order. higher elements on right and lower at left
void inorder(node*root);
//prints inorder of tree. (left, root, right)  
void preorder(node*root);
//prints preorder of tree. (root, left, right)
void postorder(node*root);
//prints postorder of tree. (left,right, root)
node * search(node*root,int key);
//searches element in the tree, return the address of node in which element is found
//if element is not found returns NULL
node * min_left_node(node*root);
//returns the left most child of a node
node * delete(node*root,int key);
//deletes the element from the tree
void BreadthFirstSearch(node *root);
//prints breadth first search traversal of tree


int main()
{
    printf("\n\n***********************************PROGRAM STARTED***********************************\n\n\n\n");
    printf("  ************  WELCOME TO BINARY SEARCH TREE IMPLEMENTATION PROGRAM  ***********\n\n\n");
    printf("                                MADE BY: DEVANSH GOEL\n");
    printf("                                      SECTION N\n");
    printf("                                 STUDENT ID: 20011990\n");
    printf("                             GRAPHIC ERA HILL UNIVERSITY\n\n");
    
    node *root = NULL; //root pointer
    
    while(1)
    {
         //printing main menu
        char *s="OPERATION PERFORMED SUCCESSFULLY";
        printf("\n\n*************************************************************************************\n\n");
        printf("YOU CAN PERFORM FOLLOWING OPERATIONS...........\n");
        printf("\n                            **************************");
        printf("\n                            |          MENU          |");
        printf("\n                            **************************");
        printf("\n                            |    1.INSERT ELEMENT    |\n");
        printf("                            |    2.DISPLAY           |\n");
        printf("                            |    3.SEARCH ELEMENT    |\n");
        printf("                            |    4.DELETE ELEMENT    |\n");
        printf("                            |    5.EXIT              |\n");
        printf("                            **************************\n");

        //asking for user choice
        printf("\n>>> Enter your choice::");
        int c;
        scanf("%d",&c);
        printf("\n\n*************************************************************************************\n");
        switch(c)
        {
            case 1:
            {
                int value;
                printf("\n>>> Enter value to be inserted::");
                scanf("%d",&value);
                root=insert(root,value); //always return address of root node at last
                break;
            }

            case 2:
            {
                //display 
                if(root==NULL)
                {
                    //checking whether tree is empty
                    printf("\n\n                                   TREE IS EMPTY.......\n\n");
                    break;
                }
                printf("\nOPENING DISPLAY MENU...........");
                int x=1;
                while(x)
                {
                    //printing a display menu..asking user whether he/she wants to display in inorder
                    //preorder or postorder
                    printf("\n\n***************************************************************************\n");
                    printf("\n\nYOU CAN DISPLAY IN FOLLOWING TRAVERSALS...........\n");
                    printf("\n**************************");
                    printf("\n|       TRAVERSALS       |");
                    printf("\n**************************");
                    printf("\n| 1.INORDER              |\n");
                    printf("| 2.PREORDER             |\n");
                    printf("| 3.POSTORDER            |\n");
                    printf("| 4.BREADTH FIRST SEARCH |\n");
                    printf("**************************\n\n");

                    //to return to main menu
                    printf("**************************\n");
                    printf("|  PRESS 5 TO RETURN TO  |\n");
                    printf("|       MAIN MENU        |\n");
                    printf("**************************\n");

                    //asking user choice
                    printf("\n>>> Enter your choice::");
                    int c2;
                    scanf("%d",&c2);
                    printf("\n\n***************************************************************************\n");
                    switch(c2)
                    {
                        case 1:
                        {
                            printf("\nTree in inorder is :: ");
                            inorder(root);
                            printf("\n");
                
                            break;
                        }

                        case 2:
                        {
                            printf("\nTree in preorder is :: ");
                            preorder(root);
                            printf("\n");
                
                            break;
                        }

                        case 3:
                        {
                            printf("\nTree in postorder is :: ");
                            postorder(root);
                            printf("\n");
                
                            break;
                        }

                        case 4:
                        {
                            BreadthFirstSearch(root);
                            break;
                        }

                        case 5:
                        {
                            x=0;
                            break;
                        }

                        default:
                        {
                            printf("\nINVALID CHOICE.........");
                        }
                    }
              
            
                }
                break;
            }

            case 3:
            {
                int key;
                printf("\n>>> Enter element to be searched in tree:");
                scanf("%d",&key);
                if(root==NULL)
                {
                    printf("\nTREE IS EMPTY....");
                }
                search(root,key);
                break;
            }

            case 4:
            {
                int key;
                printf("\n>>> Enter element to be deleted in tree:");
                scanf("%d",&key);
                if(root==NULL)
                {
                    printf("\nTREE IS EMPTY....");
                }
                delete(root,key);
                break;
            }

            case 5:
            {
                printf("\n\n*************************************************************************************\n\n");
                printf("                                   PROGRAM FINISHED                                        ");
                printf("\n\n*************************************************************************************\n\n");
                exit(0);
            }
            default: s="        INVALID CHOICE         ";
        }
        printf("\n\n*************************************************************************************\n\n");
        printf("                         %s                            ",s);
    
    }


    return 0;
}

node * new_node(int value)
{
    //creates new node and returns its address
    node * new=(node*)malloc(sizeof(node));
    new->info=value;
    new->left=NULL;
    new->right=NULL;
    return new;
}

node * insert(node*root,int value)
{

    if(root==NULL)
    {
        //stopping condition for recursion. returns the address of the node to be inserted
        printf("\nINSERTING %d ...USING RECURSIVE ALGORITHM\n",value);
        return new_node(value);
    }

    //finds right position to insert new node
    //tree will always have lower elements than root node on left
    //and higher ones at right of root
    //every child is a sub tree

    if(value<root->info)    //checks whether new node will go to left of root
    {
        //inserts element in left sub tree taking root->left as root for it
        root->left=insert(root->left,value);
    }
    else if(value>root->info) //checks whether new node will go to right of root
    {
        //inserts element in right sub tree taking root->right as root for it
        root->right=insert(root->right,value);
    }
    else if(value==root->info)  //checks if given element already exits
    {
        //in this case insertion does not take place
        printf("\nGIVEN ELEMENT %d ALREADY EXITS IN TREE..DUPLICACY NOT ALLOWED..\n",value);
    }

    //returns root once new node is inserted
    return root;
}

void inorder(node*root)
{
    if(root==NULL)
    {
        //stopping condition for recursion - stops if leaf node is reached
        return;
    }

    inorder(root->left);             //prints inorder left sub tree
    printf("%d ",root->info);        //prints root
    inorder(root->right);            //prints inorder right sub tree
}

void preorder(node*root)
{
    if(root==NULL)
    {
        //stopping condition for recursion - stops if leaf node is reached
        return;
    }

    printf("%d ",root->info);          //prints root
    preorder(root->left);              //prints preorder of left sub tree
    preorder(root->right);             //prints preorder of right sub tree

}

void postorder(node*root)
{
    if(root==NULL)
    {
        //stopping condition for recursion - stops if leaf node is reached
        return;
    }

    postorder(root->left);               //prints postorder of left sub tree
    postorder(root->right);              //prints postorder of right sub tree
    printf("%d ",root->info);            //prints root

}


node * search(node*root,int key)
{
    //if root becomes NULL that means element is not found or tree is empty
    if(root==NULL)
    {
        printf("\nGIVEN ELEMENT NOT FOUND IN TREE..\n\n");
        return NULL;
    }

    //when key is found in any node recursively a root, address of that is returned
    if(key==root->info)
    {
        printf("\nGIVEN ELEMENT %d FOUND..\n\n",key);
        return root;
    }

    //if key is less than root find it in left subtree
    if(key<root->info)
    {
        return search(root->left,key);
    }

    //if key is greater than root find it in right subtree
    else if(key>root->info)
    {
        return search(root->right,key);
    }


}

node * min_left_node(node*root)
{
    //returns the left most child of the node 
    if(root==NULL||root->left==NULL)
    {
        //if root left is NULL that means root is the left most child
        return root;
    }

    //recursivley call and return for root left subtree until left most child is reached
    return min_left_node(root->left);
}


node * delete(node*root,int key)
{
    //deletes node from the tree, first key is searched in tree than deletion takes place

    //if root becomes NULL, means element is not found in tree
    if(root==NULL)
    {
        return root;
    }

    if(key<root->info)
    {
        //if key is less than root we will find and delete it from left sub tree
        //the returning address is the address of left sub tree after changes due to deletion
        root->left=delete(root->left,key);
        return root;
    }

    if(key>root->info)
    {
        //if key is greater than root we will find and delete it from right sub tree
        //the returning address is the address of right sub tree after changes due to deletion
        root->right=delete(root->right,key);
        return root;
    }

    if(root->info==key)
    {
        printf("\nELEMENT %d DELETED FROM THE TREE...\n\n",key);
        //if key is found in the node three cases arise:

        //1.the node need to be deleted has no chlid
        //in this case we will simply delete node and replace by its right or left child, that is NULL

        //2.the node has one child, either left or right
        //in this case we will replace the node by its single child


        if(root->left==NULL)
        {
            node * temp=root->right;
            free(root);
            return temp;
        }

        if(root->right==NULL)
        {
            node * temp=root->left;
            free(root);
            return temp;
        }

        //3.the node has two childs, in this case we will replace it by 
        //left most child of its right sub tree 

        node * temp=min_left_node(root->right);                      //finding left most child of right sub tree of root
        root->info=temp->info;                                       //copying data of left most child of right sub tree to root
        root->right=delete(root->right,temp->info);                  //deleting left most child of right sub tree by recursive call
        printf("\nELEMENT %d WAS STORED BEFORE DELETION..DELETION WAS JUST A PROTOCOL ... DO NOT WORRY!!\n\n",root->info);     //to avoid duplicacy

        return root;
    }
}

//queue using linked list to implement breadth first search
typedef struct qnode
{
    node*ptr;
    struct qnode*next;
}qnode;

void enqueue(qnode**front,qnode**rear,node * data)
{
    qnode*temp=(qnode*)malloc(sizeof(qnode));
    temp->ptr=data;
    temp->next=NULL;

    if(*rear==NULL)
    {
        *front=temp;
        *rear=temp;
        return;
    }

    (*rear)->next=temp;
    *rear=temp;
    return;
}

node * dequeue(qnode**front,qnode**rear)
{
    if(*rear==NULL)
    {
        return NULL;
    }

    qnode * temp=*front;
    node  * ptr=temp->ptr;

    if(*front==*rear)
    {
        *front=NULL;
        *rear=NULL;
    }

    else
    {
        *front=(*front)->next;
    }

    free(temp);

    return ptr;
}



void BreadthFirstSearch(node *root)
{
    qnode *front=NULL, *rear=NULL;
    printf("\nBREADTH FIRST SEARCH TRAVERSAL IN THE BINARY TREE IS:\n\n");
    

    enqueue(&front,&rear,root);
    

    while(front!=NULL)
    {
        node*temp=dequeue(&front,&rear);
        printf("%d ",temp->info);
        
        if(temp->left!=NULL)
        {
            enqueue(&front,&rear,temp->left);
        }

        if(temp->right!=NULL)
        {
            enqueue(&front,&rear,temp->right);
        }
    }

}

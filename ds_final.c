#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;

} *root = NULL;

struct node *createNode(int num)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = num;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

struct node *addNode(int num, struct node *root)
{ // 100,(50) | 100,NULL
    if (root == NULL)
    {
        root = createNode(num);
    }
    else
    {
        if (root->data > num)
        {
            // left
            root->left = addNode(num, root->left); // 100,NULL
        }
        else
        {
            // right
            root->right = addNode(num, root->right); // 100,NULL
        }
    }

    return root;
}

void inOrder(struct node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data); // 25 35 40
    inOrder(root->right);
    // main();
    return;
}

void preOrder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
    // main();
    return;
}

void postOrder(struct node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
    // main();
    return;
}

struct node *findMinValueNode(struct node *root)
{

    struct node *min = root;
    while (min != NULL && min->left != NULL)
    {
        min = min->left;
    }

    return min;
}

struct node *deleteNode(struct node *root, int key)
{ // (50,35) => (35,35)
    struct node *tmp = NULL;
    if (root == NULL)
    {
        return root;
    }
    if (key < root->data)
    { // 25 < 50 | 25 < 35 | 25 < 25
        // left
        // 50
        root->left = deleteNode(root->left, key); //(50,35) => (35,35)
    }
    else if (key > root->data)
    { // 25 > 50 | 25 > 25
        // right
        root->right = deleteNode(root->right, key);
    }
    else if (key == root->data)
    { // 25 == 25
        if (root->left == NULL && root->right == NULL)
        {
            // leaf
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        { // 35
            // node with 1 child -> right
            tmp = root->right; // 40
            free(root);
            return tmp;
        }
        else if (root->right == NULL)
        {
            // node with 1 child -> left
            tmp = root->left; // 40
            free(root);
            return tmp;
        }
        else
        {
            // node with 2 child
            tmp = findMinValueNode(root->right); // 80
            root->data = tmp->data;
            root->right = deleteNode(root->right, tmp->data);
        }
    }
    return root;
}

int main()
{
    int n, ch, deln, ch2, i;
    char yn;

start:
    printf("1)Insertion\n2)Deletion\n3)Transversal\n4)Exit");
    scanf("%d", &ch);
    i = 1;
    switch (ch)
    {
    case 1:
    ins:
        printf("Enter the element:");
        scanf("%d", &n);
        if (i == 1)
        {
            root = addNode(n, root);
            i++;
        }
        else
        {
            addNode(n, root);
            i++;
        }
        printf("Do you want to add another element?");
        scanf("%s", &yn);
        if (yn == 'y' || yn == 'Y')
        {
            goto ins;
        }
        else if (yn == 'N' || yn == 'n')
        {
            goto start;
        }
        else
        {
            printf("Enter Y or N");
        }
        break;
    case 2:
    del:
        printf("Enter the node you want to delete:");
        scanf("%d", &deln);
        deleteNode(root, deln);
        printf("Do you want to delete another element?");
        scanf("%s", &yn);
        if (yn == 'y' || yn == 'Y')
        {
            goto del;
        }
        else if (yn == 'N' || yn == 'n')
        {
            goto start;
        }
        else
        {
            printf("Enter Y or N");
        }
        break;
    case 3:
    trav:
        printf("\nEnter type of traversal\n");
        printf("1)Preorder\n2)Inorder\n3)Postorder\n4)Exit\n");
        printf("Enter order of display:\n");
        scanf("%d", &ch2);
        switch (ch2)
        {
        case 1:
            printf("\n Preorder Traversal of constructed BST\n");
            preOrder(root);
            printf("\n");
            goto trav;
            break;
        case 2:
            printf("\nInorder Traversal of constructed BST \n");
            inOrder(root);
            printf("\n");
            goto trav;
            break;
        case 3:
            printf("\nPostorder Traversal of constructed BST\n");
            postOrder(root);
            printf("\n");
            goto trav;
            break;
        case 4:
            goto start;
        default:
            printf("Enter valid Number!");
            goto trav;
            break;
        }
    case 4:
        exit(0);
    }
    // int i=1;

    /*    root = addNode(50,root);//NULL
               addNode(100,root);//50
                addNode(35,root);
                addNode(25,root);
                addNode(40,root);
                addNode(150,root);
                addNode(250,root);
    */
    /* root=addNode(50,root);
         addNode(35,root);
         addNode(25,root);
         addNode(40,root);
         addNode(100,root);
         addNode(80,root);
         addNode(150,root);
         */

    // 1 for add
    // 2 for print
    // print(root);
    /*
    printf("\n%d ",root->data);//50
    printf("\n%d ",root->left->data);//35
    printf("\n%d ",root->left->left->data);//25
    printf("\n%d ",root->left->right->data);//40
    printf("\n%d ",root->right->data);//100
    printf("\n%d ",root->right->right->data);//150
    printf("\n%d ",root->right->right->right->data);//250
    */
    // printf("\nIn Order\n");
    // inOrder(root);
    // printf("\nPre Order\n");
    // preOrder(root);
    // printf("\nPost Order\n");
    // postOrder(root);
    /*deleteNode(root,25);
    printf("\nIn Order\n");
    inOrder(root);


    deleteNode(root,35);
    printf("\nIn Order\n");
    inOrder(root);

    deleteNode(root,50);
    printf("\nIn Order\n");
    inOrder(root);

    return 0;
    */
    // }
    /*

            Tree Travel :-

                        Pre Order ->    Root-Left-Right
                        In  Order ->    Left-Root-Right
                        Post Order ->   Left-Right->Root

                        Pre -> 50 , 35 , 25 , 40 , 100, 150,250
                        In  -> 25,35,40,50,100,150,250 [ asc ]
                        Post-> 25,40,35,





    */
}

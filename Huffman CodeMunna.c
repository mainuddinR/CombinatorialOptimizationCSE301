#include<stdio.h>
struct node
{
    char data;
    int freq;
    struct node *left;
    struct node *right;
};
struct node* createNode(char data,int freq)
{
    struct node *crNode=(struct node*)malloc(sizeof(struct node));
    crNode->data=data;
    crNode->freq=freq;
    crNode->left=NULL;
    crNode->right=NULL;
    return crNode;
}
void huffmancode(char data[],int freq[],int size)
{
    int i;
    struct node* nodes[size];
    for(i=0;i<size;i++)
    {
        nodes[i]=createNode(data[i],freq[i]);
    }
    huffmantree(nodes,size);
    int arr[100],top=0;
    printNode(nodes[0],arr,top);
    char str[100];
    scanf("%s",str);
    decodeHuffman(nodes[0],str);
}
void huffmantree(struct node *nodes[],int size)
{
    int i,j;
    //sort nodes[]
    for(i=0;i<size-1;i++)
    {
        for(j=0;j<size-i-1;j++)
        {
            if(nodes[j]->freq>nodes[j+1]->freq)
            {
                struct node *temp=nodes[j];
                nodes[j]=nodes[j+1];
                nodes[j+1]=temp;
            }
        }
    }
   while(size>1)
   {
        struct node *parent=createNode('x',nodes[0]->freq+nodes[1]->freq);
    parent->left=nodes[0];
    parent->right=nodes[1];
    nodes[0]=parent;
    for(i=1;i<size-1;i++)
    {
        nodes[i]=nodes[i+1];
    }
    size--;
    for(i=0;i<size-1;i++)
    {
        for(j=0;j<size-i-1;j++)
        {
            if(nodes[j]->freq>nodes[j+1]->freq)
            {
                struct node *temp=nodes[j];
                nodes[j]=nodes[j+1];
                nodes[j+1]=temp;
            }
        }
    }

   }
}
void printNode(struct node *root,int arr[],int top)
{
    int i;
    if(root->left)
    {
        arr[top]=0;
        printNode(root->left,arr,top+1);
    }
    if(root->right)
    {
        arr[top]=1;
        printNode(root->right,arr,top+1);
    }
    if(!root->left && !root->right)
    {
        printf("%c : ",root->data);
        for(i=0;i<top;i++)
        {
            printf("%d",arr[i]);
        }
        printf("\n");
    }
}
int main()
{
    char data[]={'a','b','c','d','e','f'};
    int freq[]={5,7,13,14,16,45};
    int size=6;
    huffmancode(data,freq,size);

}
void decodeHuffman(struct Node* root, char* encoded_data) {
    struct node* current = root;
    int i = 0;

    while (encoded_data[i]) {
        if (encoded_data[i] == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (current->left == NULL && current->right == NULL) {
            printf("%c", current->data);
            current = root;
        }

        i++;
    }
}

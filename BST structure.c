#include<stdio.h>
#include<stdlib.h>

struct tree{
    char *str;
    struct tree *left;
    struct tree *right;
};

void inorder(struct tree* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%s\t",root->str);
    inorder(root->right);
}

struct tree *newNode(char *str){
    struct tree *NewNode = (struct tree*)malloc(sizeof(struct tree));
    NewNode->str = str;
    NewNode->left = NULL;
    NewNode->right = NULL;
    return NewNode;
}



int main(){
    struct tree *root = newNode("Arthi");
      root->right = newNode("Christy");
      root->right->left = newNode("Dorothy");
      root->left = newNode("Fraser");
      root->left->right = newNode("Eliza");
 
  
    printf("\n");
    inorder(root);
    root->left->left = newNode("David");
    printf("\nDavid addeed\n");
    inorder(root);
    return 0;
}
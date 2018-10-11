#include<iostream>
#include<queue>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode**children;
    int count;

    TreeNode(int d){
        data = d;
        count =0;
        children = NULL;
    }
};

TreeNode* takeInput(){
    int d,count;
    cin>>d;

    TreeNode* root = new TreeNode(d);
    cout<<" Enter the children count of node "<<d<<" ";

    cin>>count;
    root->count = count;

    root->children = new TreeNode*[count];

    for(int i=0;i<count;i++){
        root->children[i] = takeInput();
    }
    return root;
}

void print(TreeNode* root){
    ///Base Case
    if(root==NULL){
        return;
    }
    ///Otherwise
    ///Print root & children
    cout<<root->data<<" -> ";
    for(int i=0;i<root->count;i++){
        cout<< root->children[i]->data<<" ";
    }

    cout<<endl;
    ///Recursively print the children of root
    for(int i=0;i<root->count;i++){
        print(root->children[i]);
    }
}
void levelOrderPrint(TreeNode*root){

    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
            TreeNode* f = q.front();

            if(f==NULL){
                cout<<endl;
                q.pop();
                if(!q.empty()){
                    q.push(NULL);
                }

            }

            else{
            q.pop();
            cout<< f->data << " ";

            for(int i=0;i<f->count;i++){
                q.push( f->children[i]);
            }

            }
    }
}

int sum(TreeNode*root){
    ///Base Case
    if(root==NULL){
        return 0;
    }
    ///Rec Case
    int s = root->data;
    for(int i=0;i<root->count;i++){
        s += sum(root->children[i]);
    }
    return s;
}

int maxSum(TreeNode*root){
    if(root==NULL){
        return 0;
    }
    int cs = root->data;
    for(int i=0;i<root->count;i++){
        cs += root->children[i]->data;
    }

    int ss;
    for(int i=0;i<root->count;i++){
        ss = maxSum(root->children[i]);
        cs = max(cs,ss);
    }
    return cs;

}

class Pair{
public:
    int sum;
    TreeNode* node;
};

Pair maxSumTwo(TreeNode*root){
    Pair p;
    if(root==NULL){
            p.sum = 0;
            p.node =NULL;
        return p;
    }
    int cs = root->data;
    for(int i=0;i<root->count;i++){
        cs += root->children[i]->data;
    }
    p.sum = cs;
    p.node = root;

    Pair ss;
    for(int i=0;i<root->count;i++){
        ss = maxSumTwo(root->children[i]);
        if(ss.sum > p.sum){
            p.sum = ss.sum;
            p.node = ss.node;
        }
    }
    return p;

}



int height(TreeNode*root){
    if(root==NULL){
        return 0;
    }
    ///Otherwise !
    int h = 0;
    for(int i=0;i<root->count;i++){
        int hc = height(root->children[i]);
        h = max(hc,h);
    }
    return h+1;
}

void printLevelK(TreeNode*root,int k){
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    for(int i=0;i<root->count;i++){
        printLevelK(root->children[i],k-1);
    }

}
int main(){

    TreeNode*root = takeInput();
    print(root);
 //   levelOrderPrint(root);
    printLevelK(root,4);
    cout<<"Height of tree is "<<height(root)<<endl;
    cout<<" Sum of Tree is "<< sum(root)<<endl;
    cout<<" Max sum is "<<maxSum(root)<<endl;
   // cout<< " Max node is "<<maxSumTwo(root).node->data <<endl;
    return 0;

}

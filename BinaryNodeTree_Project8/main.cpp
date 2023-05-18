#include <iostream>
#include "BinaryNodeTree.h"
#include  "bst.h"
#include <string>
#include "time.h"

using namespace std;

void print(int& item)
{
    cout << item << endl;
}

int main() {
   // BinaryNodeTree<string> *treePtr = new BinaryNodeTree<string>();

   int num ;

    srand(1);
    srand(time(NULL));

    //srand(time(NULL));

    auto *treePtr = new BinarySearchTree<int>();

    for(int i=0; i<100;i++)
    {
        num = rand() % 200 +1;

        treePtr->insert(num);
    }


    /*
    treePtr->insert(6);
    //cout<<insert(6)<<endl;
    treePtr->insert(2);

    cout<<"added 20"<<endl;
    treePtr->insert(10);

    cout<<"added 30"<<endl;

     */
    //treePtr->inorderTraverse(print);

    cout<<endl;

 int h = treePtr->getHeight();
 cout << "the height of this BSt is : " << h << endl;
    //cout<<"Pre - order traversal :"<<endl;

    //treePtr->preorderTraverse(print);


    //cout<<"Post - order traversal :"<<endl;

    //treePtr->postorderTraverse(print);

    //cout<<treePtr->getHeight()<<endl;

    cout << " in-order traverse is : " << endl;
    treePtr->traverseInorder();cout << endl;


    cout << " pre-order traverse is : " << endl;
    treePtr->traversePreorder();cout << endl;

    cout << " post-order traverse is : " << endl;
    treePtr->traversePostorder();cout << endl;

   // system("Pause");
    return 0;
}
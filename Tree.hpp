#ifndef TREE_h
#define TREE_h

#include<iostream>
#include<vector>
#include<map>
#include<set>


template <class T> class Tree {
    public:
        

        Tree(){
            root = NULL; //assign null root for empty tree
        };

        ~Tree(){
            delrec(root);
        }
        
        void insertElement(T val){
            tree_node* n = new tree_node; //node to be added

            n->left = NULL;
            n->right = NULL;
            n->value = val; //assign value to node

            tree_node* parent;
            parent = NULL;
            
            if(!root) {
                root = n; //if no tree, add root
            }
            else
	        {
                tree_node* curnode; 
                curnode = root;
                
                while(curnode) //navigate to node
                {
                    parent = curnode;
                    if(n->value > curnode->value) curnode = curnode->right;
                    else curnode = curnode->left;
                    
                }

                if(n->value < parent->value)//decide node location
                    parent->left = n;
                else
                    parent->right = n;
            }
        }
        

        bool search(T val){
            bool ispresent = false;
            if(!root) //can't have value in empty tree
            {
                return false;
            }
            tree_node* curnode;
            curnode = root;
            while(curnode != NULL)
            {
                if(curnode->value == val)//triggered when node is found, otherwise the node is not present and default value of ispresent is maintained
                {
                    ispresent = true;
                    break;
                }
                else
                {
                    if(val>curnode->value) curnode = curnode->right; //navigate to node
                    else curnode = curnode->left;
                }
            }

            return ispresent; //true if value is found
        }



        void deleteElement(T val){
            bool ispresent = false;
            if(!root)
            {
                return; //can't delete from empty tree
            }
            tree_node* curnode; //assign values for navigation nodes
            tree_node* parent;
            curnode = root;
            parent = (tree_node*)NULL;
            while(curnode != NULL) //first check if the node is here, navigate through tree
            {
                if(curnode->value == val)
                {
                    ispresent = true;
                    break;
                }
                else
                {
                    parent = curnode;
                    if(val>curnode->value) curnode = curnode->right;
                    else curnode = curnode->left;
                }
            }
            if(!ispresent)
            {
                return;
            }

            if((curnode->left == NULL && curnode->right != NULL)|| (curnode->left != NULL && curnode->right == NULL)) //condition for one leaf available
            {
                if(curnode->left == NULL && curnode->right != NULL)//if right node is present
                {			
                    if(parent->left == curnode)
                    {
                        parent->left = curnode->right; //replace old parent's left node
                        delete curnode;
                    }
                    else
                    {
                        parent->right = curnode->right; //replace old parent's right node
                        delete curnode;
                    }
                }
                else //if left node is present
                {
                    if(parent->left == curnode)
                    {
                        parent->left = curnode->left; //do the same thing
                        delete curnode;
                    }
                    else
                    {
                        parent->right = curnode->left;
                        delete curnode;
                    }
                }
                return;
            }

            if( curnode->left == NULL && curnode->right == NULL) //if this is end leaf node
            {
                if (parent == NULL) //for small trees
                {
                    delete curnode;

                } 
                else{
                    if(parent->left == curnode) parent->left = NULL; //clear parent node relationship
                    else parent->right = NULL;
                    delete curnode;
                    return;
                    }
                }


            if (curnode->left != NULL && curnode->right != NULL)//for multiple nodes
            {
                tree_node* detect;
                detect = curnode->right;
                if((detect->left == NULL) && (detect->right == NULL)) //go one step down and check children
                {
                    curnode = detect;
                    delete detect;
                    curnode->right = NULL;
                }
                else
                {

                    if((curnode->right)->left != NULL) //check if right node has left child
                    {
                        tree_node* leftcurrent;
                        tree_node* leftcparent;
                        leftcparent = curnode->right;
                        leftcurrent = (curnode->right)->left;
                        while(leftcurrent->left != NULL)
                        {
                            leftcparent = leftcurrent;
                            leftcurrent = leftcurrent->left;
                        }
                        curnode->value = leftcurrent->value;
                        delete leftcurrent;
                        leftcparent->left = NULL;
                    }
                    else //only remaining condition
                    {
                        tree_node* temp;
                        temp = curnode->right;
                        curnode->value = temp->value;
                        curnode->right = temp->right;
                        delete temp;
                    }

                }
                return;

                }
        }


        template<typename U>
        friend std::ostream& operator<<(std::ostream& os, const Tree<U> &t);


    private:
        struct tree_node {
            tree_node* left;
            tree_node* right;
            T value;
        };
        void delrec(tree_node* n) { //helper to delete tree
            if (n) {
	        delrec(n->left);
	        delrec(n->right);
	        delete n;
            }
        }

        void printrecursive(tree_node* n) const{ //helper to print down tree
            if(n != NULL)
            {
                if(n->left) printrecursive(n->left);
                std::cout<<" "<<n->value<<", ";
                if(n->right) printrecursive(n->right);
            }
            else return;

        }


        tree_node* root;
};


template<typename U>
std::ostream& operator<<(std::ostream& os, const Tree<U> &t){
    std::cout << "{";
    t.printrecursive(t.root);
    std::cout << "}";
    return os;
}
#endif
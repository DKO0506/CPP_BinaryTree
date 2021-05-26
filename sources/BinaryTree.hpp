#pragma once

#include <iostream>
#include <list>
#include <map>

namespace ariel {

    template<typename T> class BinaryTree {
       

        struct Node {
            T value;
            Node *right_child;
            Node *left_child;
            Node *parent;
            Node(T v): value(v), right_child(nullptr), left_child(nullptr){}
        };

        class tree_iterator {
        private:
            Node* current_node;
        public:
            tree_iterator(Node* v = nullptr):current_node(v) {}

            tree_iterator& operator++ (){
                return *this;
            }
            tree_iterator operator++ (int a){
                tree_iterator t{current_node};
                return t;
            }

            bool operator!= (const tree_iterator& other){return false;}
            const T& operator* () const {return current_node->value;}
            const T* operator->() const { return &(current_node->value); }

        };

    protected:
        Node* root;
        std::map<T, Node*> vertex;

    public:
       
        
        BinaryTree& add_root(T root){return *this;}
        
        
        BinaryTree& add_right(T node, T rChild){return *this;}
        
        BinaryTree& add_left(T node, T lChild){return *this;}
        
        tree_iterator begin_postorder(){return tree_iterator{root};}
        tree_iterator end_postorder(){return nullptr;}
        
        tree_iterator begin_preorder(){return tree_iterator{root};}
        tree_iterator end_preorder(){return nullptr;}
        
       
        tree_iterator begin_inorder(){return tree_iterator{root};}
        tree_iterator end_inorder(){return nullptr;}

  
        tree_iterator begin(){return tree_iterator{root};}
        tree_iterator end(){return nullptr;}

        friend std::ostream& operator<<(std::ostream& out, BinaryTree<T> const &tree){
            return out << "Printing tree" << std::endl;}
    };
};

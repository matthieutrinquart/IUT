#include <cstdlib>
#include <iostream>
using namespace std;

template <class K, class V> class Tree;

template <class K, class V>
class Node{
    K key;
    V value;
    Node *parent, *left, *right;
    
    // Constructor with key, value, parent, left, right
    Node(K k, V v, Node *p = NULL, Node *l = NULL, Node *r = NULL) {
        key = k;
        value = v;
        parent = p;
        left = l;
        right = r;
    }
     
    // Get the node with a given key, NULL if not found
    Node* get(K k) {
        if(key == k)
            return this;
        if(k < key)
            return left == NULL ? NULL : left->get(k);
        return right == NULL ? NULL : right->get(k);
    }    
    
    // Set the value for a key, true if a new node is created
    bool set(K k, V v) {
        if(key == k) {
            value = v;
            return false;
        }
        if(k < key && left != NULL)
            return left->set(k, v);
        if(k > key && right != NULL) 
            return right->set(k, v);
        
        // Key is not present yet
        if(k < key) {
            left = new Node(k, v, this);
            return true;
        }
        else {
            right = new Node(k, v, this);
            return true;
        }
    }
    
    bool isLeaf() {return left==NULL && right==NULL;}
    bool hasRightChild() {return right!=NULL;}
    
    Node* min() {
        if(left == NULL)
            return this;
        return left->min();
    }

    Node* max() {
        if(right == NULL)
            return this;
        return right->max();
    }

    Node* next() {
        if(right != NULL)
            return right->min();
        auto cur = this;
        while(cur != NULL && cur->key <= key)
            cur = cur->parent;
        
        return cur;
    }
    
    void remove() {
        // Leaf node removal
        if(isLeaf()) {
            if(parent->left == this)
                parent->left = NULL;
            else
                parent->right = NULL;
            delete this;
            return;
        }

        // Internal node removal
        auto replacement = hasRightChild() ? right->min() : left->max();
        key = replacement->key;
        value = replacement->value;
        replacement->remove();
    }

public:
    K getKey() const {return key;}
    V getValue() const {return value;}    
    
    friend ostream& operator<<(ostream& os, Node<K,V> *node) {
        os << '(' << node->getKey() << ',' << node->getValue() << ')';
        return os;
    }

    friend class Tree<K,V>;
};


// Class for a binary search tree
template <class K, class V>
class Tree {
    Node<K,V> *root = NULL;
public:
    bool isEmpty() {
        return root == NULL;
    }
  
    // Returns true if a new node is created
    bool set(K k, V v) {
        // Tree was empty
        if(root == NULL) {
            root = new Node<K,V>(k,v);
            return true;
        }
        
        // Tree was not empty
        return root->set(k, v);
    }
    
    // Get the node with a given key
    Node<K,V> *get(K k) {
        if(root == NULL)
            return NULL;
        return root->get(k);
    }
    
    // Returns false if the key is not present
    bool remove(K k) {
        //Cannot delete from an empty tree
        if(root == NULL) 
            return false;
        
        Node<K,V> *node = root->get(k);
        
        // Key is not in the tree. Cannot delete
        if(node == NULL)
            return false; 
            
        // Deleting last element gives an empty tree
        if(node == root && node->isLeaf()) {
            delete root;
            root = NULL;
            return true;
        }

        // Normal deletion of a node
        node->remove();
        return true;
    }
    
    // Returns NULL on empty tree
    Node<K,V> *min() {
        if(root == NULL)
            return NULL;
        return root->min();
    }
    
    // Next node in order, NULL if last
    Node<K,V> *next(Node<K,V> *node) {
        if(node == NULL)
            return NULL;
        return node->next();
    }
    
    // Remove all elements
    void clear() {
        while(!isEmpty()) 
            remove(root->getKey());
    }
    
    ~Tree<K,V>() {
        clear();
    }
};


int main() {
    Tree<string,int> *bst = new Tree<string,int>();
    
    cout <<"Numbers in lexicographical order:" << endl;
    bst->set("one",1);
    bst->set("two",2);
    bst->set("three",3);
    bst->set("four",4);
    bst->set("five",5);
    bst->set("six",6);
    bst->set("seven",7);
    bst->set("eight",8);
    bst->set("nine",9);
    
    auto cur = bst->min();
    while(cur != NULL) {
        cout << cur << endl;
        cur = bst->next(cur);
    } 
    
    cout << endl << "Removing one, two, three:" << endl;
    bst->remove("one");
    bst->remove("two");
    bst->remove("three");
    cur = bst->min();
    while(cur != NULL) {
        cout << cur << endl;
        cur = bst->next(cur);
    } 

    delete bst;
    return 0;
}


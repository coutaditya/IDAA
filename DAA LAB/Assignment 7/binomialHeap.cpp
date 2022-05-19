#include <bits/stdc++.h>
using namespace std;

// A binomial heap node structure
struct node{
    int degree, data;
    struct node *parent, *sibling, *child;
};

// This function creates a new node with given key
struct node *newNode(int key){
    struct node *temp = new node;
    temp->data = key;
    temp->degree = 0;
    temp->child = temp->parent = temp->sibling = NULL;
    return temp;
    }

    // Merging two binomial trees
    struct node *mergeBinomialTrees(struct node *b1, struct node *b2){

    if (b1->data > b2->data)
        swap(b1, b2);

    b2->parent = b1;
    b2->sibling = b1->child;
    b1->child = b2;
    b1->degree++;

    return b1;
    }

    // This function performs union of two Binomial heaps
    list<node *> unionBinomialHeap(list<node *> l1, list<node *> l2){
    list<node *> res;

    auto i = l1.begin();
    auto j = l2.begin();

    while (i != l1.end() && j != l2.end())
    {
        if ((*i)->degree <= (*j)->degree)
        {
        res.push_back((*i));
        i++;
        }
        else
        {
        res.push_back((*j));
        j++;
        }
    }

    while (i != l1.end())
    {
        res.push_back((*i));
        i++;
    }

    while (j != l2.end())
    {
        res.push_back((*j));
        j++;
    }

    return res;
}

// Adjust function ensures that the root nodes in list are in increasing order and no two binomial trees
// have the same degree.
list<node *> adjust(list<node *> heap){

    if (heap.size() <= 1)
        return heap;

    list<node *> new_heap;
    list<node *>::iterator it1, it2, it3;
    it1 = it2 = it3 = heap.begin();

    if (heap.size() == 2)
    {
        it2 = it1;
        it2++;
        it3 = heap.end();
    }
    else
    {
        it2++;
        it3 = it2;
        it3++;
    }

    while (it1 != heap.end())
    {
        if (it2 == heap.end())
        it1++;
        else if ((*it1)->degree < (*it2)->degree)
        {
        it1++;
        it2++;
        if (it3 != heap.end())
            it3++;
        }
        else if (it3 != heap.end() && (*it1)->degree == (*it2)->degree && (*it1)->degree == (*it3)->degree)
        {
        it1++;
        it2++;
        it3++;
        }
        else if ((*it1)->degree == (*it2)->degree)
        {
        struct node *temp;
        *it1 = mergeBinomialTrees(*it1, *it2);
        it2 = heap.erase(it2);
        if (it3 != heap.end())
            it3++;
        }
    }

    return heap;
}

// This function adds a Binomial tree in heap and then performs union on it
list<node *> insertTreeInHeap(list<node *> heap, struct node *tree){
    list<node *> temp;
    temp.push_back(tree);

    temp = unionBinomialHeap(temp, heap);

    return adjust(temp);
}

// This function inserts a new node in Binomial heap
list<node *> insert(int key, list<node *> heap){
    struct node *temp;
    temp = newNode(key);
    return insertTreeInHeap(heap, temp);
}

// This function returns the pointer to the minimum element of entire heap
struct node *getMin(list<node *> heap){
    struct node *minimum = NULL;
    int mini = INT_MAX;
    auto it = heap.begin();
    while (it != heap.end())
    {
        if ((*it)->data < mini)
        {
        mini = (*it)->data;
        minimum = (*it);
        }

        it++;
    }

    return minimum;
}

// This function is a helper function and it includes all the children of minimum node in the main root list and then performs union and adjust to ensure binomial trees of unique degree
list<node *> removeMinimum(struct node *tree){
    list<node *> heap;
    struct node *temp = tree->child;
    struct node *helper;

    while (temp)
    {
        helper = temp;
        temp = temp->sibling;
        helper->sibling = NULL;
        helper->parent = NULL;
        heap.push_front(helper);
    }
    return heap;
}

// This function extracts the minimum node from the Binomial heap and returns the modified heap
list<node *> extractMin(list<node *> heap){
    list<node *> new_heap, helper;
    struct node *temp;

    temp = getMin(heap);
    auto it = heap.begin();

    while (it != heap.end())
    {
        if ((*it) != temp)
        {
        new_heap.push_back((*it));
        }
        it++;
    }

    helper = removeMinimum(temp);
    helper = unionBinomialHeap(new_heap, helper);
    helper = adjust(helper);
    return helper;
}

// This function searches a given Binomial tree for a node with a given value and returns the pointer to that node
struct node *findNode(struct node *h, int val){
  if (h == NULL)
    return NULL;

  if (h->data == val)
    return h;

  struct node *res = findNode(h->child, val);
  if (res != NULL)
    return res;

  return findNode(h->sibling, val);
}

// This function takes input an old and a new key and replaces old key with new key and performs necessary swapping to ensure min-heap property
list<node *> decreaseKey(list<node *> heap, int old_val, int new_val){
  struct node *temp = NULL;
  auto it = heap.begin();

  while (it != heap.end()){
    temp = findNode(*it, old_val);

    if (temp != NULL)
      break;
    // (*it) = (*it)->sibling;
    it++;
  }

  if (temp == NULL)
    return heap;

  temp->data = new_val;

  struct node *parent = temp->parent;

  while (parent != NULL && temp->data < parent->data){
    swap(temp->data, parent->data);
    temp = parent;
    parent = parent->parent;
  }

  return heap;
}

// This function takes input a value and deletes the node with corresponding value from the Binary heap
list<node *> deleteNode(list<node *> heap, int val){
  struct node *temp = NULL;
  auto it = heap.begin();

  while (it != heap.end())
  {
    temp = findNode(*it, val);

    if (temp != NULL)
      break;

    it++;
  }

  if (temp == NULL)
  {
    cout << "Value to be deleted not found in heap " << endl;
    return heap;
  }

  temp->data = INT_MIN;
  struct node *parent = temp->parent;

  while (parent != NULL && temp->data < parent->data)
  {
    swap(temp->data, parent->data);
    temp = parent;
    parent = parent->parent;
  }
  heap = extractMin(heap);

  return heap;
}

// This function take input a root of a Binomial tree and prints all the values in that tree using DFS approach
void printTree(struct node *root){
  while (root)
  {
    cout << root->data << " ";
    printTree(root->child);
    root = root->sibling;
  }
}

// This function takes input of a Binomial heap and prints all its key values
void printHeap(list<node *> heap){
  auto it = heap.begin();

  while (it != heap.end())
  {
    printTree(*it);
    it++;
  }

  cout << endl;
}

// Main function
int main(){
    // 1. Creating a Binomial heap
    list<node *> heap;

    // 2. Inserting values in Binomial heap
    heap = insert(1, heap);
    heap = insert(2, heap);
    heap = insert(3, heap);
    heap = insert(4, heap);
    heap = insert(5, heap);
    heap = insert(6, heap);
    cout << "The heap formed is as follows\n";
    printHeap(heap);

    // 3. Getting minimum element from heap
    cout << "The minimum element in heap is " << getMin(heap)->data << endl;

    // 4. Removing minimum element from heap
    heap = extractMin(heap);
    cout << "Heap after extracing minimum value is as follows \n";
    printHeap(heap);

    // 5. Decreasing a key
    heap = decreaseKey(heap, 2, -1);
    cout << "Heap after decreasing a key is as follows\n";
    printHeap(heap);

    // 6. Deleting a node
    heap = deleteNode(heap, 4);
    cout << "Heap after deleting node is as follows\n";
    printHeap(heap);

    return 0;
}

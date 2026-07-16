/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};
*/

class Solution {
public:

    Node* merge(Node* t1, Node* t2) {

        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;

        while (t1 != nullptr && t2 != nullptr) {

            if (t1->data < t2->data) {
                res->bottom = t1;
                res = t1;
                t1 = t1->bottom;
            }
            else {
                res->bottom = t2;
                res = t2;
                t2 = t2->bottom;
            }

            res->next = nullptr;
        }

        if (t1)
            res->bottom = t1;
        else
            res->bottom = t2;

        return dummyNode->bottom;
    }

    Node* flatten(Node* root) {

        if (root == nullptr || root->next == nullptr)
            return root;

        Node* mergedHead = flatten(root->next);

        return merge(root, mergedHead);
    }
};
#include <iostream>
#include <queue>
#include <vector>

#include "Node.h"

using namespace std;


static void inOrder(Node *root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

static void preOrder(Node *root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

static void postOrder(Node *root) {
    if (root == nullptr) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

vector<vector<int> > levelOrder(Node *root) {
    if (root == nullptr) {
        return {};
    }
    queue<Node *> q;
    vector<vector<int> > res;
    q.push(root);
    int curLevel = 0;
    while (!q.empty()) {
        int len = q.size();
        res.push_back({});
        for (int i = 0; i < len; i++) {
            Node *n = q.front();
            q.pop();
            res[curLevel].push_back(n->data);
            if (n->left != nullptr) {
                q.push(n->left);
            }
            if (n->right != nullptr) {
                q.push(n->right);
            }
        }
        curLevel++;
    }
    return res;
}
//LRR
static bool ifNodeExits(Node* root,int key) {
    if (root == nullptr) {
        return false;
    }
    if (root->data==key ) {
        return true;
    }
    bool res = ifNodeExits(root->left,key);
    if (res) {
        return true;
    }
    bool res2 = ifNodeExits(root->right,key);
    return res2;


}
int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    inOrder(root);
    cout << endl;
    preOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    cout << endl;
    vector<vector<int> > res = levelOrder(root);
    for (vector<int> v: res) {
        for (int val: v) {
            cout << val << " ";
        }
        cout << endl;
    }
    bool resx = ifNodeExits(root,21);
    cout<<resx<<endl;
    return 0;
}

//
// Created by WAE on 2022/12/14.
//

#include <bits/stdc++.h>

using namespace std;

class TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode* insertNode(string &input){
        trimLeftTrailingSpaces(input);
        trimRightTrailingSpaces(input);
        input = input.substr(1, input.length() - 2);
        if (!input.size()) {
            return nullptr;
        }

        string item;
        stringstream ss;
        ss.str(input);

        getline(ss, item, ',');
        TreeNode* root = new TreeNode(stoi(item));
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while (true) {
            TreeNode* node = nodeQueue.front();
            nodeQueue.pop();

            if (!getline(ss, item, ',')) {
                break;
            }

            trimLeftTrailingSpaces(item);
            if (item != "null") {
                int leftNumber = stoi(item);
                node->left = new TreeNode(leftNumber);
                nodeQueue.push(node->left);
            }

            if (!getline(ss, item, ',')) {
                break;
            }

            trimLeftTrailingSpaces(item);
            if (item != "null") {
                int rightNumber = stoi(item);
                node->right = new TreeNode(rightNumber);
                nodeQueue.push(node->right);
            }
        }
        return root;
    }

    void trimLeftTrailingSpaces(string &input) {
        input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
            return !isspace(ch);
        }));
    }

    void trimRightTrailingSpaces(string &input) {
        input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
            return !isspace(ch);
        }).base(), input.end());
    }

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class ListNode{
    int val;
    ListNode *next;
public:
    void trimLeftTrailingSpaces(string &input) {
        input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
            return !isspace(ch);
        }));
    }

    void trimRightTrailingSpaces(string &input) {
        input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
            return !isspace(ch);
        }).base(), input.end());
    }

    vector<int> stringToIntegerVector(string input) {
        vector<int> output;
        trimLeftTrailingSpaces(input);
        trimRightTrailingSpaces(input);
        input = input.substr(1, input.length() - 2);
        stringstream ss;
        ss.str(input);
        string item;
        char delim = ',';
        while (getline(ss, item, delim)) {
            output.push_back(stoi(item));
        }
        return output;
    }

    ListNode* stringToListNode(string input) {
        // Generate list from the input
        vector<int> list = stringToIntegerVector(input);

        // Now convert that list into linked list
        ListNode* dummyRoot = new ListNode(0);
        ListNode* ptr = dummyRoot;
        for(int item : list) {
            ptr->next = new ListNode(item);
            ptr = ptr->next;
        }
        ptr = dummyRoot->next;
        delete dummyRoot;
        return ptr;
    }

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class DSU{
    vector<int> parents;
    int n = 0;
public:
    int find(int i){
        if(parents[i] == i)
            return i;
        parents[i] = find(parents[i]);
        return parents[i];
    }

    void join(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv)
            return;
        parents[pu] = parents[pv] = min(pu, pv);
    }

    void printSet(){
        for(int &i:parents){
            cout<<i<<" ";
        }
        cout <<"\n";
    }

    DSU(int n){
        this->n = n;
        parents.resize(n);
        iota(parents.begin(), parents.end(), 0);
    }
};

template<typename T>
void printVector(T t){
    for(auto &a:t){
        cout <<a<<", ";
    }
    cout <<"\n";
}
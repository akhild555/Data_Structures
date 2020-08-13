#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>



class Node;

class Node {
public:
    int key;
    Node* parent;
    std::vector<Node*> children;

    Node() {
        this->parent = NULL;
    }

    void setParent(Node* theParent) {
        parent = theParent;
        parent->children.push_back(this);
    }
};


int main_with_large_stack_space() {
    std::ios_base::sync_with_stdio(0);
    int n;
    std::cin >> n;

    std::vector<Node> nodes;
    nodes.resize(n);
    int negOne = 0;
    for (int child_index = 0; child_index < n; child_index++) {
        int parent_index;
        std::cin >> parent_index;
        if (parent_index == -1)
        {
            negOne = child_index; // to keep track of index of root node
        }
        if (parent_index >= 0)
            nodes[child_index].setParent(&nodes[parent_index]);
        nodes[child_index].key = child_index;
    }

    // Naive Implementation Below
    //int maxHeight = 0;
    //for (int leaf_index = 0; leaf_index < n; leaf_index++) {
    //    int height = 0;
    //    for (Node* v = &nodes[leaf_index]; v != NULL; v = v->parent)
    //        height++;
    //    maxHeight = std::max(maxHeight, height);
    //}

    std::queue <Node*> q; // calculate tree height using queue
    q.push(&nodes[negOne]);
    std::vector<int> level(n);
    level[negOne] = 1;

    while (!q.empty())
    {
        Node* v = q.front();
        q.pop();
        std::vector<Node*> p = v->children;
        for (size_t i = 0; i != p.size(); i++)
        {
            q.push(p[i]);
            level[p[i]->key] = level[v->key] + 1; // keep track of height of all nodes
        }
    }

    std::cout << *std::max_element(level.begin(), level.end()) << std::endl;
    return 0;
}

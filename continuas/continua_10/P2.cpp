class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        std::unordered_map<Node*, Node*> clonedNodes;
        return cloneNode(node, clonedNodes);
    }

private:
    Node* cloneNode(Node* node, std::unordered_map<Node*, Node*>& clonedNodes) {
        if (clonedNodes.find(node) != clonedNodes.end()) {
            return clonedNodes[node];
        }

        Node* clone = new Node(node->val);
        clonedNodes[node] = clone;

        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneNode(neighbor, clonedNodes));
        }

        return clone;
    }
};

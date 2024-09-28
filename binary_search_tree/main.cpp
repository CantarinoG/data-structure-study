#include "BinarySearchTree.h"

int main()
{
    BinaryTree<int> tree;

    // Insert the nodes into the tree
    tree.insertNode(1);
    tree.insertNode(2);
    tree.insertNode(3);
    tree.insertNode(4);
    tree.insertNode(5);
    tree.insertNode(6);

    std::cout << "Inorder traversal: ";
    tree.inorder();

    std::cout << "Preorder traversal: ";
    tree.preorder();

    std::cout << "Postorder traversal: ";
    tree.postorder();

    std::cout << "Level order traversal: ";
    tree.levelorder();

    std::cout << "Searching for 7: " << (tree.search(7) ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching for 6: " << (tree.search(6) ? "Found" : "Not Found") << std::endl;

    tree.deleteNode(3);
    std::cout << "Inorder traversal after removing 3: ";
    tree.inorder();

    return 0;
}

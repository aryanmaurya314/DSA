/*
    => what is tree?
    -> non-linear data structure
    -> Binary tree: atmost 2 child on each node
    -> Generic tree: n child on each node
    -> skew tree: only left child or only righ child of each node
    ++++++++++
    # Terminology:
        -> Node: smallest unit of tree contains data, left child pointer, right child pointer
        -> Root: topmost node of a tree
        -> Parent: a node 1 level up
        -> child: 1 level down
        -> ancestor: All nodes in the way of 1 level up
        -> decendent: All nodes in the way of 1 level down
        -> sibling: nodes having same parent
        -> leaf: node having no child

    # Note => parent of root can be assumed as NULL or root itself depending on question

    # Build tree:
        -> using level order traversal
        -> using recursion

    # traversal of tree:
        -> Level order traversal
        -> Inorder traversal ( LNR )
        -> Preorder traversal ( NLR )
        -> Postorder traversal ( LRN )

*/

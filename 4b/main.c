//#include "menu/classic_menu.h"
#include "methods.h"
#include "stdlib.h"
#include "stdio.h"
#include "menu/classic_menu.h"

#ifdef _WIN32
#include "windows.h"
#define select_settings() SetConsoleOutputCP(CP_UTF8)
#else
#define select_settings()
#endif

Node create_nul() {
    Node nul;
    nul.color = 0;
    nul.right = NULL;
    nul.left = NULL;
    nul.key = 0;
    nul.info = NULL;
    return nul;
}

int main(void) {
    select_settings();
    Node nul = create_nul();
    Tree *tree = create_tree(&nul);

    Node *node1 = create_node(&nul, 24, "123");
    add_node(&nul, tree, node1);
    Node *node = create_node(&nul, 5, "432");
    add_node(&nul, tree, node);
    node1 = create_node(&nul, 1, "123");
    add_node(&nul, tree, node1);
    node = create_node(&nul, 15, "123");
    add_node(&nul, tree, node);
    node = create_node(&nul, 3, "123");
    add_node(&nul, tree, node);
    node = create_node(&nul, 8, "123");
    add_node(&nul, tree, node);

//    print_tree(&nul, tree);

//    preorder_traversal(&nul, tree->root, 1);
//    node1 = search_node(&nul, tree, 3);
//    remove_node(&nul, tree, node1);

//    remove_node(tree, node1);
//    node = search_node(tree, 15);
//    tree_traversal(tree, 8);
//    char x[1000] = "";
//    print_root(x, tree->root, 1);
    menu(&nul, tree);
//    print_tree(&nul, tree);
//    scanf("\n");

    return 0;
}

#include "struct.h"
#include "stdlib.h"
#include "ctype.h"

List *initList() {
    List *list = malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void addNext(List *list, char element) {
    Node *node = malloc(sizeof(Node));
    if (!list->head) list->head = node;
    if (list->tail) {
        list->tail->next = node;
    }
    node->next = NULL;
    node->prev = list->tail;
    node->data = element;
    list->tail = node;
}

void swap(Node *node1, Node *node2) {
    char temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

void swap_words(List *list, Node* word1, Node* word2) {
    Node *f1 = word1;
    Node *f2 = word2;
    Node *e1, *e2;
    for (e1 = word1; e1->next && e1->next->data != ' '; e1 = e1->next);
    for (e2 = word2; e2->next && e2->next->data != ' '; e2 = e2->next);
    if (list->head == f1) list->head = f2;
    else if (list->head == f2) list->head = f1;
    Node *temp = f1->prev;
    f1->prev = e2->next;
    f2->prev = temp;

    temp = e1->next;
    e1->next = e2->next;
    e2->next = temp;
}

Node * next_word(Node *word) {
    Node *e;
    for (e = word; e && e->data != ' '; e = e->next);
    if (e != NULL) return e->next;
    else return NULL;
}

int compareWords(Node *word1, Node *word2) {
    for (Node *e1 = word1; e1 && e1->data != ' '; e1 = e1->next) {
        int checker = 0;
        for (Node *e2 = word2; e2 && e2->data != ' '; e2 = e2->next)
            if (tolower(e1->data) == tolower(e2->data)) checker = 1;
        if (checker == 0) return 0;
    }
    for (Node *e1 = word2; e1 && e1->data != ' '; e1 = e1->next) {
        int checker = 0;
        for (Node *e2 = word1; e2 && e2->data != ' '; e2 = e2->next)
            if (tolower(e1->data) == tolower(e2->data)) checker = 1;
        if (checker == 0) return 0;
    }
    return 1;
}


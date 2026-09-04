#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *value;
    struct Node *previous;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    size_t size;
} List;

static char *copy_string(const char *source) {
    size_t length = strlen(source) + 1;
    char *copy = malloc(length);
    if (copy == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    memcpy(copy, source, length);
    return copy;
}

void list_init(List *list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void list_insert(List *list, const char *value) {
    Node *node = malloc(sizeof(*node));
    if (node == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    node->value = copy_string(value);
    node->previous = list->tail;
    node->next = NULL;

    if (list->tail == NULL) {
        list->head = node;
    } else {
        list->tail->next = node;
    }
    list->tail = node;
    list->size++;
}

Node *list_find(const List *list, const char *value) {
    for (Node *node = list->head; node != NULL; node = node->next) {
        if (strcmp(node->value, value) == 0) {
            return node;
        }
    }
    return NULL;
}

int list_delete(List *list, const char *value) {
    Node *node = list_find(list, value);
    if (node == NULL) {
        return 0;
    }

    if (node->previous == NULL) {
        list->head = node->next;
    } else {
        node->previous->next = node->next;
    }

    if (node->next == NULL) {
        list->tail = node->previous;
    } else {
        node->next->previous = node->previous;
    }

    free(node->value);
    free(node);
    list->size--;
    return 1;
}

void list_free(List *list) {
    Node *node = list->head;
    while (node != NULL) {
        Node *next = node->next;
        free(node->value);
        free(node);
        node = next;
    }
    list_init(list);
}

static void run_tests(void) {
    List list;
    list_init(&list);

    assert(list.head == NULL && list.tail == NULL && list.size == 0);

    list_insert(&list, "Hello");
    list_insert(&list, "brave");
    list_insert(&list, "new");
    list_insert(&list, "world!");
    assert(list.size == 4);
    assert(list_find(&list, "new") != NULL);
    assert(list_find(&list, "missing") == NULL);

    assert(list_delete(&list, "Hello") == 1); /* Delete head. */
    assert(strcmp(list.head->value, "brave") == 0);
    assert(list.head->previous == NULL);

    assert(list_delete(&list, "new") == 1);   /* Delete middle. */
    assert(list.head->next == list.tail);
    assert(list.tail->previous == list.head);

    assert(list_delete(&list, "world!") == 1); /* Delete tail. */
    assert(list.tail == list.head);
    assert(list.tail->next == NULL);
    assert(list_delete(&list, "missing") == 0);

    list_free(&list);
    assert(list.head == NULL && list.tail == NULL && list.size == 0);
    puts("All doubly linked list tests passed.");
}

int main(void) {
    puts("Hello, world!");
    run_tests();
    return 0;
}

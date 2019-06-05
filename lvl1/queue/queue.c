#include <stdlib.h>

struct s_node {
    void *content;
    struct s_node *next;
};

struct s_queue {
    struct s_node *first;
    struct s_node *last;
};




struct s_queue *init(void)
{
    struct s_queue *queue;

    queue = (struct s_queue *)malloc(sizeof(struct s_queue));
    queue->first = NULL;
    queue->last = NULL;
    return queue;
}

void enqueue(struct s_queue *queue, void *content)
{
    struct s_node *n = (struct s_node *)malloc(sizeof(struct s_node));

    n->content = content;
    n->next = NULL;
    if (queue->first == NULL)
    {
        queue->first = n;
        queue->last = n;
        return ;
    }
    queue->last->next = n;
    queue->last = n;
}

void *dequeue(struct s_queue *queue)
{
    void    *content = NULL;
    struct s_node       *n = queue->first;
    if (queue->first)
    {
        content = queue->first->content;
        queue->first = n->next;
        queue->last = queue->first ? queue->last : NULL;
        free(n);
    }
    return content;
}

void *peek(struct s_queue *queue)
{
    return queue->first ? queue->first->content : NULL;
}


int isEmpty(struct s_queue *queue)
{
    return !queue->first;
}

//int         main()
//{
//    struct s_queue *q = init();
//    char *hello[] = {
//            "Hello"
//    };
//
//    printf("is empty ? = %d\n", isEmpty(q));
//    printf("peek = %s\n", peek(q));
//    enqueue(q, hello[0]);
//    printf("is empty ? = %d\n", isEmpty(q));
//    printf("peek = %s\n", peek(q));
//    dequeue(q);
//    printf("is empty ? = %d\n", isEmpty(q));
//    printf("peek = %s\n", peek(q));
//}
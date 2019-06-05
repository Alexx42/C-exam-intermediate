	#include <stdlib.h>
    
    struct s_node {
		void          *content;
		struct s_node *next;
	};

	struct s_stack {
		struct s_node *top;
	};

struct s_stack      *init() {
    struct s_stack *s = (struct s_stack *)malloc(sizeof(struct s_stack));
    if (s == NULL)
        return NULL;
    s->top = NULL;
    return s;
}

void *peek(struct s_stack *stack) {
    return stack->top ? stack->top->content : NULL;
}

int isEmpty(struct s_stack *stack) {
    return !stack->top;
}

void *pop(struct s_stack *stack) {
    if (!stack->top) {
        return NULL;
    }
    struct s_node *tmp = stack->top;
    void *content = tmp->content;
    stack->top = tmp->next;
    free(tmp);
    tmp = NULL;
    return content;
}

void push(struct s_stack *stack, void *content) {
     struct s_node *tmp = (struct s_node*)malloc(sizeof(struct s_node));
     if (tmp == NULL)
        return ;
    tmp->content = content;
    tmp->next = stack->top ? stack->top : NULL;
    stack->top = tmp;
}

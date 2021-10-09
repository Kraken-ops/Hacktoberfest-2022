#include <stdio.h>
#include <stdlib.h>

struct Graph {

    int V;  // number of vertices
    int **adj; // adjacency matrix
};

typedef struct Graph Graph;

Graph* new_graph() {

    Graph *graph = (Graph*)malloc(sizeof(Graph));

    graph->V = 0;
    graph->adj = NULL;

    return graph;
} // end of new_graph()

void display_graph(Graph *graph) {

    int **adj = graph->adj;
    int i, j;

    for (i = 0; i < graph->V; i++) {

        printf("vertex %d: ", i);

        for (j = 0; j < graph->V; j++) {

            if (*(*(adj + i) + j)) {
                printf("%d ", j);
            }
        } // end of inner for loop

        printf("\n");
    } // end of outer loop

} // end of display_graph(Graph*)


// **************  Stack starts  **************

struct Node {

	int data;
	struct Node* next;
};

typedef struct Node Node;

Node* new_node() {

    Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = 0;
    newNode->next = NULL;

    return newNode;
} // end of constructor for struct Node


struct Stack {

	struct Node* top;
};

typedef struct Stack Stack;

Stack* new_stack() {

	Stack* stack = (Stack*)malloc(sizeof(Stack));

	stack->top = NULL;

	return stack;
} // end of constructor for struct Stack

int is_stack_empty(Stack *stack) { return (stack->top == NULL); }

void push(Stack* stack, int value) {

	Node *node = new_node();

	node->data = value;
    node->next = stack->top;

	stack->top = node;

} // end of push(stack*, int)

int peek(Stack* stack) { return (stack->top)->data; }

void pop(Stack* stack) {

	if (is_stack_empty(stack)) { return; }

	Node *node = stack->top;
	stack->top = node->next;

	free(node);
} // end of pop(Stack*)

// ***************  Stack ends  ****************

char get_char(int id) { return (char)(id + 65); }

void dfs_traversal(Graph *graph, int starting_vertex) {

    int **adj = graph->adj;

    Stack *stack = new_stack();
    int is_visited[graph->V];
    int i, j;
    int vertex;

    // initialising the is_visited array
    for (i = 0; i <= graph->V; i++) { is_visited [i] = 0; }

    push(stack, starting_vertex);

    while (!is_stack_empty(stack)) {

        vertex = peek(stack);

        if (!is_visited[vertex]) {

		printf("%c ", get_char(vertex));
		is_visited[vertex] = 1;
        }

        for (j = 0; j < graph->V; j++) {

            if (*(*(adj + vertex) + j) && !is_visited[j]) {

                push(stack, j);
                break;
            }

            if (j == graph->V - 1) { pop(stack); }
        } // end of for loop

    } // end of outer while loop

} // end of dfs_traversal(Graph*)

void import_graph(Graph *graph) {

    FILE *fp;
    fp = fopen("input_new.txt", "r");

    if (fp == NULL) {

        printf("error: cannot access file\n");
        exit(1);
    }

    int V;
    fscanf(fp, "%d", &V);

    int **adj = (int**)malloc(sizeof(int*) * V);

    int i = 0, j = 0;
    int val = 0;

    for (; i < V; i++) {

        *(adj + i) = (int*)malloc(sizeof(int*) * V);

        for (j = 0; j < V; j++) {

            fscanf(fp, "%d", &val);
            *(*(adj + i) + j) = val;
        }
    } // end of outer for loop

    fclose(fp);

    graph->V = V;
    graph->adj = adj;

} // end of import_graph(Graph*)


int main() {

    Graph *graph = new_graph();

    import_graph(graph);

    printf("\nGraph :-\n");
    display_graph(graph);

    int starting_vertex;
    printf("\nEnter starting vertex for dfs traversal: ");
    scanf("%d", &starting_vertex);

    printf("\nDFS traversal: ");
    dfs_traversal(graph, starting_vertex);
    printf("\n");

    return 0;
} // end of main()

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *question;
    struct node *yes;
    struct node *no;
} node;

int yes_no(char *question)
{
    char answer[3];
    printf("%s? (y/n): ", question);
    fgets(answer, 3, stdin);
    return answer[0] == 'y';
}

node* create(char *question)
{
    node *n = malloc(sizeof(node));
    n->question = strdup(question);
    n->yes = NULL;
    n->no = NULL;
    return n;
}

void release(node *n)
{
    if (n) {
        if (n->no) {
            release(n->no);
        }
        if (n->yes) {
            release(n->yes);
        }
        if (n->question) {
            free(n->question);
        }
        free(n);
    }
}

int main(int argc, const char *argv[])
{
    char question[80];
    char suspect[20];
    node *start_node = create("Does suspect have mustache");
    start_node->no = create("Loretta Barnsworth"); 
    start_node->yes= create("Vinny the Spoon"); 

    node *current;
    do {
        current = start_node;
        while(1) {
            if (yes_no(current->question)) {
                if (current->yes) {
                    current = current->yes;
                } else {
                    printf("SUSPECT IDENTIFIED\n");
                    break;
                }
            } else if (current->no) {
                current = current->no;
            } else {
                
                // Make the yes node the new suspect name
                printf("Who's the suspect? ");
                fgets(suspect, 20, stdin);
                strtok(suspect, "\n"); //lets remove the newline char!
                node *yes_node = create(suspect);
                current->yes = yes_node;

                // Make the no node a copy of this question
                node *no_node = create(current->question);
                current->no = no_node;

                // Then replace this question with the new question
                printf("Give me a question that is TRUE for %s but not for %s: ", 
                        suspect, current->question);
                fgets(question, 80, stdin);
                strtok(question, "\n"); //lets remove the newline char!
                // we have to free the existing question before allocating to it
                // otherwise we get a memory leak!
                free(current->question);
                current->question = strdup(question);

                break;
            }
        }
    } while(yes_no("Run again"));
    release(start_node);
    return 0;
}

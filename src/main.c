#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./inc/linkedList.h"

void print_entry(char *entry) {
	printf("You entered: %s\n", entry);
}

int main(int argc, char *argv[]) {
	char input[201];
        struct node *head = NULL;
	while(1) {
		printf("prompt> ");
		if (fgets(input, 200, stdin) == NULL) {
			printf("An error ocurred.\n");
			break;
		}

		if (strncmp(input, "exit\n", 5) == 0) {
			printf("Leaving. Good bye.\n");
			break;
		}
                
                if (strncmp(input, "put\n", 3) == 0) {
                    put(&head, getNumber(input));
		} 
                
                if (strncmp(input, "list\n", 5) == 0) {
                    list(&head);
		}
                
                if (strncmp(input, "get\n", 3) == 0) {
                    getPos(&head, getNumber(input));
		}
                
                if (strncmp(input, "last\n", 4) == 0) {
                    getLast(&head);
		}
                
                if (strncmp(input, "remove\n", 6) == 0) {
                    removePos(&head, getNumber(input));
		}
                
                if (strncmp(input, "desc\n", 3) == 0) {
                    removePos(&head);
		}
                
                if (strncmp(input, "asc\n", 3) == 0) {
                    removePos(&head);
		}


		print_entry(input);
	}

	return EXIT_SUCCESS;
}

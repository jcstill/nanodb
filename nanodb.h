#ifndef __nanodb_h__
#define __nanodb_h__
#include <assert.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/***************************************
*            column headers            *
***************************************/
struct header{
        struct header* next;
        char *columnname;
        char columntype;
};
void print_header(struct header* head){
        struct header* iterator = head;
        printf("H");
        while (iterator != NULL){
                // printf("address: %p name: \"%s\" type: \'%c\'\n", iterator, iterator->columnname, iterator->columntype);
                printf(" -> n:\"%s\"|t:", iterator->columnname);
                switch(iterator->columntype){
                        case 0b0000:
                                printf("\"NULL\"");
                                break;
                        case 0b0001:
                                printf("\"char\"");
                                break;
                        case 0b0010:
                                printf("\"unsigned char\"");
                                break;
                        case 0b0011:
                                printf("\"signed char\"");
                                break;
                        case 0b0100:
                                printf("\"int\"");
                                break;
                        case 0b0101:
                                printf("\"unsigned int\"");
                                break;
                        case 0b0110:
                                printf("\"short\"");
                                break;
                        case 0b0111:
                                printf("\"unsigned short\"");
                                break;
                        case 0b1000:
                                printf("\"long\"");
                                break;
                        case 0b1001:
                                printf("\"unsigned long\"");
                                break;
                        case 0b1010:
                                printf("\"float\"");
                                break;
                        case 0b1011:
                                printf("\"double\"");
                                break;
                        case 0b1100:
                                printf("\"long double\"");
                                break;
                        case 0b1101:
                                printf("\"bool\"");
                                break;
                        case 0b1110:
                                printf("\"string\"");
                                break;
                        case 0b1111:
                                printf("\"NULL\"");
                                break;
                }
                iterator = iterator->next;
        }
        printf("\n");
}
void pushBack_header(struct header** head, char *columnname, char columntype){
        while (*head){
                head = &(*head)->next;
        }
        *head = malloc(sizeof(**head));
        (*head)->columnname = columnname;
        (*head)->columntype = columntype;
        (*head)->next = NULL;
}
void pushFront_header(struct header** head, char *columnname, char columntype){
        struct header* new_node = malloc(sizeof(head));
        new_node->columnname = columnname;
        new_node->columntype = columntype;
        new_node->next = *head;
        *head = new_node;
}


/***************************************
*              column data             *
***************************************/
union dataunion{
        char            data_ch;
        unsigned char   data_uc;
        // int             data_in;
        unsigned int    data_ui;
        // short           data_sh;
        // unsigned short  data_us;
        // long            data_lo;
        // unsigned long   data_ul;
        // float           data_fl;
        // double          data_do;
        // long double     data_ld;
        bool            data_bo;
        // string          data_st;
};
struct data_node{
        struct data_node* right;
        // struct data_node* left;
        // struct data_node* up;
        // struct data_node* down;
        union dataunion data;
};
void print_data_node(struct data_node* head){
        struct data_node* iterator = head;
        while (iterator != NULL){
                printf(" -> \"0x%08X\"", iterator->data.data_ui);
                // printf(" -> \"0x%08X\"", iterator->data.data_ch);
                iterator = iterator->right;
        }
        printf("\n");
}

void pushBack_data_ch(struct data_node** head, char data_ch){
        while (*head){
                head = &(*head)->right;
        }
        *head = malloc(sizeof(**head));
        (*head)->data.data_ch = data_ch;
        (*head)->right = NULL;
}
void pushFront_data_ch(struct data_node** head, char data_ch){
        struct data_node* new_node = malloc(sizeof(head));
        new_node->data.data_ch = data_ch;
        new_node->right = *head;
        *head = new_node;
}
// void popBack_data(struct data_node** head){
//         struct data_node* tmp = *head;
//         while (tmp->right->right){
//                 tmp = tmp->right;
//         }
//         free (tmp->right);
//         tmp->right = NULL;
// }

void pushBack_data_ui(struct data_node** head, char data_ui){
        while (*head){
                head = &(*head)->right;
        }
        *head = malloc(sizeof(**head));
        (*head)->data.data_ui = data_ui;
        (*head)->right = NULL;
}
void pushFront_data_ui(struct data_node** head, char data_ui){
        struct data_node* new_node = malloc(sizeof(head));
        new_node->data.data_ui = data_ui;
        new_node->right = *head;
        *head = new_node;
}

void pushBack_data_bo(struct data_node** head, char data_bo){
        while (*head){
                head = &(*head)->right;
        }
        *head = malloc(sizeof(**head));
        (*head)->data.data_bo = data_bo;
        (*head)->right = NULL;
}
void pushFront_data_bo(struct data_node** head, char data_bo){
        struct data_node* new_node = malloc(sizeof(head));
        new_node->data.data_bo = data_bo;
        new_node->right = *head;
        *head = new_node;
}


/***************************************
*            list of columns           *
***************************************/
struct rowlist{
        struct data_node* rowdata;
        struct rowlist* next;
};

void pushBack_rowlist(struct rowlist** head, struct data_node** data){
        while (*head){
                head = &(*head)->next;
        }
        *head = malloc(sizeof(**head));
        (*head)->rowdata = *data;
        (*head)->next = NULL;
}
void pushFront_rowlist(struct rowlist** head, struct data_node** data){
        struct rowlist* new_node = malloc(sizeof(head));
        new_node->rowdata = *data;
        new_node->next = *head;
        *head = new_node;
}

void print_rowlist(struct rowlist* head){
        // struct rowlist* iterator = head->next;
        struct rowlist* iterator = head;
        int i=0;
        while (iterator != NULL){
                printf("%d", i);
                print_data_node(iterator->rowdata);
                iterator = iterator->next;
                ++i;
        }
        printf("\n");
}














#endif
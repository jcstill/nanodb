#include "nanodb.h"
#include <string.h>


// void print_bin(unsigned char value){
//         for (int i = sizeof(char) * 7; i >= 0; i--){
//                 printf("%d", (value & (1 << i)) >> i );
//         }
//         putc('\n', stdout);
// }












































int main(){
















        // header
        struct header* head = NULL;
        pushBack_header(&head, "T or F", 0b1101);
        pushBack_header(&head, "number", 0b0101);
        pushBack_header(&head, "name", 0b1110);
        print_header(head);

        // list of rows
        struct rowlist* rows = NULL;

        struct data_node* row0 = NULL;
        pushBack_data_bo(&row0, false);
        pushBack_data_ui(&row0, 82);
        pushBack_data_ch(&row0, 'H');
        pushBack_rowlist(&rows, &row0);

        struct data_node* row1 = NULL;
        pushBack_data_bo(&row1, true);
        pushBack_data_ui(&row1, 11);
        pushBack_data_ch(&row1, 'A');
        pushBack_rowlist(&rows, &row1);

        struct data_node* row2 = NULL;
        pushBack_data_bo(&row2, false);
        pushBack_data_ui(&row2, 63);
        pushBack_data_ch(&row2, 'J');
        pushBack_rowlist(&rows, &row2);

        struct data_node* row3 = NULL;
        pushBack_data_bo(&row3, true);
        pushBack_data_ui(&row3, 172);
        pushBack_data_ch(&row3, 'B');
        pushBack_rowlist(&rows, &row3);

        struct data_node* row4 = NULL;
        pushBack_data_bo(&row4, false);
        pushBack_data_ui(&row4, 62);
        pushBack_data_ch(&row4, 't');
        pushBack_rowlist(&rows, &row4);

        struct data_node* row5 = NULL;
        pushBack_data_bo(&row5, true);
        pushBack_data_ui(&row5, 38);
        pushBack_data_ch(&row5, '%');
        pushBack_rowlist(&rows, &row5);

        struct data_node* row6 = NULL;
        pushBack_data_bo(&row6, false);
        pushBack_data_ui(&row6, 255);
        pushBack_data_ch(&row6, 255);
        pushBack_rowlist(&rows, &row6);

        // popBack_data(&row3);
        // popBack_data(&row3);
        // popBack_data(&row5);

        print_rowlist(rows);

        return 0;
}






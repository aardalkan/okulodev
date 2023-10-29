#pragma warning(disable:4996)


#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>



struct tekcift
{
    int data;
    struct tekcift* next;
}; 

struct tekcift* createNode(int data) {
    struct tekcift* newNode = (struct tekcift*)malloc(sizeof(struct tekcift));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct tekcift** head, int data) {
    struct tekcift* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct tekcift** head, int data) {
    struct tekcift* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct tekcift* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(struct tekcift* node) {
    while (node != NULL) {
        printf("%d, ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}








typedef struct rastgele {
    int data;
    struct rastgele* next;
} rastgele;

struct rastgele* createNode2(int data) {
    struct rastgele* newNode2 = (struct rastgele*)malloc(sizeof(struct rastgele));
    newNode2->data = data;
    newNode2->next = NULL;
    return newNode2;
}

void insertRandomNumber(struct rastgele** head, int data) {
    struct rastgele* newNode2 = createNode2(data);
    newNode2->next = *head;
    *head = newNode2;
}

void printList2(struct rastgele* node) {
    while (node != NULL) {
        printf("%d, ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void Sort(rastgele* head) {
    int incomplete;
    rastgele* ptr1;
    rastgele* lptr = NULL;

    do {
        incomplete = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {

                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;

                incomplete = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (incomplete);
}







struct studentdatabase
{
    char name[30];
    int age;
    int id;

    struct studentdatabase* next;
};

struct studentdatabase* createNode3(char name[30], int age, int id) {
    struct studentdatabase* newNode3 = (struct studentdatabase*)malloc(sizeof(struct studentdatabase));
    strcpy(newNode3->name, name);
    newNode3->age = age;
    newNode3->id = id;
    newNode3->next = NULL;
    return newNode3;
}

void insertStudent(struct studentdatabase** head, char name[30], int age, int id) {
    struct studentdatabase* newNode3 = createNode3(name, age, id);
    newNode3->next = *head;
    *head = newNode3;
}

void printList3(struct studentdatabase* node) {
    int counter = 1;
    while (node != NULL) {
        printf("%d- %s, %d, %d\n", counter, node->name, node->age, node->id);
        node = node->next;
        counter++;
    }
}








void checkRegistration(struct studentdatabase* node) {
    char registrationsearch[30];
    scanf_s("%29s", registrationsearch, sizeof(registrationsearch));

    int checker = 1;

    while (node != NULL && checker) {
        if (strcmp(node->name, registrationsearch) == 0) {
            checker = 0;
            printf("the student you searched for is registered!\n");

            if (node->next != NULL) {
                int input;
                printf("Next student is %s\n", node->next->name);
                printf("Do you wish to delete %s's registration? (1/0) ", node->next->name);
                scanf_s("%d", &input);

                if (input) {
                    struct studentdatabase* temp = node->next;
                    node->next = node->next->next;
                    free(temp);
                }
            }
        }

        node = node->next;
    }

    if (checker)
        printf("the student you searched for is NOT registered.!\n");
}






void longestName(struct studentdatabase* node) {
    char tempname[30] = "";
    while (node != NULL) {
        if (strlen(node->name) > strlen(tempname)) {
            strcpy(tempname, node->name);
        }
        node = node->next;
    }
    printf("%s", tempname);
}















int main() {


    struct tekcift* head1 = NULL;
    int tekciftinputvalue;


    struct rastgele* head2 = NULL;
    srand(time(NULL));
    int randomnumber = rand();


    struct studentdatabase* head3 = NULL;
    insertStudent(&head3, "ogrenci", 15, 1001);
    insertStudent(&head3, "Ali", 22, 1001);
    insertStudent(&head3, "Ayse", 23, 1002);
    insertStudent(&head3, "Mehmet", 21, 1003);
    insertStudent(&head3, "Zeynep", 20, 1004);
    insertStudent(&head3, "Emir", 19, 1005);
    insertStudent(&head3, "Elif", 24, 1006);
    insertStudent(&head3, "Eren", 20, 1007);
    insertStudent(&head3, "Selin", 22, 1008);
    insertStudent(&head3, "Canan", 17, 1009);
    


    while (1) {
        int choice;
        scanf_s("%d", &choice);

        switch (choice) {


        case 1:
            scanf_s("%d", &tekciftinputvalue);
            while (tekciftinputvalue != -1) {

                if (tekciftinputvalue % 2 == 0) {
                    insertAtBeginning(&head1, tekciftinputvalue);
                }
                else {
                    insertAtEnd(&head1, tekciftinputvalue);
                }
                printList(head1);
                scanf_s("%d", &tekciftinputvalue);
            }
            break;


        case 2:
            for (int i = 0; i < 100; i++) {
                randomnumber = rand();
                insertRandomNumber(&head2, randomnumber);
            }

            printList2(head2);
            Sort(head2);
            printf(" \n");
            printList2(head2);
            break;


        case 3:
            printList3(head3);
            break;


        case 4:
            checkRegistration(head3);
            break;

        case 5:
            longestName(head3);
            break;

        }



    }









    return 0;
}
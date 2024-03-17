#include <stdio.h>
#include <stdlib.h>

struct Tache{

    int data;
    struct Tache *next;
    struct Tache *prev;

 };


typedef struct Tache *node;

 typedef struct {

    node first;
    node last;

 }Pointers;


node createNode(int Value_of_Data){
    node temp;
    temp = (node)malloc(sizeof(struct Tache));
    temp->data = Value_of_Data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

Pointers addNode(node head, int Value_of_Data)
{

    Pointers pointers;
    node temp,p;
    temp = createNode(Value_of_Data);
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        p  = head;
        while(p->next != NULL)
        {
                if(temp->data > p->data)
                {
                        printf("\n\n%d",p->data);
                        break;

                }
                p = p->next;
        }

        if(temp->data > p->data)
        {
                    if(p->prev == NULL)
                    {
                        temp->prev=NULL;
                        p->prev = temp;
                        temp->next = p;
                        pointers.first = temp;
                        while(p->next != NULL)
                            {
                                p = p->next;
                            }
                        pointers.last = p;
                        return pointers;
                    }else
                    {
                        p->prev->next=temp;
                        temp->prev=p->prev;
                        p->prev = temp;
                        temp->next = p;
                        pointers.first = head;
                        while(p->next != NULL)
                            {
                                p = p->next;
                            }
                        pointers.last = p;
                        return pointers;
                    }
        }else
        {
                    temp->next = p->next;
                    p->next = temp;
                    temp->prev = p;
                    pointers.first = head;
                    pointers.last = temp;
                    return pointers;
        }
    }

}

            void Affichage_normal(node head)
            {
                while(head->next != NULL)
                    {
                        printf("\n--%d**\n",head->data);
                        head = head->next;
                    }
                printf("\n--%d**\n",head->data);
            head = NULL;
            }

            void Affichage_inverse(node last)
            {
                while(last->prev != NULL)
                    {
                        printf("\n--%d**\n",last->data);
                        last = last->prev;
                    }
                printf("\n--%d**\n",last->data);

            last = NULL;
            }


int main()
{
        Pointers first_last;
        node my_list;

    my_list = NULL;
    first_last=addNode(my_list,5);
    first_last=addNode(first_last.first,5);
    first_last=addNode(first_last.first,3);
    first_last=addNode(first_last.first,2);
    first_last=addNode(first_last.first,1);
    first_last=addNode(first_last.first,7);
    first_last=addNode(first_last.first,0);
    first_last=addNode(first_last.first,6);
    first_last=addNode(first_last.first,7);
    first_last=addNode(first_last.first,1);
    first_last=addNode(first_last.first,99);
    first_last=addNode(first_last.first,85);
    first_last=addNode(first_last.first,66);
    first_last=addNode(first_last.first,92);
    first_last=addNode(first_last.first,0);
    first_last=addNode(first_last.first,77);


Affichage_normal(first_last.first);
printf("\n--------------------\n");
Affichage_inverse(first_last.last);

return 0;
}

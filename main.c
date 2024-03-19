#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int Tache_ID =1;

typedef struct
{
    int annee,mois,jour,heure,minute;

}Date;

 struct Tache{

    int id;
    int prio;
    char desc[500];
    Date date;
    bool completer;

    struct Tache *next;
    struct Tache *prev;

 };


typedef struct Tache *node;

 typedef struct {

    node first;
    node last;

 }Pointers;


 int read_int(char* donnee)
 {
     char my_Int[20];

        printf("Saisissez %s\n",donnee);
        scanf("%s",my_Int);

            bool flag ;
            do
            {

                flag= true;
                int i=0;
                for( i == 0; i <strlen(my_Int) ; i++ )
                {
                    if(my_Int[i]< 48 || my_Int[i]>57)
                    {
                        while(getchar()!='\n');
                        printf("\n Entrez une valeur exacte\n");
                        scanf("%s",my_Int);
                        flag =false;
                        break;
                    }
                }

            }while(flag == false);

return atoi(my_Int);
 }

node createNode(){
    node temp;
    temp = (node)malloc(sizeof(struct Tache));
    temp->next = NULL;
    temp->prev = NULL;

    temp->id = Tache_ID;
    Tache_ID++;

    temp->completer = false;

    printf("Tache %d \n\nSaisisez une description\n",temp->id);
    scanf(" %[^\n]",temp->desc);

    printf("Entrez la date ::---------------------------------------\n");

                printf("Annee :     ");
                do{
                    temp->date.annee = read_int("Anne");
                }while(temp->date.annee != 2024);

                printf("Mois  :     ");
                do{
                    temp->date.mois =read_int("Mois");
                }while(temp->date.mois < 1 || temp->date.mois > 12);
                printf("Jour  :     ");
                if(temp->date.mois == 1 || temp->date.mois == 3 || temp->date.mois == 5 || temp->date.mois == 7 || temp->date.mois == 8 || temp->date.mois == 10 || temp->date.mois == 12)
                {
                    do{
                        temp->date.jour = read_int("Jour");
                    }while(temp->date.jour < 1 || temp->date.jour>31);

                }else if(temp->date.mois == 2)
                {
                    do{
                        temp->date.jour = read_int("Jour");
                    }while(temp->date.jour < 1 || temp->date.jour>29);
                }else
                {
                    do{
                        temp->date.jour = read_int("Jour");
                    }while(temp->date.jour < 1 || temp->date.jour>30);

                }
                printf("Heure :     ");
                do{
                    temp->date.heure = read_int("Heure");
                }while(temp->date.heure < 0 || temp->date.heure>23);
                printf("Minutes  :  ");
                do{
                    temp->date.minute = read_int("Minutes");
                }while(temp->date.minute < 0 || temp->date.minute > 59);

    printf("Entrez la Priorite ::  1  2 ou  3 ---------------------------\n");
                do{
                    temp->prio = read_int("Priorite");
                }while(temp->prio !=1 && temp->prio != 2 && temp->prio != 3);

    return temp;
}

int compare_par_date(Date date1,Date date2)
{
    if(date1.annee == date2.annee && date1.mois == date2.mois && date1.jour == date2.jour && date1.heure == date2.heure && date1.minute == date2.minute)
        return 0;
    if(date1.mois > date2.mois)
    {
        return 1;
    }else
    {
        if(date1.jour > date2.jour)
        {
            return 1;
        }else
        {
            if(date1.heure > date2.heure)
            {
                    return 1;
            }else
            {
                if(date1.minute> date2.minute)
                    return 1;
            }
        }
    }

    if(date1.annee == date2.annee && date1.mois == date2.mois && date1.jour == date2.jour && date1.heure == date2.heure && date1.minute == date2.minute)
        return 0;
return -1;
}

Pointers Insert_Node(node head,node temp)
{
    Pointers pointers;
    node p;
    p  = head;
        while(p->next != NULL)
        {
                if(compare_par_date(temp->date,p->date)==1)
                {
                        break;
                }
                p = p->next;
        }

        if(compare_par_date(temp->date,p->date)==1)
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

        }
return pointers;
}
Pointers addNode(node head)
{

    Pointers pointers;
    node temp;
    temp = createNode();
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        return pointers = Insert_Node(head,temp);
    }

        pointers.first = head;
        temp = head;
        while(temp->next != NULL)
            temp=temp->next;
        pointers.last = temp;
return pointers;
}

Pointers Suprimer_tache(node head, int id){

    node p= head;
    Pointers pointers;

    while(p->next != NULL)
    {
        if(p->id == id)
            break;

        p=p->next;
    }
    if(p->id == id)
    {
        if(p->prev == NULL && p->next == NULL)
            {
                free(p);
                pointers.first = NULL;
                pointers.last = NULL;
                return pointers;

            }

        if(p->prev == NULL && p->next != NULL)
            {
                p->next->prev = NULL;
                pointers.first = p->next;
                free(p);
                while(p->next != NULL)
                    {
                        p=p->next;
                    }
                pointers.last = p;
                return pointers;
            }
        if(p->prev != NULL && p->next == NULL)
            {
                pointers.last = p->prev;
                p->prev->next = NULL;
                free(p);
                pointers.first = head;
                return pointers;
            }

        p->prev->next= p->next;
        p->next->prev= p->prev;
        free(p);
        while(p->next != NULL)
                    {
                        p=p->next;
                    }
        pointers.last = p;
        pointers.first = head;


    }

return pointers;


}

Pointers modifier(node head , int id)
{
    node p= head,temp;
    Pointers pointers;

    while(p->next != NULL)
    {
        if(p->id == id)
            break;

        p=p->next;
    }
    temp = p;
    temp->id = id;
    temp->completer = false;

    printf("Tache %d \n\nSaisisez une description\n",temp->id);
    scanf(" %[^\n]",temp->desc);

    printf("Entrez la date ::---------------------------------------\n");

                printf("Annee :     ");
                do{
                    temp->date.annee = read_int("Anne");
                }while(temp->date.annee != 2024);

                printf("Mois  :     ");
                do{
                    temp->date.mois =read_int("Mois");
                }while(temp->date.mois < 1 || temp->date.mois > 12);
                printf("Jour  :     ");
                if(temp->date.mois == 1 || temp->date.mois == 3 || temp->date.mois == 5 || temp->date.mois == 7 || temp->date.mois == 8 || temp->date.mois == 10 || temp->date.mois == 12)
                {
                    do{
                        temp->date.jour = read_int("Jour");
                    }while(temp->date.jour < 1 || temp->date.jour>31);

                }else if(temp->date.mois == 2)
                {
                    do{
                        temp->date.jour = read_int("Jour");
                    }while(temp->date.jour < 1 || temp->date.jour>29);
                }else
                {
                    do{
                        temp->date.jour = read_int("Jour");
                    }while(temp->date.jour < 1 || temp->date.jour>30);

                }
                printf("Heure :     ");
                do{
                    temp->date.heure = read_int("Heure");
                }while(temp->date.heure < 0 || temp->date.heure>23);
                printf("Minutes  :  ");
                do{
                    temp->date.minute = read_int("Minutes");
                }while(temp->date.minute < 0 || temp->date.minute > 59);

    printf("Entrez la Priorite ::  1  2 ou  3 ---------------------------\n");
                do{
                    temp->prio = read_int("Priorite");
                }while(temp->prio !=1 && temp->prio != 2 && temp->prio != 3);

                if(compare_par_date(temp->date,p->date)!=0)
                {
                    pointers=Suprimer_tache(head,id);
                    pointers = Insert_Node(head,temp);
                    return pointers;
                }
pointers.first =head;
while(p->next != NULL)
    {
              p=p->next;
    }
pointers.last = p;

return pointers;
}

            void Affichage_inverse(node head)
            {
                printf("\n\n********----**********TO DO LIST************----**********\n");
                printf("*****************AFFICHAGE ORDRE INVERSE**********************\n\n");

                while(head->next != NULL)
                    {
                        printf("%d || %s || %d / %d / %d - %d h: %dmn|| complete : %x || priorite : %d\n",head->id,head->desc,head->date.annee,head->date.mois,head->date.jour,head->date.heure,head->date.minute,head->completer,head->prio);
                        head = head->next;
                    }
                        printf("%d || %s || %d / %d / %d - %d h: %dmn|| complete : %x || priorite : %d\n",head->id,head->desc,head->date.annee,head->date.mois,head->date.jour,head->date.heure,head->date.minute,head->completer,head->prio);
            head = NULL;
            printf("\n******************AFFICHAGE TERMINE**********************\n\n");
            }

            void Affichage_normal(node last)
            {
                printf("\n\n********----**********TO DO LIST************----**********\n");
                printf("******************AFFICHAGE ORDRE NORMAL**********************\n\n");
                while(last->prev != NULL)
                    {
                        printf("%d || %s || %d / %d / %d - %d h: %dmn|| complete : %x || priorite : %d\n",last->id,last->desc,last->date.annee,last->date.mois,last->date.jour,last->date.heure,last->date.minute,last->completer,last->prio);
                        last = last->prev;
                    }
                        printf("%d || %s || %d / %d / %d - %d h: %dmn|| complete : %x || priorite : %d\n",last->id,last->desc,last->date.annee,last->date.mois,last->date.jour,last->date.heure,last->date.minute,last->completer,last->prio);
            last = NULL;
            printf("\n******************AFFICHAGE TERMINE**********************\n\n");
            }

int main()
{
        Pointers my_List;
        node head;
        int quit = 0, choix;

        my_List.first = NULL;
        my_List.last = NULL;


        printf("Bienvenue dans votre gestionaire de taches  **** To_Do Supreme ****\n\n");
        printf("Commencer par ajouter votre premiere tache\n\n");


        my_List.first=my_List.last=createNode();
        printf("\n");

        do{

            printf("\n1|| Pour ajoutter une tache tappez 1\n");
            printf("2|| Pour l affichage en date chronologique tappez 2\n");
            printf("3|| Pour l affichage en date anti_chronologique tappez 3\n");
            printf("4|| Affichage filtrer suivant la priorite tappez 4\n");
            printf("5|| Modifier une tache 5\n");
            printf("6|| Marquer une tache comme terminee tappez 6\n");
            printf("7|| Suprimer une tache 7\n");
            printf("0|| Enregistrer et quitter tappez 0\n\n");

            do{
                quit = read_int("votre choix");
                printf("\n");
            }while(quit<0 || quit>7);


            if(quit == 1){
                my_List = addNode(my_List.first);
            }
            if( quit == 2){
                Affichage_normal(my_List.last);
            }
            if(quit == 3){
                Affichage_inverse(my_List.first);
            }
            if(quit==4)
            {
                do{
                    choix = read_int("priorite");
                }while(choix<1 || choix > 3);

                head = my_List.first;
                printf("\n\n********----**********TO DO LIST************----**********\n");
                printf("******************AFFICHAGE PRIORITE %d**********************\n\n",choix);
                while(head->next != NULL)
                    {
                        if(head->prio == choix)
                            printf("%d || %s || %d / %d / %d - %d h: %dmn|| complete : %x\n",head->id,head->desc,head->date.annee,head->date.mois,head->date.jour,head->date.heure,head->date.minute,head->completer);
                        head = head->next;
                    }
                        if(head->prio == choix)
                            printf("%d || %s || %d / %d / %d - %d h: %dmn|| complete : %x\n",head->id,head->desc,head->date.annee,head->date.mois,head->date.jour,head->date.heure,head->date.minute,head->completer);
                head = NULL;
            }
            if(quit == 7)
            {

                choix = read_int("Id de la tache a suprimer");

                my_List=Suprimer_tache(my_List.first,choix);

                if(my_List.first == NULL && my_List.last == NULL)
                {
                    printf("La liste des taches est vide, Recommencer par ajouter une tache\n\n");
                    Tache_ID = 0;
                    my_List.first=my_List.last=createNode();
                    printf("\n");
                }
            }
            if(quit == 6){

                    choix = read_int("Id de la tache a marquer complete");
                    head = my_List.first;
                while(head->next != NULL)
                    {
                        if(head->id == choix)
                            {
                                break;
                            }
                        head = head->next;
                    }
                    if(head->id == choix)
                    {
                        head->completer = true;


                    }


                head = NULL;
            }
            if(quit == 5)
            {
                choix = read_int("Id de la tache a modifier");
                my_List = modifier(my_List.first,choix);

            }

        }while(quit != 0);


//Free Memory;
        while(my_List.first != NULL)
        {
            my_List.first = my_List.first->next;
            free(my_List.first->prev);
        }
        free(my_List.first);

my_List.first = NULL;
my_List.last = NULL;

return 0;
}

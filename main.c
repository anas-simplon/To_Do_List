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
    scanf("%s",temp->desc);

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


return -1;
}

Pointers addNode(node head)
{

    Pointers pointers;
    node temp,p;
    temp = createNode();
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
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
    }

        pointers.first = head;
        pointers.last = temp;
return pointers;
}

            void Affichage_normal(node head)
            {
                while(head->next != NULL)
                    {
                        printf("%d || %s || %d %d %d %d %d|| complete : %x || priorite : %d\n",head->id,head->desc,head->date.annee,head->date.mois,head->date.jour,head->date.heure,head->date.minute,head->completer,head->prio);
                        head = head->next;
                    }
                        printf("%d || %s || %d %d %d %d %d|| complete : %x || priorite : %d\n",head->id,head->desc,head->date.annee,head->date.mois,head->date.jour,head->date.heure,head->date.minute,head->completer,head->prio);
            head = NULL;
            }

            void Affichage_inverse(node last)
            {
                while(last->prev != NULL)
                    {
                        printf("%d || %s || %d %d %d %d %d|| complete : %x || priorite : %d\n",last->id,last->desc,last->date.annee,last->date.mois,last->date.jour,last->date.heure,last->date.minute,last->completer,last->prio);
                        last = last->prev;
                    }
                        printf("%d || %s || %d %d %d %d %d|| complete : %x || priorite : %d\n",last->id,last->desc,last->date.annee,last->date.mois,last->date.jour,last->date.heure,last->date.minute,last->completer,last->prio);
            last = NULL;
            }

int main()
{
        Pointers my_List;
        node head;
        int quit = 0, choix;

        my_List.first = NULL;
        my_List.last = NULL;


        printf("Bienvenue dans votre gestionaire de taches  **** To_Do Spreme ****\n\n");
        printf("Commencer par ajouter votre premiere tache\n\n");


        my_List.first=my_List.last=createNode();
        printf("\n");

        do{

            printf("1|| Pour ajoutter une tache tappez 1\n");
            printf("2|| Pour l affichage en date chronologique tappez 2\n");
            printf("3|| Pour l affichage en date anti_chronologique tappez 3\n");
            printf("4|| Affichage filtrer suivant la priorite tappez 4\n");
            printf("5|| Marquer une tache comme terminee tappez 5\n");
            printf("6|| Suprimer une tache\n");
            printf("0|| Enregistrer et quitter tappez 0\n");

            do{
                quit = read_int("votre choix");
            }while(quit<0 || quit>6);


            if(quit == 1){
                my_List = addNode(my_List.first);
            }
            if( quit == 2){
                Affichage_normal(my_List.first);
            }
            if(quit == 3){
                Affichage_inverse(my_List.last);
            }
            if(quit==4)
            {
                do{
                    choix = read_int("priorite");
                }while(choix<1 || choix > 3);

                head = my_List.first;
                while(head->next != NULL)
                    {
                        if(head->prio == choix)
                            printf("%d || %s || %d %d %d %d %d|| complete : %x || priorite : %d\n",head->id,head->desc,head->date.annee,head->date.mois,head->date.jour,head->date.heure,head->date.minute,head->completer,head->prio);
                        head = head->next;
                    }
                        if(head->prio == choix)
                            printf("%d || %s || %d %d %d %d %d|| complete : %x || priorite : %d\n",head->id,head->desc,head->date.annee,head->date.mois,head->date.jour,head->date.heure,head->date.minute,head->completer,head->prio);
                head = NULL;

            }

        }while(quit != 0);







return 0;
}

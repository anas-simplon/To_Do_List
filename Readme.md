# To Do List

This apllicantion is simple C code simulation of to do list application created by Anas BOUDALI.

**this application menu in *C***

```
do{

            printf("\n1|| Pour ajoutter une tache tappez 1\n");
            printf("2|| Pour l affichage en date chronologique tappez 2\n");
            printf("3|| Pour l affichage en date anti_chronologique tappez 3\n");
            printf("4|| Affichage filtrer suivant la priorite tappez 4\n");
            printf("5|| Modifier une tache 5\n");
            printf("6|| Marquer une tache comme terminee tappez 6\n");
            printf("7|| Suprimer une tache 7\n");
            printf("0|| Enregistrer et quitter tappez 0\n\n");

```

### Les Listes

Cette application utilise le concepte des listes doublement chainées à fin de faciliter l'utilisation de la mémoire et une consomation minimale.

**List declaration in *C***

```
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


```


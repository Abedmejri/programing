#include <stdio.h>
#include <string.h>

typedef struct  {
    char nom[30];
    char ville[30];
    char telephone[15];
} contact;

///////////////////////////////////// done
void creefichier(char nomf[]){
    printf("Nom du fichier : ");
    scanf("%s", nomf);
    FILE* f = fopen(nomf, "w");  
    if (f == NULL) {
        printf("Erreur \n");
        return;
    }
    fclose(f);
}

////////////////////////////////// done
void saisie(contact* c){
    printf("Entrez le nom : ");
    scanf("%s", (*c).nom);
    printf("Entrez la ville : ");
    scanf("%s", (*c).ville);
    printf("Entrez le numéro de telephone : ");
    scanf("%s", (*c).telephone);
}

/////////////////////////////// done
void ajout(char nomf[], int* n){
    FILE* f = fopen(nomf, "a");  
    if (f == NULL) {
        printf("Erreur  \n");
        return;
    }
    contact c;
    int reponse = 1;
    *n = 0;
    while (reponse) {
        saisie(&c);
        fprintf(f, "%s %s %s\n", c.nom, c.ville, c.telephone);  
        (*n)++;
        printf("Voulez-vous ajouter un autre contact ? (1=oui, 0=non) ");
        scanf("%d", &reponse);
    }
    fclose(f);
}
//////////////////////////////done
void rechercheParNom(char nomf[]) {
    FILE* f = fopen(nomf, "r");
    contact c;
    char nom[30];
    int trouve = 0;

    printf("Entrez le nom a rechercher : ");
    scanf("%s", nom);

    while (fscanf(f, "%s %s %s", c.nom, c.ville, c.telephone) == 3) {
        if (strcmp(c.nom, nom) == 0) {
            printf("Nom : %s\nVille : %s\nTelephone : %s\n", c.nom, c.ville, c.telephone);
            trouve = 1;
        }
    }
    fclose(f);
}
/////////////////////////////done
void rechercheParville(char nomf[]) {
    FILE* f = fopen(nomf, "r");
    contact c;
    char nom[30];
    int trouve = 0;

    printf("Entrez  ville a rechercher : ");
    scanf("%s", ville);

    while (fscanf(f, "%s %s %s", c.nom, c.ville, c.telephone) == 3) {
        if (strcmp(c.ville, ville) == 0) {
            printf("Nom : %s\nVille : %s\nTelephone : %s\n", c.nom, c.ville, c.telephone);
            trouve = 1;
        }
    }
    fclose(f);
}

/////////////////////////////done affichage 5ayeb
void afficheTousLesContacts(char nomf[]) {
    FILE* f;
    contact c;

    f = fopen(nomf, "r");
    while (fgets(c.nom, sizeof(contact), f) != NULL) {
        printf("Nom : %s Ville : %s Telephone : %s", c.nom, c.ville, c.telephone);
    }
    fclose(f);
}

//////////////////////////////done
int main(){
    contact contacts[100];  
    char nomf[50] = "";
    int ch;
    int n = 0;
    
    
    do {
    	printf("\n-----------Menu contact----------\n");
        printf(" 1: Creer le fichier de contacts\n 2: Ajouter un contact\n 3: Afficher tous les contacts\n 4: Recherche par nom\n 5: Recherche par ville\n 6: Quitter\n\n Votre choix : ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                creefichier(nomf);
                break;
                
            case 2:
                ajout(nomf,&n);
                break;
                
            case 3:
                afficheTousLesContacts(nomf);
                break;
                
            case 4:
                rechercheParNom(nomf);
                break;
                
            case 5:
                rechercheParville(nomf)
                break;
                
            case 6:
                printf("Au revoir \n");
                break;
                
            
        }
    } while (ch != 6);
   
    
}


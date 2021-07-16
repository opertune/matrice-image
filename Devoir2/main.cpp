/* Devoir 2
* Saisir une matrice qui permet d’afficher une image
* Date : 31/03/2020
* Author : Baucheron Romain
*/

#include <iostream>
#include <myconio.h>

using namespace std;

// Constante de la taille de la matrice
#define N 10

// Valeur des 4 couleurs : blanc, gris clair, gris foncé et noir
int couleur[4] = {15, 7, 8, 0};

// Module permettant de réaliser une saisie contrôlée
int saisie(int x, int y){
    int val;
    do{
        gotoxy(x, y); cout << " ";
        gotoxy(x, y); val=getche();
    }while(val<48 || val>51);
    return(val-48);
}

// Module permettant d'afficher les points et de saisie la matrice
void saisieMatrice(int image[N][N]){
    gotoxy(1, 1); cout << "Sasie de la matrice (valeurs 0 blanc, 1 gris clair, 2 gris fonc\x82 ou 3 noir) : ";
    // Affichage des points pour montrer où se fait la saisie
    for(int x = 0; x<N; x++){
        for(int y=0; y<N; y++){
            gotoxy(x*3+1, y+2); cout << ".";
        }
    }
    // Saisie
    for(int x=0; x<N; x++){
        for(int y=0; y<N; y++){
            image[x][y] = saisie(x*3+1, y+2);
        }
    }
}

// Fonction qui retourne la valeur de la luminosité
int calculLuminosite(int image[N][N]){
    // Initialisation à 0 de la luminosité
    int luminosite = 0;
    // Calcul de la somme du contenu de la matrice
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            luminosite += image[i][j];
        }
    }
    // Retourne la moyenne
    return(luminosite/(N*N));
}

// Procedure qui affiche l'image
void afficheImage(int image[N][N], int x){
    // Affiche la couleur saisie dans la matrice
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
                gotoxy(i*1+x, j+15);
                textbackground(couleur[image[i][j]]);
                cout << " ";
        }
    }
    textbackground(0);
}

// Procedure qui accentue le constrate de l'image
void accentueContraste(int image[N][N]){
    // Récuperation de la luminosité de base
    int luminosite = calculLuminosite(image);
    // Augmente ou diminue la luminosite en fonction de la valeur de base
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(image[i][j] > luminosite && image[i][j] < 3){
                image[i][j] += 1;
            }else{
                if(image[i][j] < luminosite && image[i][j] > 0){
                    image[i][j] -= 1;
                }
            }
        }
    }
}

int main()
{
    // Déclaration
    int image[N][N];
    // Saisie de la matrice d'origine
    saisieMatrice(image);
    // Affichage de l'image
    afficheImage(image, 1);
    // Accentuation du contraste
    accentueContraste(image);
    // Affichage de l'image
    afficheImage(image, N+10);
    return 0;
}

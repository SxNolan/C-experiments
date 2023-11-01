
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <ctype.h>

#define ROWS 9
#define COLUMNS 9

            int campo[ROWS][COLUMNS];
            char campovisibile[ROWS][COLUMNS];
            int numero_difficolta =-1;
            int riga_scelta;
            int colonna_scelta;
            int gamestatus = 0;

            void visualizza_casella_ij(int a, int b);
            void inizializza_gioco();
            void scegli_posizione();
            void visualizza_campovisibile();
            void scegli_difficolta();



            int main(void) {
                /*Gruppo:
                Matricola:  Alex Mazzoni       E-mail: alex.mazzoni3@studio.unibo.it
                Matricola:  Giovanni Luca      E-mail: giovanni.luca@studio.unibo.it
                Matricola:  Michele Farneti    E-mail: michele.farneti@studio.unibo.it
                */
                char voce_selezionata;
                bool flag = true;
                bool partitainiziata=false;

                printf("\nSettimana 6 - Esercizio 2\t E-mail di riferimento: alex.mazzoni3@studio.unibo.it\n\n");
                printf("Benvenuto in CAMPO MINATO!");

                //Realizzo un semplice menu che dará, tramite l'input da tastiera, l'opportunitá all'utente di scegliere quale azione compiere
                while (flag == true)
                {
                    printf("\nCosa intendi fare?\n\nGioca (0)\nImposta difficolta (1)\'\nEsci (2)\n\n");
                    voce_selezionata = getchar();
                    switch (voce_selezionata) {
                        case '0':
                            //In caso l'utente sia pronto a giocare, inizializzo il campo in relazione alla difficolta
                            inizializza_gioco();
                            flag = false;
                            partitainiziata=true;
                            break;
                        case '1':
                            //Permetto all'utente di scegliere la difficoltá a cui giocare
                            scegli_difficolta();
                            break;
                        case '2':
                            //Nel caso l'utente non voglia giocare, gli consento di uscire
                            flag = false;
                            break;
                    }
                }

                //In caso l'itente acconsenta di giocare, procedo con le varie fasi del gioco
                if(partitainiziata==true)
                {
                    visualizza_campovisibile();
                    do{
                        scegli_posizione();
                        visualizza_casella_ij(colonna_scelta,riga_scelta);
                        visualizza_campovisibile();
                    }
                    while(gamestatus==0);
                }
                printf("\n\nAlla prossima!!");
                return 0;
            }

            void visualizza_casella_ij(int a, int b) {
                if (campo[a][b] == -1) {
                    campovisibile[a][b]='B';
                    printf("BOOM! Hai svelato una bomba. hai perso...\n");
                    gamestatus =1;
                }
                else
                {
                    int bombcount=0;
                    //Slot superiore centrale;
                    if(a>0)
                    {
                        if(campo[a-1][b] == -1)
                        {
                            bombcount++;
                        }
                        if(b>0)
                        {
                            if(campo[a-1][b-1] == -1)
                            {
                                bombcount++;
                            }
                        }
                        if(b<8)
                        {
                            if(campo[a-1][b+1] == -1)
                            {
                                bombcount++;
                            }
                        }
                    }

                    if(a<8)
                    {
                        if(campo[a+1][b]==-1)
                        {
                            bombcount++;
                        }
                        if(b<8)
                        {
                            if(campo[a+1][b+1] == -1)
                            {
                                bombcount++;
                            }
                        }
                        if(b>0)
                        {
                            if(campo[a+1][b-1] == -1)
                            {
                                bombcount++;
                            }
                        }
                    }
                    if(b>0)
                    {
                        if(campo[a][b-1]==-1)
                        {
                            bombcount++;
                        }
                    }
                    if(b<8)
                    {
                        if(campo[a][b+1]==-1)
                        {
                            bombcount++;
                        }
                    }

                    //Nel caso non ci fossero bombe in prossimitá controllo le caselle adiacenti
                    if(bombcount ==0)
                    {
                        if(a>0)
                        {
                            visualizza_casella_ij(a-1,b);
                            if(b>0)
                            {
                                visualizza_casella_ij(a-1,b-1);
                            }
                            if(b<8)
                            {
                                visualizza_casella_ij(a-1,b+1);
                            }
                        }

                        if(a<8)
                        {
                            visualizza_casella_ij(a+1,b);
                            if(b<8)
                            {
                                visualizza_casella_ij(a+1,b+1);
                            }
                            if(b>0)
                            {
                                visualizza_casella_ij(a+1,b-1);
                            }
                        }
                        if(b>0)
                        {
                            visualizza_casella_ij(a,b-1);
                        }
                        if(b<8)
                        {
                            visualizza_casella_ij(a,b+1);
                        }
                    }
                    campovisibile[a][b] = bombcount+48;
                }
            }

            void inizializza_gioco() {
                srand(time(NULL));
                int numero_mine;
                int i;
                int riga_casuale;
                int colonna_casuale;

                //Vado a selezionare il numero di mine che saranno presenti nel campo in base alla difficolta scelta.
                switch (numero_difficolta) {
                    case 2:
                        numero_mine = 5;
                        break;
                    case 3:
                        numero_mine = 10;
                        break;
                    case 4:
                        numero_mine = 15;
                        break;
                    case 5:
                        numero_mine = 20;
                        break;
                    default:
                        numero_mine = 1;
                }

                //Utilizzo due matrici, una che andró a stampare ed una che restera nascosta per la realizzazione del campo
                //Nel particolare, la matrice campovisibile sará quella che l'utente andrá man mano
                // a scoprire, mentre quella campo,ad essa parallela conterrá le posizioni delle bombe
                for (i = 0; i < ROWS; i++)
                {
                    for (int j = 0; j < ROWS; j++)
                    {
                        campo[i][j] = 0;
                        campovisibile[i][j] = 'X';
                    }
                    printf("\n");
                }

                //Genero casualmente le mine, facendo attenzione a non generarle nelle stesse posizioni
                i=0;
                do
                {
                    riga_casuale =  rand() % 9;
                    colonna_casuale = rand() % 9;
                    if(campo[riga_casuale][colonna_casuale]==0)
                    {
                        campo[riga_casuale][colonna_casuale] = -1;
                        i++;
                    }
                } while (i < numero_mine);
                if (numero_mine == 1) {
                    printf("\n\nIn questo campo e\' nascosta %i mina, attenzione!\n",numero_mine);
                } else {
                    printf("\n\nIn questo campo sono nascoste %i mine, attenzione!\n", numero_mine);
                }

            }

            void scegli_posizione() {
                printf("\nSeleziona una casella (due interi da 0 a 8 che ne rappresentano le coordinate (riga colonna))");
                scanf("%d", &colonna_scelta);
                fflush(stdin);
                scanf("%d", &riga_scelta);
                fflush(stdin);
            }


//Visualizzione del campo per l'utente
            void visualizza_campovisibile()
            {
                int i;

                for (i = 0; i < ROWS; i++)
                {
                    for (int j = 0; j < COLUMNS; j++)
                    {
                        printf("%4c", campovisibile[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");
            }

            void scegli_difficolta() {
                //Faccio reinserire all'utente la difficoltá desiderata fino a quando non inserisce un valore contemplato
                do
                {
                    printf("Scegli una difficolta da 1 a 5 inclusi: ");
                    scanf("%d", &numero_difficolta);
                    fflush(stdin);
                }
                while(numero_difficolta<1 ||numero_difficolta >5);

                printf("Difficolta scelta: %d / 5\n\n", numero_difficolta);
            }

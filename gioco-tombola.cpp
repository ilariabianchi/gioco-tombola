#include <iostream>
#include <time.h>
#include <cstdlib>
#include <unistd.h>

using namespace std;

int main(){

    srand(time(NULL));

    int estratto=rand()%90+1, num_cartella;

    // variabile per vedere chi fa tombola
    bool tombola_fatta=false;

    cout<<"\33[1m";
    cout<<"\33[38;5;168m"; 
    cout<<"GIOCO DELLA TOMBOLA!!!\n";
    cout<<"\33[0m";
    cout<<"\33[22m";

    cout<<"\nquante cartelle vuoi generare? ";
    cin>>num_cartella;
    cout<<endl;

    cout<<"\33[3m";
    cout<<"perfetto, iniziamo!\n";
    cout<<"\33[23m";

    //dichiaro array per cartelle e array per segnare numeri già usati
    int cartelle[3][9], numeri[91], numeri_messi, colonna, n;

    //azzero array cartella
    for(int i=0;i<3;i++){
        for(int j=0;j<9;j++){
            cartelle[i][j]=0;
        }
    }

    //azzero array numeri già messi
    for(int i=0;i<=90;i++){
        numeri[i]=0;
    }

    //genero cartelle
    for(int y=0; y<num_cartella; y++){
        for(int i=0; i<3; i++){
            numeri_messi=0;

            //5 numeri per riga
            while(numeri_messi<5){
                colonna=rand()%9;

                //se lo spazio è già occupato genera altri numeri
                if(cartelle[i][colonna]!=0){
                    continue;
                } 

                //prima colonna (0) numeri da 1 a 9
                if(colonna==0){
                    n=rand()%9+1;   
                }
                //ultima colonna (8) numeri da 80 a 90
                else if(colonna==8){
                    n=rand()%11+80; 
                }
                //colonne restanti uguali alla colonna * 10 + 0-9
                else{
                    n=rand()%10+colonna*10; 
                }    

                //controllo se numero c'è nella cartella
                if(numeri[n]==0){
                	
                	//lo inserisco nella cartella
                    cartelle[i][colonna]=n;
                    
                    //lo segno occupato
                    numeri[n]=1; 
                    
                    //incremento i numeri messi nelle righe
                    numeri_messi++;
                }
            }
        }
    }

    // array per segnare numeri estratti
    int numeri_sorteggiati[91];
    for(int i=0; i<91; i++){
        numeri_sorteggiati[i] = 0;
    }

    //salvo posizione iniziale dove inizia la cartella
    cout<<"\33[s";

    //estraggo
    for(int i=1; i<=90; i++){

        //estrazione numero casuale
        estratto=rand()%90+1;
        while(numeri_sorteggiati[estratto]==1){
            estratto=rand()%90+1;
        }

        //segno numero estratto come occupato
        numeri_sorteggiati[estratto]=1;

        //vedo la tombola
        if(!tombola_fatta){
            for(int y=0; y<num_cartella; y++){
                int conta_tombola=0;

                //righe della cartella
                for(int r=0; r<3; r++){
                	
                    // ciclo sulle colonne
                    for(int c=0; c<9; c++){
                    	
                        //se il numero della cartella è occupato e il numero della cartella è uscito nrl sorteggio aumento i numeri che sono usciti
                        if(cartelle[r][c]!=0&&numeri_sorteggiati[cartelle[r][c]]==1){
                            conta_tombola++;
                        }
                    }
                }

                //se tutti i 15 numeri della cartella sono stati estratti si tombola
                if(conta_tombola==15){
                    
					cout<<"TOMBOLA!!! SULLA CARTELLA "<<y+1<<"!!!\n\n";
                    
					//segno che c'e la tombola
                    tombola_fatta=true;
                    
                    //non controllo più le cartelle
					break;
                }
            }
        }


        //torno all'inizio dove era salvato il cursore
        cout<<"\33[u";

        //cancello le righe del tabellone e anche il numero estratto
        for(int r=0; r<30; r++){	
            cout<<"\33[2K"<<"\n";
        }

        //torno all'inizio
        cout<<"\33[u";

        //metto le cartelle aggiorante
        for(int y=0; y<num_cartella; y++){
        	
            cout<<"\33[38;5;168m"; 
            cout<<"\n\ncartella numero: "<<y+1<<endl;
            cout<<"\33[0m";

            for(int i=0; i<3; i++){
                cout<<"---------------------------\n";

                for(int j=0; j<9; j++){

                    //se non c'è nulla stampo uno spazio vuoto
                    if(cartelle[i][j]==0){
                        cout<<"   ";
                    }
					else {
                        //coloro il numero uscito
                        if(numeri_sorteggiati[cartelle[i][j]]==1){
                            cout<<"\33[38;5;168m"; 
                        }

                        //allineo
                        if(cartelle[i][j]<10){
                            cout<<" "<<cartelle[i][j]<<" ";		
                        }
						else {
                            cout<<cartelle[i][j]<<" ";
                        } 

                        //azzero colore
                        cout<<"\33[0m";
                    }
                }
                cout<<endl;
            }
            cout<<"---------------------------\n\n\n";
        }

        //numero estratto
        cout<<"\33[38;5;168m";
        cout<<"il numero estratto e'... "<<estratto<<endl<<endl;
        cout<<"\33[0m";

        //tebellone
        cout<<"tabellone dei numeri:\n\n";
        
        for (int t=1; t<=90; t++){
            // se numero già estratto coloro
            if(numeri_sorteggiati[t]==1){
                cout<<"\33[38;5;168m";
            }

            //incolonno bene i numeri
            if(t<10){
                cout<<t<<"   ";
            }
			else {
                cout<<t<<"  ";
            }
			
			//azzero colore
            cout<<"\33[0m"; 
            
            //ogni 10 numeri a capo
            if (t%10==0){
                cout<<endl<<endl;
            }
        }
        
        //se faccio tombola il gioco finisce
        if(tombola_fatta){
            break;
        }
        
        // ogni 4 secondi
        sleep(4);
    }

    return 0;
}

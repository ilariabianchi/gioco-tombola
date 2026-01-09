#include <iostream>
#include <time.h>
#include <cstdlib>
#include <unistd.h>

using namespace std;

int main(){
	
	srand(time(NULL));
	
	int estratto=rand()%90+1, num_cartella;
	
	cout<<"\33[1m";
	cout<<"\33[38;5;168m"; 
	cout<<"GIOCO DELLA TOMBOLA!!!\n";
	cout<<"\33[0m";
	cout<<"\33[22m";
	
	cout<<"\nquante cartelle vuoi generare? ";
	cin>>num_cartella;
	cout<<endl;
	
	cout<<"\33[3m";
	cout<<"perfetto, iniziamo!\n\n";
	cout<<"\33[23m";
	
	cout<<"\33[38;5;174m";
	cout<<"il numero estratto e'... "<<estratto<<endl<<endl;
	cout<<"\33[0m";
	
	cout<<"tabellone dei numeri:\n"<<endl;
	
	//ciclo for che stampa i numeri da 1 a 90
	for(int i=1; i<=90; i++){
		
		//ciclo while per incolonnare giusti i primi 10 numeri
    	while (i<11){
    	
    		if(i==1){
    			cout<<i<<"  ";
				i++;	
			}
			cout<<" "<<i<<"  ";
			i++;
			if(i==11){
				cout<<endl<<endl;
			}
		}
    	cout<<i<<"  ";
    	
    	//ogni volta che vengono stampati 10 numeri va a capo
    	if(i%10==0){
        	cout<<endl<<endl;
    	}
	}

	//inizializzo array a zero
    int cartelle[3][9], numeri[91];
    
    int numeri_messi, colonna, n;
    
   	for(int c=0; c<num_cartella; c++){
   		
   		cout<<"\33[38;5;168m"; 
   		cout<<"\ncartella numero "<<c+1<<endl;
   		cout<<"\33[0m";
   		
   		//metto gli array tutti a zero
   		for(int i=0;i<3;i++){
        	for(int j=0;j<9;j++){
            	cartelle[i][j]=0;
        	}
    	}
    	//metto a zero
    	for(int i=0;i<=90;i++){
        	numeri[i]=0;
    	}
   	
   	//for che si ripete tre volte per controllare tre righe
   	for(int i=0; i<3; i++){
    	
        numeri_messi=0;

        while(numeri_messi<5){
            colonna=rand()%9;
			
			//se lo spazio è già occupato genero altri numeri
            if(cartelle[i][colonna]!=0){
            	continue;
			} 
			
			//se è la prima colonna (0) stampo i  numeri da 1 a 10
            if(colonna==0){
            	 n=rand()%9+1;   
			} 
			
			//se è l'ultima colonna (8) fa i numeri tra 80 e 90   
            else if(colonna==8){
            	 n=rand()%11+80; 
			}
			
			//tutte le altre colonne
            else {
            	n=rand()%10+colonna*10; 
			}    
			
			//controlla quali numeri sono stati già messi
            if(numeri[n]==0){
            	
            	//se è libero metto il numero
                cartelle[i][colonna]=n;
                
                //lo segno come occupato
                numeri[n]=1;
                
                //incremento i numeri usati (5 per riga)
                numeri_messi++;
            }
        }
    }

    // stampa cartella
    
    //for per righe
    for(int i=0;i<3;i++){
    	cout<<"---------------------------"<<endl;

    	//for per colonne
        for(int w=0;w<9;w++){

        	//se nello spazio c'è zero metto lo spazio
            if(cartelle[i][w]==0){
            	cout<<"   ";
            
            //se è <10 metto lo spazio anche prima per allineeralo
			}
            else if(cartelle[i][w]<10){
            	cout<<" "<< cartelle[i][w]<<" ";
			} 
			
			//negli altri caso stampo il numero normalmente
            else{
            	cout<<cartelle[i][w]<<" ";	
			}
        }
        cout<<endl;
    }
    cout<<"---------------------------"<<endl<<endl<<endl;
	}
   	
    
    return 0;

}

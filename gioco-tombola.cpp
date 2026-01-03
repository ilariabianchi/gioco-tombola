#include <iostream>
#include <time.h>
using namespace std;

int main(){
	
	srand(time(NULL));
	
	int estratto=rand()%90+1, num_cartella;
	
	cout<<"GIOCO DELLA TOMBOLA!!!\n\n";
	
	cout<<"tabellone dei numeri:\n"<<endl;
	
	//ciclo for che stampa i numeri da 1 a 90
	for(int i=1; i<91; i++){
		
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
		
	cout<<"\n\ncartelle giocatori:\n\n";
	
	int numeri[5], ordine, precedente=0;
	for(int i=0; i<3; i++){
		//ciclo per generare i numeri da mettere nelle cartelle
	for(int i=0; i<5; i++){
		num_cartella=rand()%90+1;
		numeri[i]=num_cartella;
		
		//se i numeri sono uguali non si stampano e se ne fanno altri
		if(num_cartella==precedente){
			i--;
			continue;
		}
		precedente=num_cartella;	
	}
	
	//ciclo che mette in ordine i numeri generati
	for(int i=0; i<4; i++){
		for(int w=i+1; w<5; w++){
			
			//se il numero in posizione i è maggiore del numero in posizione i+1 allora vengono ordinati
			if(numeri[i]>numeri[w]){
				
				//ordine è una variabile di appoggio a cui assegno il valore del numero in poszione i
				ordine=numeri[i];
				
				//poi scambio il numero in poszione i con quello nella posizione i+1 così si ordinano in modo crescente
				numeri[i]=numeri[w];
				
				//infine assegno il valore del numero nella poszione i+1 alla variabile di appoggio per riconfrontarli
				numeri[w]=ordine;	
			}
			
		}
	}
	
	//ciclo che stampa la sequenza in ordine
	for(int i=0; i<5; i++){
		cout<<numeri[i]<<" ";
	}
	cout<<endl;
	cout<<"---------------"<<endl;
	
	}
	
    
    return 0;
}

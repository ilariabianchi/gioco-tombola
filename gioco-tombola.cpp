#include <iostream>
#include <time.h>
using namespace std;

int main(){
	
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
	
	//genera due cartelle
	for(int i=0; i<2; i++){
    	cout<<"---------------"<<endl;
    	
    	//genera i numeri da mettere nelle cartelle
    	for(int i=1; i<=15; i++){
        	num_cartella=rand()%90+1;
        	cout<<num_cartella<<" ";
        	
			//ogni riga contiene cinque numeri e poi va a capo con la riga successiva
        	if(i%5==0){
            	cout<<endl;
            	cout<<"---------------"<<endl;
        	}
    	}
    cout<<endl;
	}
    
    return 0;
}


#include <iostream>
#include <time.h>
using namespace std;

int main(){

for(int i=1; i<91; i++){
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
    if(i%10==0){
        cout<<endl<<endl;;
    }
	}
    
    return 0;
}


#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

main(){
    char Poema[200], vocales[]="aeiou";
    int vocal=0, consonante=0, flag=0;

    cout << "Ingresar poema: " << endl;
    _flushall();
    gets(Poema);

    for(int i=0; i<200 && Poema[i]!='\0'; i++){
        for(int j=0; j<6; j++){
            if(Poema[i]==vocales[j]){
                vocal++;
                flag=1;
                break;
            }
        }
        if(flag==0 && Poema[i]!=' ' && Poema[i]!= ',' && Poema[i]!='.'){
            consonante++;
        } else {
            flag=0;
        }
    }

    cout << endl << "El poema tiene " << vocal << " vocales y " << consonante << " consonantes." << endl << endl;
    system("PAUSE");
}
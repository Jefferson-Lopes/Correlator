/*
Decoder

Programa para transformar uma entrada binária, de até 2'b11, em 
um número decimal e mostrar no display de 7 segmentos 

       _a__
     f|    |b
      |_g__|
     e|    |
      |____|c
        d

by Jefferson Lopes
*/

#include <iostream>

using namespace std;

void decoder(bool *, char *, int *);

int main(){
	setlocale(LC_ALL, "");
    
    bool input[2] = {}, ans = 0;
    char result[7] = {};
    int dec = 0;

    cout << endl << "Decoder" << endl << endl;
    cout << "Insira uma entrada de ate 2'b11:" << endl; 
    cout << "OBS: o tipe de dado de entrada eh bool," << endl;
    cout << "     use Ctrl + Z para encerrar" << endl << endl;

    cout << endl << "Insira 2 valores: ";

    while (cin >> input[1] >> input[0]){
        decoder(input, result, &dec);

        cout << "Decimal: " << dec << "\tDisplay: ";
        for(int i = 0; i < 7; i++)
            cout << result[i];

        cout << endl << endl << "Insira 2 valores: ";
    }

    cout << endl << "End" << endl;

    return 0;
}

void decoder(bool *input, char *result, int *dec){
    if(!input[1] && !input[0]){// 2'b00 - 0
        result[0] = 'a';
        result[1] = 'b';
        result[2] = 'c';
        result[3] = 'd'; 
        result[4] = 'e';
        result[5] = 'f';
        result[6] = '0';
        *dec = 0;
    }
    else if (!input[1] && input[0]){// 2'b01 - 1
        result[0] = '0';
        result[1] = 'b';
        result[2] = 'c';
        result[3] = '0'; 
        result[4] = '0';
        result[5] = '0';
        result[6] = '0';
        *dec = 1;
    }
    else if (input[1] && !input[0]){// 2'b10 - 2
        result[0] = 'a';
        result[1] = 'b';
        result[2] = '0';
        result[3] = 'd'; 
        result[4] = 'e';
        result[5] = '0';
        result[6] = 'g';
        *dec = 2;
    }
    else if (input[1] && input[0]){// 2'b11 - 3
        result[0] = 'a';
        result[1] = 'b';
        result[2] = 'c';
        result[3] = 'd'; 
        result[4] = '0';
        result[5] = '0';
        result[6] = 'g';
        *dec = 3;
    }
}
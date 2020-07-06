/*
Autocorrelação de sinais

Programa para calcular a autocorrelação entre o mesmo sinal
deslocado no tempo, com quantidade de bits variável.


by Jefferson Lopes
*/

#include <iostream>

using namespace std;

#define SIZE 3 //quantidade de bits à ser analisado

void autocorrelation(int *, int *);
void printCorrelation(int *, int *);

int main(){
	setlocale(LC_ALL, "");

	int signal[SIZE] = {};
	int correlation[(2*SIZE - 1)] = {}; 

	cout << endl << "Insira " << SIZE << " numeros naturais para representar o sinal" << endl;
	for (int i = 0; i < SIZE; i++) { cin  >> signal[i]; } 

	autocorrelation(signal, correlation);

	printCorrelation(signal, correlation);

	return 0;
}

void autocorrelation(int *signal, int *correlation){
	for(int i = 0, hold = 0, diffe = 0; i < (2*SIZE - 1); i++, hold = 0){
		if(i < SIZE){
			diffe = (SIZE - 1) - i;
			for(int y = 0; y <= i; y++, diffe++)
				hold += signal[y] * signal[diffe];
		}                               
		else
			hold = correlation[(2*SIZE - 2) - i];
		
		correlation[i] = hold;
	}
}

void printCorrelation(int *signal, int *correlation){
	cout << endl << endl;
	for(int i = 0; i < (2*SIZE - 1); i++){
		for(int y = 1; y < SIZE; y++)
			cout << "  ";

		for(int y = 0; y < SIZE; y++)
			cout << signal[y] << " ";

		cout << endl;

		for(int y = 0; y < i; y++)
			cout << "  ";

		for(int y = 0; y < SIZE; y++)
			cout << signal[y] << " ";

		cout << endl;
		cout << "out[" << i << "]: " << correlation[i];
		cout << endl << endl;
	}
}
#include <iostream>

using namespace std;

#define SIZE 3

void cross_correlator(bool*, bool*, int*);
void print_cross(bool*, bool*, int*);

int main(){
    setlocale(LC_ALL, "");
    bool input1[SIZE] = {}, input2[SIZE] = {};
    int resul[2*SIZE - 1] = {};

    cout << endl << "Insira 2 sinais de " << SIZE << " bits" << endl;
    cout << endl << "Input 1: ";
    for (int i = SIZE - 1; i >= 0; i--)
        cin >> input1[i];
    cout << "Input 2: ";
    for (int i = SIZE - 1; i >= 0; i--)
        cin >> input2[i];

    cross_correlator(input1, input2, resul);

    print_cross(input1, input2, resul);

    return 0;
}

void cross_correlator(bool *input1, bool *input2, int *resul){
    for (int i = 0; i < (2*SIZE - 1); i++){
        if(i < SIZE){
            for (int y = 0, diffe = (SIZE-1-i); y <= i; y++){
                resul[i] += input1[y] * input2[diffe + y]; 
            }
        }else{
            for (int y = 0, diffe = (i+1-SIZE); y < (2*SIZE-1-i); y++){
                resul[i] += input1[diffe + y] * input2[y];
            }
        }
    }
}

void print_cross(bool *input1, bool *input2, int *resul){
    cout << endl << endl;
	for(int i = 0; i < (2*SIZE - 1); i++){
		for(int y = 1; y < SIZE; y++)
			cout << "  ";

		for(int y = 0; y < SIZE; y++)
			cout << input1[y] << " ";

		cout << endl;

		for(int y = 0; y < i; y++)
			cout << "  ";

		for(int y = 0; y < SIZE; y++)
			cout << input2[y] << " ";

		cout << endl;
		cout << "out[" << i << "]: " << resul[i];
		cout << endl << endl;
	}
}
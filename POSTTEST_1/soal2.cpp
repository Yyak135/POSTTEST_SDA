#include <iostream>
using namespace std;

int main() 
{
    const int N = 3;
    int matriks[N][N];

    // Input matriks 3x3
    cout << "Masukkan elemen matriks 3x3:" << endl;
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            cout << "M[" << i << "][" << j << "] = ";
            cin >> matriks[i][j];
        }
    }

    cout << "\nMatriks 3x3:" << endl;
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    // Hitung jumlah diagonal utama + diagonal sekunder
    int jumlah = 0;
    for (int i = 0; i < N; i++) 
    {
        jumlah += matriks[i][i];             // diagonal utama
        jumlah += matriks[i][N - 1 - i];     // diagonal sekunder
    }

    cout << "\nJumlah diagonal utama + diagonal sekunder = " << jumlah << endl;

    return 0;
}

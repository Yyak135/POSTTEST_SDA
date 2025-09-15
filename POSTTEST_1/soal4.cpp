#include <iostream>
using namespace std;

// Fungsi tukar menggunakan double pointer
void tukar(int **a, int **b) 
{
    int temp = **a;
    **a = **b;
    **b = temp;
}

int main() 
{
    int x, y;
    cout << "Masukkan nilai x: ";
    cin >> x;
    cout << "Masukkan nilai y: ";
    cin >> y;

    int *px = &x;
    int *py = &y;

    cout << "\nSebelum ditukar: x = " << x << ", y = " << y << endl;
    tukar(&px, &py);
    cout << "Sesudah ditukar: x = " << x << ", y = " << y << endl;

    return 0;
}

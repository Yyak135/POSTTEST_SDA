#include <iostream>
#include <string>
using namespace std;

// Struktur node untuk linked list
struct Node 
{
    char data;    // Menyimpan satu karakter
    Node* next;   // Pointer ke node berikutnya dalam stack
};

// Fungsi untuk menambahkan elemen ke stack (push operation)
void push(Node*& top, char data) 
{
    // Membuat node baru dengan data yang diberikan
    Node* newNode = new Node{data, top};
    top = newNode;  // Node baru menjadi top stack
}

// Fungsi untuk menghapus dan mengambil elemen dari stack (pop operation)
char pop(Node*& top) 
{
    if (top == nullptr) return '\0';  // Jika stack kosong, return null character
    
    Node* temp = top;                 // Simpan node top sementara
    char poppedValue = temp->data;    // Simpan nilai data dari node top
    top = top->next;                  // Pindahkan top ke node berikutnya
    delete temp;                      // Hapus node lama dari memori
    return poppedValue;               // Kembalikan nilai yang di-pop
}

// Fungsi untuk membalik string menggunakan stack
string reverseString(string s) 
{
    Node* stackTop = nullptr;  // Pointer untuk top of stack (awalnya kosong)
    string reversed = "";      // String untuk menyimpan hasil yang sudah dibalik

    // Memasukkan setiap karakter dari string ke dalam stack
    for (char c : s) 
    {
        push(stackTop, c);  // Push setiap karakter ke stack
    }

    // Mengeluarkan setiap karakter dari stack dan membentuk string terbalik
    while (stackTop != nullptr) 
    {
        reversed += pop(stackTop);  // Pop karakter dari stack dan tambahkan ke string hasil
    }
    
    return reversed;  // Mengembalikan string yang sudah dibalik
}

int main() 
{
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl;
    return 0;
}
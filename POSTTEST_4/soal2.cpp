#include <iostream>
#include <string>
using namespace std;

// Struktur untuk node dalam linked list
struct Node 
{
    char data;    // Menyimpan karakter kurung buka
    Node* next;   // Menunjuk ke node berikutnya
};

// Fungsi untuk menambahkan karakter kurung buka ke stack
void push(Node*& top, char data) 
{
    // Buat node baru dan letakkan di atas stack
    Node* newNode = new Node{data, top};
    top = newNode;  // Node baru sekarang menjadi top stack
}

// Fungsi untuk mengambil karakter dari stack
char pop(Node*& top) 
{
    if (top == nullptr) return '\0';  // Jika stack kosong, return null
    
    Node* temp = top;                 // Simpan node top
    char poppedValue = temp->data;    // Ambil data dari node top
    top = top->next;                  // Geser top ke node berikutnya
    delete temp;                      // Hapus node yang di-pop
    return poppedValue;               // Kembalikan karakter
}

// Fungsi untuk mengecek apakah kurung seimbang
bool areBracketsBalanced(string expr) 
{
    Node* stackTop = nullptr;  // Stack untuk menyimpan kurung buka
    
    // Loop melalui setiap karakter dalam string
    for (char c : expr) 
    {
        // Jika karakter adalah kurung buka, masukkan ke stack
        if (c == '(' || c == '{' || c == '[') 
        {
            push(stackTop, c);  // Push kurung buka ke stack
        }

        // Jika karakter adalah kurung tutup
        else if (c == ')' || c == '}' || c == ']') 
        {
            // Cek jika stack kosong - berarti ada kurung tutup tanpa pasangan
            if (stackTop == nullptr) return false;

            // Ambil kurung buka terakhir dari stack
            char topChar = pop(stackTop);
            
            // Cek apakah kurung buka dan tutup cocok
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) 
            {
                return false;  // Tidak cocok, return false
            }
        }
    }
    
    // Jika stack kosong, semua kurung memiliki pasangan
    // Jika stack tidak kosong, berarti ada kurung buka tanpa pasangan
    return stackTop == nullptr;
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;

    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;

    return 0;
}
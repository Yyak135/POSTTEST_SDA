#include <iostream>
using namespace std;

// Struktur untuk menyimpan data dan hubungan antara data
struct Node 
{
    int data;       // Menyimpan nilai angka
    Node* next;     // Menunjuk ke data berikutnya
    Node* prev;     // Menunjuk ke data sebelumnya
};

// Fungsi untuk memasukkan data baru secara terurut
void sortedInsert(Node *&head_ref, int data) 
{
    // Buat data baru
    Node* newNode = new Node{data, nullptr, nullptr};
    
    // Kasus 1: Jika list masih kosong
    if (head_ref == nullptr) 
    {
        // Data baru menunjuk ke dirinya sendiri (membentuk lingkaran)
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;  // Data baru menjadi kepala list
        return;
    }
    
    Node* current = head_ref;
    
    // Kasus 2: Jika data baru lebih kecil dari data kepala
    if (data < head_ref->data) 
    {
        Node* tail = head_ref->prev;  // Ambil data terakhir
        
        // Sisipkan data baru sebelum kepala
        newNode->next = head_ref;
        newNode->prev = tail;
        head_ref->prev = newNode;
        tail->next = newNode;
        head_ref = newNode;  // Update kepala menjadi data baru
        return;
    }
    
    // Kasus 3: Cari posisi yang tepat untuk data baru
    while (current->next != head_ref && current->next->data < data) 
    {
        current = current->next;  // Maju sampai menemukan posisi yang tepat
    }
    
    // Sisipkan data baru setelah current
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
}

// Fungsi untuk menampilkan semua data dalam list
void printList(Node *head_ref) 
{
    if (head_ref == nullptr) 
    {
        cout << "List kosong" << endl;
        return;
    }
    
    Node *current = head_ref;
    do 
    {
        cout << current->data << " ";  // Tampilkan data
        current = current->next;       // Pindah ke data berikutnya
    } while (current != head_ref);     // Berhenti ketika kembali ke kepala
    cout << endl;
}

int main() 
{
    Node *head = nullptr;  // List mulai dari kosong
    
    // Memasukkan data secara acak tapi akan tersusun otomatis
    sortedInsert(head, 30);
    sortedInsert(head, 10);
    sortedInsert(head, 40);
    sortedInsert(head, 20);
    
    cout << "Circular Doubly Linked List (sorted): ";
    printList(head);  // Output: 10 20 30 40
    
    return 0;
}
#include <iostream>
using namespace std;

// Struktur untuk menyimpan data dan hubungannya
struct Node 
{
    int data;       // Menyimpan nilai angka
    Node* next;     // Menunjuk ke data berikutnya  
    Node* prev;     // Menunjuk ke data sebelumnya
};

// Fungsi untuk menukar posisi data pertama dan terakhir
void exchangeHeadAndTail(Node *&head_ref) 
{
    // Jika list kosong atau hanya ada 1 data, tidak perlu ditukar
    if (head_ref == nullptr || head_ref->next == head_ref) 
    {
        return;
    }
    
    // Simpan data pertama (head) dan data terakhir (tail)
    Node* head = head_ref;
    Node* tail = head_ref->prev;
    
    // Kasus khusus: jika hanya ada 2 data
    if (head->next == tail && tail->prev == head) 
    {
        head_ref = tail;  // Data terakhir jadi data pertama
        return;
    }
    
    // Simpan tetangga dari data pertama dan terakhir
    Node* head_next = head->next;  // Data setelah head
    Node* tail_prev = tail->prev;  // Data sebelum tail
    
    // Proses penukaran hubungan:
    // Data sebelum tail sekarang menunjuk ke head
    tail_prev->next = head;
    // Data setelah head sekarang menunjuk ke tail  
    head_next->prev = tail;
    
    // Tail sekarang menjadi head baru:
    tail->next = head_next;  // Tail menunjuk ke data setelah head lama
    tail->prev = head;       // Tail menunjuk ke head lama
    
    // Head lama sekarang menjadi tail baru:
    head->next = tail;       // Head lama menunjuk ke tail baru
    head->prev = tail_prev;  // Head lama menunjuk ke data sebelum tail lama
    
    // Update kepala list menjadi tail (yang sekarang jadi head baru)
    head_ref = tail;
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
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);  // Berhenti ketika kembali ke awal
    cout << endl;
}

// Fungsi untuk menambah data di akhir list
void insertEnd(Node *&head_ref, int data) 
{
    Node *newNode = new Node{data, nullptr, nullptr};
    
    // Jika list kosong, data baru menjadi satu-satunya data
    if (head_ref == nullptr) 
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }
    
    // Cari data terakhir
    Node *tail = head_ref->prev;
    
    // Sambungkan data baru ke dalam lingkaran
    newNode->next = head_ref;
    newNode->prev = tail;
    head_ref->prev = newNode;
    tail->next = newNode;
}

int main() 
{
    Node *head = nullptr;  // List mulai dari kosong
    
    // Membuat list: 1 2 3 4 5
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);
    
    cout << "List sebelum exchange: ";
    printList(head);  // Output: 1 2 3 4 5
    
    exchangeHeadAndTail(head);  // Tukar posisi 1 dan 5
    
    cout << "List setelah exchange head dan tail: ";
    printList(head);  // Output: 5 2 3 4 1
    
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

// Struktur untuk menyimpan data dokumen dalam antrian
struct Node 
{
    string document;  // Menyimpan nama file dokumen
    Node* next;       // Menunjuk ke dokumen berikutnya dalam antrian
};

// Fungsi untuk menambahkan dokumen ke dalam antrian printer
void enqueue(Node*& front, Node*& rear, string document) 
{
    // Buat data baru untuk dokumen
    Node* newNode = new Node{document, nullptr};
    
    // Jika antrian kosong, dokumen baru menjadi yang pertama dan terakhir
    if (front == nullptr) 
    {
        front = rear = newNode;
    } 
    // Jika antrian sudah ada isinya, tambahkan di belakang
    else 
    {
        rear->next = newNode;  // Sambungkan dokumen terakhir ke dokumen baru
        rear = newNode;        // Dokumen baru sekarang menjadi yang terakhir
    }
}

// Fungsi untuk mengambil dokumen dari antrian untuk diproses
string dequeue(Node*& front, Node*& rear) 
{
    if (front == nullptr) return "";  // Jika antrian kosong, return string kosong
    
    string doc = front->document;  // Ambil nama dokumen yang paling depan
    Node* temp = front;            // Simpan pointer ke dokumen yang akan dihapus
    front = front->next;           // Geser ke dokumen berikutnya dalam antrian
    
    // Jika setelah diambil antrian menjadi kosong
    if (front == nullptr) 
    {
        rear = nullptr;  // Set pointer belakang juga jadi kosong
    }
    
    delete temp;    // Hapus data dokumen yang sudah diambil
    return doc;     // Kembalikan nama dokumen yang akan diproses
}

// Fungsi untuk memproses semua dokumen dalam antrian
void processAllDocuments(Node*& front, Node*& rear) 
{
    // Loop sampai semua dokumen dalam antrian habis diproses
    while (front != nullptr) 
    {
        string doc = dequeue(front, rear);      // Ambil dokumen dari antrian
        cout << "Memproses: " << doc << endl;   // Tampilkan dokumen yang sedang diproses
    }
}

int main() 
{
    Node* front = nullptr;  // Pointer ke dokumen paling depan dalam antrian
    Node* rear = nullptr;   // Pointer ke dokumen paling belakang dalam antrian

    // Tambahkan beberapa dokumen ke dalam antrian printer
    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);  // Proses semua dokumen secara berurutan

    return 0;
}
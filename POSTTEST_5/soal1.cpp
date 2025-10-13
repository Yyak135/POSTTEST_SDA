#include <iostream>
using namespace std;

// Struktur Node pada Binary Search Tree (BST)
struct Node 
{
    int data;       // Menyimpan nilai data dari node
    Node* left;     // Menunjuk ke child kiri
    Node* right;    // Menunjuk ke child kanan

    // Menginisialisasi node baru dengan nilai tertentu
    Node(int val) 
    {
        data = val;
        left = nullptr;   // Awalnya belum punya child kiri
        right = nullptr;  // Awalnya belum punya child kanan
    }
};

// Fungsi untuk menambahkan node baru ke dalam BST
Node* insert(Node* root, int val) 
{
    // Jika tree masih kosong, buat node baru sebagai root
    if (root == nullptr) 
    {
        return new Node(val);
    }

    // Jika nilai yang dimasukkan lebih kecil dari data root, masukkan ke subtree kiri
    if (val < root->data) 
    {
        root->left = insert(root->left, val);
    } 
    // Jika nilai yang dimasukkan lebih besar dari data root, masukkan ke subtree kanan
    else if (val > root->data) 
    {
        root->right = insert(root->right, val);
    }

    // Kembalikan root untuk menjaga struktur tree
    return root;
}

// Fungsi untuk menghitung jumlah total node dalam tree
int countNodes(Node* root) 
{
    // Jika tree kosong (tidak ada node), maka jumlah node = 0
    if (root == nullptr)
        return 0;
    
    // Jika tidak kosong:
    // Hitung 1 untuk node saat ini, lalu tambahkan jumlah node di subtree kiri dan kanan
    // Logikanya mirip traversal: kita kunjungi semua node, tapi alih-alih mencetak, kita menghitung
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() 
{
    Node* root = nullptr;  // Membuat tree kosong

    // Menambahkan data ke dalam BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);

    // Menampilkan hasil perhitungan jumlah total node
    cout << "Jumlah total node dalam tree adalah: " << countNodes(root) << endl; 

    return 0;
}

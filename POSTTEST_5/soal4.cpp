#include <iostream>
using namespace std;

// Struktur Node yang digunakan pada Binary Tree
struct Node 
{
    int data;       // Menyimpan nilai data
    Node* left;     // Menunjuk ke child kiri
    Node* right;    // Menunjuk ke child kanan

    // Membuat node baru
    Node(int val) 
    {
        data = val;
        left = nullptr;   // Awalnya belum punya child kiri
        right = nullptr;  // Awalnya belum punya child kanan
    }
};

// Fungsi insert digunakan untuk menambahkan node baru ke dalam Binary Search Tree (BST)
Node* insert(Node* root, int val) 
{
    // Jika tree masih kosong, buat node baru sebagai root
    if (root == nullptr)
        return new Node(val);

    // Jika nilai lebih kecil dari root, simpan di subtree kiri
    if (val < root->data)
        root->left = insert(root->left, val);
    // Jika nilai lebih besar dari root, simpan di subtree kanan
    else if (val > root->data)
        root->right = insert(root->right, val);

    // Kembalikan root agar struktur tree tetap terhubung
    return root;
}

// Fungsi untuk melakukan traversal dengan metode Post-Order
void postOrderTraversal(Node* root) 
{
    // Jika node kosong, hentikan rekursi
    if (root == nullptr)
        return;

    // Kunjungi subtree kiri terlebih dahulu
    postOrderTraversal(root->left);

    // Setelah itu kunjungi subtree kanan
    postOrderTraversal(root->right);

    // Terakhir, cetak data node saat ini 
    cout << root->data << " ";
}

int main() 
{
    Node* root = nullptr;  // Awalnya tree masih kosong

    // Menambahkan node ke dalam tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    // Menampilkan hasil traversal dengan metode Post-Order
    cout << "Post-order traversal dari tree adalah: ";
    postOrderTraversal(root); 
    cout << endl;

    return 0;
}

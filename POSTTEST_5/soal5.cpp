#include <iostream>
using namespace std;

// Struktur Node yang digunakan pada Binary Tree
struct Node 
{
    int data;        // Menyimpan nilai dari node
    Node* left;      // Pointer menuju child kiri
    Node* right;     // Pointer menuju child kanan

    // inisialisasi node baru
    Node(int val) 
    {
        data = val;          // Nilai data diisi dengan parameter val
        left = nullptr;      // Awalnya belum punya child kiri
        right = nullptr;     // Awalnya belum punya child kanan
    }
};

// Fungsi insert untuk menambahkan node baru ke dalam Binary Search Tree (BST)
Node* insert(Node* root, int val) 
{
    // Jika tree masih kosong, buat node baru dan jadikan sebagai root
    if (root == nullptr)
        return new Node(val);

    // Jika nilai lebih kecil dari root, masukkan ke subtree kiri
    if (val < root->data)
        root->left = insert(root->left, val);
    // Jika nilai lebih besar dari root, masukkan ke subtree kanan
    else if (val > root->data)
        root->right = insert(root->right, val);

    // Kembalikan root agar hubungan antar node tetap utuh
    return root;
}

// Fungsi untuk melakukan traversal dengan metode Pre-Order 
void preOrderTraversal(Node* root) 
{
    // Jika node kosong, hentikan rekursi
    if (root == nullptr)
        return;

    // Cetak data dari node saat ini terlebih dahulu 
    cout << root->data << " ";

    // Rekursif ke subtree kiri
    preOrderTraversal(root->left);

    // Rekursif ke subtree kanan
    preOrderTraversal(root->right);
}

int main() 
{
    Node* root = nullptr;  // Awalnya tree masih kosong

    // Tambahkan beberapa node ke dalam tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    // Tampilkan hasil traversal Pre-Order
    cout << "Pre-order traversal dari tree adalah: ";
    preOrderTraversal(root); 
    cout << endl;

    return 0;
}

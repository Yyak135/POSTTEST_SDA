#include <iostream>
using namespace std;

// Struktur Node yang digunakan pada Binary Search Tree (BST)
struct Node 
{
    int data;       // Menyimpan nilai data dari node
    Node* left;     // Menunjuk ke child kiri
    Node* right;    // Menunjuk ke child kanan

    // Membuat node baru dengan nilai tertentu
    Node(int val) 
    {
        data = val;
        left = nullptr;   // Awalnya belum punya child kiri
        right = nullptr;  // Awalnya belum punya child kanan
    }
};

// Fungsi untuk menambahkan node baru ke dalam tree (sesuai aturan BST)
Node* insert(Node* root, int val) 
{
    // Jika tree kosong, buat node baru dan jadikan sebagai root
    if (root == nullptr)
        return new Node(val);

    // Jika nilai lebih kecil dari root, masukkan ke subtree kiri
    if (val < root->data)
        root->left = insert(root->left, val);
    // Jika nilai lebih besar dari root, masukkan ke subtree kanan
    else if (val > root->data)
        root->right = insert(root->right, val);

    // Kembalikan root agar struktur tree tetap terhubung
    return root;
}

// Fungsi untuk mencari nilai terkecil dalam BST
int findMinValue(Node* root) 
{
    // Jika tree kosong, kembalikan -1 sebagai tanda tidak ada data
    if (root == nullptr)
        return -1;

    // Karena pada BST nilai terkecil selalu ada di node paling kiri, maka kita bergerak terus ke arah kiri sampai tidak ada child kiri lagi
    while (root->left != nullptr)
        root = root->left;

    // Node paling kiri adalah node dengan nilai terkecil
    return root->data;
}

int main() 
{
    Node* root = nullptr;  // Awalnya tree kosong

    // Menambahkan beberapa data ke dalam tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    // Menampilkan hasil nilai terkecil di dalam tree
    cout << "Nilai terkecil dalam tree adalah: " << findMinValue(root) << endl; 

    return 0;
}

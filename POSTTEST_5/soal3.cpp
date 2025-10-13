#include <iostream>
using namespace std;

// Struktur Node yang digunakan pada Binary Search Tree (BST)
struct Node 
{
    int data;       // Menyimpan nilai data dari node
    Node* left;     // Menunjuk ke child kiri
    Node* right;    // Menunjuk ke child kanan

    // Membuat node baru, untuk mengatur nilai awal data dan pointer child
    Node(int val) 
    {
        data = val;
        left = nullptr;   // Awalnya belum memiliki child kiri
        right = nullptr;  // Awalnya belum memiliki child kanan
    }
};

// Fungsi untuk menambahkan node baru ke dalam BST sesuai dengan aturannya
Node* insert(Node* root, int val) 
{
    // Jika tree masih kosong, buat node baru dan kembalikan sebagai root
    if (root == nullptr)
        return new Node(val);

    // Jika nilai yang dimasukkan lebih kecil dari data root, masukkan ke subtree kiri
    if (val < root->data)
        root->left = insert(root->left, val);
    // Jika nilai yang dimasukkan lebih besar dari data root, masukkan ke subtree kanan
    else if (val > root->data)
        root->right = insert(root->right, val);

    // Kembalikan root agar struktur tree tetap utuh
    return root;
}

// Fungsi untuk mencari nilai terbesar dalam Binary Search Tree
int findMaxValue(Node* root) 
{
    // Jika tree kosong, kembalikan -1 sebagai tanda tidak ada data
    if (root == nullptr)
        return -1;

    // Karena pada BST nilai terbesar selalu ada di node paling kanan, maka kita terus bergerak ke kanan sampai tidak ada anak kanan lagi
    while (root->right != nullptr)
        root = root->right;

    // Node paling kanan adalah node dengan nilai terbesar
    return root->data;
}

int main() 
{
    Node* root = nullptr;  // Awalnya tree kosong

    // Menambahkan beberapa nilai ke dalam BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 80);

    // Menampilkan nilai terbesar dari tree
    cout << "Nilai terbesar dalam tree adalah: " << findMaxValue(root) << endl; 

    return 0;
}

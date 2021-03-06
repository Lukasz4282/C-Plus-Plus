#include "pch.h"
#include <iostream>
using namespace std;

class BST
{

	struct node {
		int data;
		node* left;
		node* right;
	};

	node* root;

	node* makeEmpty(node* t)
	{
		if (t == NULL)
			return NULL;
		else
		{
			makeEmpty(t->left);
			makeEmpty(t->right);
			delete t;
		}
		return NULL;
	}

	node* insert(int x, node* t)
	{
		if (t == NULL)
		{
			t = new node;
			t->data = x;
			t->left = t->right = NULL;
		}
		else if (x < t->data)
			t->left = insert(x, t->left);
		else if (x > t->data)
			t->right = insert(x, t->right);
		return t;

	}
	int sum(node* t)
	{
		if (root == NULL)
			return 0;
		return (t->data + sum(t->left) + sum(t->right));
	}

	node* findMin(node* t)
	{
		if (t == NULL)
			return NULL;
		else if (t->left == NULL)
			return t;
		else
			return findMin(t->left);
	}

	node* findMax(node* t) {
		if (t == NULL)
			return NULL;
		else if (t->right == NULL)
			return t;
		else
			return findMax(t->right);
	}

	node* remove(int x, node* t) {
		node* temp;
		if (t == NULL)
		{
			cout << "This tree is empty";
			return NULL;
		}

		else if (x < t->data)
			t->left = remove(x, t->left);
		else if (x > t->data)
			t->right = remove(x, t->right);
		else if (t->left && t->right)
		{
			temp = findMin(t->right);
			t->data = temp->data;
			t->right = remove(t->data, t->right);
		}
		else
		{
			temp = t;
			if (t->left == NULL)
				t = t->right;
			else if (t->right == NULL)
				t = t->left;
			delete temp;
		}

		return t;
	}

	void printPostorder(struct node* t)
	{
		if (t == NULL)
			return;
		printPostorder(t->left);
		printPostorder(t->right);
		cout << t->data << " ";
	}

	void printPreorder(struct node* t)
	{
		if (t == NULL)
			return;
		cout << t->data << " ";
		printPreorder(t->left);
		printPreorder(t->right);
	}

	void inorder(node* t) {
		if (t == NULL)
			return;
		inorder(t->left);
		cout << t->data << " ";
		inorder(t->right);
	}

	node* find(node* t, int x) {
		if (t == NULL)
			return NULL;
		else if (x < t->data)
			return find(t->left, x);
		else if (x > t->data)
			return find(t->right, x);
		else if (x == t->data)
			return t;
		else
			return t;
	}

	int OddNumbers(node* t, int odd)
	{
		int temp = 0;
		if (t != NULL)
		{
			odd = OddNumbers(t->left, odd);
			odd = OddNumbers(t->right, temp) + OddNumbers(t->left, temp);
			if ((t->data % 2) != 0)
				odd++;
		}
			return odd;

	}

	int EvenNumbers(node* t, int odd)
	{
		int temp = 0;
		if (t != NULL)
		{
			odd = OddNumbers(t->left, odd);
			odd = OddNumbers(t->right, temp) + OddNumbers(t->left, temp);
			if ((t->data % 2) == 0)
				odd++;
		}
		return odd;

	}

	//cout << "Total odd numbers: " << odd << endl;
	//cout << "Total even numbers: " << even << endl;
public:
	BST() {
		root = NULL;
	}

	~BST() {
		root = makeEmpty(root);

	}

	void insert(int x) {
		root = insert(x, root);
	}

	void remove(int x) {
		root = remove(x, root);
	}

	void display() {
		inorder(root);
		cout << endl;
	}

	void search(int x) {
		root = find(root, x);
		if (root != NULL)
			cout << x << " has been found !" << endl;
		else cout << x << " has not been found !" << endl;
	}

	void add()
	{
		cout << "Total: " << sum(root) << endl;
	}

	void postorder()
	{
		cout << "PostOrder: ";
		printPostorder(root);
		cout << endl;
	}

	void preorder()
	{
		cout << "PreOrder: ";
		printPreorder(root);
		cout << endl;
	}

	void inorder()
	{
		cout << "InOrder: ";
		inorder(root);
		cout << endl;
	}

	void oddeven()
	{
		int x = 0, temp;
		temp = OddNumbers(root, x);
		cout << "The number of odd numbers is: " << temp << endl;
		temp = EvenNumbers(root, x);
		cout << "The number of even numbers is: " << temp << endl;
	}
};

int main() {
	BST t;
	t.insert(20);
	t.insert(25);
	t.insert(15);
	t.insert(10);
	t.insert(30);
	t.display();
	t.remove(20);
	t.display();
	t.remove(25);
	t.display();
	t.remove(30);
	t.display();
	t.search(15);
	t.insert(20);
	t.insert(25);
	t.insert(30);
	t.insert(23);
	t.postorder();
	t.preorder();
	t.inorder();
	t.display();
	t.oddeven();
	return 0;
}

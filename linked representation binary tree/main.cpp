#include <iostream>
using namespace std;
class Tree {
	int data;
public:
	Tree* left;
	Tree* right;
	Tree(int d = 0, Tree* l = nullptr, Tree* r = nullptr) : data(d), left(l), right(r) {
	}
	void set_data();
	int get_data() const;
	void set_left_right(Tree *l, Tree *r) {
		left = l; right = r;
	}

};
void Tree::set_data() {
	cout << "Enter data: ";
	cin >> data;
}
int Tree::get_data() const {
	return data;
}
void display_preorder(Tree *n) {
	if (n == nullptr)
		return;
	cout << n->get_data() << endl;
	display_preorder(n->left);
	display_preorder(n->right);
}

void display_postorder(Tree* n) {
	if (n == nullptr)
		return;
	display_postorder(n->left);
	display_postorder(n->right);
	cout << n->get_data() << endl;
}
void display_inorder(Tree* n) {
	if (n == nullptr)
		return;
	display_inorder(n->left);
	cout << n->get_data() << endl;
	display_inorder(n->right);
}
int main() {
	Tree* nl = new Tree(11);
	Tree* nr = new Tree(5);
	Tree* n = new Tree(7, nl, nr);
	Tree* nl_left = new Tree(13);
	Tree* nr_left = new Tree(8);
	Tree* nr_right = new Tree(2);	
	nl->set_left_right(nl_left, nullptr);
	nr->set_left_right(nr_left, nr_right);

	display_inorder(n);

	delete n, nl, nr,nl_left, nr_left, nr_right;

	return 0;
}
#define IsRoot(x) (x.parent == NULL)
#define IsLeftChild(x) !IsRoot(x) && ( &x == x.parent->leftchild)
#define FromParentTo(x) IsRoot(x)?_root:(IsLeftChild(x)?x.parent->leftchild:x.parent->rightchild)
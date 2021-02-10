#define IsRoot(x) ((x).parent == NULL)
#define IsLeftChild(x) !IsRoot(x) && ( &(x) == (x).parent->leftchild)
#define IsRightChild(x) !IsRoot(x) && (&(x) == (x).parent->rightchild)
#define FromParentTo(x) IsRoot(x)?_root:(IsLeftChild(x)?(x).parent->leftchild:(x).parent->rightchild)

#define HasRightChild(x) ((x).rightchild)
#define HasLeftChild(x) ((x).leftchild)
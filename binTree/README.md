**binTree:**<br>
| 操作接口                                                     | 功能                                              | 成员类型    |
| :----------                                                  | :------                                           | :---------- |
| binTree(T const& e){}                                        | 构造一个根存储的值为e的二叉树                     | 构造器      |
| binTree(){}                                                  | 构造一个空二叉树                                  | 构造器      |
| int size const()                                             | 返回二叉树的规模                                  | 函数        |
| bool empty()                                                 | 返回该树是否为空                                  | 函数        |
| binNode\<T\>* root()                                         | 返回根节点的指针                                  | 函数        |
| binNode\<T\>* insertAsRoot(T const& e)                       | 将e作为根节点的数据插入                           | 函数        |
| binNode\<T\>* insertAsRC(binNode\<T\>* x, T const& e)        | 对x的右节点插入                                   | 函数        |
| binNode\<T\>* insertAsLC(binNode\<T\>* x, T const& e)        | 对x的左节点插入                                   | 函数        |
| binNode\<T\>* attachAsRC(binNode\<T\>* x, binTree\<T\>* & S) | 将二叉树S作为节点x的右子树                        | 函数        |
| binNode\<T\>* attachAsLC(binNode\<T\>* x,binTree\<T\>*& S)   | 将二叉树S作为节点x的左子树                        | 函数        |
| int remove(binNode\<T\>* x)                                  | 将x节点及其儿孙节点从树上删除，返回总共删除的总数 | 函数        |
| binTree\<T\>* secede(binNode\<T\>* x)                        | 将x节点及其儿孙从树上分离，返回被分离的树         | 函数        |
| template \<typename VST\> void travPre(VST& visit)           | 先序遍历：对每个元素执行visit操作                 | 函数        |
| template \<typename VST\> void travPost(VST& visit)          | 后序遍历：对每个元素执行visit操作                 | 函数        |
| template \<typename VST\> void travLevel(VST& visit)         | 层序遍历：对每个元素执行visit操作                 | 函数        |
| template \<typename VST\> void travIn(VST& visit)            | 中序遍历：对每个元素执行visit操作                 | 函数        |


**binNode:(二叉树节点)**<br>
| 操作接口                                              | 功能                                                    | 成员类型    |
| :---------------------------------------------------- | :------                                                 | :---------- |
| binNode\<T\>* parent                                  | 当前节点的父亲节点                                      | 参数        |
| binNode\<T\>* leftchild                               | 当前节点的左儿子节点                                    | 参数        |
| binNode\<T\>* rightchild                              | 当前节点的右儿子节点                                    | 参数        |
| T data                                                | 当前节点存储的数据                                      | 参数        |
| int height                                            | 当前节点的高度(当前节点到其叶子节点的最大高度)          | 参数        |
| binNode(T const& edata){}                             | 构造一个存储edata数据的节点                             | 构造器      |
| binNode(T const& edata , binNode\<T\>* pa) {}         | 构造一个存储edata数据的节点,并将该节点父亲节点设置为pa  | 构造器      |
| int size()                                            | 返回当前节点(this节点)的规模                            | 函数        |
| binNode\<T\>* insertAsLeftChild(T const& e)           | 将数据为e的新节点插入当前节点的左节点，返回新插入的节点 | 函数        |
| binNode\<T\>* insertAsRightChild(T const& e)          | 将数据为e的新节点插入当前节点的右节点，返回新插入的节点 | 函数        |
| binNode\<T\>* succ()                                  | 返回中序遍历下当前节点的直接后缀                        | 函数        |
| template \<typename VST\> void travLevel(VST& visit)  | 从当前节点开始层序遍历,并对每个元素执行visit操作        | 函数        |
| template \<typename VST\> void travPost (VST& visit)  | 从当前节点开始后序遍历,并每个元素执行visit操作          | 函数        |
| template \<typename VST\> void travPre(VST& visit)    | 从当前节点开始先序遍历,并对每个元素执行visit操作        | 函数        |
| template \<typename VST\> void travIn (VST& visit)    | 从当前节点开始中序遍历,并对每个元素执行visit操作        | 函数        |


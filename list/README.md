**List:**<br>
| 操作接口                                                 | 功能                                           | 接口类型    |
| :-----------------------------------------------------   | :--------------------------------------------- | :---------- |
| List(){}                                                 | 构造                                           | 构造器      |
| List(List<T>const& L ){}                                 | 复制传入的列表                                 | 构造器      |
| int size() const                                         | 报告列表当前的规模(节点总数)                   | 函数        |
| ListNode\<T\>* first() const,ListNode\<T\>* last() const | 返回首末节点的位置                             | 函数        |
| ListNode\<T\>* insertAtFirst(T const& e)                 | 将e当作首节点插入                              | 函数        |
| ListNode\<T\>* insertAtLast(T const& e)                  | 将e当作末节点插入                              | 函数        |
| ListNode\<T\>* insertA(ListNode\<T\>* p , T const& e)    | 将e当作节点p的直接后继插入                     | 函数        |
| ListNode\<T\>* insertB(ListNode\<T\>* p , T const& e)    | 将e当作节点p的直接前驱插入                     | 函数        |
| T remove(ListNode\<T\>* p)                               | 删除位置p处的节点，返回其引用                  | 函数        |
| int disordered () const                                  | 判断所有节点是否已按非降序排列                 | 函数        |
| void sort()                                              | 调整各节点的位置，使之按照非降序排列           | 函数        |
| void sort(ListNode\<T\>* p,int n)                        | 对列表中起始为p,宽度为n的列表进行排序          | 函数        |
| ListNode\<T\>* find(T const& e) const                    | 查找目标元素e,失败时返回NULL                   | 函数        |
| ListNode\<T\>* find(T const& e,int n,ListNode\<T\>* p)y  | 从p开始向前的n个节点中寻找e                    | 函数        |
| ListNode\<T\>* search(T const& e,int n,ListNode\<T\>* p) | 在有序列表的n个前驱中,找到不大于e的最靠后者    | 函数        |
| int deduplicate()                                        | 无序列表删除重复节点,返回删除节点的个数        | 函数        |
| int uniquify()                                           | 有序列表删除重复节点,返回删除节点的个数        | 函数        |
| template \<typename VST\> void traverse(VST& visit)      | 遍历列表并统一处理所有元素                     | 函数        |

**listNode:**<br>
| 操作接口                                                                        | 功能                    | 接口类型    |
| :-----------------------------------------------------   | :--------------------------------------------- | :---------- |
| T data;                                                                         | T类型的数据             | 参数        |
| ListNode\<T\>* pred;                                                            | 当前节点的前驱          | 参数        |
| ListNode\<T\>* succ;                                                            | 当前节点的后继          | 参数        |
| ListNode(){}                                                                    | 构造                    | 构造器      |
| ListNode(T e, ListNode\<T\>* p , ListNode\<T\>* s) : data(e),pred(p),succ(s){}  | 构造                    | 构造器      |
| ListNode\<T\>* insertAsPred(T const& e);                                        | 向当前节点的前面插入    | 函数        |
| ListNode\<T\>* insertAsSucc(T const& e);                                        | 向当前节点的后面插入    | 函数        |

**vector:**<br>
| 操作接口                                                | 功能                                                     | 成员类型    |
| :------------------------------------------------------ | :------------------------------------------------------- | :---------- |
| vector(int c = DEFAULT_CAPACITY){}                      | 创建一个大小为c的向量，默认是DEFAULT_CAPACITY(3)         | 构造器      |
| vector(T const* A, Rank lo, Rank hi){}                  | 复制类型为T的数组的区间[lo,hi)来构造向量                 | 构造器      |
| vector(vector<T> const& V, Rank lo, Rank hi){}          | 复制向量V的区间[lo,hi)内的元素来构造向量                 | 构造器      |
| vector(vector<T> const& V){}                            | 复制向量V整体来构造向量                                  | 构造器      |
| int size() const                                        | 报告向量当前的规模(元素总数)                             | 函数        |
| bool empty() const                                      | 返回向量的规模                                           | 函数        |
| int get(Rank r)                                         | 获取秩为r的元素                                          | 函数        |
| int put(Rank r,T const& e)                              | 用e替换秩为r的元素的数值                                 | 函数        |
| Rank insert(Rank r,T const& e)                          | e作为秩为r的元素插入,原后继依次后移                      | 函数        |
| Rank insert(T const& e)                                 | 将e插入向量末尾                                          | 函数        |
| T remove(Rank r)                                        | 删除秩为r的元素,返回该元素的原值                         | 函数        |
| int remove(Rank lo,Rank hi)                             | 删除去区间[lo,hi)的所以元素，返回删除元素的数目          | 函数        |
| int disordered() const                                  | 判断所有元素是否已按非降序排列 ，返回相邻逆序对的数目    | 函数        |
| void sort(Rank lo,Rank hi)                              | 调整区间[lo,hi)各元素的位置，使之按照非降序排列          | 函数        |
| void sort()                                             | 调整向量各元素的位置，使之按照非降序排列                 | 函数        |
| Rank find(T const& e) const                             | 查找目标元素e                                            | 函数        |
| Rank find(T const& e, Rank lo, Rank hi) const           | 在区间[lo,hi)内查找目标元素e                             | 函数        |
| Rank search(const T& e, Rank lo,Rank hi)                | 有序向量在区间[lo,hi)查找e,返回不大于e且秩最大的节点     | 函数        |
| int deduplicate()                                       | 无序向量删除重复元素，返回删除元素个数                   | 函数        |
| int uniquify()                                          | 有序向量删除重复元素，返回删除元素个数                   | 函数        |
| template \<typename VST\> void traverse(VST & visit)    | 遍历向量并统一处理所有元素                               | 函数        |


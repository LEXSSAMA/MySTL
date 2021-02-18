**graphicMatrix:**<br>
| 操作接口                                           | 功能                                                     | 成员类型    |
| :------------------------------------------------- | :------                                                  | :---------- |
| graphicMatrix(){}                                  | 构造一个邻接矩阵图                                       | 构造器      |
| Tv remove(int r)                                   | 删除秩为r的顶点                                          | 函数        |
| Tv& getVertex(int r)                               | 获取秩为r的顶点的数据                                    | 函数        |
| int getInDegree(int r)                             | 获取秩为r的顶点的出度                                    | 函数        |
| int getOutDegree(int r)                            | 获取秩为r的顶点的入度                                    | 函数        |
| int getFirstNbr(int r)                             | 获取秩为r的顶点的首个邻接顶点                            | 函数        |
| int getNextNbr(int v,int u)                        | 获取秩为v的顶点(相对于秩为u的顶点的)下一个邻接顶点       | 函数        |
| VStatus& getStatus(int r)                          | 获取秩为r的顶点的状态                                    | 函数        |
| int& getDTime(int r)                               | 获取秩为r的顶点的时间标签dTime                           | 函数        |
| int& getFTime(int r)                               | 获取秩为r的顶点的时间标签fTime                           | 函数        |
| int& getParent(int r)                              | 获取秩为r的顶点在遍历树中的父亲                          | 函数        |
| int& getPriority(int r)                            | 获取秩为r的顶点在遍历树中的优先级数                      | 函数        |
| bool exists(int v,int u)                           | 判断边e(v,u)是否存在                                     | 函数        |
| int insertV(Tv const& d)                           | 插入一个储存数据为d的新顶点                              | 函数        |
| void insertE(Te const& edata,int v,int u,int w)    | 为顶点v,u之间插入一个存储数据为edata,权重为w有向边e(v,u) | 函数        |
| Te remove(int v, int u)                            | 删除边e(v,u)                                             | 函数        |
| Etype& getType(int v,int u)                        | 获取边e(v,u)的类型                                       | 函数        |
| Te& getEdge(int v,int u)                           | 获取边e(v,u)存储的数据                                   | 函数        |
| int& getWeight(int v,int u)                        | 获取边e(v,u)的权重                                       | 函数        |

**edge:**<br>
| 操作接口                                                        | 功能         | 成员类型    |
| :-------------------------------------------------              | :------      | :---------- |
| Te data                                                         | 边存储的数据 | 参数        |
| int weight                                                      | 边的权重     | 参数        |
| Etype type                                                      | 边的类型     | 参数        |
| edge(Te const& d, int w) : data(d),weight(w),type(UNDETERMINED) | 构造一条新边 | 构造器      |
		
<br>**vertex:**<br>
| 操作接口                                           | 功能                   | 成员类型    |
| :------------------------------------------------- | :------                | :---------- |
| Tv data                                            | 顶点存储的数据         | 参数        |
| int inDegree                                       | 顶点的入度             | 参数        |
| int outDegree                                      | 顶点的出度             | 参数        |
| VStatus status                                     | 顶点的状态             | 参数        |
| int dTime                                          | 顶点的时间状态         | 参数        |
| int fTime                                          | 顶点的时间状态         | 参数        |
| int parent                                         | 顶点在遍历树中的父亲   | 参数        |
| int priority                                       | 顶点在遍历树中的优先级 | 参数        |
| vertex(Tv const& d = (Tv)0)                        | 构造一个新的顶点       | 构造器      |


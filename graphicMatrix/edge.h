#pragma once

template <typename Te> struct edge {
    Te data; int weight; Etype type;    /*边中存储的数据,边的权重，在遍历树中所属的类型*/
    edge(Te const& d, int w) : data(d),weight(w),type(UNDETERMINED){}
};

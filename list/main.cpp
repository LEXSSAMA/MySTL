#include "list.h"
#include <stdio.h>

int main(){
    List<int> L ;
    printf("size = %d\n",L.size());
    for(int i=0;i<10;i++) {
        L.insertAtLast(rand()%300);
    }
    printf("\n\n");
    for(int i=0;i<10;++i){
        printf("%d ",L[i]);
    }
    printf("\n");
    L.sort();
    printf("\n\n");
    for(int i=0;i<10;++i){
        printf("%d ",L[i]);
    }
    printf("\nsize = %d\n",L.size());
    return 0;
}

#include "vector.h"
#include "stdio.h"

int main(){
	vector<vector<int>> V;
	for(int i=0;i<10;++i){
		V.insert(vector<int>(10,10,i));
		for(int j =0;j<10;++j)
			printf("%d ",V[i][j]);
		printf("\n");
	}
}

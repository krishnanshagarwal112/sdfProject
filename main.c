#include <stdio.h>

void displayMatrix(int r, int c,int arr[r][c]){
	for(int i =0; i < r; i++)
	{
		if(i == 0){
			for(int j = 0; j < c; j ++){
				printf("___");
			}
			printf("_\n");
		}
		for(int j = 0; j < c; j++){
			if(j == 0){
				printf("|");
			}
			if(arr[i][j] < 0 || arr[i][j] >= 10){
				printf("%d",arr[i][j]);
			}
			else{
				printf(" %d",arr[i][j]);
			}
			printf("|");
		}
			printf("\n");
		for(int j = 0; j < c; j ++){
			printf("___");
		}
		printf("_\n");
	}
}

void transpose(int r, int c, int mat1[r][c], int mat2[c][r]){
	for(int i = 0; i < c; i++){
		for(int j = 0; j < r; j++){
			mat2[i][j] = mat1[j][i];
		}
	}

}

int main(){
	//first we will input a matrix by the user !
	int r,c;
	printf("Enter number of rows : ");
	scanf("%d",&r);
	printf("Enter number of columns: ");
	scanf("%d",&c);

	int mat[r][c];
	int transposeMat[c][r];

	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			printf("Enter element {%d:%d} > ",i,j);
			int ele;
			scanf("%d",&ele);
			mat[i][j] = ele;
		}
	}
	
	displayMatrix(r,c,mat);
	transpose(r,c,mat,transposeMat);
	displayMatrix(c,r,transposeMat);
	
	

	return 0;
}

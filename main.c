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

void addition(int n1,int n2, int mat1[n1][n2],int mat2[n1][n2],int mat3[n1][n2]){
	for(int i = 0; i < n1; i++){
		for(int j = 0; j < n2; j++){
			mat3[i][j] = mat1[i][j] + mat2[i][j];
		}
	}
}

void subtraction(int n1,int n2, int mat1[n1][n2],int mat2[n1][n2],int mat3[n1][n2]){
	for(int i = 0; i < n1; i++){
		for(int j = 0; j < n2; j++){
			mat3[i][j] = mat1[i][j] - mat2[i][j];
		}
	}
}

void multiplication(int r1, int c1, int r2, int c2,int mat1[r1][c1], int mat2[r2][c2], int mat3[r1][c2]){
	for(int i = 0; i < r1; i++){
		for(int j = 0; j < c2; j++){
			mat3[i][j] = 0;
			for(int k = 0; k < c1; k++){
				mat3[i][j] += mat1[i][k]* mat2[k][j];
			}
		}
	}
}



int* minorArray(int n1, int n2, int mat[3][3]){
	int arr[4];
	int k = 0;
	while(k != 4){
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				if(i != n1 && j != n2){
					arr[k] = mat[i][j];
					k++;
				}
			}
		}
	}
	return arr;
}

int main(){

	// we will ask user for their choice !
	int choice;
	printf("Transpose -> 1\n");
	printf("Addition -> 2\n");
	printf("Subtraction -> 3\n");
	printf("Multiplication -> 4\n");
	printf("Enter your choice > \n");

	scanf("%d",&choice);

	if(choice == 1){
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
		printf("\nNormal Matrix\n");
		displayMatrix(r,c,mat);
		transpose(r,c,mat,transposeMat);
		printf("\nTranspose Matrix\n");;
		displayMatrix(c,r,transposeMat);
	}
	else if(choice == 2){
		// we will input two matrixes by user
		int r;
		int c;
		printf("Enter number of rows > ");
		scanf("%d",&r);
		printf("Enter number of columns > ");
		scanf("%d",&c);
		printf("\n");

		int mat1[r][c];
		int mat2[r][c];
		int mat3[r][c];
	
		printf("\n");
		printf("First Matrix Input");
		printf("\n");
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				printf("Enter element {%d:%d} > ",i,j);
				int ele;
				scanf("%d",&ele);
				mat1[i][j] = ele;
			}
		}

		printf("\n");
		printf("This is the first matrix");
		printf("\n");
		displayMatrix(r,c,mat1);

		printf("Second Matrix Input\n");

		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				printf("Enter element {%d:%d} > ",i,j);
				int ele;
				scanf("%d",&ele);
				mat2[i][j] = ele;
			}
		}

		printf("\n");
		printf("This is the second matrix");
		displayMatrix(r,c,mat2);
		printf("\n");

		addition(r,c,mat1,mat2,mat3);
		printf("The third matrix which is formed by addition of above two matrix : \n");
		displayMatrix(r,c,mat3);
	}

	else if(choice == 3){

		// we will input two matrixes by user
		int r;
		int c;
		printf("Enter number of rows > ");
		scanf("%d",&r);
		printf("Enter number of columns > ");
		scanf("%d",&c);
		printf("\n");

		int mat1[r][c];
		int mat2[r][c];
		int mat3[r][c];
	
		printf("\n");
		printf("First Matrix Input");
		printf("\n");

		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				printf("Enter element {%d:%d} > ",i,j);
				int ele;
				scanf("%d",&ele);
				mat1[i][j] = ele;
			}
		}

		printf("\n");
		printf("This is the first matrix");
		printf("\n");
		displayMatrix(r,c,mat1);	
		printf("\n");

		printf("Second Matrix Input\n");

		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				printf("Enter element {%d:%d} > ",i,j);
				int ele;
				scanf("%d",&ele);
				mat2[i][j] = ele;
			}
		}
		printf("\n");
		printf("This is the first matrix");
		printf("\n");
		displayMatrix(r,c,mat2);
		printf("\n");

		subtraction(r,c,mat1,mat2,mat3);
		printf("The third matrix which is formed by subtraction of above two matrix : \n");
		displayMatrix(r,c,mat3);
	}

	else if(choice == 4){
		int r1;
		int c1;
		int r2;
		int c2;

		printf("Enter number of rows for first matrix : ");
		scanf("%d",&r1);
		printf("Enter number of columns for first matrix : ");
		scanf("%d",&c1);
		printf("Enter number of rows for second matrix : ");
		scanf("%d",&r2);
		printf("Enter number of columns for second matrix : ");
		scanf("%d",&c2);
		printf("\n");
		
		if(c1 != r2){
			printf("Given matrix order do not satisify the condition for matrix multiplication");
		}
		else{
			int mat1[r1][c1];
			int mat2[r2][c2];
			int mat3[r1][c2];

		printf("\n");
		printf("First Matrix Input");
		printf("\n");

		for(int i = 0; i < r1; i++){
			for(int j = 0; j < c1; j++){
				printf("Enter element {%d:%d} > ",i,j);
				int ele;
				scanf("%d",&ele);
				mat1[i][j] = ele;
			}
		}

		printf("\n");
		printf("This is the first matrix");
		printf("\n");
		displayMatrix(r1,c1,mat1);	
		printf("\n");

		printf("Second Matrix Input\n");

		for(int i = 0; i < r2; i++){
			for(int j = 0; j < c2; j++){
				printf("Enter element {%d:%d} > ",i,j);
				int ele;
				scanf("%d",&ele);
				mat2[i][j] = ele;
			}
		}
		printf("\n");
		printf("This is the second matrix");
		printf("\n");
		displayMatrix(r2,c2,mat2);
		printf("\n");
		
		printf("The Third Matrix which is product of above two matrix : \n");
		multiplication(r1,c1,r2,c2,mat1,mat2,mat3);
		displayMatrix(r1,c2,mat3);
		
		}
	}



	

	return 0;
}

#include<stdio.h>
float round(float num){
   int n=num;
   float val=num-n;
   if(val>=0.9){
       n=n+1;
   }
   else if(val<=0.1)
   {
       n=n;
   }
   else{
       float n=num;
       return n;
   }
    return n;
}
int main()
{
    int i,j,k,n,row,col,l;
    float mat[5][5];
    printf("enter the number of variable:");
    scanf("%d",&n);
    row=n;
    col=n+1;
    float sm[row],sf=0.0,rm,temp;
    printf("enter coefficient element of variable in term of matrix:\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%f",&mat[i][j]);
        }
    }
    printf("entered matrix is :\n");
      for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%f\t",mat[i][j]);
        }
        printf("\n");
    }
       for(i=0;i<row-1;i++){

        for(j=i+1;j<row;j++){
              if(mat[i][i]==0)
            {
                if(mat[i+1][j-1]!=0&&(i+1)>=0&&(i+1)<row){
                    for(l=0;l<col;l++){
                        temp=mat[i][l];
                        mat[i][l]=mat[i+1][l];
                        mat[i+1][l]=temp;
                    }
                
                }
                
                else if(mat[i-1][j-1]!=0&&(i-1)>=0&&(i-1)<row){
                    for(l=0;l<col;l++){
                        temp=mat[i][l];
                        mat[i][l]=mat[i-1][l];
                        mat[i-1][l]=temp;
                    }
                
                }
                else  if(mat[i+2][j-1]!=0&&(i+2)>=0&&(i+2)<row){
                    for(l=0;l<col;l++){
                        temp=mat[i][l];
                        mat[i][l]=mat[i+2][l];
                        mat[i+2][l]=temp;
                    }
                }
                  else  if(mat[i-2][j-1]!=0&&(i-2)>=0&&(i-2)<row){
                    for(l=0;l<col;l++){
                        temp=mat[i][l];
                        mat[i][l]=mat[i-2][l];
                        mat[i-2][l]=temp;
                    }
                }
            }
            rm=mat[j][i];
            for(k=i;k<col;k++){
                mat[j][k]=mat[j][k]-(rm*(mat[i][k]/mat[i][i]));
            }
        }
    }
    printf("\neclon matrix is:\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%f\t",mat[i][j]);
        }
        printf("\n");
    }
for(i=row;i>0;i--){
    sm[i]=(mat[i-1][col-1]-sf)/mat[i-1][i-1];
    sf=0.0;
    for(j=i;j<=row;j++){
        sf=sf+(mat[i-2][j-1]*sm[j]);
    }
}
printf("required solution are:\n");
for(i=1;i<=row;i++){
    sm[i]=round(sm[i]);
    printf("x%d=%f\n",i,sm[i]);
}
    return 0;
}
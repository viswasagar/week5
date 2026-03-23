/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 #include<stdlib.h>
 int compare(const void *a,const void *b){
    int * intervalA= *(int **)a;
    int * intervalb=*(int **)b;
    return intervalA[0]-intervalb[0];
 }
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    qsort(intervals,intervalsSize,sizeof(int*),compare);
    int count=0;
    
    *returnColumnSizes=(int *)malloc(intervalsSize * sizeof(int));
    
    int **merged=(int **)malloc(intervalsSize * sizeof(int *));
    for(int i=0;i<intervalsSize;i++)
merged[i]=(int *)malloc(2 * sizeof(int));
int l=0,r=1;
int flag=1;
int maxend=intervals[l][r];
int current=l;
while(r < intervalsSize){
    if(maxend >= intervals[r][0]){
        if(intervals[r][1]>maxend){
            maxend=intervals[r][1];
        }
                    r++;

    }
    else{
           merged[count][0]=intervals[current][0];
        merged[count][1]=maxend; 
                (*returnColumnSizes)[count]=2;
        count++;
        current=r;
        maxend=intervals[current][1];
        l=r;
        r++;
    }
}
merged[count][0]=intervals[current][0];
merged[count][1]=maxend;
                (*returnColumnSizes)[count]=2;

count++;
*returnSize=count;

return merged;
}

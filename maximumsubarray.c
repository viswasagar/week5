int maxSubArray(int* nums, int numsSize) {
     if(numsSize ==1){
return nums[0];
    }
    int sum=0,max=0,l=0,r=0,len=0;
    for(int i=0;i<numsSize;i++){
        sum+=nums[i];
        if(sum > max){
            r=i;
            max=sum;
        }
        if(sum<0){
            if(sum < max && max==0 && i==0){
                max=sum;
            }
            sum=0;
            l=i;
        }
    }
    return max;
}

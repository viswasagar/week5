int reverse(int x){
long long fd=0;
if(x==0){
    return 0;
}
if(x>0){
    if(x>= 2147483647){
        return 0;
    }
while(x>0){

    fd=fd *10 +x%10;
    
    x/=10;
    if(fd >= (((1<<30)-1)*2 +1) && x>=0 && x<=9){
        return 0;
    }
}
return fd;
}
else{
    if(x <= -2147483648){
        return 0;
    }
    x=-x;
    while(x>0){
    fd=fd *10 +x%10;
    x/=10;
    if(fd >= (((1<<30)-1)*2 +1) && x>=0 && x<=9){
        return 0;
    }
}
return -fd;
}
}

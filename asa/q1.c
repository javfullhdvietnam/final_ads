Iterative Version (C)
#include <stdio.h>
#include <string.h>

int main(){
    char s[1000];
    scanf("%s", s);
    int n = 0; 
    while(s[n]) n++;
    for(int i=0;i<n-1;i++){
        char mn=s[i]; 
        int idx=i; 
        for(int j=n-1;j>i;j--){
            if(((s[j]<mn)&&(i>0||s[j]!='0'))||(s[j]==mn&&j>idx)){
                mn=s[j]; 
                idx=j;
            }
        }
        if(idx!=i){
            char t=s[i]; 
            s[i]=s[idx]; 
            s[idx]=t; 
            break;
        }
    }
    printf("%s\n", s);
    return 0;
}
Recursive Version (C)
#include <stdio.h>
#include <string.h>

void r(char *s,int i,int n,int *done){
    if(i>=n-1||*done) return;
    char mn=s[i]; 
    int idx=i; 
    for(int j=n-1;j>i;j--){
        if(((s[j]<mn)&&(i>0||s[j]!='0'))||(s[j]==mn&&j>idx)){
            mn=s[j]; 
            idx=j;
        }
    }
    if(idx!=i){
        char t=s[i]; 
        s[i]=s[idx]; 
        s[idx]=t; 
        *done=1;
    } else {
        r(s,i+1,n,done);
    }
}

int main(){
    char s[1000];
    scanf("%s",s);
    int n=strlen(s),done=0;
    r(s,0,n,&done);
    printf("%s\n",s);
    return 0;
}
Complexity Analysis
Both the iterative and recursive solutions perform a nested search for the best digit to swap, leading to 
O(n^2) time complexity in the worst case, where 
𝑛
n is the number of digits. The space complexity for both is O(n)
due to storing digits in an auxiliary array.

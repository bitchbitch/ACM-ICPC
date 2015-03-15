#include <stdio.h>
#include <string.h>
main(){char s[101];int t;scanf("%d",&t);char k[101]; while(t--){memset(k,0,sizeof(k));scanf("%s",s);int i=0;for(;;i++){k[i]='A';if(!strstr(s,k)){puts(k);break;}}}}

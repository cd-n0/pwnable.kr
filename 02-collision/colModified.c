#include <stdio.h>
#include <string.h>
/* set hashcode to integer 568134124 hex 0x21DD09EC */
unsigned long hashcode = 0x21DD09EC;
/* check_password */
unsigned long check_password(const char* p){
        /* set ip as an integer pointer to argument of the function */
        int* ip = (int*)p;
        int i;
        int res=0;
        /* iterate 5 times */
        for(i=0; i<5; i++){
                res += ip[i];
                /* res = ip[0] + ip[1] + ip[2] + ip[3] + ip[4] */
        }
        return res;
}

int main(int argc, char* argv[]){
        if(argc<2){
                printf("usage : %s [passcode]\n", argv[0]);
                return 0;
        }
        if(strlen(argv[1]) != 20){
                printf("passcode length should be 20 bytes\n");
                return 0;
        }

        if(hashcode == check_password( argv[1] )){
                system("/bin/cat flag");
                return 0;
        }
        else
                printf("wrong passcode.\n");
        return 0;
}

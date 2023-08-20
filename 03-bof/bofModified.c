#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void func(int key){
    /* the buffer is 0x0010 long */
	char overflowme[32];
	printf("overflow me : ");
	gets(overflowme);	// smash me!
	if(key == 0xcafebabe){
		system("/bin/sh");
	}
	else{
		printf("Nah..\n");
	}
}
int main(int argc, char* argv[]){
    /* we need to change this 0xdeadbeef to 0xcafebabe with buffer overflow */
	func(0xdeadbeef);
	return 0;
}


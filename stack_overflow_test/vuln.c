// compile with gcc -m32 vuln.c -fno-stack-protector -no-pie -o vuln
#include <stdio.h>
void backdoor(){
    printf("Backdoor activated!\n");
    system("/bin/sh");
}
void init(){
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stderr, 0, 2, 0);
}
int main(){
    init();
    char input[0x20];
    // give it a stack addrerss
    printf("stack addr at: %p\n", &input);
    printf("Enter your input: ");
    gets(input);
    printf("You entered: %s\n", input);

    return 0;
}
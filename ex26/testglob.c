#include <glob.h>
#include <stdio.h>
#include <unistd.h>
//ls -l *.c ../*.c
int main(){
    glob_t globbuf;

    glob("*.c", GLOB_TILDE, NULL, &globbuf);
    int i = 0;
    for(i = 0; i< globbuf.gl_pathc; i++){
        printf("%s\n", globbuf.gl_pathv[i]);
    }
    return 0;
}
#define _GNU_SOURCE

#include "dbg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glob.h>

#define MAX_SIZE 1024

int parse_args(int* use_or, int *argc, char **argv[])
{
    (*argc)--;
    (*argv)++;
    if(!strcmp((*argv)[0],"-o"))
    {
        (*argc)--;
        (*argv)++;
        check(*argc > 0, "USAGE: logfind [-o] word");
        *use_or = 1;
    } 
    return 0;

error:
    return -1;
}

int list_file(glob_t *pglob)
{
    FILE *file = fopen(".logfind","r");
    check(file, "Could not open file.");
    char *line = calloc(MAX_SIZE,sizeof(char));
    check_mem(line);
    int glob_flag = GLOB_PERIOD;
    int rc = -1;
    
    while(fgets(line,MAX_SIZE-1,file)!=NULL){
        line[strlen(line)-1] = '\0';
        rc = glob(line,glob_flag,NULL,pglob); // rc = glob()을 안하면 glob함수가 정상적으로 작동을 안함? 왜그러는지는 모르겠음
        check(rc ==0 || rc == GLOB_NOMATCH, "Failed to glob");
        //printf(" %ld\n",pglob->gl_pathc);
        if(glob_flag == GLOB_PERIOD) glob_flag |= GLOB_APPEND;
    }
    rc = 0;
    return rc;

error:
    if(file) fclose(file);
    if(line) free(line);
    return -1;
}
int found_it(int use_or, int found_count,int search_len){
    if(use_or && found_count > 0){ // or가 있고 하나 이상 찾아야 됨 -> and
        return 1; 
    } else if(!use_or && found_count == search_len){ //or 가 없고 검색된 수와 발견된 수가 같아야함 -> and
        return 1;
    } else {
        return 0;
    }
}

int scan_file(int use_or, const char *filename,int search_len, char *search_for[])
{
    FILE *file = fopen(filename, "r");
    check(file, "Could not open %s.",filename);
    char *line = calloc(MAX_SIZE,sizeof(char));
    check_mem(line);
    int i = 0;
    int line_count = 1;
    int found_count = 0;

    while(fgets(line,MAX_SIZE-1,file)!=NULL){
        //printf("line: %s\n",line);
        for(i = 0; i < search_len; i++){
            if(strcasestr(line, search_for[i])){
                found_count++;
                //printf("File: %s, line[%d]: %s, Search: %s",filename, line_count, line, search_for[i]);  
            }
        }

        if(found_it(use_or, found_count, search_len)){
            printf("File: %s, line[%d]: %s",filename, line_count, line); 
            break;            
        } else {
        found_count = 0;
        }
        line_count++;
    }

    fclose(file);
    return 0;
error:
    if(file) fclose(file);
    if(line) free(line);
    return -1;
}


int main(int argc, char *argv[])
{
    int i = 0;
    int use_or = 0;
    glob_t globbuf;
    check(argc > 2, "USAGE: logfind word word word");

    check(parse_args(&use_or,&argc,&argv)==0,"Failed parse_args");
    
    check(list_file(&globbuf)==0,"Failed list_file.");
    
    for(i = 0; i < globbuf.gl_pathc; i++){
        //printf("File: %s\n", globbuf.gl_pathv[i]);
        scan_file(use_or,globbuf.gl_pathv[i],argc,argv);
    }

    globfree(&globbuf);
    return 0;
error:
    return 1;
}
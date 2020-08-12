 
#include <stdio.h> 
#include <stdlib.h>
#include <dirent.h> 
#include <string.h>

int main(void) 
{ 
    struct dirent *de;
    int n=0;
    char ch;
    DIR *dr = opendir("."); 
  
    if (dr == NULL)
    { 
        printf("Could not open current directory" ); 
        exit(19);
    } 
    char files[10][240];  
    while ((de = readdir(dr)) != NULL)
    {
        char name_temp[240];
        if ((!strcmp(de->d_name, ".")) || (!strcmp(de->d_name, ".."))){
            continue;
        }
        strcpy(name_temp, de->d_name);
        for (int i = 0; i < sizeof(name_temp); i++)
        {
            if (name_temp[i]=='.')
            {  
                strcpy(files[n], name_temp);
                n++;
            }
        }
    }
    closedir(dr); 
    for (int i = 0; i < n; i++)
    {
        printf("%d: %s\n", i+1, files[i]);
    }
    for (int i = 0; i < n; i++)
    {
        FILE *fp=fopen(files[i], "r");
        char *temp;
        if(!(temp=(char*)malloc(sizeof(char)*sizeof(files[i])))){
            perror(NULL);
            system("pause");
            exit(5);
        }  
        strcpy(temp, files[i]);
        strcpy(files[i], "C:/Users/Dimitar Belemezov/Desktop/paste/copy_");
        strncat(files[i], temp, sizeof(temp)*10);
        FILE *fp_d=fopen(files[i], "ab");
        if(fp==NULL || fp_d==NULL)
        {
            printf("Problem with files! round %d", i);
            exit(3);
        }
        while( ( ch = fgetc(fp) ) != EOF )
        {
            fputc(ch, fp_d);
        }
        fclose(fp);
        fclose(fp_d);
        free(temp);
    }
    system("pause");
    return 0; 
} 



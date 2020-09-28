#include<bits/stdc++.h>
#include<ctype.h>
#include <string.h>
using namespace std;

void intermediate()
{
    FILE *fp1, *fp2;
    char c;
    char *input = "input.txt";
    char *output = "intermediate.txt";
    int line_no=1;

    fp1 = fopen(input, "r");
    fp2 = fopen(output, "w");

    printf("%d:",line_no);
    fprintf(fp2,"%d:",line_no);

    if(!fp1)printf("File can't be found");
    else
    {
        while((c = fgetc(fp1)) != EOF)
        {
            printf("%c", c);
            fputc(c, fp2);

            if(c == '\n')
            {
                line_no++;
                printf("%d:",line_no);
                fprintf(fp2,"%d:",line_no);
            }
        }
    }

    fclose(fp1);
    fclose(fp2);

    printf("\n\n\n");
}

void comment_remove()
{
    FILE *p1,*p2;
    char c;

    char *input = "intermediate.txt";
    char *output1 = "cmnt_output1.txt";
    char *output2 = "cmnt_output2.txt";
    char *output3 = "cmnt_output3.txt";



    p1 = fopen(input, "r");
    p2 = fopen(output1,"w");
    if(!p1)
        printf("\nFile can't be opened!");
    else
    {
        while((c = fgetc(p1)) != EOF)
        {
            if (c == '/')
            {
                c = fgetc(p1);
                if(c == '/')
                    while(c!='\n')
                        c = fgetc(p1);
                else
                {
                    fputc('/', p2);
                    fputc(c, p2);
                }
            }
            else fputc(c, p2);
        }
    }
    fclose(p1);
    fclose(p2);


    p1 = fopen(output1, "r");
    p2 = fopen(output2,"w");
    if(!p1)
        printf("\nFile can't be opened!");
    else
    {
        while((c = fgetc(p1)) != EOF)
        {
            if (c == '/')
            {
                c = fgetc(p1);
                if(c == '*')
                {
                    do{
                        c = fgetc(p1);
                    }while(c != '*');
                    c = fgetc(p1);
                }
                else fputc(c, p2);
            }
            else fputc(c, p2);
        }
    }
    fclose(p1);
    fclose(p2);


    p1 = fopen(output2, "r");
    p2 = fopen(output3,"w");
    if(!p1)
        printf("\nFile can't be opened!");
    else
    {
        while((c = fgetc(p1)) != EOF)
        {
            if (c == ' ')
            {
                while(c == ' ')
                    c = fgetc(p1);
                fputc(' ', p2);
                fputc(c, p2);
            }
            else fputc(c, p2);
        }
    }
    fclose(p1);
    fclose(p2);

    p1 = fopen(output3,"r");
    while((c=fgetc(p1))!=EOF)
        printf("%c",c);
    fclose(p1);

    printf("\n\n");

}
int isKey(char lex[20]){
    char a[100][100]= {"int","float","void","char","long","if","else","double"};
    for(int i=0; i<8; i++){
        if(strcmp(lex,a[i])==0){
            return 1;
        }
    }
    return 0;
}


int main(void){
    intermediate();
    comment_remove();

    FILE *p1,*p2,*p3;
    char c,d;

    p1 = fopen("input.txt","r");
    p2 = fopen("output1.txt","w");

    int flagForNewIden = 0;
    int line = 1;
    int  bracketCounterStart = 0, bracketCounterEnd = 0;
    if(!p1) printf("\nFile can't be opened!");
    else
    {
        while((c = fgetc(p1)) != EOF)
        {
            if(c=='\n')
                line++;

            if(c=='{')
                bracketCounterStart++;
            if(c=='}'){
                bracketCounterEnd++;
                if(bracketCounterStart < bracketCounterEnd)
                cout <<"Misplaced '}' at line " << line << endl;
            }

        }
    }

    fclose(p1);
    fclose(p2);

    p1 = fopen("input.txt","r");
    p2 = fopen("output2.txt","w");
    int semiBalance = 0;
    char chk[100],chk2[100];
    int  j=0;
    int ln=1;
    while((c=fgetc(p1))!=EOF)
    {
        chk[j]=c;
        j++;
        if(c=='\n')
            {ln++;

             chk[--j]=NULL;

            if(strcmp(chk,chk2)==0)
                printf("Duplicate token at line %d\n",ln);
            strcpy (chk2,chk);
            j=0;
            }
        if(c==' ')
        {

            chk[--j]=NULL;

            if(strcmp(chk,chk2)==0 )
                printf("Duplicate token %s at line %d\n",chk,ln);
            if(isKey(chk) && isKey(chk2) )
                printf("Duplicate token %s at line %d\n",chk,ln);
            strcpy (chk2,chk);
            j=0;
        }



    }

    fclose(p1);
    fclose(p2);

    p1 = fopen("input.txt","r");
    p2 = fopen("output3.txt","w");


    j=0;
    ln=1;
    int ifBalance=0;
    while((c=fgetc(p1))!=EOF)
    {
        chk[j]=c;
        j++;
        if(c=='\n')
            {ln++;

            }
        if(c==' ')
        {

            chk[--j]=NULL;

            if(strcmp(chk,"if")==0) ifBalance=1;
            else if(strcmp(chk,"else")==0) ifBalance--;
            if(ifBalance<0){
                printf("Unmatched %s at line %d\n",chk,ln);
                ifBalance=0;
            }

            strcpy (chk2,chk);
            j=0;
        }
    }

    fclose(p1);
    fclose(p2);


    ///If else balance checker :
    p1 = fopen("input.txt","r");
    p2 = fopen("output4.txt","w");

    ln=1;
    int ifBalance1 = 0;

    while((c=fgetc(p1))!=EOF)
    {
        chk[j]=c;
        if(c=='\n')
            ln++;
        j++;
        if(c==' ')
        {
            chk[--j]=NULL;
            if(strcmp(chk,"if")==0)
            {
                ifBalance1=1;

            }
            else if(strcmp(chk,"else")==0)
            {
                ifBalance1--;
            }

            //else if(strcmp(chk, isKey())==0) ifBalance1--;

            if(ifBalance <0)
            {
                printf("Extra ELSE detected at line %d\n",ln);
                ifBalance1=0;
            }
            strcpy (chk2,chk);
            j=0;
        }


    }
    fclose(p1);
    fclose(p2);


    return 0;
}

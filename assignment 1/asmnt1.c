#include <stdio.h>
int main()
{
    FILE *p1,*p2;
    char c;

    char *input = "input1_160104025.c";
    char *output1 = "output1.txt";
    char *output2 = "output2.txt";
    char *output3 = "output3.txt";
    char *output4 = "output4.txt";


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


    p1 = fopen(output3, "r");
    p2 = fopen(output4,"w");
    if(!p1) printf("\nFile can't be opened!");
    else
    {
        while((c = fgetc(p1)) != EOF)
        {
            int line=0;
            if (c == '\n')
                //fputc(' ', p2);
                continue;
            else
                fputc(c, p2);

        }
    }
    fclose(p1);
    fclose(p2);


    printf("Input for the program : \n");
    p1 = fopen(input,"r");
    while((c=fgetc(p1))!=EOF) printf("%c",c);
    fclose(p1);

    printf("\n");


    printf("Output of the input file :\n");
    p1 = fopen(output4,"r");
    while((c=fgetc(p1))!=EOF)
        printf("%c",c);
    fclose(p1);

    printf("\n");

    return 0;
}

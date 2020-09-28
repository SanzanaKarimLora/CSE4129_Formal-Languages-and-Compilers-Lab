#include<stdio.h>
#include<string.h>
#include<bits/stdc++.h>


void A(void);
void X(void);
char str[100];
int f=0;
int i=0;
int l;

int main(void)
{

    printf("\nGiven CFGs:\n");
    printf("\n\A -> aXd");
    printf("\nX -> bbX");
    printf("\nX-> bcX");
    printf("\nEnter a string : ");
    scanf("%s", str);

    l = strlen(str);
    if (l>=1)  A();

    else
        printf("\nString is not accepted\n");

    if (l == i && f )
        printf("\nString is accepted\n");
    else
        printf("\nString is not accepted\n");

    return 0;
}

void A()
{
    if(str[i]=='a')
    {
        i++;

        X();
     if(f==1)
     {
         if(str[i]=='d')
        {
            i++;
            f=1;
            return ;
        }
        else
        {
            f=0;
            return;
        }
     }


    }
}

/*void X() {
	if (str[i] == 'b' || (str[i+1]=='b' ||str[i+1]=='c')) {
		i++;
		f=1;
	}
	else {f=0; return;}
    if (i<l-1) X();
}*/

void X()
{
    if(str[i]=='b')
    {
        i++;
        if(str[i]=='b' ||str[i]=='c')
        {
            i++;
            f=1;
            if(i<l-1)X();
        }
        else
        {
            f=0;
            return;
        }
    }
    else
    {
        f=0;
        return ;
    }


}


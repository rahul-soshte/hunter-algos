#include<stdio.h>
#define SIZE 50 /*SIZE OF STACK*/ 
#include<ctype.h>
char s[SIZE];
int top=-1;//Global Declarations

void push(char elem)
{
    s[++top]=elem; //PUSH operation

}
char pop()
{
    return (s[top--]); //POP operation

}

int pr(char elem)
{
    switch(elem){
        case '#':return 0;
        case '(':return 1;
        case '+':
        case '-':return 2;
        case '*':
        case '/':return 3;


    }
}
void main()
{
    char infx[50],pofx[50],ch,elem;
    int i=0,k=0;
    printf("\n\nRead the infix Expression ? ");
    scanf("%s",infx);
    push('#');
    while((ch=infx[i++]) != '\0')
{
    if(ch=='(') push(ch);
    else
        if(isalnum(ch)) pofx[k++]=ch;
    else if (ch==')')
    {
        while(s[top]!='(')
            pofx[k++]=pop();
        elem=pop();

    }
    else{
        //OPERATOR
        while(pr(s[top])>=pr(ch))
            pofx[k++]=pop();
        push(ch);

    }

}
while(s[top]!='#')
pofx[k++]=pop();//POP FROM STACK TILL EMPTY
pofx[k]='\0';
printf("\n\nGiven Infix Expression:%s Postfix Expression:%s \n",infx,pofx);
}
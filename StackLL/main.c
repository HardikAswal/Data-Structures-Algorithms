#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top=NULL;

void push(int x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));

    if(t==NULL)
        printf("Stack is full.\n");
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}

int pop()
{
    struct Node *t;
    int x=-1;
    if(top==NULL)
        printf("Stack is empty.\n");
    else
    {
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

void Display()
{
    struct Node *p;
    p=top;

    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int isBalanced(char *exp)
{
    int i;
    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            push(exp[i]);

        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
        {
            if(top==NULL)
                return 0;
            else if(top->data=='(' && exp[i]==')')
                pop();
            else if(top->data=='{' && exp[i]=='}')
                pop();
            else if(top->data=='[' && exp[i]==']')
                pop();
        }
    }
    if(top==NULL)
        return 1;
    else
        return 0;
}

int pre(char x)
{
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 2;
    else
        return 0;
}

int isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/' || x=='^' || x=='(' || x==')')
        return 0;
    return 1;
}

char* inToPost(char *infix)
{
    char *postfix;
    int len=strlen(infix);
    postfix=(char *)malloc((len+1)*sizeof(char));
    int i=0,j=0;

    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
        {
            postfix[j++]=infix[i++];
        }
        else
        {
            if(top==NULL || (pre(infix[i])>pre(top->data)))
                push(infix[i++]);
            else
            {
                postfix[j++]=pop();
            }
        }
    }

    while(top!=NULL)
        postfix[j++]=pop();
    postfix[j]='\0';

    return postfix;
}

int outPre(char x)
{
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 3;
    else if(x=='^')
        return 6;
    else if (x=='(')
        return 7;
    else if (x==')')
        return 0;
}

int inPre(char x)
{
    if(x=='+' || x=='-')
        return 2;
    else if(x=='*' || x=='/')
        return 4;
    else if(x=='^')
        return 5;
    else if (x=='(')
        return 0;
    else if (x==')')
        return -1;
}

char* inToPost2(char *infix)
{
    int len=strlen(infix);
    char *postfix=(char *)malloc((len+1)*sizeof(char));
    int i=0,j=0;

    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
        {
            postfix[j++]=infix[i++];
        }
        else
        {
            if(infix[i]=='(') //BASE CODE
                push(infix[i++]);

            else if(infix[i]==')')
            {
               while(top!=NULL && top->data!='(')
                    postfix[j++]= pop();
               if(top!=NULL && top->data!='(')
                    return -1; //Invalid Expression
               else{
                    pop();
                    i++;
               }
            }

            else if(top==NULL || (outPre(infix[i])>inPre(top->data)))
            {
                push(infix[i++]);
            }
        }
    }
    while(top!=NULL)
        postfix[j++]=pop();
    postfix[j]='\0';
     return postfix;
}

int Eval(char *postfix)
{
    int i,x1,x2,res;

    for(i=0;postfix[i]!='\0';i++)
    {
        if(isOperand(postfix[i]))
            push(postfix[i]-'0');
        else
        {
            x2=pop();
            x1=pop();

            switch(postfix[i])
            {
                case '+': res=x1+x2; break;
                case '-': res=x1-x2; break;
                case '*': res=x1*x2; break;
                case '/': res=x1/x2; break;
            }
            push(res);
        }
    }
    return top->data;
}

int main()
{
    char *postfix = "234*+82/-";
    printf("Result is %d",Eval(postfix));
    return 0;
}

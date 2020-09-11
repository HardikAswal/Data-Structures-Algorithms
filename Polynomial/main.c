#include <stdio.h>
#include <stdlib.h>

struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    struct Term *terms;
};

void Create(struct Poly *p)
{
    int i;
    printf("Enter number of terms: \n");
    scanf("%d",&p->n);
    p->terms=(struct Term *)malloc(p->n*sizeof(struct Term));

    printf("Enter terms:\n");

    for(i=0;i<p->n;i++)
    {
        scanf("%d%d",&p->terms[i].coeff,&p->terms[i].exp);
    }
}

void Display(struct Poly p)
{
    int i;
    for(i=0;i<p.n;i++)
        printf("%dx%d+",p.terms[i].coeff,p.terms[i].exp);
    printf("\n");
}

struct Poly *Add(struct Poly *p1,struct Poly *p2)
{
    int i=0,j=0,k=0;
    struct Poly *sum;
    sum=(struct Poly *)malloc(sizeof(struct Poly));
    sum->terms=(struct Term *)malloc(p1->n+p2->n*sizeof(struct Term));

    while(i<p1->n && j<p2->n)
    {
        if(p1->terms[i].exp >p2->terms[j].exp)
            sum->terms[k++]=p1->terms[i++];
        else if(p1->terms[i].exp<p2->terms[j].exp)
            sum->terms[k++]=p2->terms[j++];
        else{
            sum->terms[k]=p1->terms[i];
            sum->terms[k++].coeff=p1->terms[i++].coeff+p2->terms[j++].coeff;
        }
    }
    for(;i<p1->n;i++)
        sum->terms[k++]=p1->terms[i];
    for(;j<p2->n;j++)
        sum->terms[k++]=p2->terms[j];
    sum->n=k;
    return sum;

};

int main()
{
    struct Poly p1,p2,*p3;
    Create(&p1);
    Create(&p2);

    p3=Add(&p1,&p2);

    printf("\n");
    Display(p1);
    printf("\n");
    Display(p2);
    printf("\n");
    Display(*p3);
    return 0;
}

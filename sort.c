#include "stdio.h"
#define u8 unsigned char

#define LESS(a,b) ((a)<(b))
#define EXCH(d,i,j,ty) {ty c;c=d[i];d[i]=d[j];d[j]=c;}
#define LEN(d,ty) (sizeof(d)/sizeof(ty))

//like playing poker
void ins_sort(u8 *d,u8 l)
{
	u8 i,j;
	for(i=0;i<l;i++)
	{
		for(j=i;(j>0)&&LESS(d[j],d[j-1]);j--)
		{
			EXCH(d,j,j-1,u8);
		}
	}
}

void shell_sort(u8 *d,u8 l)
{
	u8 i,j,h;
	h=l;
	while(h>1)
	{
		h=h/3+1;
		for(i=h;i<l;i++)
		{
			for(j=i;(j>=h)&&LESS(d[j],d[j-h]);j-=h)
			{
				EXCH(d,j,j-h,u8);
			}
		}
	}
}

u8 part(u8 *d,u8 lo,u8 hi)
{
	u8 i,j,v;
	i=lo;
	j=hi+1;
	v=d[lo];
	while(1)
	{
		while(LESS(d[++i],v)) if(i==hi) break;//find item bigger than v in left
		while(LESS(v,d[--j])) if(j==lo) break;//find item less than v in right
		if(i>=j) break;
		EXCH(d,i,j,u8);
	}
	EXCH(d,lo,j,u8);
	return j;
}

void q_sort(u8 *d,u8 lo,u8 hi)
{
	u8 j;
	if(hi <= lo) return;
	j=part(d,lo,hi);
	q_sort(d,lo,j-1);
	q_sort(d,j+1,hi);
}

void _pri(u8 *d,u8 l)
{
	u8 i;
	for(i=0;i<l;i++)
	{
		printf("%x ",d[i]);
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	u8 d[]={2,3,5,1,5,7,2,4,8,9,1,2,3};
	//ins_sort(d,LEN(d,u8));
	//shell_sort(d,LEN(d,u8));
	q_sort(d,0,LEN(d,u8)-1);
	_pri(d,LEN(d,u8));
	return 0;
}
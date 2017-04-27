#include "stdio.h"
#define u8 unsigned char

#define LEN(d,ty) (sizeof(d)/sizeof(ty))

u8 binary_search(u8 *d,u8 l,u8 t,u8 *o)
{
	u8 lo,mid,hi;
	lo=0;
	hi=l-1;
	while(lo <= hi)
	{
		mid=(lo+hi)/2;
		if(d[mid]==t)
		{
			*o=mid;
			return 1;
		}
		if(d[mid]<t)
		{
			lo=mid+1;
		}
		else
		{
			hi=mid-1;
		}
	}
	return 0;
}

typedef struct
{
	u8 visited;
};

u8 dfs(u8)

int main(int argc, char const *argv[])
{
	u8 d[]={1,3},o;
	if(binary_search(d,LEN(d,u8),3,&o))
	{
		printf("find:%d\n",o);
	}
	else
	{
		printf("not find\n");
	}
	return 0;
}
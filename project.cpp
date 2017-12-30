
// 1 大数的加法

/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//给短的字符串增加长度 让两个字符串相等
char *new_str(char *str,int longdate,int shortdate)
{         
	int j=longdate-shortdate;  
	char *newstr=(char *)malloc(shortdate+j);
	//追加的部分补为'0'
	char ch='0';
	strset(newstr,ch);
	strncpy(newstr,str,shortdate);
	return newstr;
}
 //对两个字符串进行相加
char *add_date(char *sum,char *str1,char *str2,int longdate)
{
	int i;
	int acc=0;
	for(i=0;i<longdate;i++)
	{
		sum[i]=(str1[i]-'0')+(str2[i]-'0')+acc+'0';
		acc=0;
		if(sum[i]>'9')
		{
			sum[i]=(sum[i]-'0'-10)+'0';
			acc=1;
			sum[i+1]=acc+'0';
		}
	}
	return sum;
}
char *add(char *str1,char *str2)
{
	assert(NULL!=str1&&NULL!=str2);
	int len1=strlen(str1);
	int len2=strlen(str2);
	int len=(len1>len2)? len1+2:len2+2;
	char *ret=(char *)calloc(len,sizeof(char));
	int acc=0;
	int i;
	if(len1==len2)
	{
      return  ret=add_date(ret,str1,str2,len1);
	}
	
	else if(len1>len2)
	{   
        char *newstr=new_str(str2,len1,len2);
		return  ret=add_date(ret,str1,newstr,len1);
	}                
	
	else if(len1<len2)
	{      
		char *newstr=new_str(str1,len2,len1);
		return  ret=add_date(ret,str2,newstr,len2);
	}
}
void main()
{
	char str1[]="1";
	char str2[]="99";
	char *sum=NULL;
	printf("%s + %s=\n",str1,str2);
	strrev(str1);
	strrev(str2);
	sum=add(str1,str2);
	strrev(sum);
	printf("%s\n",sum);
}
*/


//  2 大数减法
/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
 //分配空间
char *new_str(char *str,int longdate,int shortdate)
{
		int j=longdate-shortdate;  //1
		//为短的字符串追加空间
		char *newstr=(char *)malloc(shortdate+j);
		//追加的部分补为'0'
		char ch='0';
		strset(newstr,ch);
		strncpy(newstr,str,shortdate);
		return newstr;
}
 //相减函数  (str1-str2) len(str1)<len(str2)的情况 
char *subdate2(char *sub,char *str1,char *str2,char len)
{
	int i;
	for(i=0;i<len;i++)
	{
		sub[i]=(str2[i]-'0')-(str1[i]-'0')+'0';
		if(sub[i]<'0')
		{
			sub[i]=((str2[i]-'0'+10)-(str1[i]-'0'))+'0';
			str1[i+1]=(str1[i+1]-'0'-1)+'0';
		}
	}
		sub[i]='-';
		return sub;
}
//相减函数   (str1-str2) len(str1)>=len(str2)的情况
char *subdate(char *sub,char *str1,char *str2,int len1)
{
	int i;
	for(i=0;i<len1;i++)
	{
		sub[i]=(str1[i]-'0')-(str2[i]-'0')+'0';
		if(sub[i]<'0')
		{	
			sub[i]=((str1[i]-'0'+10)-(str2[i]-'0'))+'0';
			str1[i+1]=(str1[i+1]-'0'-1)+'0';
		}
	}
	return sub;
}
char *subtract(char *str1,char *str2)
{
	assert(NULL!=str1&&NULL!=str2);
	int len1=strlen(str1);
	int len2=strlen(str2);
	int len=(len1>len2)? len1+2:len2+2;
	char *ret=(char *)calloc(len,sizeof(char));
	
	if(len1==len2)
	{
		//若减数小于被减数 那么就是被减数减去减数的值取负即可
		if(str2[len1-1]>str1[len1-1])
		{
			return ret=subdate2(ret,str1,str2,len1);
		}
		else  //若减数大于被减数  直接减即可
			return ret=subdate(ret,str1,str2,len1);
	}
	
	else if(len1>len2)
	{
	    char *newstr=new_str(str2,len1,len2);
	    return ret=subdate(ret,str1,newstr,len1);
	}
	
	else if(len1<len2)
	{		
	    char *newstr=new_str(str1,len2,len1);
		return ret=subdate2(ret,newstr,str2,len2);
	}
}
void main()
{
	char str1[]="0";
	char str2[]="99";
	char *sub=NULL;
	printf("%s - %s=\n",str1,str2);
	strrev(str1);
	strrev(str2);
	sub=subtract(str1,str2);
	strrev(sub);
	printf("%s\n",sub);
}*/




//大数的乘法
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//相加函数 //相加也要根据不同的情况相加       
void add(char *str1,char *str2, char *ret)  
{  
	assert(str1!=NULL&&str2!=NULL);
    strrev(str1);  
    strrev(str2);
    int i = 0;  
    int tmp, acc = 0;  
    while (str1[i] != 0 && str2[i]!= 0)  
    {  
        tmp = str1[i] - '0' + str2[i] - '0'; //把两字符变成整型相加的值放入临时变量tmp中 
        if (tmp > 9)  //判断tmp是否会产生进位  若有进位进入if循环处理进位
        {  
            tmp = tmp - 10;   //若产生进位则-10 把acc设置为1 不过要在判断当前是否有进位后 再为下一次设置是否有进位
            ret[i] = tmp + '0'; //把处理过进位的tmp放入ret中  
            if (acc)  //判断当前是否有进位 若有进位则当前+1
			{
				ret[i]++; 
			}
            acc = 1;  //有进位把acc设置为1(这是判断当前相加后且有进位的情况下为下次设置的进位)
        }  
        else   //相加后没有进位的情况
        {  
            ret[i] = tmp + '0';    
            if (acc)   //判断上次相加是否产生了进位 若有则这次值+1  
			{
				ret[i]++;
			}
            acc = 0;  //次时的acc是这次相加值没有产生进位的情况  所以我们把acc设置为0
        }  
        i++;  
    }  
  
    if (str2[i] == 0 && str1[i]!=0)  
    {  
        ret[i] = str1[i];  
        if (acc) 
		{
			ret[i]++;
		}
        i++;  
        while (str1[i] != 0)  
        {  
            ret[i] = str1[i];  
            i++;  
        } 
    }  
    else if (str1[i] == 0 && str2[i]!=0)  
    {  
        ret[i] = str2[i];  
        if (acc)
		{
			ret[i]++;
		}
        i++;  
        while (str2[i] != 0)  
        {  
            ret[i] = str2[i];  
            i++;  
        }  
    }  
    else if (str1[i] ==0 && str2[i]==0 && acc)  
    {  
        ret[i] = 1;  
        i++;  
    }  
  
    while (ret[i-1] == 0 &&i>1)
	{
		i--;
	}
    ret[i] = 0;  
    strrev(str1);  
    strrev(str2);  
    if(str1!=ret)
	{
		strrev(ret);
	}
}  
 /*相乘函数*/ 
void multiply(char *str1, char *str2, char *ret)  
{  
	assert(str1!=NULL&&str2!=NULL||ret==NULL); //判断字符串是否符合
    int i,j,k,acc;  
    char temp[161]; //定义一个临时字符数组 保存每一轮的乘积  
    int tmp;  
  
    strrev(str1);  
    strrev(str2);  
    i = 0;  
    acc = 0;  
    while (str2[i] != '\0')  
    {  
        for (j = 0; j < strlen(str1); j++)//相乘的方式是 多*1   
        {  
            tmp = (str1[j] - '0')*(str2[i] - '0');  //临时变量保存每个字符转换成整型的乘积
            temp[j] = '0' + tmp % 10;   //临时量%10的值放入临时数组中 
            temp[j] =(temp[j]-'0')+ acc+'0';  //加进位 
            acc = 0;  //让进位回到初始状态 
            while (tmp > 9)  //这条while语句作用是叠加进位 （计算有多大的进位） 
            {  
                tmp -= 10; //tmp每次-10 进位+1 直到tmp<10为止 
                acc++;  
            }  
        }     
        if (acc)    //这条if语句的作用是判断最后一次相乘是否有进位 若有把最后一次进位加到temp[j+1]上
		{
			temp[j++] = '0' + acc;  
		}
        acc = 0;  //让进位回到初始状态 
        temp[j] = '\0';  
        strrev(temp);  
        for (k = 0; k < i; k++)
		{
			temp[j+k] = '0'; 
		}
        temp[j+k] = '\0';  
  
        add(ret, temp, ret);//这里第一个ret表示的是temp前一轮的乘积数组第二个ret表示前一轮乘积和temp相加和的数组 累加思想
        i++;  
    }  
    strrev(str1);  
    strrev(str2);  
}  
  
void main()  
{  
	char str1[]="123568";
	char str2[]="456789";
	printf("%s * %s=\n",str1,str2);
	int len1=strlen(str1);
	int len2=strlen(str2);
	int len=(len1>=len2)? len1*2:len2*2;  //计算保存乘积的字符串的长度
	char *ret=(char *)calloc(len,sizeof(char)); //为保存乘积的字符串开辟空间
    multiply(str1,str2,ret);  
    printf("%s\n",ret); 
}





// 1 �����ļӷ�

/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//���̵��ַ������ӳ��� �������ַ������
char *new_str(char *str,int longdate,int shortdate)
{         
	int j=longdate-shortdate;  
	char *newstr=(char *)malloc(shortdate+j);
	//׷�ӵĲ��ֲ�Ϊ'0'
	char ch='0';
	strset(newstr,ch);
	strncpy(newstr,str,shortdate);
	return newstr;
}
 //�������ַ����������
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


//  2 ��������
/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
 //����ռ�
char *new_str(char *str,int longdate,int shortdate)
{
		int j=longdate-shortdate;  //1
		//Ϊ�̵��ַ���׷�ӿռ�
		char *newstr=(char *)malloc(shortdate+j);
		//׷�ӵĲ��ֲ�Ϊ'0'
		char ch='0';
		strset(newstr,ch);
		strncpy(newstr,str,shortdate);
		return newstr;
}
 //�������  (str1-str2) len(str1)<len(str2)����� 
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
//�������   (str1-str2) len(str1)>=len(str2)�����
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
		//������С�ڱ����� ��ô���Ǳ�������ȥ������ֵȡ������
		if(str2[len1-1]>str1[len1-1])
		{
			return ret=subdate2(ret,str1,str2,len1);
		}
		else  //���������ڱ�����  ֱ�Ӽ�����
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




//�����ĳ˷�
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//��Ӻ��� //���ҲҪ���ݲ�ͬ��������       
void add(char *str1,char *str2, char *ret)  
{  
	assert(str1!=NULL&&str2!=NULL);
    strrev(str1);  
    strrev(str2);
    int i = 0;  
    int tmp, acc = 0;  
    while (str1[i] != 0 && str2[i]!= 0)  
    {  
        tmp = str1[i] - '0' + str2[i] - '0'; //�����ַ����������ӵ�ֵ������ʱ����tmp�� 
        if (tmp > 9)  //�ж�tmp�Ƿ�������λ  ���н�λ����ifѭ�������λ
        {  
            tmp = tmp - 10;   //��������λ��-10 ��acc����Ϊ1 ����Ҫ���жϵ�ǰ�Ƿ��н�λ�� ��Ϊ��һ�������Ƿ��н�λ
            ret[i] = tmp + '0'; //�Ѵ������λ��tmp����ret��  
            if (acc)  //�жϵ�ǰ�Ƿ��н�λ ���н�λ��ǰ+1
			{
				ret[i]++; 
			}
            acc = 1;  //�н�λ��acc����Ϊ1(�����жϵ�ǰ��Ӻ����н�λ�������Ϊ�´����õĽ�λ)
        }  
        else   //��Ӻ�û�н�λ�����
        {  
            ret[i] = tmp + '0';    
            if (acc)   //�ж��ϴ�����Ƿ�����˽�λ ���������ֵ+1  
			{
				ret[i]++;
			}
            acc = 0;  //��ʱ��acc��������ֵû�в�����λ�����  �������ǰ�acc����Ϊ0
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
 /*��˺���*/ 
void multiply(char *str1, char *str2, char *ret)  
{  
	assert(str1!=NULL&&str2!=NULL||ret==NULL); //�ж��ַ����Ƿ����
    int i,j,k,acc;  
    char temp[161]; //����һ����ʱ�ַ����� ����ÿһ�ֵĳ˻�  
    int tmp;  
  
    strrev(str1);  
    strrev(str2);  
    i = 0;  
    acc = 0;  
    while (str2[i] != '\0')  
    {  
        for (j = 0; j < strlen(str1); j++)//��˵ķ�ʽ�� ��*1   
        {  
            tmp = (str1[j] - '0')*(str2[i] - '0');  //��ʱ��������ÿ���ַ�ת�������͵ĳ˻�
            temp[j] = '0' + tmp % 10;   //��ʱ��%10��ֵ������ʱ������ 
            temp[j] =(temp[j]-'0')+ acc+'0';  //�ӽ�λ 
            acc = 0;  //�ý�λ�ص���ʼ״̬ 
            while (tmp > 9)  //����while��������ǵ��ӽ�λ �������ж��Ľ�λ�� 
            {  
                tmp -= 10; //tmpÿ��-10 ��λ+1 ֱ��tmp<10Ϊֹ 
                acc++;  
            }  
        }     
        if (acc)    //����if�����������ж����һ������Ƿ��н�λ ���а����һ�ν�λ�ӵ�temp[j+1]��
		{
			temp[j++] = '0' + acc;  
		}
        acc = 0;  //�ý�λ�ص���ʼ״̬ 
        temp[j] = '\0';  
        strrev(temp);  
        for (k = 0; k < i; k++)
		{
			temp[j+k] = '0'; 
		}
        temp[j+k] = '\0';  
  
        add(ret, temp, ret);//�����һ��ret��ʾ����tempǰһ�ֵĳ˻�����ڶ���ret��ʾǰһ�ֳ˻���temp��Ӻ͵����� �ۼ�˼��
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
	int len=(len1>=len2)? len1*2:len2*2;  //���㱣��˻����ַ����ĳ���
	char *ret=(char *)calloc(len,sizeof(char)); //Ϊ����˻����ַ������ٿռ�
    multiply(str1,str2,ret);  
    printf("%s\n",ret); 
}




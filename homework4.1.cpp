#include<iostream>  
#include<cstring> 
#include<fstream> 
using namespace std;

struct WORD{                           //创建一个结构体
    int count;
    char s;
    void exchange(Word &word)  //交换单词
    {
        string tStr=word.Str;
        int tCount=word.Count;
        word.Str=Str;
        word.Count=Count;
        Str=tStr;
        Count=tCount;
    }
}w[100];
bool isword(char a[] ) //判断是否是一个单词
{
	int i=0;
	for (i=0;a[i]!='\0';i++ )
		if ((a[i] >='a'&&a[i]<='z')||(a[i]>='0'&&a[i]<='9'))
			return(true);
		else
			return(false);
}

int judge(char b[], int n)                     //判断该单词是否出现过
{
    if (n>0)
        for (int i=0;i<n;i++)
        {
            if (!strcmp(b,&w[i].s))    //出现
            {
                w[i].count++;
                return(-1);
            }
        }
}


int main(void)
{
    char result[500];
    char *ptr;
	char p;
	int n;
    ifstream file("A_Tale_of_Two_Cities.txt"); //从文件中读取
    if (!file )
    {
        cout<<"不能打开文件";
    }
    while (!file.eof())
    {
        file.getline( result, 500 );
    }
    file.close();
    int j=0; //大写转小写
    while (result[j]!='/0'&&result[j+1]!='/0')
    {
        if (result[j] >='A'&& result[j]<='Z')
        {
            result[j] = result[j]-'A'+'a';
            j++;
        }
    }
    cout<<result;
    char *sep = " ";
    int i=0;
    ptr=strtok(result," ");            //利用strtok函数来分割result字符串中的单词
    while (ptr!= NULL)
    {
        if (isword(p)!=false)
        {
            if (judge(p,n) != false )
            {
                w[n].s=*p;    //赋值给数组
                n++;
            }
        }
        ptr = strtok( NULL, " " );
    }
    int t = 0;
    char y[10];
    cout<<"请输入需要统计的单词："; 
    cin>>y;                                        //输入需要统计的单词
    while (!strcmp(w[t].s,y))                     //查询比较所需统计的单词 
    {
        t++;
    }
    cout<< w[t].s << ":" <<w[t].count<<'\n';      //输出统计结果
    return(0);
}
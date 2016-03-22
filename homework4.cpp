#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct Num{
    int num;
    char *s;

void    exchange( Word &word )  /* 交换单词 */
    {
        string    tStr    = word.Str;
        int    tCount    = word.Count;
        word.Str    = Str;
        word.Count    = Count;
        Str        = tStr;
        Count        = tCount;
    }
}
Num word[999];

int Change(char str[999])//大写转小写
{
	int a = 0;
    while (str[a] != '\0')//当str字符串未结束时将大写字母转小写
    {
        if (str[a] >= 'A'&&str[a] <= 'Z')
            str[a] = str[a] + 32;//因为大写字母与小写字母的ascll码值相差32，大写转小写要加上32
        a++;
    }
	return 0;
}
int Judge(char w[])//判断是否符合题意的单词
{
     for (int e = 1; w[e] != '\0';)
    {
		 if(strlen(w)<4)//判断单词字长是否超过以及等于4
	   	return -1;
         if (w[e] >= 'a' && w[e] <= 'z')//判断单词的首字符是否是字母
	    return -1;
         if (!((w[e] >= 'a' && w[e] <= 'z') || (w[e] >= '0' && w[e] <= '9')))//判断单词中是否有非字母数字
            return -1;
        else
            e++;
	}
	 return 0;
}
int Fre(char f[],int total )   //统计单词出现过的频率
{
    if (total>0)
    for (int i = 0; i <total; i++)
    {
        if (!strcmp(f, word[i].s))  
        {
            word[i].num++;      
            return -1;
        }
    }
	return 0;
}
void SortWordDown( Word *words,int size )  //降序排序
{
    for (int i=0;i<size;i++)
    {
        for(int j=0; j<size-1;j++)
        {
            if (words[j].Count<words[j+1].Count)
            {
                words[j].exchange(words[j+1]);

            }
        }
    }
}
int main()
{   char sentence[999];
   ifstream file("A_Tale_of_Two_Cities.txt"); //从文件中读取
    while (!file.eof())
    {
        file.getline(result,500);
    }
    file.close();
   
    const char *delim = ",“”.' '‘’!?";  //delim是用来定义分隔符的内容
    char *p= strtok(sentence, delim);//strtok函数根据分隔符分隔字符串
	int n=0;
	int c=0;
    while (p)
    {
       Change(p);
		if (Judge(p) != -1)
        {
            if (Fre(p, n)!=-1)
            {
                word[n].s = p;
                n++;
            }
        }
        p = strtok(NULL, delim);
    }
     int t = 0;
    ofstream outfile;                       /* 输出文件到result1 */
    outfile.open( "Result1.txt" )
    SortWordDown( w, count );
    while (word[c].s)        //输出统计结果
    {
        cout << word[c].s<< "：" << word[c].num << '\n';
        c++;
    }
    return 0;
}
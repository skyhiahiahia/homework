#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct Num{
    int num;
    char *s;

void    exchange( Word &word )  /* �������� */
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

int Change(char str[999])//��дתСд
{
	int a = 0;
    while (str[a] != '\0')//��str�ַ���δ����ʱ����д��ĸתСд
    {
        if (str[a] >= 'A'&&str[a] <= 'Z')
            str[a] = str[a] + 32;//��Ϊ��д��ĸ��Сд��ĸ��ascll��ֵ���32����дתСдҪ����32
        a++;
    }
	return 0;
}
int Judge(char w[])//�ж��Ƿ��������ĵ���
{
     for (int e = 1; w[e] != '\0';)
    {
		 if(strlen(w)<4)//�жϵ����ֳ��Ƿ񳬹��Լ�����4
	   	return -1;
         if (w[e] >= 'a' && w[e] <= 'z')//�жϵ��ʵ����ַ��Ƿ�����ĸ
	    return -1;
         if (!((w[e] >= 'a' && w[e] <= 'z') || (w[e] >= '0' && w[e] <= '9')))//�жϵ������Ƿ��з���ĸ����
            return -1;
        else
            e++;
	}
	 return 0;
}
int Fre(char f[],int total )   //ͳ�Ƶ��ʳ��ֹ���Ƶ��
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
void SortWordDown( Word *words,int size )  //��������
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
   ifstream file("A_Tale_of_Two_Cities.txt"); //���ļ��ж�ȡ
    while (!file.eof())
    {
        file.getline(result,500);
    }
    file.close();
   
    const char *delim = ",����.' '����!?";  //delim����������ָ���������
    char *p= strtok(sentence, delim);//strtok�������ݷָ����ָ��ַ���
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
    ofstream outfile;                       /* ����ļ���result1 */
    outfile.open( "Result1.txt" )
    SortWordDown( w, count );
    while (word[c].s)        //���ͳ�ƽ��
    {
        cout << word[c].s<< "��" << word[c].num << '\n';
        c++;
    }
    return 0;
}
//���������inarray[] ��������ַ�����; inlen����ĳ���
//���������outarray[] �������ַ�����; outlen���������ĳ���


#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

#define LOWMASK 0x0f
#define HIGHMASK (1<<4)
#define CHARLEN 7
#define uint unsigned int 
#define uchar unsigned char 

// ���������inarray[] ��������ַ����飻inlen����ĳ���
// ���������outarray [] �������ַ����飻outlen���������ĳ���
// uchar outarray[]�������ַ������õ������λ������Чλ���Ƿ���λ
void CodeChar(const char inarray[], uint inlen, uchar outarray[], uint &outlen);

// ���������inarray������������飻inlen���������鳤�ȣ�outk�������ַ���ԭ�����е��±�λ��
// ���������outchar�������ֵ��inlen���������鳤��
void DecodeChar(const uchar inarray[], uint inlen, uint outk, char &outchar);

void main(void)   
{   
	char *in = "abcdefghijklmnuvw";
	uchar out[100] = {0};
	int outindex = 0;
	uint outcount;
	int incount = strlen(in);
	float coderatio = 0;//ѹ������
	char outchar;
	
	while(outindex < 100)
		out[outindex++] = 0;
	
	CodeChar(in, incount, out, outcount);
	out[incount] = (uchar)'/0'; // ����
	
	cout << "ѹ��ǰ�ֽ�:" << incount << endl << "ѹ��ǰ�ֽ�:" << outcount << endl;
	
	coderatio = (float)outcount/incount;
	printf("ѹ�����ʣ�%6f\n", coderatio);
	
	printf("ѹ����%s\n",out);
	
	outindex = 0; // ����
	while(outindex < incount)
	{
		DecodeChar(out, outcount, outindex, outchar);
		cout << outchar;//<<endl;
		outindex++;
	}
	cout << endl;
}


void CodeChar(const char inarray[], uint inlen, uchar outarray[], uint &outlen) 
{
	int InIndex = 0;
	int OutIndex = 0;
	int CompoudIndex = 0;
	int CompoudValue = 0;
	int tempchar = 0;

	while(inlen--)
	{
		tempchar = inarray[InIndex] - 'a'; //���ַ���������0��26

		if(InIndex%2 == 0)             
			 outarray[OutIndex] = ( tempchar & LOWMASK) << 4; //ż��λ�����ÿ���ַ��ĸ�λ
		else        
			 outarray[OutIndex] |=(tempchar & LOWMASK); // ����λ�����ÿ���ַ��ĵ�λ

		if((InIndex%2 == 1) && (InIndex != 0)) // ��������������������������±�
			 OutIndex++;

		// ��ÿ���ַ��ĵ���λ���������0��7�ֱ��Ӧ���ַ��ĵ�7����0λ
		CompoudValue |= ((tempchar & HIGHMASK) << 3) >> (InIndex%8);

		CompoudIndex++;
		if(CompoudIndex == sizeof(char) * 8)// ����˰˸����󣬽��ϳ�ֵ���浽�������
		{     
			CompoudIndex = 0;
			outarray[OutIndex] = CompoudValue;
			OutIndex++;
		}
		InIndex++;
	}

	if(InIndex%2 == 1)       // ĳ������ַ�ֻ���˸���λ��������ϳ�ֵ������±�δ����
		OutIndex++;

	if(CompoudIndex != 0) // ��ʱ˵���������������8�ı��������һ���ϳ�ֵ����δ����
	{
		outarray[OutIndex] = CompoudValue;
		OutIndex++;
	}

	outlen =OutIndex; // ����ת����Ϻ��������鳤��
}
 

void DecodeChar(const uchar inarray[], uint inlen, uint outk, char &outchar)
{
	int CompoudIndex = 0;
	int HighValue = 0;      // �������ַ��ĵ���λ(ת��Ϊ0��26֮���)
	int LowValue = 0;       // �������ַ��ĵ���λ(ת��Ϊ0��26֮���)
	int CompoudValue = 0;   // ������ֵ

	if(((outk+8)/8 * 5 - 1) < inlen) // �������ַ������λ�������һ���ϳ�ֵ��
		HighValue = ((inarray[((outk+8)/8 * 5 - 1)] >> (CHARLEN - (outk%8))) & 0x01) << 4;
	else 
	{						// �������ַ������λ�����һ���ϳ�ֵ��
		HighValue = ((inarray[inlen-1] >> (CHARLEN - (outk%8))) & 0x01) << 4;
	}


	if(outk%2 == 0)     // ż�������ڸ�λ
		  LowValue = inarray[outk/2+outk/8] >> 4;
	else
		  LowValue = inarray[outk/2+outk/8] & LOWMASK;

	CompoudValue = HighValue | LowValue; //����������
	CompoudValue += 'a';    // �������ַ�

	outchar = CompoudValue;
} 
 
 



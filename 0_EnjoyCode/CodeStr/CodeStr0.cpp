//26���Ʊ���
#include <iostream>
using namespace std;

#define AZMAX 26
#define uint unsigned int
#define uchar unsigned char

//���������inarray[] ��������ַ����飻inlen����ĳ���
//���������outarray [] �������������飻outlen���������ĳ���
// unsigned int outarray[] ���������������õ������λ������Чλ���Ƿ���λ
void AzCodeChar(const char inarray[], uint inlen, uint outarray[], uint &outlen)
{
	int InIndex = 0;
	int OutIndex = 0;
	uint CompoudValue = 0;
	
	while(inlen--)
	{
		CompoudValue = CompoudValue* AZMAX + (inarray[InIndex] - 'a'); // ���ַ���������0��26
		InIndex++;
		// �����ַ���˳�����γ�26�����Ѹ�������Ӧ��ֵ�ĺ��������
		
		if(InIndex%6 == 0) // �����ַ�ת��Ϊһ��������
		{
			outarray[OutIndex] = CompoudValue;
			CompoudValue = 0;
			OutIndex++;
		}            
	}
	
	if(InIndex%6 != 0) //���������ַ�������δ����
	{
		outarray[OutIndex] = CompoudValue;
		CompoudValue = 0;
		OutIndex++;
	}
	
	outlen =OutIndex; // ����ת����Ϻ��������鳤��
}

// ���������inarray ������������飻inlen���������鳤�ȣ�
// outindex�������ַ���ԭ�����е��±�λ�ã�outlen�������ַ���ԭ�����ܳ��ȣ��Ȱ�5λ�������һ��������
// ���������outchar�������ֵ
void AzDecodeChar(const uint inarray[], uint inlen, uint outindex, uint outlen, char &outchar)
{
	
	int DecodeValue = 0;      // ������ֵ
	unsigned int DevideIndex = 0;
	unsigned int DevideValue = 1;
	
	if(outindex < (inlen - 1)*6)    //�������ַ��������һ���ϳ�ֵ��
	{     
		DevideIndex = 5 - outindex%6; //�õ�������������26����ָ��            
	}
	else // �������ַ������һ���ϳ�ֵ��
	{
		DevideIndex = 5 - (inlen*6 - outlen) - outindex%6;// ��ʱ���λ�������С��
	}
	
	while(DevideIndex > 0)
	{
		DevideValue *= AZMAX;       //�õ���������26^ DevideIndex
		DevideIndex--;
	}
	
	DecodeValue   = (inarray[outindex/6]/DevideValue)%AZMAX;// �õ���ǰ�ĸ�λ��
	
	outchar = DecodeValue + 'a';
} 

void   main(void)   
{   
	char *in = "abcdefghijklmnuvw";
	uint out[100] = {0};
	int outindex = 0;
	uint outcount;
	int incount = strlen(in);
	float coderatio = 0;
	char outchar;
	
	while(outindex < 100)
		out[outindex++] = 0;
	
	AzCodeChar(in, incount, out, outcount);
	cout << outcount << endl;
	
	coderatio = (float)outcount * sizeof(int)/incount;
	printf("ѹ�����ʣ�%6f\n", coderatio);
	
	outindex = 0; // ����
	while(outindex < incount)
	{
		AzDecodeChar(out, outcount, outindex, incount, outchar);
		cout << outchar;
		outindex++;
	}
	cout << endl;
}

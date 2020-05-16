//输入参数：inarray[] 待编码的字符数组; inlen数组的长度
//输入参数：outarray[] 编码后的字符数组; outlen编码后数组的长度


#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

#define LOWMASK 0x0f
#define HIGHMASK (1<<4)
#define CHARLEN 7
#define uint unsigned int 
#define uchar unsigned char 

// 输入参数：inarray[] 待编码的字符数组；inlen数组的长度
// 输入参数：outarray [] 编码后的字符数组；outlen编码后数组的长度
// uchar outarray[]编码后的字符数组用到了最高位，是有效位，非符号位
void CodeChar(const char inarray[], uint inlen, uchar outarray[], uint &outlen);

// 输入参数：inarray上面编码后的数组；inlen编码后的数组长度；outk待解码字符在原数组中的下标位置
// 输出参数：outchar解码的码值；inlen编码后的数组长度
void DecodeChar(const uchar inarray[], uint inlen, uint outk, char &outchar);

void main(void)   
{   
	char *in = "abcdefghijklmnuvw";
	uchar out[100] = {0};
	int outindex = 0;
	uint outcount;
	int incount = strlen(in);
	float coderatio = 0;//压缩比率
	char outchar;
	
	while(outindex < 100)
		out[outindex++] = 0;
	
	CodeChar(in, incount, out, outcount);
	out[incount] = (uchar)'/0'; // 编码
	
	cout << "压缩前字节:" << incount << endl << "压缩前字节:" << outcount << endl;
	
	coderatio = (float)outcount/incount;
	printf("压缩比率：%6f\n", coderatio);
	
	printf("压缩后：%s\n",out);
	
	outindex = 0; // 解码
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
		tempchar = inarray[InIndex] - 'a'; //将字符换成数字0－26

		if(InIndex%2 == 0)             
			 outarray[OutIndex] = ( tempchar & LOWMASK) << 4; //偶数位存放在每个字符的高位
		else        
			 outarray[OutIndex] |=(tempchar & LOWMASK); // 奇数位存放在每个字符的低位

		if((InIndex%2 == 1) && (InIndex != 0)) // 存放完两个数后，增加输出数组的下标
			 OutIndex++;

		// 将每个字符的第五位存放起来，0－7分别对应此字符的第7－第0位
		CompoudValue |= ((tempchar & HIGHMASK) << 3) >> (InIndex%8);

		CompoudIndex++;
		if(CompoudIndex == sizeof(char) * 8)// 存放了八个数后，将合成值保存到输出数组
		{     
			CompoudIndex = 0;
			outarray[OutIndex] = CompoudValue;
			OutIndex++;
		}
		InIndex++;
	}

	if(InIndex%2 == 1)       // 某个输出字符只用了高四位，但保存合成值的输出下标未增加
		OutIndex++;

	if(CompoudIndex != 0) // 此时说明输入数组个数非8的倍数，最后一个合成值上面未保存
	{
		outarray[OutIndex] = CompoudValue;
		OutIndex++;
	}

	outlen =OutIndex; // 保存转换完毕后的输出数组长度
}
 

void DecodeChar(const uchar inarray[], uint inlen, uint outk, char &outchar)
{
	int CompoudIndex = 0;
	int HighValue = 0;      // 待解码字符的第五位(转换为0－26之后的)
	int LowValue = 0;       // 待解码字符的低四位(转换为0－26之后的)
	int CompoudValue = 0;   // 解码后的值

	if(((outk+8)/8 * 5 - 1) < inlen) // 待解码字符的最高位不在最后一个合成值内
		HighValue = ((inarray[((outk+8)/8 * 5 - 1)] >> (CHARLEN - (outk%8))) & 0x01) << 4;
	else 
	{						// 待解码字符的最高位在最后一个合成值内
		HighValue = ((inarray[inlen-1] >> (CHARLEN - (outk%8))) & 0x01) << 4;
	}


	if(outk%2 == 0)     // 偶数保存在高位
		  LowValue = inarray[outk/2+outk/8] >> 4;
	else
		  LowValue = inarray[outk/2+outk/8] & LOWMASK;

	CompoudValue = HighValue | LowValue; //解码后的数字
	CompoudValue += 'a';    // 解码后的字符

	outchar = CompoudValue;
} 
 
 



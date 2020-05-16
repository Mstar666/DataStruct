//26进制编码
#include <iostream>
using namespace std;

#define AZMAX 26
#define uint unsigned int
#define uchar unsigned char

//输入参数：inarray[] 待编码的字符数组；inlen数组的长度
//输入参数：outarray [] 编码后的整型数组；outlen编码后数组的长度
// unsigned int outarray[] 编码后的整型数组用到了最高位，是有效位，非符号位
void AzCodeChar(const char inarray[], uint inlen, uint outarray[], uint &outlen)
{
	int InIndex = 0;
	int OutIndex = 0;
	uint CompoudValue = 0;
	
	while(inlen--)
	{
		CompoudValue = CompoudValue* AZMAX + (inarray[InIndex] - 'a'); // 将字符换成数字0－26
		InIndex++;
		// 按照字符的顺序依次乘26，即把各个数对应的值的和求出来了
		
		if(InIndex%6 == 0) // 六个字符转化为一个整型数
		{
			outarray[OutIndex] = CompoudValue;
			CompoudValue = 0;
			OutIndex++;
		}            
	}
	
	if(InIndex%6 != 0) //不足六个字符，上面未保存
	{
		outarray[OutIndex] = CompoudValue;
		CompoudValue = 0;
		OutIndex++;
	}
	
	outlen =OutIndex; // 保存转换完毕后的输出数组长度
}

// 输入参数：inarray 上面编码后的数组；inlen编码后的数组长度；
// outindex待解码字符在原数组中的下标位置；outlen待解码字符的原数组总长度（比按5位编码多了一个参数）
// 输出参数：outchar解码的码值
void AzDecodeChar(const uint inarray[], uint inlen, uint outindex, uint outlen, char &outchar)
{
	
	int DecodeValue = 0;      // 解码后的值
	unsigned int DevideIndex = 0;
	unsigned int DevideValue = 1;
	
	if(outindex < (inlen - 1)*6)    //待解码字符不在最后一个合成值内
	{     
		DevideIndex = 5 - outindex%6; //得到待除的数基于26的幂指数            
	}
	else // 待解码字符在最后一个合成值内
	{
		DevideIndex = 5 - (inlen*6 - outlen) - outindex%6;// 此时最高位的意义变小了
	}
	
	while(DevideIndex > 0)
	{
		DevideValue *= AZMAX;       //得到待除的数26^ DevideIndex
		DevideIndex--;
	}
	
	DecodeValue   = (inarray[outindex/6]/DevideValue)%AZMAX;// 得到当前的个位数
	
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
	printf("压缩比率：%6f\n", coderatio);
	
	outindex = 0; // 解码
	while(outindex < incount)
	{
		AzDecodeChar(out, outcount, outindex, incount, outchar);
		cout << outchar;
		outindex++;
	}
	cout << endl;
}

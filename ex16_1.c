//공용체의 기본: 공용체의 기억 공간은 멤버의 데이터 크기 중에서 가장 큰 데이터형의 크기로 정해진다
//공용체는 메모리를 공유!!한다
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <string.h>

union uchr {
	char chr1;
	char chr2[3];
};
int main()
{
	union uchr data;
	strcpy(data.chr2, "AB");
	printf("data.chr1 = %c\n", data.chr1);
	printf("data.chr2 = %s\n", data.chr2);
	data.chr1 = 'C';
	printf("data.chr1 = %c\n", data.chr1);
	printf("data.chr2 = %s\n", data.chr2);
	//서로 공간이 겹쳐있기 때문에, chr1을 수정하면 
	// chr2의 첫 번째 글자도 자동으로 바뀌게 됩니다.
	return 0;
}
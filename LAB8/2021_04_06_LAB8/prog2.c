#include <stdio.h>
#include <string.h>

struct phone {
	int country;
	unsigned long long phoneNum;
};

struct person {
	char name[20];
	int age;
	struct phone p1; //phone 구조체 변수
} P2;

int main(void) {
	
	//struct person p2; //person 구조체 변수
	
	strcpy(P2.name, "정민");
	P2.age = 23;
	P2.p1.country = 82;
	P2.p1.phoneNum = 35018711;

	printf("사람의 이름 : %s\n", P2.name);
	printf("사람의 나이 : %d\n", P2.age);
	printf("사람의 국가번호 : %d\n", P2.p1.country);
	printf("사람의 전화번호 : %llu\n", P2.p1.phoneNum);

	return 0;
}
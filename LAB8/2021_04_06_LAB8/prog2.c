#include <stdio.h>
#include <string.h>

struct phone {
	int country;
	unsigned long long phoneNum;
};

struct person {
	char name[20];
	int age;
	struct phone p1; //phone ����ü ����
} P2;

int main(void) {
	
	//struct person p2; //person ����ü ����
	
	strcpy(P2.name, "����");
	P2.age = 23;
	P2.p1.country = 82;
	P2.p1.phoneNum = 35018711;

	printf("����� �̸� : %s\n", P2.name);
	printf("����� ���� : %d\n", P2.age);
	printf("����� ������ȣ : %d\n", P2.p1.country);
	printf("����� ��ȭ��ȣ : %llu\n", P2.p1.phoneNum);

	return 0;
}
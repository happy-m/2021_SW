#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct contact {
	char name[32];
	char phone[32];
} CONTACT;

CONTACT* AllocateContacts(int count);
void InputContacts(CONTACT* contacts, int count);
void PrintContacts(const CONTACT* contacts, int count);
int CompareByName(const void* e1, const void* e2);
int CompareByPhone(const void* e1, const void* e2);
void SelectType(const CONTACT* contacts, int count);

int main()
{
	CONTACT* contacts = NULL;
	int cnt = 0;

	printf("저장할 연락처의 개수 : ");
	scanf("%d", &cnt);
	while (getchar() != '\n');

	contacts = AllocateContacts(cnt);
	if (contacts == NULL)
		return -1;

	InputContacts(contacts, cnt);
	SelectType(contacts, cnt);
//	PrintContacts(contacts, cnt);

	free(contacts);
	contacts = NULL;

	return 0;
}

CONTACT* AllocateContacts(int count)
{
	CONTACT* result = NULL;
	result = (CONTACT*)malloc(sizeof(CONTACT) * count);
	if (result == NULL)
		printf("동적 메모리 할당 실패\n");
	else
		memset(result, 0, sizeof(CONTACT) * count);
	return result;
}

void InputContacts(CONTACT* contacts, int count)
{
	int i;

	for (i = 0; i < count; i++)
	{
		printf("이    름 : ");
		gets(contacts[i].name);
		printf("전화번호 : ");
		gets(contacts[i].phone);
	}
}

void PrintContacts(const CONTACT* contacts, int count)
{
	int i;
	printf(" --- 전체 연락처 목록 ---\n");
	for (i = 0; i < count; i++)
	{
		printf("%-16s %-16s\n", contacts[i].name, contacts[i].phone);
	}

}

void SelectType(const CONTACT* contacts, int count) {

	int onetwo = 0;
	printf("출력방법 선택 :\n1.이름순 출력\n2.전화번호순 출력\n");
	scanf("%d", &onetwo);
	if (onetwo == 1) {
		printf("이름순으로 출력합니다.\n");
		qsort(contacts, count, sizeof(CONTACT), CompareByName);
		PrintContacts(contacts, count);
	}
	else if (onetwo == 2) {
		printf("전화번호순으로 출력합니다\n.");
		qsort(contacts, count, sizeof(CONTACT), CompareByPhone);
		PrintContacts(contacts, count);
	}
}

int CompareByName(const void* e1, const void* e2) {
	const CONTACT* p1 = (const CONTACT*) e1;
	const CONTACT* p2 = (const CONTACT*) e2;
	return strcmp(p1->name, p2->name);
}

int CompareByPhone(const void* e1, const void* e2) {
	const CONTACT* p1 = (const CONTACT*) e1;
	const CONTACT* p2 = (const CONTACT*) e2;
	return strcmp(p1->phone, p2->phone);
}

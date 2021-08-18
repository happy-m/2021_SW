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

	printf("������ ����ó�� ���� : ");
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
		printf("���� �޸� �Ҵ� ����\n");
	else
		memset(result, 0, sizeof(CONTACT) * count);
	return result;
}

void InputContacts(CONTACT* contacts, int count)
{
	int i;

	for (i = 0; i < count; i++)
	{
		printf("��    �� : ");
		gets(contacts[i].name);
		printf("��ȭ��ȣ : ");
		gets(contacts[i].phone);
	}
}

void PrintContacts(const CONTACT* contacts, int count)
{
	int i;
	printf(" --- ��ü ����ó ��� ---\n");
	for (i = 0; i < count; i++)
	{
		printf("%-16s %-16s\n", contacts[i].name, contacts[i].phone);
	}

}

void SelectType(const CONTACT* contacts, int count) {

	int onetwo = 0;
	printf("��¹�� ���� :\n1.�̸��� ���\n2.��ȭ��ȣ�� ���\n");
	scanf("%d", &onetwo);
	if (onetwo == 1) {
		printf("�̸������� ����մϴ�.\n");
		qsort(contacts, count, sizeof(CONTACT), CompareByName);
		PrintContacts(contacts, count);
	}
	else if (onetwo == 2) {
		printf("��ȭ��ȣ������ ����մϴ�\n.");
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

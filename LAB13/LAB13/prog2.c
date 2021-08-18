#include <stdio.h>

typedef struct person {
	char name[40];
	char age[30];
}Person;

Person* AllocateContacts(int num);
void CompareByAge(const void* age1, const void* age2);

int main(void) {
	Person* people = NULL;
	int num = 0;

	printf("������ ����� ���� �Է����ּ��� : ");
	scanf("%d", &num);

	people = AllocateContacts(num);

	for (int i = 0; i < num; i++) {
		printf("�̸��� ���̸� ������� �Է��ϼ��� : ");
		scanf("%s %d", &people[i].name, &people[i].age);
	}
	
	qsort(people, num, sizeof(Person), CompareByAge);
	printf("���̰� ���� ���� ����� %s�Դϴ�.", people[0].name);

	return 0;
}
void CompareByAge(const void* age1, const void* age2) {
	const Person* f1 = (const Person*)age1;
	const Person* f2 = (const Person*)age2;

	if (f1->age < f2->age) {
		return 1;
	}
	else if (f1->age > f2->age) {
		return -1;
	}
	else if (f1->age == f2->age) {
		return 0;
	}
}
Person* AllocateContacts(int count)
{
	Person* result = NULL;
	result = (Person*)malloc(sizeof(Person) * count);
	if (result == NULL)
		printf("���� �޸� �Ҵ� ����\n");
	else
		memset(result, 0, sizeof(Person) * count);
	return result;
}
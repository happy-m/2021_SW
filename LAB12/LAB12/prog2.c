#include <stdio.h>

typedef struct login_info {
	char id[20];
	char password[20];
} LOGIN_INFO;

LOGIN_INFO* AllocateContacts(int select);

int main(int argc, char* argv[]) {
	FILE* file = NULL;
	int select = 0;
	LOGIN_INFO* info = NULL;
	int cnt = 0;
	printf("��ü ����� ���� �Է����ּ��� : ");
	scanf("%d", &select);
	getchar();

	info = AllocateContacts(select);

	file = fopen("UserInfo.txt", "w");
	if (file == NULL) {
		printf("���� ���� ����\n");
		return -1;
	}

	printf("===== ����� ���̵�, ��й�ȣ �Է� =====\n");
	for (int i = 0; i < select; i++) {
		printf("id : ");
		scanf("%s", info[i].id);
		getchar();
		printf("password : ");
		scanf("%s", info[i].password);
		getchar();

		cnt = cnt + 1;
	}

	fprintf(file, "%d\n", select);
	for (int i = 0; i < select; i++) {
		fprintf(file, "%s ", info[i].id);
		fprintf(file, "%s\n", info[i].password);
	}
	fclose(file);

	return 0;
	
}

LOGIN_INFO* AllocateContacts(int select) {
	LOGIN_INFO* result = NULL;
	result = (LOGIN_INFO*)malloc(sizeof(LOGIN_INFO) * select);
	if (result == NULL)
		printf("���� �޸� �Ҵ� ����\n");
	else
		memset(result, 0, sizeof(LOGIN_INFO) * select);
	return result;
}
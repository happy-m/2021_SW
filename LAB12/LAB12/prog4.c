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

	file = fopen("UserInfoBinary.bin", "wb");
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

	fwrite(file, sizeof(int), 1, file);
	for (int i = 0; i < select; i++) {
		fwrite(info, sizeof(LOGIN_INFO), select, file);
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
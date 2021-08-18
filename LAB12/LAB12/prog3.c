#include <stdio.h>
#include <string.h>

typedef struct login_info {
	char id[20];
	char password[20];
} LOGIN_INFO;

LOGIN_INFO* AllocateContacts(int select);
int CompareByID(const void* id1, const void* id2);
int CompareByPwd(const void* pwd1, const void* pwd2);
int* findID(const void* id1, const void* id2);
int* findPassword(const void* pwd1, const void* pwd2);
void OpenFile(LOGIN_INFO* info, int* count);
void ReadInfo(LOGIN_INFO* info, int* count);

int main(int argc, char* argv[]) {
	FILE* file = NULL;
	int select = 0;
	LOGIN_INFO* info = NULL; 
	LOGIN_INFO searchID;
	LOGIN_INFO searchPwd;
	LOGIN_INFO* resultid = NULL;
	LOGIN_INFO* resultpwd = NULL;
	int cnt = 0;
	int* count = &cnt;
	
	OpenFile(info, count);	
	int reall = *count;
	info = AllocateContacts(reall);
	ReadInfo(info, count);
	cnt = *count;
	count = &cnt;

	while (1) {
		printf("===== 로그인 =====\n");
		qsort(info, cnt, sizeof(*info), CompareByID);
		printf("ID : ");
		scanf("%s", &searchID.id);
		getchar();

		if (strcmp(&searchID, ".") == 0) {
			break;
		}

		resultid = (int*)bsearch(&searchID, info, cnt, sizeof(*info), (int(*)(const void*, const void*))findID);
		if (resultid == NULL) {
			printf("존재하지 않는 아이디입니다.\n");
		}
		else {
			qsort(info, cnt, sizeof(*info), CompareByPwd);
			printf("Password : ");
			scanf("%s", &searchPwd.password);
			getchar();


			resultpwd = (int*)bsearch(&searchPwd, info, cnt, sizeof(*info), (int(*)(const void*, const void*))findPassword);

			if (resultpwd == NULL) {
				printf("로그인에 실패하였습니다.\n");
			}
			else if (strcmp(resultpwd, info[resultpwd-info].password)) {
				printf("로그인에 성공하였습니다.\n");
			}
		}
	}
	return 0;
}

void ReadInfo(LOGIN_INFO* info, int* count) {
	FILE* file = NULL;
	int fcnt = 0;
	file = fopen("UserInfo.txt", "a+");
	if (file == NULL) {
		printf("파일 열기 실패\n");
		return -1;
	}
	else {
		fscanf(file, "%d", &fcnt);
		*count = fcnt;

		for (int i = 0; i < *count; i++) {
			fscanf(file, "%s %s", info[i].id, info[i].password);
		}

	}
	fclose(file);
}

void OpenFile(LOGIN_INFO* info, int* count) {
	FILE* file = NULL;
	int fcnt = 0;
	file = fopen("UserInfo.txt", "r");
	if (file == NULL) {
		printf("파일 열기 실패\n");
		return -1;
	}
	else {
		fscanf(file, "%d", &fcnt);
		*count = fcnt;
	}
	fclose(file);
}
int CompareByID(const void* id1, const void* id2) {
	const LOGIN_INFO* f1 = (const LOGIN_INFO*)id1;
	const LOGIN_INFO* f2 = (const LOGIN_INFO*)id2;

	return strcmp(f1->id, f2->id);
}

int CompareByPwd(const void* pwd1, const void* pwd2) {
	const LOGIN_INFO* f1 = (const LOGIN_INFO*)pwd1;
	const LOGIN_INFO* f2 = (const LOGIN_INFO*)pwd2;

	return strcmp(f1->password, f2->password);
}

int* findID(const void* id1, const void* id2) {
	const LOGIN_INFO* p1 = (const LOGIN_INFO*)id1;
	const LOGIN_INFO* p2 = (const LOGIN_INFO*)id2;

	return strcmp(p1->id, p2->id);
}

int* findPassword(const void* pwd1, const void* pwd2) {
	const LOGIN_INFO* p1 = (const LOGIN_INFO*)pwd1;
	const LOGIN_INFO* p2 = (const LOGIN_INFO*)pwd2;

	return strcmp(p1->password, p2->password);
}

LOGIN_INFO* AllocateContacts(int count)
{
	LOGIN_INFO* result = NULL;
	result = (LOGIN_INFO*)malloc(sizeof(LOGIN_INFO) * count);
	if (result == NULL)
		printf("동적 메모리 할당 실패\n");
	else
		memset(result, 0, sizeof(LOGIN_INFO) * count);
	return result;
}
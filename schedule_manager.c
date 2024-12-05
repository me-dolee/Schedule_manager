#include <stdio.h>
#include <string.h>

#define MAX_SCHEDULES 100
#define MAX_STRING_LENGTH 100

typedef struct {
    char date[MAX_STRING_LENGTH];
    char time[MAX_STRING_LENGTH];
    char content[MAX_STRING_LENGTH];
} Schedule;

Schedule schedules[MAX_SCHEDULES];
int scheduleCount = 0;

void addSchedule();
void viewSchedules();
void deleteSchedule();

int main() {
    int choice;

    while (1) {
        printf("\n===== 스케줄 정리 프로그램 =====\n");
        printf("1. 일정 추가\n");
        printf("2. 일정 조회\n");
        printf("3. 일정 삭제\n");
        printf("4. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSchedule();
                break;
            case 2:
                viewSchedules();
                break;
            case 3:
                deleteSchedule();
                break;
            case 4:
                printf("프로그램을 종료합니다.\n");
                return 0;
            default:
                printf("잘못된 입력입니다. 다시 시도하세요.\n");
        }
    }
    return 0;
}

// 일정 추가
void addSchedule() {
    if (scheduleCount >= MAX_SCHEDULES) {
        printf("더 이상 일정을 추가할 수 없습니다.\n");
        return;
    }

    printf("날짜 입력 (예: 2025-01-01): ");
    scanf("%s", schedules[scheduleCount].date);
    printf("시간 입력 (예: 12:00): ");
    scanf("%s", schedules[scheduleCount].time);
    printf("일정 내용 입력: ");
    getchar();
    fgets(schedules[scheduleCount].content, MAX_STRING_LENGTH, stdin);
    schedules[scheduleCount].content[strcspn(schedules[scheduleCount].content, "\n")] = '\0';

    scheduleCount++;
    printf("일정이 추가되었습니다.\n");
}

// 일정 조회
void viewSchedules() {
    if (scheduleCount == 0) {
        printf("등록된 일정이 없습니다.\n");
        return;
    }

    printf("\n===== 등록된 일정 =====\n");
    for (int i = 0; i < scheduleCount; i++) {
        printf("%d. 날짜: %s, 시간: %s, 내용: %s\n",
               i + 1, schedules[i].date, schedules[i].time, schedules[i].content);
    }
}

// 일정 삭제
void deleteSchedule() {
    int index;

    if (scheduleCount == 0) {
        printf("삭제할 일정이 없습니다.\n");
        return;
    }

    printf("\n삭제할 일정 번호를 입력하세요 (1~%d): ", scheduleCount);
    scanf("%d", &index);

    if (index < 1 || index > scheduleCount) {
        printf("잘못된 번호입니다. 다시 시도하세요.\n");
        return;
    }

    // 삭제
    for (int i = index - 1; i < scheduleCount - 1; i++) {
        schedules[i] = schedules[i + 1];
    }
    scheduleCount--;

    printf("일정이 삭제되었습니다.\n");
}

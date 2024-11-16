#include <stdio.h>

unsigned char calculate_checksum(int* data, int length) {
    unsigned char checksum = 0;

    for (int i = 0; i < length; i++) {
        checksum |= data[i];  // OR 연산을 이용한 checksum 계산
    }

    return checksum;
}

int compare_arrays(int* original, int* input, int length) {
    unsigned char checksum_original = calculate_checksum(original, length);
    unsigned char checksum_input = calculate_checksum(input, length);

    if (checksum_original == checksum_input) {
        return 1;  // 배열이 일치하면 1을 반환
    } else {
        return 0;  // 배열이 일치하지 않으면 0을 반환
    }
}

int main() {
    int original_data[] = {18, 52, 86, 120};  // 원본 데이터 배열
    int length = sizeof(original_data) / sizeof(original_data[0]);

    int input_data[4];  // 입력 데이터 배열

    printf("Enter 4 integers for comparison:\n");
    for (int i = 0; i < length; i++) {
        scanf("%d", &input_data[i]);  // 사용자로부터 배열 입력 받기
    }

    // 배열 비교
    if (compare_arrays(original_data, input_data, length)) {
        printf("Arrays are identical.\n");
    } else {
        printf("Arrays are different.\n");
    }

    return 0;
}
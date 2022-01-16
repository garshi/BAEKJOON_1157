#include <stdio.h>
#include<stdlib.h>

char WORD[1000000];											// 단어를 입력받을 배열
int num = 0;												

int main(void) {											// 메인함수

	
	int A[26] = { 0 };										// 각 알파벳의 개수를 입력하기 위한 배열

	fgets(WORD, sizeof(WORD), stdin);						// 단어 입력 받기
	
	int MAX_num = 0;										// 최대값의 알파벳 개수 받기 위한 int




	for (int i = 0; i < 1000000; i++) {						// 각 알파벳 개수 판별 반복문


		num = 0;											// 현재 반복문에서 판정하고 있는 알파벳

		if (WORD[i] == '\0') break;							// 문자열 끝에서 종료

		for(char a = 'a'; a <= 'z'; a++) {

			if (WORD[i] == a) A[num] ++;			//num번째 알파벳(ex : 0번째 알파벳은 a)
			num++;									//num번째 알파벳 아닌거 확인하면 num++로 다음 확인
			
		}

		num = 0;

		for (char b = 'A'; b <= 'Z'; b++) {
			if (WORD[i] == b) A[num] ++;			// 대문자 확인 반복문
			num++;
		}
		
	}


	int MAX = A[0];							// 최대값


	for (int i = 1; i < 26; i++) {			// 최대값 판정

		if (MAX < A[i]) {

			MAX = A[i];
			MAX_num = i;
			A[i] = 0;

		}
		
	}

	A[0] = 0;


	for (int i = 0; i <26; i++) {

		if (MAX == A[i]) {				// 최대값과 같은 값이 있다면 
			printf("?");				// ? 출력후 
			return 0;					// 종료
		}

	}
	

	
	 printf("%c", 65 + MAX_num);		// 가장 많이 나온 알파벳 출력
	

}
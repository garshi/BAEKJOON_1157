#include <stdio.h>
#include< stdlib.h>

int main(void) {


	
	char WORD[1000000];								// 단어 char
	
	int A[52] = { 0 };										// 각 알파벳의 출현 횟수

	fgets(WORD, sizeof(WORD), stdin);				// 단어 입력 받기

	int MAX = 0;							// 최대값
	int MAX_num = 0;						// 최대값을 가진 알파벳의 순서




	for (int i = 0; i < 1000000; i++) {			// 각 알파벳 개수 판별 반복문


		int num = 0;							// 현재 반복문에서 판정하고 있는 알파벳

		if (WORD[i] == '\0') break;							// 문자열 끝에서 종료

		for(char a = 'a'; a <= 'z'; a++) {

			if (WORD[i] == a) A[num] ++;			//num번째 알파벳(ex : 0번째 알파벳은 a)
			num++;									//num번째 알파벳 아닌거 확인하면 num++로 다음 확인
			
		}

		for (char b = 'A'; b <= 'Z'; b++) {
			if (WORD[i] == b) A[num+26] ++;			// 대문자 확인 반복문
			num++;
		}
		
	}



	for (int i = 1; i < 52; i++) {			// 최대값 판정

		if (MAX < A[i]) {

			MAX = A[i];
			MAX_num = i;
			A[i] = 0;

		}
	}


	for (int i = 0; i < 52; i++) {

		if (MAX == A[i]) {				// 최대값과 같은 값이 있다면 
			printf("?");				// ? 출력후 
			return 0;					// 종료
		}

	}
	

	if (MAX < 26) printf("%c", 97 + MAX_num);			// MAX가 소문자 일시 출력

	else if (MAX >= 26) printf("%c", 39 + MAX_num);		// MAX가 대문자 일시 출력 
	

}
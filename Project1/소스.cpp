#include <stdio.h>
#include<stdlib.h>

char WORD[1000000];											// �ܾ �Է¹��� �迭
int num = 0;												

int main(void) {											// �����Լ�

	
	int A[26] = { 0 };										// �� ���ĺ��� ������ �Է��ϱ� ���� �迭

	fgets(WORD, sizeof(WORD), stdin);						// �ܾ� �Է� �ޱ�
	
	int MAX_num = 0;										// �ִ밪�� ���ĺ� ���� �ޱ� ���� int




	for (int i = 0; i < 1000000; i++) {						// �� ���ĺ� ���� �Ǻ� �ݺ���


		num = 0;											// ���� �ݺ������� �����ϰ� �ִ� ���ĺ�

		if (WORD[i] == '\0') break;							// ���ڿ� ������ ����

		for(char a = 'a'; a <= 'z'; a++) {

			if (WORD[i] == a) A[num] ++;			//num��° ���ĺ�(ex : 0��° ���ĺ��� a)
			num++;									//num��° ���ĺ� �ƴѰ� Ȯ���ϸ� num++�� ���� Ȯ��
			
		}

		num = 0;

		for (char b = 'A'; b <= 'Z'; b++) {
			if (WORD[i] == b) A[num] ++;			// �빮�� Ȯ�� �ݺ���
			num++;
		}
		
	}


	int MAX = A[0];							// �ִ밪


	for (int i = 1; i < 26; i++) {			// �ִ밪 ����

		if (MAX < A[i]) {

			MAX = A[i];
			MAX_num = i;
			A[i] = 0;

		}
		
	}

	A[0] = 0;


	for (int i = 0; i <26; i++) {

		if (MAX == A[i]) {				// �ִ밪�� ���� ���� �ִٸ� 
			printf("?");				// ? ����� 
			return 0;					// ����
		}

	}
	

	
	 printf("%c", 65 + MAX_num);		// ���� ���� ���� ���ĺ� ���
	

}
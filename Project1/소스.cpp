#include <stdio.h>
#include< stdlib.h>

int main(void) {


	
	char WORD[1000000];								// �ܾ� char
	
	int A[52] = { 0 };										// �� ���ĺ��� ���� Ƚ��

	fgets(WORD, sizeof(WORD), stdin);				// �ܾ� �Է� �ޱ�

	int MAX = 0;							// �ִ밪
	int MAX_num = 0;						// �ִ밪�� ���� ���ĺ��� ����




	for (int i = 0; i < 1000000; i++) {			// �� ���ĺ� ���� �Ǻ� �ݺ���


		int num = 0;							// ���� �ݺ������� �����ϰ� �ִ� ���ĺ�

		if (WORD[i] == '\0') break;							// ���ڿ� ������ ����

		for(char a = 'a'; a <= 'z'; a++) {

			if (WORD[i] == a) A[num] ++;			//num��° ���ĺ�(ex : 0��° ���ĺ��� a)
			num++;									//num��° ���ĺ� �ƴѰ� Ȯ���ϸ� num++�� ���� Ȯ��
			
		}

		for (char b = 'A'; b <= 'Z'; b++) {
			if (WORD[i] == b) A[num+26] ++;			// �빮�� Ȯ�� �ݺ���
			num++;
		}
		
	}



	for (int i = 1; i < 52; i++) {			// �ִ밪 ����

		if (MAX < A[i]) {

			MAX = A[i];
			MAX_num = i;
			A[i] = 0;

		}
	}


	for (int i = 0; i < 52; i++) {

		if (MAX == A[i]) {				// �ִ밪�� ���� ���� �ִٸ� 
			printf("?");				// ? ����� 
			return 0;					// ����
		}

	}
	

	if (MAX < 26) printf("%c", 97 + MAX_num);			// MAX�� �ҹ��� �Ͻ� ���

	else if (MAX >= 26) printf("%c", 39 + MAX_num);		// MAX�� �빮�� �Ͻ� ��� 
	

}
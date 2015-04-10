#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int strike, ball;

void strike_reset(){
	strike = 0;
	ball = 0;
}

int main(){
	int out, score;
	int first_base, second_base, third_base;
	int hit;
	ball = 0; 
	strike = 0; 
	out = 0; 
	score = 0;
	first_base = 0; 
	second_base = 0; 
	third_base = 0;
	
	srand((unsigned)time(NULL));
	while (1){
		int random_for_pitcher;
		printf("============================\n점수: %d\n아웃: %d\n스트라이크/볼: %d/%d\n", score, out, strike, ball);
		printf("1루: %d 2루: %d 3루: %d\n============================\n", first_base, second_base, third_base);
		random_for_pitcher = rand() % 100;
		hit = 0;
		if (random_for_pitcher <= 70){
			printf("\n\n투수가 직구를 던집니다.\n타격 방법을 선택하세요.(1.풀스윙 2.스윙 3. 대기)\n");
			scanf("%d", &hit);
			int random_for_hitter;
			random_for_hitter = rand() % 100;
			if (hit == 1 && random_for_hitter <= 80){
				int random_for_fullswing;
				random_for_fullswing = rand() % 100;
				if (random_for_fullswing < 30) out++;
				else if (random_for_fullswing >= 30 && random_for_fullswing < 65) {
					if (third_base == 1){
						score++;
						third_base--;
					}
					if (second_base == 1){
						third_base++;
						second_base--;
					}
					if (first_base == 1){
						second_base++;
						first_base--;
					}
					first_base++;
					printf("1루타입니다\n");
					strike_reset();
				}
				else if (random_for_fullswing >= 65 && random_for_fullswing < 85) {
					if (third_base == 1){
						score++;
						third_base--;
					}
					if (second_base == 1){
						score++;
						second_base--;
					}
					if (first_base == 1){
						third_base++;
						first_base--;
					}
					second_base++;
					printf("2루타입니다!\n");
					strike_reset();
				}
				else if (random_for_fullswing >= 85 && random_for_fullswing < 95){
					if (third_base == 1){
						score++;
						third_base--;
					}
					if (second_base == 1){
						score++;
						second_base--;
					}
					if (first_base == 1){
						score++;
						first_base--;
					}
					third_base++;
					printf("3루타입니다!\n");
				}
				else {
					score += (first_base + second_base + third_base + 1);
					printf("홈런입니다!!!\n");
					strike_reset();
				}
			};
			if (hit == 1 && random_for_hitter > 80){
				out++;
				printf("플라이아웃!\n");
				strike_reset();
			};
			if (hit == 2 && random_for_hitter <= 65){
				int random_for_swing;
				random_for_swing = rand() % 100;
				if (random_for_swing < 30) out++;
				else if (random_for_swing >= 30 && random_for_swing < 65) {
					if (third_base == 1){
						score++;
						third_base--;
					}
					if (second_base == 1){
						third_base++;
						second_base--;
					}
					if (first_base == 1){
						second_base++;
						first_base--;
					}
					first_base++;
					printf("1루타입니다\n");
					strike_reset();
				}
				else if (random_for_swing >= 65 && random_for_swing < 85) {
					if (third_base == 1){
						score++;
						third_base--;
					}
					if (second_base == 1){
						score++;
						second_base--;
					}
					if (first_base == 1){
						third_base++;
						first_base--;
					}
					second_base++;
					printf("2루타입니다!\n");
					strike_reset();
				}
				else if (random_for_swing >= 85 && random_for_swing < 95) {
					if (third_base == 1){
						score++;
						third_base--;
					}
					if (second_base == 1){
						score++;
						second_base--;
					}
					if (first_base == 1){
						score++;
						first_base--;
					}
					third_base++;
					printf("3루타입니다!\n");
				}
				else {
					score += (first_base + second_base + third_base + 1);
					printf("홈런입니다!!!\n");
					strike_reset();
				}
			};
			if (hit == 2 && random_for_hitter > 65){
				out++;
				printf("플라이아웃!\n");
				strike_reset();
			};
			if (hit == 3){
				int random_for_wait;
				random_for_wait = rand() % 100;
				if (random_for_wait <= 40) {
					strike++;
					printf("스트라이크!\n");
				}
				else {
					ball++;
					printf("볼!\n");
				}
			};
		};
		if (random_for_pitcher > 70) {
			hit = 0;
			printf("\n\n투수가 변화구를 던집니다.\n타격 방법을 선택하세요.(1.풀스윙 2.스윙 3. 대기):");
			scanf("%d", &hit);
			int random_for_hitter;
			random_for_hitter = rand() % 100;
			if (hit == 1 && random_for_hitter <= 60){
				int random_for_fullswing;
				random_for_fullswing = rand() % 100;
				if (random_for_fullswing < 30) out++;
				else if (random_for_fullswing >= 30 && random_for_fullswing < 65) {
					if (third_base == 1){
						score++;
						third_base--;
					}
					if (second_base == 1){
						third_base++;
						second_base--;
					}
					if (first_base == 1){
						second_base++;
						first_base--;
					}
					first_base++;
					printf("1루타입니다\n");
					strike_reset();
				}
				else if (random_for_fullswing >= 65 && random_for_fullswing < 85) {
					if (third_base == 1){
						score++;
						third_base--;
					}
					if (second_base == 1){
						score++;
						second_base--;
					}
					if (first_base == 1){
						third_base++;
						first_base--;
					}
					second_base++;
					printf("2루타입니다!\n");
					strike_reset();
				}
				else if (random_for_fullswing >= 85 && random_for_fullswing < 95) {
					if (third_base == 1){
						score++;
						third_base--;
					}
					if (second_base == 1){
						score++;
						second_base--;
					}
					if (first_base == 1){
						score++;
						first_base--;
					}
					third_base++;
					printf("3루타입니다!\n");
				}
				else {
					score = first_base + second_base + third_base + 1;
					printf("홈런입니다!!!!\n");
					strike_reset();
				}
			};
			if (hit == 1 && random_for_hitter > 60){
				out++;
				printf("플라이아웃!\n");
				strike_reset();
			}
			if (hit == 2 && random_for_hitter <= 70){
				int random_for_swing;
				random_for_swing = rand() % 100;
				if (random_for_swing < 30) {
					out++;
					printf("플라이아웃!\n");
					strike_reset();
				}
				else if (random_for_swing >= 30 && random_for_swing < 65) {
					if (third_base == 1){
						score++;
						third_base--;
					}
					if (second_base == 1){
						third_base++;
						second_base--;
					}
					if (first_base == 1){
						second_base++;
						first_base--;
					}
					first_base++;
					printf("1루타입니다\n");
					strike_reset();
				}
				else if (random_for_swing >= 65 && random_for_swing < 85) {
					if (third_base == 1){
						score++;
						third_base--;
					}
					if (second_base == 1){
						score++;
						second_base--;
					}
					if (first_base == 1){
						third_base++;
						first_base--;
					}
					second_base++;
					printf("2루타입니다!\n");
					strike_reset();
				}
				else if (random_for_swing >= 85 && random_for_swing < 95){
					if (third_base == 1){
						score++;
						third_base--;
					}
					if (second_base == 1){
						score++;
						second_base--;
					}
					if (first_base == 1){
						score++;
						first_base--;
					}
					third_base++;
					printf("3루타입니다!\n");
				}
				else {
					score += (first_base + second_base + third_base + 1);
					printf("홈런입니다!!!\n");
					strike_reset();
				}
			};
			if (hit == 2 && random_for_hitter > 70){
				out++;
				printf("플라이아웃!\n");
				strike_reset();
			}
			if (hit == 3){
				int random_for_wait;
				random_for_wait = rand() % 100;
				if (random_for_wait <= 40) {
					strike++;
					printf("스트라이크!\n");
				}
				else {
					ball++;
					printf("볼!\n");
				}
			};
		};
		if (ball == 4){
			first_base++;
			strike_reset();
			}
		if (strike == 3){
			out++;
			strike_reset();
			}

		if (out >= 3){
			printf("삼진아웃! 게임 끝!\n\n\n");
			break;
			};
	};
	system("pause");
	return 0;
}
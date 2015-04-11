#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int strike, ball;
int first_base, second_base, third_base;
int score;

void strike_reset(){		//타자 진루시 스트라이크, 볼 리셋
	strike = 0;
	ball = 0;
}

void swing_miss(){
	strike++;
	printf("헛스윙입니다.\n");
	}

void first_run(){			//1루타 상황 진루
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

void second_run(){			//2루타 상황 진루
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

void third_run(){			//3루타 상황 진루
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

void home_run(){			//홈런 상황 진루
	score += (first_base + second_base + third_base + 1);
	first_base = 0;
	second_base = 0;
	third_base = 0;
	printf("홈런입니다!!!\n");
	strike_reset();
}

int main(){
	int out;
	int hit;
	ball = 0; 
	strike = 0; 
	out = 0; 
	score = 0;
	first_base = 0; 
	second_base = 0; 
	third_base = 0;
	
	srand((unsigned)time(NULL));		

	while (1){				//out이 3이 될 때 까지 반복
		int random_for_pitcher;
		printf("============================\n점수: %d\n아웃: %d\n스트라이크/볼: %d/%d\n", score, out, strike, ball);
		printf("1루: %d 2루: %d 3루: %d\n============================\n", first_base, second_base, third_base);
		random_for_pitcher = rand() % 100;
		hit = 0;
		if (random_for_pitcher <= 70){		//70%확률로 투수가 직구를 던짐
			printf("\n\n투수가 직구를 던집니다.\n타격 방법을 선택하세요.(1.풀스윙 2.스윙 3. 대기):");
			scanf("%d", &hit);
			int random_for_hitter;
			random_for_hitter = rand() % 100;
			if (hit == 1 && random_for_hitter < 80){
				int random_for_fullswing;										  //풀 스윙 상황을 포함한 나머지 타격 상황들은 동일한 형식을 가짐(확률은 다름)
				random_for_fullswing = rand() % 100;
				if (random_for_fullswing < 30)
					swing_miss();												  // 30% 확률로 헛스윙
				else if (random_for_fullswing >= 30 && random_for_fullswing < 65) // 35% 확률로 1루타
					first_run(); 
				else if (random_for_fullswing >= 65 && random_for_fullswing < 85) // 20% 확률로 2루타
					second_run();
				else if (random_for_fullswing >= 85 && random_for_fullswing < 95) // 10% 확률로 3루타
					third_run();
				else
					home_run();													  // 5% 확률로 홈런
			}
			if (hit == 1 && random_for_hitter >= 80){
				out++;															  // 풀스윙시 20% 확률로 플라이 아웃
				printf("플라이아웃!\n");
				strike_reset();
			}
			if (hit == 2 && random_for_hitter <= 65){
				int random_for_swing;
				random_for_swing = rand() % 100;
				if (random_for_swing < 30)
					swing_miss();
				else if (random_for_swing >= 30 && random_for_swing < 65)
					first_run();
				else if (random_for_swing >= 65 && random_for_swing < 85)
					second_run();
				else if (random_for_swing >= 85 && random_for_swing < 95)
					third_run();
				else
					home_run();
			}
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
			}
		}
		if (random_for_pitcher > 70) {
			hit = 0;
			printf("\n\n투수가 변화구를 던집니다.\n타격 방법을 선택하세요.(1.풀스윙 2.스윙 3. 대기):");
			scanf("%d", &hit);
			int random_for_hitter;
			random_for_hitter = rand() % 100;
			if (hit == 1 && random_for_hitter <= 60){
				int random_for_fullswing;
				random_for_fullswing = rand() % 100;
				if (random_for_fullswing < 30)
					swing_miss();
				else if (random_for_fullswing >= 30 && random_for_fullswing < 65)
					first_run();
				else if (random_for_fullswing >= 65 && random_for_fullswing < 85)
					second_run();
				else if (random_for_fullswing >= 85 && random_for_fullswing < 95)
					third_run();
				else
					home_run();
			}
			if (hit == 1 && random_for_hitter > 60){
				out++;
				printf("플라이아웃!\n");
				strike_reset();
			}
			if (hit == 2 && random_for_hitter <= 70){
				int random_for_swing;
				random_for_swing = rand() % 100;
				if (random_for_swing < 30)
					swing_miss();
				else if (random_for_swing >= 30 && random_for_swing < 65)
					first_run();
				else if (random_for_swing >= 65 && random_for_swing < 85)
					second_run();
				else if (random_for_swing >= 85 && random_for_swing < 95)
					third_run();
				else
					home_run();
			}
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
			}
		}
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
			}
	}
	system("pause");
	return 0;
}
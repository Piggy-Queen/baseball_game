#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void strike_reset(){
	int strike, ball;
	strike = 0;
	ball = 0;
}

void base_count(int first_base, int second_base, int third_base, int score){
	while (first_base > 1) {
		first_base--; 
		second_base++; 
	}
	while (second_base > 1) { 
		second_base--; 
		third_base++; 
	}
	while (third_base > 1) {
		third_base--; 
		score++; 
	}
}

int main(){
	int ball, strike, out, score;
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
		printf("============================\n����: %d\n�ƿ�: %d\n��Ʈ����ũ/��: %d/%d\n", score, out, strike, ball);
		printf("1��: %d 2��: %d 3��: %d\n============================\n", first_base, second_base, third_base);
		random_for_pitcher = rand() % 100;
		hit = 0;
		if (random_for_pitcher <= 70){
			printf("\n\n������ ������ �����ϴ�.\nŸ�� ����� �����ϼ���.(1.Ǯ���� 2.���� 3. ���)\n");
			scanf("%d", &hit);
			int random_for_hitter;
			random_for_hitter = rand() % 100;
			if (hit == 1 && random_for_hitter <= 80){
				int random_for_fullswing;
				random_for_fullswing = rand() % 100;
				if (random_for_fullswing < 30) out++;
				else if (random_for_fullswing >= 30 && random_for_fullswing < 65) {
					first_base++;
					printf("1��Ÿ�Դϴ�\n");
					strike_reset();
				}
				else if (random_for_fullswing >= 65 && random_for_fullswing < 85) {
					first_base += 2;
					printf("2��Ÿ�Դϴ�!\n");
					strike_reset();
				}
				else if (random_for_fullswing >= 85 && random_for_fullswing < 95){
					first_base += 3;
					printf("3��Ÿ�Դϴ�!\n");
				}
				else {
					score += (first_base + second_base + third_base + 1);
					printf("Ȩ���Դϴ�!!!\n");
					strike_reset();
				}
			};
			if (hit == 1 && random_for_hitter > 80){
				out++;
				printf("�ö��̾ƿ�!\n");
				strike_reset();
			};
			if (hit == 2 && random_for_hitter <= 65){
				int random_for_swing;
				random_for_swing = rand() % 100;
				if (random_for_swing < 30) out++;
				else if (random_for_swing >= 30 && random_for_swing < 65) {
					first_base++;
					printf("1��Ÿ�Դϴ�!\n");
					strike_reset();
				}
				else if (random_for_swing >= 65 && random_for_swing < 85) {
					first_base += 2;
					printf("2��Ÿ�Դϴ�!\n");
					strike_reset();
				}
				else if (random_for_swing >= 85 && random_for_swing < 95) {
					first_base += 3;
					printf("3��Ÿ�Դϴ�!\n");
					strike_reset();
				}
				else {
					score += (first_base + second_base + third_base + 1);
					printf("Ȩ���Դϴ�!!!\n");
					strike_reset();
				}
			};
			if (hit == 2 && random_for_hitter > 65){
				out++;
				printf("�ö��̾ƿ�!\n");
				strike_reset();
			};
			if (hit == 3){
				int random_for_wait;
				random_for_wait = rand() % 100;
				if (random_for_wait <= 40) {
					strike++;
					printf("��Ʈ����ũ!\n");
				}
				else {
					ball++;
					printf("��!\n");
				}
			};
		};
		if (random_for_pitcher > 70) {
			hit = 0;
			printf("\n\n������ ��ȭ���� �����ϴ�.\nŸ�� ����� �����ϼ���.(1.Ǯ���� 2.���� 3. ���):");
			scanf("%d", &hit);
			int random_for_hitter;
			random_for_hitter = rand() % 100;
			if (hit == 1 && random_for_hitter <= 60){
				int random_for_fullswing;
				random_for_fullswing = rand() % 100;
				if (random_for_fullswing < 30) out++;
				else if (random_for_fullswing >= 30 && random_for_fullswing < 65) {
					first_base++;
					printf("1��Ÿ�Դϴ�!\n");
					strike_reset();
				}
				else if (random_for_fullswing >= 65 && random_for_fullswing < 85) {
					first_base += 2;
					printf("2��Ÿ�Դϴ�!\n");
					strike_reset();
				}
				else if (random_for_fullswing >= 85 && random_for_fullswing < 95) {
					first_base += 3, second_base += 2;
					printf("3��Ÿ�Դϴ�!\n");
					strike_reset();
				}
				else {
					score = first_base + second_base + third_base + 1;
					printf("Ȩ���Դϴ�!!!!\n");
					strike_reset();
				}
			};
			if (hit == 1 && random_for_hitter > 60){
				out++;
				printf("�ö��̾ƿ�!\n");
				strike_reset();
			}
			if (hit == 2 && random_for_hitter <= 70){
				int random_for_swing;
				random_for_swing = rand() % 100;
				if (random_for_swing < 30) {
					out++;
					printf("�ö��̾ƿ�!\n");
					strike_reset();
				}
				else if (random_for_swing >= 30 && random_for_swing < 65) {
					first_base++;
					printf("1��Ÿ�Դϴ�!\n");
					strike_reset();
				}
				else if (random_for_swing >= 65 && random_for_swing < 85) {
					first_base += 2;
					printf("2��Ÿ�Դϴ�!\n");
					strike_reset();
				}
				else if (random_for_swing >= 85 && random_for_swing < 95){
					first_base += 3;
					printf("3��Ÿ�Դϴ�!\n");
					strike_reset();
				}
				else {
					score += (first_base + second_base + third_base + 1);
					printf("Ȩ���Դϴ�!!!\n");
					strike_reset();
				}
			};
			if (hit == 2 && random_for_hitter > 70){
				out++;
				printf("�ö��̾ƿ�!\n");
				strike_reset();
			}
			if (hit == 3){
				int random_for_wait;
				random_for_wait = rand() % 100;
				if (random_for_wait <= 40) {
					strike++;
					printf("��Ʈ����ũ!\n");
				}
				else {
					ball++;
					printf("��!\n");
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
		
		base_count(first_base, second_base, third_base, score);
		
		if (out >= 3){
			printf("�����ƿ�! ���� ��!\n\n\n");
			break;
			};
	};
	system("pause");
	return 0;
}
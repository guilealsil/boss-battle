#include<stdio.h>
#include<stdlib.h> 
#include<locale.h> //utilizada em conjunto com a linha do setlocale
#include<time.h> //biblioteca para usar o rand().
#include<conio.h> 
#include<ctype.h> //converte letras minusculas para maisusculas
#include<windows.h> //função para mudar a cor de determinada parte do código, tbm inclui timers

int main() 
{
	setlocale(LC_ALL,"Portuguese");
	system("color A");
	int hp_b = 333, hp_p = 99, sp_p = 25;
	int skill_a = 1, skill_b = 2, heal = 3;
	int dmga = 20;
	int dmgb[2];
	dmgb[0] = 8;
	dmgb[1] = 9;
	dmgb[2] = 10;
	int rec = 10;
	int dmgp = 8;
	int op;
	
	printf("\t############## Boss Battle ##############\n\n");
	
	printf(" ANXIETY: 'FAREI DA SUA VIDA UMA MISÉRIA!'\n");
	printf(" Player: 'É o que veremos.'\n\n");
	
	do{
		repeat:
		printf("\tAÇÕES E CUSTOS DE SP:\n\n"); //menu
		printf("\t[1] SLASH - 20 ATK [%d SP]\n", skill_a);
		printf("\t[2] TRIPLE SLASH - 3 HITS (8, 9, 10 ATK) [%d SP]\n", skill_b);
		printf("\t[3] HEAL - RECUPERA 10 HP [%d SP]\n", heal);
		printf("\t[PASSIVO] Player RECUPERA 2 DE SP A CADA RODADA\n");
		printf("\t[PASSIVO] O DANO DE SLASH AUMENTA EM 1 A CADA RODADA\n");
		printf("\t[PASSIVO DE ANXIETY] SE O HP FOR MENOR QUE 150, DANO DE ANXIETY AUMENTA EM 1 A CADA RODADA\n\n");
		printf("Selecione uma opção: ");
		scanf("%d", &op);
		printf("\n");
			switch (op){
				case 1:
					system("cls"); //habilidade 1 + dano ao anxiety e player
					printf("=*=*=*=*=*=*=*=*=*=*=*=*=\n\n");
					hp_b = hp_b - dmga;
					printf(" ANXIETY recebeu %d de dano.\n", dmga);
					printf(" HP de ANXIETY: %d\n\n", hp_b);
					hp_p = hp_p - dmgp;
					printf(" Player recebeu %d de dano.\n", dmgp);
					printf(" HP de Player: %d\n", hp_p);
					sp_p = sp_p - 1;
					printf(" SP de Player: %d\n\n", sp_p);
					printf("=*=*=*=*=*=*=*=*=*=*=*=*=\n\n");
					break;
				case 2:
					system("cls"); //habilidade 2 + dano ao anxiety e player
					printf("=*=*=*=*=*=*=*=*=*=*=*=*=\n\n");
					hp_b = hp_b - dmgb[0];
					printf(" ANXIETY recebeu %d de dano.\n", dmgb[0]);
					hp_b = hp_b - dmgb[1];
					printf(" ANXIETY recebeu %d de dano.\n", dmgb[1]);
					hp_b = hp_b - dmgb[2];
					printf(" ANXIETY recebeu %d de dano.\n", dmgb[2]);
					printf(" HP de ANXIETY: %d\n\n", hp_b);
					hp_p = hp_p - dmgp;
					printf(" Player recebeu %d de dano.\n", dmgp);
					printf(" HP de Player: %d\n", hp_p);
					sp_p = sp_p - 2;
					printf(" SP de Player: %d\n\n", sp_p);
					printf("=*=*=*=*=*=*=*=*=*=*=*=*=\n\n");
					
					break;
				case 3:
					system("cls"); //habilidade 3 + dano ao player
					printf("=*=*=*=*=*=*=*=*=*=*=*=*=\n\n");
					hp_p = hp_p + rec;
					hp_p = hp_p - dmgp;
					printf(" Player recebeu %d de dano.\n", dmgp);
					printf(" Player se curou em %d.\n", rec);
					printf(" HP de Player: %d\n", hp_p);
					sp_p = sp_p - 3;
					printf(" SP de Player: %d\n\n", sp_p);
					printf("=*=*=*=*=*=*=*=*=*=*=*=*=\n\n");
					break;
				default:
					system("cls");
					printf("Opção inválida. Tente novamente.\n");
					goto repeat;
			}
		if (hp_p < 1){
			system("cls");
			printf("\n\t\tGAME OVER\n\n");
			goto stop;
		}
		
		sp_p = sp_p+2; //passivo 1 do player
		dmga++; // passivo 2 do player
		
		if (hp_b < 150){ //passivo do anxiety
			dmgp++;
		}
	} while (hp_b > 0);
	
	system("cls");
	printf("\n\t\tVITÓRIA!");

	stop:
	system("pause");
	return 0;
}


#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<locale.h>
void clear()
{
	int c;
	while((c=fgetc(stdin))!=EOF && c != '\n');
}
void imprime(char jogo[4][4])
{
	int i, j;
	for(i=0;i<4;i++)
	{
		printf("\n");
		for(j=0;j<4;j++)
		{
			if(j==0)
			{
				printf("%c", jogo[i][j]);
			}
			else if(i==0)
				{
					printf("\t %c", jogo[i][j]);
				}
			else 
			{
				printf("\t[%c]", jogo[i][j]);
			}
		}
	}
	printf("\n\n");
}
char verifica(char jogo[4][4])
{
	//Horizontal:
	if(jogo[1][1]==jogo[1][2] && jogo[1][1]==jogo[1][3])
	{
		return jogo[1][1];
	}
	else if(jogo[2][1]==jogo[2][2] && jogo[2][1]==jogo[2][3])
	{
		return jogo[2][1];
	}
	else if(jogo[3][1]==jogo[3][2] && jogo[3][1]==jogo[3][3])
	{
		return jogo[3][1];
	}
	//Vertical:
	else if(jogo[1][1]==jogo[2][1] && jogo[1][1]==jogo[3][1])
	{
		return jogo[1][1];
	}
	else if(jogo[1][2]==jogo[2][2] && jogo[1][2]==jogo[3][2])
	{
		return jogo[1][2];
	}
	else if(jogo[1][3]==jogo[2][3] && jogo[1][3]==jogo[3][3])
	{
		return jogo[1][3];
	}
	//Diagonal:
	else if(jogo[1][1]==jogo[2][2] && jogo[1][1]==jogo[3][3])
	{
		return jogo[1][1];
	}
	else if(jogo[3][1]==jogo[2][2] && jogo[3][1]==jogo[1][3])
	{
		return jogo[3][1];
	}
	else
	{
		return ' ';
	}
}
char round(int vez)
{
	if(vez%2==0)
	{
		return 'X';
	}
	else
	{
		return 'O';
	}
}
int main()
{
	setlocale(LC_ALL,"Portuguese");
	char jogo[4][4]= {{' ','1','2','3'},
	   				  {'A',' ',' ',' '},
					  {'B',' ',' ',' '},
					  {'C',' ',' ',' '}};
	char linha, coluna, vez=0;
	while(vez<9)
	{
		printf("***JOGO DA VELHA***\n");
		imprime(jogo);
		if(verifica(jogo)!=' ')
		{
			printf("Fim de jogo.\n O ganhador foi %c.\n", verifica(jogo));
			break;
		}
		else
		{
			printf("É a vez do %c.\n", round(vez));
			printf("Digite a linha e a coluna:\n");
			scanf("%c%c",&linha,&coluna);
			linha=toupper(linha);
			system("cls");
			clear();	
			if((linha-64)<4 && (coluna-48)<4)
		    {
		    	if(jogo[linha-64][coluna-48]==' ')
		    	{
		    		if(vez % 2==0 && vez!=8)
					{
						jogo[linha-64][coluna-48]='X';
					}
					else if(vez%2!=0)
					{
						jogo[linha-64][coluna-48]='O';
					}
					else if(vez==8)
					{
						jogo[linha-64][coluna-48]='X';
						imprime(jogo);
						if (verifica(jogo)==' ')
						{
							printf("Fim de jogo.\nEmpate.\n");
						}
						else
						{
							printf("Fim de jogo.\n O ganhador foi %c.\n", verifica(jogo));
						}	
					}
				}
				else
				{
					printf("\tEsta posição já está ocupada.\n\n");
					vez-=1;
				}
			 }
			else
			{
				printf("\tEsta posição não existe.\n\n");
				vez-=1;
			}
		}
		vez+=1;
	}

	return 0;
}

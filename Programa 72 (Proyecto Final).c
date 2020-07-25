#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

int clave();
void marco();
void gotoxy(int x, int y);
void nombre();
void capturar();
void mostrar();
void buscar();
void salir();

int cont=0;

struct TheMart
{
	char producto[30];
	int unidades;
	long long codigo;
	float precio, total;
}obj[20];

void main(void)
{	
	system("cls");
	int resp,R=2,alias,opc;
	system("cls");
	resp=clave();
	do
	{
		system("cls");
		if(resp==2)
			break;
		do
		{
			system("cls");
			system("COLOR 0F");
			marco();
			nombre();
			gotoxy(30,10);
			printf("_____________________________________________________________________");
			gotoxy(40,12);
			printf("1.-CAPTURAR");
			gotoxy(40,14);
			printf("2.-MOSTRAR");
			gotoxy(40,16);
			printf("3.-BUSCAR");
			gotoxy(40,18);
			printf("4.-SALIR");
			gotoxy(40,20);
			printf("\n\n\t\t\t\t\tSELECCIONE UNA OPCION(1-4): ");
			scanf("%d", &opc);
			switch(opc)
			{
				case 1:
					capturar();
					break;
				case 2:
					mostrar();
					break;
				case 3:
					buscar();
					break;
				case 4:
					R=1;
					salir();
			}
		}
		while(opc!=4);
		R=1; 
	}
	while(R==2);
	salir();
}

void capturar()
{
	system("cls");
	marco();
	nombre();
	gotoxy(30,10);
	printf("_____________________________________________________________________");
	if(cont<20)
	{
		fflush(stdin);
		gotoxy(40,12);
		printf("PRODUCTO: ");
		scanf("%[^\n]", &obj[cont].producto);
		gotoxy(40,14);
		printf("CODIGO: ");
		scanf("%lld", &obj[cont].codigo);
		gotoxy(40,16);
		printf("UNIDADES: ");
		scanf("%d", &obj[cont].unidades);
		gotoxy(40,18);
		printf("PRECIO UNIDAD: ");
		scanf("%f", &obj[cont].precio);
		obj[cont].total=obj[cont].precio*obj[cont].unidades;
		cont++;
	}
	else
	{
		gotoxy(40,12);
		printf("NO HAY ESPACIO DISPONIBLE...");
		getch();
	}
		
}

void mostrar()
{
	int i,a=20,unidades=0,efectivo,aleatorio,z;
	float subTotal=0,iva,TOTAL,cambio;
	srand(time(NULL));
	time_t o;
	system("cls");
	marco();
	nombre();
	gotoxy(30,10);
	printf("_____________________________________________________________________");
	if(cont!=0)
	{
		for(i=0;i<cont;i++)
		{
			system("COLOR F0");
			marco();
			nombre();
			gotoxy(30,10);
			printf("_____________________________________________________________________");
			gotoxy(44,11);
			printf("NUEVA THE MART DE MEXICO S DE RL DE CV");
			gotoxy(44,12);
			printf("NEXTENGO 78 STA.CRUZ ACAYUCAN 0277");
			gotoxy(44,13);
			printf("AZCAPOTZALCO MEX CDMX RFC NTM9709224W4");
			gotoxy(44,14);
			printf("\t\tUNIDAD LA CIMA");
			gotoxy(44,15);
			printf("AC.JUAN GIL PRECIADO # 1544 FRACC.");
			gotoxy(44,16);
			printf("LA CIMA ZAPOPAN, JALISCO C.P. 45130");
			gotoxy(44,17);
			printf("QUEJAS Y SUGERENCIAS 01 800 000 0096");
			gotoxy(44,19);
			printf("UNIDADES");
			gotoxy(53,19);
			printf("PRODUCTO");
			gotoxy(62,19);
			printf("CODIGO");
			gotoxy(72,19);
			printf("PRECIO");
			gotoxy(44,a);
			printf("%d", obj[i].unidades);
			gotoxy(53,a);
			printf("%s", obj[i].producto);
			gotoxy(62,a);
			printf("%lld", obj[i].codigo);
			gotoxy(72,a);
			printf("%f", obj[i].total);
			a++;
		}
		for(i=0;i<cont;i++)
		{
			subTotal=subTotal+obj[i].total;
			unidades=unidades+obj[i].unidades;	
		}
		iva=subTotal*.16;
		TOTAL=subTotal+iva;
		gotoxy(62,a);
		printf("TOTAL: \t%f", TOTAL);
		gotoxy(62,a+1);
		printf("EFECTIVO:\t");
		scanf("%d", &efectivo);
		gotoxy(62,a+1);
		printf("EFECTIVO:\t%d", efectivo);
		cambio=efectivo-TOTAL;
		gotoxy(62,a+2);
		printf("CAMBIO:\t%f", cambio);
		gotoxy(62,a+3);
		printf("IVA:\t%f", iva);
		gotoxy(44,a+4);
		printf("\t\tTOTAL EN LETRA");
		gotoxy(44,a+6);
		printf("\t\tARTICULOS VENDIDOS: %d", unidades);
		aleatorio=rand()%2;
		for(z=0;z<40;z++)
		{
			gotoxy(44+z,a+7);
			if(aleatorio==0)
				printf("%c",186);
			else if(aleatorio==1)
				printf("%c", 179);	
		}
		gotoxy(44,a+8);
		printf("\t\tComo te atendimos?");
		gotoxy(44,a+9);
		printf("\t\twww.miopiniontmmx,com");
		gotoxy(44,a+10);
		printf("REGIMEN OFICIAL PARA GRUPO DE SOCIEDADES");
		gotoxy(44,a+11);
		printf("COMPRA TAMBIEN EN THEMART.COM.MX");
		gotoxy(44,a+12);
		printf("REGIMEN OFICIAL PARA GRUPO DE SOCIEDADES");
  		o = time(NULL);
  		gotoxy(44,a+13);
   		printf("\t\t%s", asctime(localtime(&o)));
		getch();	
	}
	else
	{
		gotoxy(40,12);
		printf("\n\n\t\t\t\t\tEL ARREGLO ESTA VACIO...");
		getch();
	}
}


void buscar()
{
	system("cls");
	marco();
	nombre();
	gotoxy(30,10);
	printf("_____________________________________________________________________");
	int i;
	if(cont!=0)
	{
		int band=0;
		char l[30];
		fflush(stdin);
		gotoxy(40,12);
		printf("ESCRIBE EL NOMBRE DEL PRODUCTO A BUSCAR: ");
		scanf("%[^\n]", &l);
		for(i=0;i<cont;i++)
			if(strcmp(l,obj[i].producto)==0)
			{
				system("cls");
				marco();
				nombre();
				gotoxy(30,10);
				printf("_____________________________________________________________________");
				gotoxy(40,12);
				printf("CODIGO: %lld", obj[i].codigo);
				gotoxy(40,14);
				printf("UNIDADES: %d", obj[i].unidades);
				gotoxy(40,16);
				printf("PRECIO POR UNIDAD: %f", obj[i].precio);
				gotoxy(40,18);
				printf("TOTAL: %f", obj[i].total);
				band=1;
				getch();
			}
		if(band==0)
		{
			gotoxy(40,14);
			printf("NO EXISTE EL DATO...");
			getch();
		}
				
	}
	else
	{
		gotoxy(40,14);
		printf("NO HAY ELEMENTOS EN EL ARREGLO...");
		getch();
	}
		
}

void salir()
{
	system("cls");
	marco();
	nombre();
	gotoxy(34,16);
	printf("_______________________ADIOS______________________");
	printf("\n\n\n\n\n\n\n\n");
	
}
int clave()
{
	marco();
	int claver=1999,clave,resp,opor=0;
	gotoxy(43,12);
	printf("#############################");
	gotoxy(43,14);
	printf("INGRESE CLAVE DE ACCESO: ");
	scanf("%d", &clave);
	while(clave!=claver)
	{
		system("cls");
		opor=opor+1;
		if(opor==3)
		{
			system("cls");
			resp=2;
			return 2;
		}
		marco();
		gotoxy(43,12);
		printf("#############################");
		gotoxy(43,14);
		printf("INGRESE CLAVE DE ACCESO: ");
		scanf("%d", &clave);			
	}
}

void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon,dwPos);
}

void marco()
{
	int x1=0,x2=40,y1=0,y2=119,i=0;
	
	for(i=0;i<120;i++)
	{
		gotoxy(i,x1);
		printf("%c",250);
		gotoxy(i,x2);
		printf("%c",250);
	}
	for(i=0;i<40;i++)
	{
		gotoxy(y1,i);
		printf("%c",250);
		gotoxy(y2,i);
		printf("%c",250);
	}
	
}

void nombre()
{
	//T
	gotoxy(35,4);
	printf("%c", 219);
	gotoxy(35,5);
	printf("%c", 219);
	gotoxy(35,6);
	printf("%c", 219);
	gotoxy(35,7);
	printf("%c", 219);
	gotoxy(35,8);
	printf("%c", 219);
	gotoxy(36,4);
	printf("%c", 223);
	gotoxy(37,4);
	printf("%c", 223);
	gotoxy(38,4);
	printf("%c", 223);
	gotoxy(39,4);
	printf("%c", 223);
	gotoxy(40,4);
	printf("%c", 223);
	gotoxy(34,4);
	printf("%c", 223);
	gotoxy(33,4);
	printf("%c", 223);
	gotoxy(32,4);
	printf("%c", 223);
	gotoxy(31,4);
	printf("%c", 223);
	gotoxy(30,4);
	printf("%c", 223);
	//H
	gotoxy(43,4);
	printf("%c", 219);
	gotoxy(43,5);
	printf("%c", 219);
	gotoxy(43,6);
	printf("%c", 219);
	gotoxy(43,7);
	printf("%c", 219);
	gotoxy(43,8);
	printf("%c", 219);
	gotoxy(44,6);
	printf("%c", 223);
	gotoxy(45,6);
	printf("%c", 223);
	gotoxy(46,6);
	printf("%c", 223);
	gotoxy(47,6);
	printf("%c", 223);
	gotoxy(48,6);
	printf("%c", 223);
	gotoxy(49,4);
	printf("%c", 219);
	gotoxy(49,5);
	printf("%c", 219);
	gotoxy(49,6);
	printf("%c", 219);
	gotoxy(49,7);
	printf("%c", 219);
	gotoxy(49,8);
	printf("%c", 219);
	//E
	gotoxy(52,4);
	printf("%c", 219);
	gotoxy(52,5);
	printf("%c", 219);
	gotoxy(52,6);
	printf("%c", 219);
	gotoxy(52,7);
	printf("%c", 219);
	gotoxy(52,8);
	printf("%c", 219);
	gotoxy(53,4);
	printf("%c", 223);
	gotoxy(54,4);
	printf("%c", 223);
	gotoxy(55,4);
	printf("%c", 223);
	gotoxy(56,4);
	printf("%c", 223);
	gotoxy(53,6);
	printf("%c", 223);
	gotoxy(54,6);
	printf("%c", 223);
	gotoxy(55,6);
	printf("%c", 223);
	gotoxy(56,6);
	printf("%c", 223);
	gotoxy(53,8);
	printf("%c", 220);
	gotoxy(54,8);
	printf("%c", 220);
	gotoxy(55,8);
	printf("%c", 220);
	gotoxy(56,8);
	printf("%c", 220);
	//M
	gotoxy(62,4);
	printf("%c", 219);
	gotoxy(62,5);
	printf("%c", 219);
	gotoxy(62,6);
	printf("%c", 219);
	gotoxy(62,7);
	printf("%c", 219);
	gotoxy(62,8);
	printf("%c", 219);
	gotoxy(63,4);
	printf("%c", 219);
	gotoxy(64,5);
	printf("%c", 219);
	gotoxy(65,6);
	printf("%c", 219);
	gotoxy(66,6);
	printf("%c", 219);
	gotoxy(67,5);
	printf("%c", 219);
	gotoxy(68,4);
	printf("%c", 219);
	gotoxy(69,4);
	printf("%c", 219);
	gotoxy(69,5);
	printf("%c", 219);
	gotoxy(69,6);
	printf("%c", 219);
	gotoxy(69,7);
	printf("%c", 219);
	gotoxy(69,8);
	printf("%c", 219);
	//A
	gotoxy(72,4);
	printf("%c", 219);
	gotoxy(72,5);
	printf("%c", 219);
	gotoxy(72,6);
	printf("%c", 219);
	gotoxy(72,7);
	printf("%c", 219);
	gotoxy(72,8);
	printf("%c", 219);
	gotoxy(73,4);
	printf("%c", 223);
	gotoxy(74,4);
	printf("%c", 223);
	gotoxy(75,4);
	printf("%c", 223);
	gotoxy(76,4);
	printf("%c", 223);
	gotoxy(73,6);
	printf("%c", 223);
	gotoxy(74,6);
	printf("%c", 223);
	gotoxy(75,6);
	printf("%c", 223);
	gotoxy(76,6);
	printf("%c", 223);
	gotoxy(77,4);
	printf("%c", 219);
	gotoxy(77,5);
	printf("%c", 219);
	gotoxy(77,6);
	printf("%c", 219);
	gotoxy(77,7);
	printf("%c", 219);
	gotoxy(77,8);
	printf("%c", 219);
	//R
	gotoxy(80,4);
	printf("%c", 219);
	gotoxy(80,5);
	printf("%c", 219);
	gotoxy(80,6);
	printf("%c", 219);
	gotoxy(80,7);
	printf("%c", 219);
	gotoxy(80,8);
	printf("%c", 219);
	gotoxy(81,4);
	printf("%c", 219);
	gotoxy(82,4);
	printf("%c", 219);
	gotoxy(83,4);
	printf("%c", 219);
	gotoxy(84,5);
	printf("%c", 219);
	gotoxy(83,6);
	printf("%c", 219);
	gotoxy(82,6);
	printf("%c", 219);
	gotoxy(81,6);
	printf("%c", 219);
	gotoxy(81,7);
	printf("%c", 219);
	gotoxy(82,7);
	printf("%c", 220);
	gotoxy(83,8);
	printf("%c", 223);
	gotoxy(84,8);
	printf("%c", 220);
	//T
	gotoxy(91,4);
	printf("%c", 219);
	gotoxy(91,5);
	printf("%c", 219);
	gotoxy(91,6);
	printf("%c", 219);
	gotoxy(91,7);
	printf("%c", 219);
	gotoxy(91,8);
	printf("%c", 219);
	gotoxy(92,4);
	printf("%c", 223);
	gotoxy(93,4);
	printf("%c", 223);
	gotoxy(94,4);
	printf("%c", 223);
	gotoxy(95,4);
	printf("%c", 223);
	gotoxy(96,4);
	printf("%c", 223);
	gotoxy(97,4);
	printf("%c", 223);
	gotoxy(90,4);
	printf("%c", 223);
	gotoxy(89,4);
	printf("%c", 223);
	gotoxy(88,4);
	printf("%c", 223);
	gotoxy(87,4);
	printf("%c", 223);
	
	
	
}

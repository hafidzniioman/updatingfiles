#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int point1 = 0;
	int point2 = 0;
	int point3 = 0;

	struct 
	{
		char prodi[3];
		char nama[100];
		char nilai[3];
	}rekaman;

	struct 
	{
		char prodi[3];
		char nama[100];
		char nilai[3];
	}flag1;

	struct 
	{
		char prodi[3];
		char nama[100];
		char nilai[3];
	}flag2;

	struct 
	{
		char prodi[3];
		char nama[100];
		char nilai[3];
	}flag3;

	FILE *arsipMatkul;
	FILE *arsipMatkulUpdate;

	arsipMatkul = fopen("arsip_updating_file.dat", "r");
	arsipMatkulUpdate = fopen("arsipMatkulUpdate.dat", "w");

	fscanf(arsipMatkul, "%s %s %s \n", rekaman.prodi, rekaman.nama, rekaman.nilai);

	do{
		if (point3 == 0)
		{
			if (strcmp(rekaman.nilai, "75")==0)
			{
				point2 = 1;
				strcpy(flag3.prodi, rekaman.prodi);
				strcpy(flag3.nama, rekaman.nama);
				strcpy(flag3.nilai, rekaman.nilai);
			}else{
				point1 = 0;
				point3 = 0;

				fprintf(arsipMatkulUpdate, "%s %s %s\n", flag2.prodi, flag2.nama, flag2.nilai);
			}
		}else if(point1 == 1 && strcmp(rekaman.nilai, "75") !=0)
			{
				point3 = 1;
				strcpy(flag2.prodi, rekaman.prodi);
				strcpy(flag2.nama, rekaman.nama);
				strcpy(flag2.nilai, rekaman.nilai);
			}else if (strcmp(rekaman.nilai, "75")==0 && point1 == 0)
			{
				point1 = 1;
				strcpy(flag1.prodi, rekaman.prodi);
				strcpy(flag1.nama, rekaman.nama);
				strcpy(flag1.nilai, rekaman.nilai);
			}
			if (point1 == 1 && point2 == 1 && point3 == 1)
			{
				strcpy(flag2.nilai, "80");
				fprintf(arsipMatkulUpdate, "%s %s %s\n",flag1.prodi, flag1.nama, flag1.nilai );
				fprintf(arsipMatkulUpdate, "%s %s %s\n",flag2.prodi, flag2.nama, flag2.nilai );
				fprintf(arsipMatkulUpdate, "%s %s %s\n",flag3.prodi, flag3.nama, flag3.nilai );

				point1 = 1;
				point2 = 0;
				point3 = 0;

				strcpy(flag1.prodi, flag3.prodi);
				strcpy(flag1.nama, flag3.nama);
				strcpy(flag1.nilai, flag3.nilai);
			}
			else{
				if (point1 == 0)
				{
					fprintf(arsipMatkulUpdate, "%s %s %s\n", rekaman.prodi, rekaman.nama, rekaman.nilai );
				}
			}
			fscanf(arsipMatkul,"%s %s %s\n", rekaman.prodi, rekaman.nama, rekaman.nilai);

		}while(!feof(arsipMatkul));

		fclose(arsipMatkul);
		fclose(arsipMatkulUpdate);
		return 0;
	}
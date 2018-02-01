#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void sifre()
{
    FILE *sifre;

    char sifre_gir[20];
    char sifre_kontrol[20];
    char *sifre_pointer = sifre_gir;
    char *sifre_kontrol_pointer = sifre_kontrol;
    int size,i;

    sifre = fopen("sifre.txt","w+");
    if(sifre == NULL)
    {
        printf("DOSYA ACILAMADI !!!");
        exit(1);
    }

    printf("Bir sifre olusturun :");
    gets(sifre_pointer);
    size = strlen(sifre_pointer);

    for(i=size;i>=0;i--)
    {
        fputc(*(sifre_pointer + i),sifre);
    }
    password:
    printf("\nSifre giriniz :");
    gets(sifre_kontrol_pointer);

    for(i=0;i<20;i++)
    {
        if(*(sifre_pointer + i) == *(sifre_kontrol_pointer + i))
        {

                printf("\nGiris yapildi\n");
                printf("------------------\n\n\n");
                return ;


        }
        else
        {
                printf("\nGiris yapilamadi\n");
                printf("------------------\n\n\n");
                goto password;

        }


    }

    fclose(sifre);

}




typedef struct
{
    int red[5][50];
}kirmizi_matine;
typedef struct
{
    int green[5][50];
}yesil_matine;
typedef struct
{
    int blue[5][50];
}mavi_matine;
typedef struct
{
    char kirmizi_salon;
    char yesil_salon;
    char mavi_salon;
    kirmizi_matine kirmiz;
    yesil_matine yesil;
    mavi_matine mavi;
}salonlar;





int main()
{
    system("color 1e");
    sifre();

    salonlar salon;
    int a = 0, b = 0, c = 0, don = 0;
    int ogr;
    int ogr_ucreti;
    int tam_ucreti;
    int salon_giris;
    int matine_giris;
    int bilgilendirme;

    while(don == 0)
    {

        printf("\nred salonu ici '1'\nGreen salonu icin '2'\nBlue salonu icin '3'\nSalon seciniz :");
        scanf("%d",&salon_giris);
        printf("\n1. matine icin '1'\n2. matine icin '2'\n3. matine icin '3'\n4. matine icin '4'\n5. matine icin '5'\nMatine seciniz :");
        scanf("%d",&matine_giris);

        switch(salon_giris)
        {
        case 1:

            while(salon.kirmiz.red[matine_giris][a] == 1)
            {
                a++;
            }
            if(a == 50)
            {
                printf("%d. matine doludur.",matine_giris);
                continue;
            }
            salon.kirmiz.red[matine_giris][a] = 1;

            FILE *kirmizi_sat;
            kirmizi_sat = fopen("kirmizi_salon.txt","a");
            fprintf(kirmizi_sat,"matine :%d\nkoltuk : %d\n",matine_giris,a+1);
            fclose(kirmizi_sat);

            break;
        case 2:

            while(salon.yesil.green[matine_giris][b] == 1)
            {
                b++;
            }
            if(b = 50)
            {
                printf("%d. matine doludur.",matine_giris);
                continue;
            }
            salon.yesil.green[matine_giris][b] = 1;

            FILE *yesil_sat;
            yesil_sat = fopen("yesil_salon.txt","a");
            fprintf(yesil_sat,"Matine : %d\nkoltuk : %d",matine_giris,b+1);
            fclose(yesil_sat);

            break;
        case 3:
            while(salon.mavi.blue[matine_giris][c] == 1)
            {
                c++;
            }
            if(c = 50)
            {
                printf("%d. matine doludur.",matine_giris);
                continue;
            }
            salon.mavi.blue[matine_giris][c] = 1;

            FILE *mavi_sat;
            mavi_sat = fopen("mavi_salon.txt","a");
            fprintf(mavi_sat,"matine : %d\nkoltuk : %d\n",matine_giris,c+1);
            fclose(mavi_sat);

            break;
        default:
            printf("yanlis salon numarasi girdiniz");
            continue;

        }

        printf("\n\nUcretin Ailnmasi\n\n");
        printf("\nOgrenci bileti 20TL,Tam bileti 30TL\n");
        printf("Ogrenciyseniz 1'e basiniz\nogrenci degilseniz 2'ye basiniz :");
        scanf("%d",&ogr);
        switch(ogr)
        {
        case 1:
            ogr_ucreti++;
            break;
        case 2:
            tam_ucreti++;
            break;
        }

        printf("\n***********************************************************************\n");
        printf("Hasilat bilgileri icin herhangi bir tusa basiniz\nSalon ve matine secimleri icini 0t'e basiniz :");
        scanf("%d",&don);

    }

    FILE *hasilat;
    hasilat = fopen("hasilat.txt","w");
    if(hasilat == NULL)
    {
        printf("hasilat dosyasi acilamadi !!!\n");
        exit(1);
    }
    fprintf(hasilat,"ogrenci bileti : %d\ntam bilet : %d",ogr_ucreti,tam_ucreti);
    fclose(hasilat);

    printf("Hasilat bilgileri icin 1'e basiniz\nsalon bilgileri icin herhangi bir tusa basiniz :");
    scanf("%d",&bilgilendirme);

    switch(bilgilendirme)
    {
    case 1:
        fopen("hasilat.txt","r");

        fclose(hasilat);
        break;
    default:
        break;

    }

    return 0;
}

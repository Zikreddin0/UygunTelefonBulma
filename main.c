#include <stdio.h>
#include <math.h>

typedef struct {
    char isim[20];
    char model[20];
    float fiyat;
}Tel;
int main() {
    FILE*fp,*fp2;
    fp=fopen("C:\\Users\\LENOVO\\OneDrive\\Masaüstü\\FIYAT.txt","r");
    fp2 = fopen("C:\\Users\\LENOVO\\OneDrive\\Masaüstü\\ONERI.txt","w");
    Tel t1;
    if (!fp || !fp2) {
        printf("Dosya acma islemi hatayla sonuclandi!\n");
        return 1;
    }
    float ortalama =0;
    float fark;
    float toplam=0;
    int sayac=0;
    float min=9000000;
    while(fscanf(fp,"%s %s %f",t1.isim,t1.model,&t1.fiyat)==3)
    {
        sayac++;
        toplam += t1.fiyat;
    }
    rewind(fp);
    ortalama=toplam/sayac;
    while(fscanf(fp,"%s %s %f",t1.isim,t1.model,&t1.fiyat)==3)
    {
        fark =fabs(ortalama-t1.fiyat);
        if (fark<min) {
            min=fark;
        }
    }
    rewind(fp);
    fprintf(fp2,"Ortalama:%.3f\n",ortalama);
    fprintf(fp2,"Onerdigimiz cep telefonu:\n");
    while(fscanf(fp," %s %s %f",t1.isim,t1.model,&t1.fiyat)==3) {

        if (fabs(fabs(ortalama - t1.fiyat) - min) < 0.001){
            fprintf(fp2,"%s %s %.2f\n",t1.isim,t1.model,t1.fiyat);
        }
    }
    fclose(fp);
    fclose(fp2);
    return 0;
}
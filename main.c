#include <stdio.h>
#include <math.h>

typedef struct {
    char isim[20];
    char model[20];
    float fiyat;
}Tel;
int main() {
    FILE*fp,*fp2;
    fp=fopen("C:\\Users\\LENOVO\\OneDrive\\Masaüstü\\FIYAT.txt","r");//dosyalarımızın yolunu ve modunu ayarladık
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
    /*sayac değişkenini tanımlamamızın sebebimiz programi manuellikten kurtarip daha kullanışlı bir hale getirmek bu sayede dosyada kaç satır 
    yani telefon var ise o kadar deger alıp ortalamaı bulmayı sağladı*/
    float min=9000000;
    /*döngülere başlamadan:
    taslak projemizde şartımızı !feof(fp) ile kurmuştuk ancak bu durum ortalamaya yanlış değerler atamamıza sebep oluyordu  bizde şöyle düşündük:
    while dan istediğimiz şeyi şarta bağlayıp okutma 
    başarılı bir şekilde oluyor ise devam et değilse dosya bitmiş demektir ve okumayı bırakacak*/
    while(fscanf(fp,"%s %s %f",t1.isim,t1.model,&t1.fiyat)==3)// dosya her bir satırda 3 şey okumalı isim,model,fiyat her satır başına 3 kere başarılı okuma gerçekleştirmeli
    {
        sayac++;
        toplam += t1.fiyat;
    }
    rewind(fp);
    ortalama=toplam/sayac;
    while(fscanf(fp,"%s %s %f",t1.isim,t1.model,&t1.fiyat)==3)//bu döngünün amacı en küçük farkı bulmak
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

        if (fabs(fabs(ortalama - t1.fiyat) - min) < 0.001){//eğer fark değeri ile min değeri birbirine eşitse veya 0 a yakınsa aradığımız değer odur
            fprintf(fp2,"%s %s %.2f\n",t1.isim,t1.model,t1.fiyat);
        }
    }
    fclose(fp);
    fclose(fp2);
    return 0;
}

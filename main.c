#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
///fonksiyonları tanımladım
int anamenu(void);
void firmagirisimenu(void);
void musterigirisimenusu(void);
void rezervasyonyap(void);
void seferno(void);
void seferbaslangicsaati(void);
void sefervarissaati(void);
void seferbaslangicsehri(void);
void sefervarissehri(void);
void thasilat(void);
void kisibasiucret(void);
void otobusekle(void);
void seferkoltukbilgisi(void);
void seferlerilistele(void);
void rezervasyongoster(void);
///değişkenleri global olarak tanımladım
char modeldizisi[50][50],seferkayit[50][6],seferbsaati0[50][50],sefervsaati[50][50],seferbaslangicsehri0[50][50],sefervarissehri0[50][50],herhangi,rezervasyonno[50][8],ad[50][50],soyad[50][50],onay;
int sefersecim=0,sefersecim2[50],       nosayaci0=0,personelsayaci=0,kapasitesayaci=0,modelsayaci=0,bsehrisayaci=0,vsehrisayaci=0,hasilatsayaci=0,ucretsayaci=0,personeldizisi[50],kapasitedizisi[50],otobusnodizisi[50],sefernosayac=0,seferbsayaci=0,sefervsayaci=0,kacotobusvar=0,kacrezervasyonvar=0,adsayac=0,soyadsayaci=0,koltuksayac=0,rezervasyonsecim,koltuksecimsayaci=0,sefersecim2sayaci=0,hangiotobus=0,koltuk[50][50]={0},koltuksayisi=0,koltuksecim[50];
float                                                           hasilat[50],kisibasiucret0[50];

int main(int argc, const char * argv[]) {
    anamenu();///ana menü fonksiyonuna yönlendirdim

///Bilgilendirme->Bilgileri hafızaya diziler ile aldım ve her bilgiyi bir diziye atadım.Burada hangi bilgi hangi otobüse ait olduğunu bilmek için ise dizi indisini kullandım.Mesala 0. indis 1.otobüsün bilgilerini taşıyor yani 3. otobüsün bilgilerini dizilerin 2.indisi taşıyor.
    
    return 0;
}
int anamenu(){
Menu1:
    printf("ANA MENÜ\n");
    printf("1-Firma Girişi\n");
    printf("2-Müşteri Girişi\n");
    printf("3-Çıkış\n");
    printf("lütfen bir seçim yapınız-->");
    char girisd;
    scanf("%s",&girisd);
    switch (girisd) {
        case '1':
        {
            system("clear");
            firmagirisimenu();
            break;
        }
        case '2':{
            system("clear");
            musterigirisimenusu();
            break;
        }
        case '3':{
            printf("Hoşça kalın.\n");
            return 0;
            break;
        }
        default:{
            system("clear");
            printf("Hatalı bir giriş yaptınız!!!-Tekrar deneyiniz\n");
            goto Menu1;
            break;
        }
}
    return 0;
}

void firmagirisimenu(){
    
Menu:
    printf("1-Otobüs Ekle\n");
    printf("2-Sefer Bilgisi Ekle\n");
    printf("3-Sefer/Koltuk Bilgisi\n");
    printf("4-Bir Üst Menüye Dön\n");
    printf("lütfen bir seçim yapınız-->");
    char firmagirisd;
    scanf("%s",&firmagirisd);
    switch (firmagirisd) {
        case '1':
        {   system("clear");
            otobusekle();
            kacotobusvar+=1;///ilerde sefer listelerken for döngüsü için kaç otobus oldugunu saydırıyorum
            printf("\n");
            
            printf("firma menüsüne dönmek için bir tuş giriniz->");
            scanf("%s",&herhangi);
            switch (herhangi) {
            default:{
             system("clear");
             firmagirisimenu();
             
                    break;
                }
            }
 
            break;
        }
        case '2':{
            system("clear");
            int otobusnocevap;
            printf("Sefer bilgisi eklemek istediğiniz otobüs numarası giriniz->");
            scanf("%d",&otobusnocevap);
///alt kısımda bir eksiltmemizin nedeni 2.otobüsün bilgileri 1. indise kayıt edileceğinden
            sefernosayac=otobusnocevap-1;
            seferbsayaci=otobusnocevap-1;
            sefervsayaci=otobusnocevap-1;
            bsehrisayaci=otobusnocevap-1;
            vsehrisayaci=otobusnocevap-1;
            hasilatsayaci=otobusnocevap-1;
            ucretsayaci=otobusnocevap-1;
 
            seferno();
            seferbaslangicsaati();
            sefervarissaati();
            seferbaslangicsehri();
            sefervarissehri();
            thasilat();
            kisibasiucret();
            printf("\n\n\n");
            printf("firma menüsüne dönmek için bir tuş giriniz->");
            scanf("%s",&herhangi);
            switch (herhangi) {
            default:{
             system("clear");
             firmagirisimenu();
             
                    break;
                }
            }
            break;
        }
        case '3':{
            system("clear");
            seferkoltukbilgisi();
            printf("firma menüsüne dönmek için bir tuş giriniz->");
            scanf("%s",&herhangi);
            switch (herhangi) {
            default:{
             system("clear");
                anamenu();
                    break;
                }
            }

            break;
        }
        case '4':{
            system("clear");
            anamenu();
            break;
        }
        default:{
            system("clear");
            printf("Hatalı bir giriş yaptınız!!!-Tekrar deneyiniz\n");
            goto Menu;
            break;
        }
        }
    
}

void otobusekle(){
otobusnodizisi[nosayaci0]=nosayaci0+1;///otomatik olarak otobus numaraları atanıyor
nosayaci0++;

printf("%d.otobüsün kapasitesini giriniz->",kapasitesayaci+1);
scanf("%d",&kapasitedizisi[kapasitesayaci]);///kapasite alınıyor
    kapasitesayaci++;
    if (kapasitedizisi[kapasitesayaci]<=30) {///personel sayısı atanıyor
        personeldizisi[personelsayaci]=2;
    }
    else{
        personeldizisi[personelsayaci]=3;
    }
    personelsayaci++;

printf("Otobüs modeli giriniz:");///otobus modeli alınıyor
scanf("%s",modeldizisi[modelsayaci]);
modelsayaci++;
printf("\n\n\n");
   
 
    
    
}
void seferno(){///sefer numarası atanıyor

 seferkayit[sefernosayac][0]=7;
 seferkayit[sefernosayac][1]=0;

     srand(time (NULL));
     int i,j;
     for (i=sefernosayac; i<sefernosayac+1; i++) {
         for (j = 2; j<6; j++) {
             seferkayit[i][j]=rand()%16;
         }

     }
     
     for(int y=sefernosayac;y<sefernosayac+1;y++){
         printf("%d.Otobusün sefer numarası:",y+1);
         for(int k=0;k<6;k++){
         printf("%X",seferkayit[y][k]);
     }printf("\n");
     }
 
    sefernosayac++;
    
}

void seferbaslangicsaati()
{///sefer başlangıc ve bitiş sürelerini kullanıcının girdiği gibi aldım (dakikanın öğrenci numarası olma özelliğini malesef ekleyemedim)
    printf("Sefer başlangıç saati giriniz->");
    scanf("%s",seferbsaati0[seferbsayaci]);
    seferbsayaci++;
}

void sefervarissaati()
{
    printf("Sefer varış saati giriniz->");
    scanf("%s",sefervsaati[sefervsayaci]);
    sefervsayaci++;
}

void seferbaslangicsehri()
{
    printf("Sefer başlangıç şehri giriniz->");
    scanf("%s",seferbaslangicsehri0[bsehrisayaci]);
    bsehrisayaci++;
}
void sefervarissehri()
{
    printf("Sefer Varış şehri giriniz->");
    scanf("%s",sefervarissehri0[vsehrisayaci]);
    vsehrisayaci++;
}

void thasilat()
{
    printf("İstenilen toplam hasılat değerini giriniz->");
    scanf("%f" ,&hasilat[hasilatsayaci]);
    hasilatsayaci++;
}
void kisibasiucret()
{
kisibasiucret0[ucretsayaci]=hasilat[ucretsayaci]/kapasitedizisi[ucretsayaci];
printf("Kişi başı ücret->%.2f\n",kisibasiucret0[ucretsayaci]);
}

void seferkoltukbilgisi()
///burada sefer koltuk bilgisi almak yerine seçtirme ile yaptım
{   for(int y=0;y<sefernosayac;y++){
    printf("%d.Otobusün sefer nosu:",y+1);
    for(int k=0;k<6;k++){
    printf("%X",seferkayit[y][k]);
}printf("\n");

}
    printf("Sefer numarasını seçiniz ->");
    scanf("%d",&sefersecim);

        printf("Otobusün\nNumarası:->%d\nModeli:->%s\nKapasitesi:->%d\nPersonel sayısı:->%d\nSefer başlangıç saati->%s\nSefer varış saati->%s\nSefer başlangiç şehri->%s\nSefer variş şehri->%s\nKişi başı ücret->%.2f\n",otobusnodizisi[sefersecim-1],modeldizisi[sefersecim-1],kapasitedizisi[sefersecim-1],personeldizisi[sefersecim-1],seferbsaati0[sefersecim-1],sefervsaati[sefersecim-1],seferbaslangicsehri0[sefersecim-1],sefervarissehri0[sefersecim-1],kisibasiucret0[sefersecim-1]);

    printf("\n\n\n");
}
void musterigirisimenusu()
{

    
    printf("1-Seferleri listele\n");
    printf("2-Sefer Rezervasyon yap\n");
    printf("3-Rezarvasyon göster\n");
    printf("4-Üst menüye dön\n");
    printf("lütfen bir seçim yapınız-->");
    char girisd1;
    scanf("%s",&girisd1);
    switch (girisd1) {
        case '1':
        {   system("clear");
            seferlerilistele();
            printf("Müşteri giriş menüsüne gitmek için herhangi bir tuş giriniz->");
            scanf("%s",&herhangi);
            switch (herhangi) {
            default:{
                system("clear");
                musterigirisimenusu();
                    break;
                }
            }
            
            break;
        }
        case '2':{
            system("clear");
            rezervasyonyap();
            printf("Müşteri giriş menüsüne gitmek için herhangi bir tuş giriniz->");
            scanf("%s",&herhangi);
            switch (herhangi) {
            default:{
                system("clear");
                musterigirisimenusu();
                    break;
                }
            }
            break;
        }
        case '3':{
            system("clear");
            rezervasyongoster();
            printf("Müşteri giriş menüsüne gitmek için herhangi bir tuş giriniz->");
            scanf("%s",&herhangi);
            switch (herhangi) {
            default:{
                system("clear");
                musterigirisimenusu();
                    break;
                }
            }
            break;
        }
        case '4':{
            system("clear");
            anamenu();
        }
    }

}
void seferlerilistele()
{
    for (int i=0; i<nosayaci0; i++) {
        printf("%d.Otobüsün\nNumarası:->%d\nModeli:->%s\nKapasitesi:->%d\nPersonel sayısı:->%d\nSefer başlangıç saati->%s\nSefer varş saati->%s\nSefer baslangiç şehri->%s\nSefer varış şehri->%s\nKişi başı ücret->%.2f\n",i+1,otobusnodizisi[i],modeldizisi[i],kapasitedizisi[i],personeldizisi[i],seferbsaati0[i],sefervsaati[i],seferbaslangicsehri0[i],sefervarissehri0[i],kisibasiucret0[i]);
        printf("\n");
    }
        
}


void rezervasyonyap()
{
    for(int i=0;i<kacotobusvar;i++){
        printf("%d.Otobusün sefer numarası:",i+1);
        for(int k=0;k<6;k++){
        printf("%X",seferkayit[i][k]);
    }
        printf("\n");
    }
        printf("Sefer numarasını seçiniz ->");
        scanf("%d",&sefersecim2[sefersecim2sayaci]);
    koltuksayisi=kapasitedizisi[sefersecim2[sefersecim2sayaci]-1];///koltuk sayısı alınıyor
   
    printf("Adinizi giriniz->");
    scanf("%s",ad[adsayac]);
    
    printf("Soyadınızı giriniz->");
    scanf("%s",soyad[soyadsayaci]);
    
    
    for (int i=0; i<koltuksayisi; i++) {///olan tüm koltuklar yazdırıldı
        if (koltuk[sefersecim2[sefersecim2sayaci]-1][i]==1) {
            continue;
        }
        printf("%d.koltuk-> \n",i+1);
        
    }
printf("Rezervasyon yaptırmak istediğiniz koltuğun numarasını yazınız->");
scanf("%d",&koltuksecim[kacrezervasyonvar]);
    koltuk[sefersecim2[sefersecim2sayaci]-1][koltuksecim[kacrezervasyonvar]-1]=1;
///tüm koltukar 0 seçilen koltuk 1 oldu
    for (int i=0; i<koltuksayisi; i++)
    {
        printf("%d.koltuk->",i+1);
        
        if (koltuk[sefersecim2[sefersecim2sayaci]-1][i]==1) {
            printf("X");
        }
        printf("\n");
    }
  
    printf("İşaretlenen koltuğa rezervasyon yapmak istediğinizden emin misiniz");
    scanf("%s",&onay);
    switch (onay)
    {
        case 'E':
        case 'e':{

            for (int i=kacrezervasyonvar; i<=kacrezervasyonvar; i++) {
                for (int j=0; j<8; j++) {
                    rezervasyonno[i][j]=rand()%16;
                }
            }

            printf("\n");
            
            for(int i=kacrezervasyonvar; i<=kacrezervasyonvar; i++){
                printf("Rezervasyon numaranız->:");
                for(int k=0;k<8;k++){
                printf("%X",rezervasyonno[i][k]);
                }
            }
            printf("\n");
            ///evet dedikten sonra sayaçları artırdım
            adsayac++;
            soyadsayaci++;
            kacrezervasyonvar++;
            koltuksecimsayaci++;
            sefersecim2sayaci++;
            break;

        }
        case 'H':
        case 'h':{
            printf("Rezervasyonunuz iptal edilmiştir.\n");
            break;
        }
           
        default:
            break;
    }
 
 }
    
void rezervasyongoster()
{
  
    for (int i=0; i<kacrezervasyonvar; i++) {
        printf("%d.-->",i+1);
        for (int j=0; j<8; j++) {
            printf("%X",rezervasyonno[i][j]);
        }
        printf("\n");
    }
///burada da rezervasyon seçme mantığını kullandım
    printf("Yukardakilerden  hangisi sizin rezervasyon numaranız->");
    scanf("%d",&rezervasyonsecim);
   
    hangiotobus=sefersecim2[rezervasyonsecim-1];
    hangiotobus--;///hangi otobüsun sefer bilgilerini çağırmam gerektiğini böyle öğrendim
    
    
    printf("Adınız->%s\t",ad[rezervasyonsecim-1]);
    printf("Soyadınız->%s\t",soyad[rezervasyonsecim-1]);
    printf("Koltuk numaranız->%d\n",koltuksecim[rezervasyonsecim-1]);
printf("%d.Otobüsün\nNumarası:->%d\nModeli:->%s\nKapasitesi:->%d\nPersonel sayısı:->%d\nSefer başlangıç saati->%s\nSefer varış saati->%s\nSefer baslangiç şehri->%s\nSefer variş şehri->%s\nKişi başı ücret->%.2f\n",hangiotobus+1,otobusnodizisi[hangiotobus],modeldizisi[hangiotobus],kapasitedizisi[hangiotobus],personeldizisi[hangiotobus],seferbsaati0[hangiotobus],sefervsaati[hangiotobus],seferbaslangicsehri0[hangiotobus],sefervarissehri0[hangiotobus],kisibasiucret0[hangiotobus]);
}

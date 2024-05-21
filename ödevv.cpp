#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <windows.h>
//Bakiye icin kuyruk tanimlamasi
typedef struct KUYRUK {
    int sayi;
    struct KUYRUK *sonraki;
} kuyruk;

kuyruk *ilk = NULL, *son, *yeni, *sil;

enum renkler {
    kirmizi=1, siyah=2 }; //Renk oyununda renkleri tanimlayan veri yapisi

struct yigin{//Token biriktirmek icin yiginn tanimlamasi
    int token;
    struct yigin *onceki;
    };
    typedef struct yigin *node;
    node tepe=NULL;

void push(node etkin){ // Yigin icin push fonksiyonu
    if(tepe==NULL){ //Yigin bos ise
    tepe=etkin;
    tepe->onceki=NULL;
    }
    else{//yigin dolu ise
    etkin->onceki=tepe;
    tepe=etkin;
    }
}

//Bakiyeye ekleme yapan kuyruk yapisi
void ekle(int sayi) {
    yeni = (kuyruk*) malloc(sizeof (kuyruk));
    yeni->sayi = sayi;
    yeni->sonraki = NULL;

    if (ilk == NULL) {
        ilk = (kuyruk *) malloc(sizeof (kuyruk));
        ilk = yeni;
        son = ilk;
    } else {
        son->sonraki = yeni;
        son = son->sonraki;
    }

}
//Bakiyeyi sifirlamak i�in kullandigimiz kuyruk yapisi
void cikar() {
    if (ilk == NULL) {
    } else {
        sil = (kuyruk*) malloc(sizeof (kuyruk));
        sil = ilk;
        ilk = ilk->sonraki;
        free(sil);
    }

}
//Guncel bakiyeyi gosteren fonksiyon
void listele() {
    if (ilk == NULL) {
        printf("Kuyruk Bos\n");
    } else {
        kuyruk *gecici = ilk;
        while (gecici != NULL) {
            printf("\nBakiyeniz: $%d ", gecici->sayi);
            gecici = gecici->sonraki;
        }
        printf("\n");
    }

}
int kazandiniz(int k){
if(k>1){
    kazandiniz(k-1);
    printf("** ");
    //Sleep(250);
}
}
//RULET basligi fonksiyonu
void rulet_basligi(void);
//rulet cevirme fonksiyonu
int rulet_cevir(void);

int oyun(int o){
if(o>1){
    oyun(o-1);
    //degiskenler
int bahismodu;
int duzbahis, yatirilan, parite;
int sayi;
int bakiye;
int renkbahis;
node etkin;

//enum renkler;

//diziler
int kirmizi[18]={1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
int siyah[18]={2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};

//Hosgeldiniz yaisi ve baslik
printf("***\n");
printf("***\n");
rulet_basligi();
printf("\n***\n");
printf("***\n");


//Oyun hakkinda aciklamalar
printf("CASINO'ya hosgeldiniz\n");
printf("\nHer girisinizde hesabiniza 100$ bakiye tanimlanir\n");
printf("Casino'muzda 3 tip oyun oynayabilirsiniz\n\n");
printf("1) Duz Bahis oyunu: Bir sayi secersiniz. Yuksek risk! Yuksek kazanc! (1den 35e kadar)\n\n");
printf("2) Renk oyunu: Bir renk seciniz(K veya S)\n Kirmizi numaralar  1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36\n Siyah numaralar 2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35\n\n");
printf("3) Tek-Cift oyunu: Tek veya Cift seciniz (1 veya 2)");


//oyun modu se�imi ve bakiye tanimi
printf("\nLutfen oynamak istediginiz bahis turunu seciniz.1, 2 veya 3'e basiniz> ");
scanf("%d", &bahismodu);
bakiye=100;


//Kazandikca oyunun d�nmesini saglayan dongu
while(bakiye>0)
{
    if (bahismodu==1)       //Duz bahis modu
       {
        printf("\nHer sey kazanmak icin degil mi? :)\n 1'den 36'ya kadar sayi seciniz> ");
        scanf("%d", &duzbahis);
        x1:
        printf("Ne kadar para yatirmak istersiniz? Odemeler 1'e 35 yapilir> ");
        scanf("%d", &yatirilan);
        if(yatirilan>bakiye){
            printf("Bakiyeniz: $%d, lutfen uygun bir para yatiriniz.\n",bakiye);
            goto x1;
        }
        printf("\nHesabinizdan $%d , %d numaraya yatirildi", yatirilan, duzbahis);
        printf("\nRuleti cevirmek icin ENTER'a basiniz. Ellerini ac ve dua et! :)");
        getchar();
        getchar();
        rulet_cevir();
                if (sayi==duzbahis){
                   bakiye += (yatirilan*35);
                   cikar();
                   printf("Tebrikler Kazandiniz! Hesabiniza $%d para tanimlandi.\n", yatirilan*35);
                   kazandiniz(8);
                   ekle(bakiye);
                   listele();
                   push(etkin);
                   }
                else{
                   bakiye -= yatirilan;
                   cikar();
                   printf("Uzgunuz. $%d kaybettiniz.\n", yatirilan);
                   ekle(bakiye);
                   listele();
                   push(etkin);
       }
       }
     else if (bahismodu==2)         //Kirmizi veya siyah renk bahis modu
          {
           printf("\nTamam. Bir renk seciniz. Kirmizi icin 1'e Siyah icin 2'ye basiniz> ");
           scanf("%d", &renkbahis);
           x2:
           printf("\nNe kadar para yatirmak istersiniz? Odemeler 1'e 1 yapilir> ");
           scanf("%d", &yatirilan);
           if(yatirilan>bakiye){
            printf("Bakiyeniz: $%d, lutfen uygun bir para yatiriniz.\n",bakiye);
            goto x2;
        }
           printf("\nHesabinizdan $%d , %d numaraya yatirildi", yatirilan, renkbahis);
           printf("\nRuleti cevirmek icin ENTER'a basiniz. Ellerini ac ve dua et! :)");
           getchar();
           getchar();
           rulet_cevir();
                if (renkbahis==1)
                    {
                    if (sayi==kirmizi[18])
                      {bakiye += yatirilan;
                       cikar();
                       ekle(bakiye);
                       printf("Tebrikler Kazandiniz! Hesabiniza $%d para tanimlandi,\n", yatirilan);
                       kazandiniz(8);
                       listele();

                       }
                    else{
                       bakiye -= yatirilan;
                       cikar();
                       ekle(bakiye);
                       printf("Uzgunuz. $%d kaybettiniz.\n", yatirilan);
                       listele();
                    }
                    }
                 if (renkbahis==2)
                    {
                    if (sayi==siyah[18]){
                       bakiye += yatirilan;
                       cikar();
                       ekle(bakiye);
                       printf("Tebrikler Kazandiniz! Hesabiniza $%d para tanimlandi.\n", yatirilan);
                       kazandiniz(5);
                       listele();}
                    else{
                       bakiye -= yatirilan;
                       cikar();
                       ekle(bakiye);
                       printf("Uzgunuz. $%d kaybettiniz.\n", yatirilan);
                       listele();
                    }
                    }
          }
     else           //Tek ve �ift bahis modu
         {  printf("Tamam. Tek icin 1'e Cift icin 2'ye basiniz. Seciminizi bilgece yapiniz :)> ");
            scanf("%d", &parite);
            x3:
            printf("\nNe kadar para yatirmak istersiniz? Odemeler 1'e 1 yapilir> ");
            scanf("%d", &yatirilan);
            if(yatirilan>bakiye){
            printf("Bakiyeniz: $%d, lutfen uygun bir para yatiriniz.\n",bakiye);
            goto x1;
        }
                  if (parite==1){
                     printf("\nTek sayilara $%d yatirdiniz", yatirilan);}
                  else{
                      printf("\nCift sayilara $%d yatirdiniz", yatirilan);}
            printf("\nRuleti cevirmek icin ENTER'a basiniz. Ellerini ac ve dua et! :)");
            getchar();
            getchar();
            rulet_cevir();
                   if (parite==1)
                      {
                        if (sayi%2==1)
                          {bakiye += yatirilan;
                          cikar();
                           printf("Tebrikler Kazandiniz! Hesabiniza $%d para tanimlandi.\n", bakiye);
                           kazandiniz(8);
                           ekle(bakiye);
                           listele();}
                        else{
                           bakiye -= yatirilan;
                           cikar();
                           printf("Uzgunuz. $%d kaybettiniz.\n", yatirilan);
                           ekle(bakiye);
                           listele();
                        }
                      }
                   else{
                         if (sayi%2==0)
                          {bakiye += yatirilan;
                           cikar();
                           printf("Tebrikler Kazandiniz! Hesabiniza $%d para tanimlandi.\n", bakiye);
                           kazandiniz(8);
                           ekle(bakiye);
                           listele();}
                        else{}
                           bakiye -= yatirilan;
                           cikar();
                           printf("Uzgunuz. $%d kaybettiniz.\n", yatirilan);
                           ekle(bakiye);
                           listele();
                           }
         }

}






getchar();
getchar();
return (0);
}
}

int main (void) //main fonksiyonu
{
oyun(10);

}


void rulet_basligi(void)
{
    printf("       \n");
    printf("      *   *     *      *  *        * * * *  * * * * *    \n");
    printf("      *     *   *      *  *        *            *      \n");
    printf("      *   *     *      *  *        *            *\n");
    printf("      *   *     *      *  *        * * * *      * \n");
    printf("      *    *    *      *  *        *            *  \n");
    printf("      *     *     *   *   * * * *  * * * *      *  \n");
    printf("                           ");
}


int rulet_cevir(void)
{
    int sayi;
    srand(time(NULL));
    sayi=1+(rand()%36);
    printf("Top yere dustu * %d *\n", sayi);
    return sayi;
}

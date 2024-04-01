#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rastgelesayi() {
  int result = 0;
  srand(time(NULL));
  result = rand() % 3 + 1;
  return result;
}

/*
1 - Artık yıl : kullanıcı bir yıl girecek ve bunun artık yol olup olmadığı geri
dönecek
2 - girilen sayıların toplamını bulma : 0 girilene kadar girilen tüm
sayıları toplayan bir döngü 3 -girilen rakamı veya sayıyı tersten  yazdıran
fonksiyon...
*/

void mesaj(char *msg) { printf("%s\n", msg); }
// Kullanıcıdan round için bir sayı istenecek ve o kadar raund oynanacak
// kullanıcının ismi sorulacak ve hoşgeldin kısmına o isim eklenecek.
int main() {
  int OyuncuSecimi, BilgisayarSecimi, Sonuc;
  int round = 0;
  int playerWins = 0; // 1
  int computerWins = 0;
  int draw = 0;
  char *OyuncuIsmi;
  mesaj("Lutfen ismini bahsediniz...");
  scanf("%s", OyuncuIsmi); // array bir pointer'dır
  printf("Tas Kagit Makas Oyununa Hosgeldiniz %s \n", OyuncuIsmi);
  mesaj("Lutfen kac round oynamak istediginizi giriniz");
  scanf("%d", &round);

  do {

    for (int i = 0; i < round; i++) {

      mesaj("Lutfen Tas Kagit Makas arasinda seciminizi yapiniz:");
      mesaj("1. Tas");
      mesaj("2. Kagit");
      mesaj("3. Makas");
      scanf("%d", &OyuncuSecimi);

      if (OyuncuSecimi < 1 || OyuncuSecimi > 3) {
        mesaj("Lutfen 1 ve 3 arasinda bir deger giriniz\a");
        return -1;
      }

      BilgisayarSecimi = rastgelesayi();

      if (OyuncuSecimi == BilgisayarSecimi)
        Sonuc = 0;
      else if ((OyuncuSecimi == 1) && (BilgisayarSecimi == 3)) {
        Sonuc = 1;
      } else if ((OyuncuSecimi == 2) && (BilgisayarSecimi == 1)) {
        Sonuc = 1;

      } else if ((OyuncuSecimi == 3) && (BilgisayarSecimi == 2))
        Sonuc = 1;

      else
        Sonuc = -1;

      if (Sonuc == 0) {
        mesaj("Berabere \n");
        draw++;
      }

      else if (Sonuc == 1) {
        mesaj("Oyuncu Kazandi \n");
        playerWins++;
      } else {
        mesaj("Bilgisayar kazandi \n");
        computerWins++;
      }
    }
    if (playerWins > computerWins) {
      printf("Oyun bitti ve Oyuncu Kazandi Puani = %d \n", playerWins);
    } else if (computerWins > playerWins) {
      printf("Oyun bitti ve AI kazandi Puani = %d \n", computerWins);
    } else if (computerWins == playerWins) {
      mesaj("Kazanan olmadi");
    } else
      mesaj("Yok anasinin nikahi");

    draw = playerWins = computerWins = 0;
    getchar(); // buffer tazeleme
    mesaj("Tekrardan oynamak ister misiniz?,Y veya y yazarak tekrardan "
          "oynabilirsiniz \n");
  } while (getc(stdin) == 'y' || getc(stdin) == 'Y'); // true -> false
  mesaj("Nasil yendim ama");
  return 0;
}
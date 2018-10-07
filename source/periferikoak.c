/*-------------------------------------
periferikoak.c
-------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include "definizioak.h"


int tekla; //sakatutako tekla gordetzeko aldagaia



int TeklaDetektatu() 
{
	//TRUE itzultzen du teklaren bat sakatu dela detektatzen badu
	if ((~TEKLAK_DAT & 0x03ff)!=0) return 1;
	else return 0;

}

int SakatutakoTekla() //Sakatzen den teklaren identifikazioa egiten du.
{

if ((TEKLAK_DAT & 0x0001)==0) return A;
else if ((TEKLAK_DAT & 0x0002)==0) return B;
else if ((TEKLAK_DAT & 0x0004)==0) return SELECT;
else if ((TEKLAK_DAT & 0x0008)==0) return START;
else if ((TEKLAK_DAT & 0x0010)==0) return ESKUBI;
else if ((TEKLAK_DAT & 0x0020)==0) return EZKER;
else if ((TEKLAK_DAT & 0x0040)==0) return GORA;
else if ((TEKLAK_DAT & 0x0080)==0) return BEHERA;
else if ((TEKLAK_DAT & 0x0100)==0) return R;
else if ((TEKLAK_DAT & 0x0200)==0) return L;


}

void konfiguratuTeklatua(int TEK_konf)
{
	TEKLAK_KNT=TEKLAK_KNT | TEK_konf;
	//Teklatuaren konfigurazioa bere S/I erregistroak aldatuz
}

void konfiguratuTenporizadorea(int Latch, int TENP_konf) //Latch guk egindako kalkulua izango da eta TENP_Konf kontagailu martxan jartzeko aktibatu beharreko bita da, 7.bita hain zuzen.
{
	//Tenporizadorearen konfigurazioa bere S/I erregistroak aldatuz
	DENB0_DAT=Latch;
	DENB0_KNT= TENP_konf | DENB0_KNT;

}

void TekEtenBaimendu()
{
	//Teklatuaren etenak baimendu
	//Lan hau burutzeko lehenengo eten guztiak galarazi behar dira eta bukaeran baimendu 
	IME=0;
	IE = IE | 0x1000;
	IME=1;
}

void TekEtenGalarazi()
{

	//Teklatuaren etenak galarazi
	//Lan hau burutzeko lehenengo eten guztiak galarazi behar dira eta bukaeran baimendu 
	IME=0;
	IE = IE & 0xEFFF;
	IME=1;
}  

void DenbEtenBaimendu()
{

//Denboragailu baten etenak baimendu (Timer0)
//Horretarako lehenengo eten guztiak galarazi eta bukaeran berriro baimendu
	IME=0;
	IE = IE | 0x0008;
	IME=1;
}

void DenbEtenGalarazi()
{

//Denboragailu baten etenak galarazi (Timer0)
//Horretarako lehenengo eten guztiak galarazi eta bukaeran berriro baimendu
	IME=0;
	IE = IE & 0xFFF7;
	IME=1;

}

void ErlojuaMartxanJarri() // Denboragailua martxan jartzen du.
{

	DENB0_KNT = DENB0_KNT | 0x0080;
}

void ErlojuaGelditu() // Denboragailua pausatzen du.
{

	DENB0_KNT = DENB0_KNT & 0xFF7F;
}

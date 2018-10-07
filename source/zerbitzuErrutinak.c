/*-------------------------------------
periferikoak.c
-------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include "definizioak.h"
#include "periferikoak.h"
#include "fondoak.h"
#include "spriteak.h"

int EGOERA;
pilota b={80,50,1,1};
int KontJ2;
int KontJ1;

void tekEten () /* Tekla bat sakatzen denean, eten hau exekutatuko da, gainontzeko etenak deuseztatuz.dfdd
 	 	 	 	 Bertan erabakitzen da tekla bakoitzak zer eragin duen jokoan eta kontroletan.*/
{


if (EGOERA == JOKOA){	
//palen mugimendua --
	if (SakatutakoTekla()==A){

		if (J2P.y>0){	//Baldintza honen bitartez, spritea pantailatik irten dadin galarazten dugu.
			J2P.y=J2P.y-8; //Spritearen Y koordenatuak 8 pixel egingo ditu beherantz.
			ErakutsiPala(2,J2P.x,J2P.y); //Spritea(pala) koordenatu berrietan erakusten du.
		}
	}
	if (SakatutakoTekla()==B){
	
		if (J2P.y<160){
			J2P.y=J2P.y+8; //Spritearen Y koordenatuak 8 pixel egingo ditu beherantz.
			ErakutsiPala(2,J2P.x,J2P.y);
		}	
	}
	if (SakatutakoTekla()==GORA){
		if (J1P.y>0){
			J1P.y=J1P.y-8;
			ErakutsiPala(1,J1P.x,J1P.y);
		}
	}
	if (SakatutakoTekla()==BEHERA){
		if (J1P.y<160){
			J1P.y=J1P.y+8;
			ErakutsiPala(1,J1P.x,J1P.y);
		}
	}
}

}
void tenpEten()
{
	static int tik=0;
	static int seg=0;
	

if (EGOERA=JOKOA)
{	
	Erakutsibola(3,b.x,b.y);
	tik++; //eten bakoitzean, tik bat gehituko da.
	if (tik==45) //45 eten segunduko, beraz 45 eten egitean, segundu bat pasako da.
	{
		seg++;
		iprintf("\x1b[2;2HDenbora: %d", seg);
		tik=0; // 45 eten egitean, segundu bat gehitu, eta tik-a 0-ra berrituko da.

		if (seg==120){ //2 minutu pasatzean, partida amaituko da.
			iprintf("\x1b[2J"); //goiko pantaila garbitzeko.	
			EGOERA=AMAITU;
			ErlojuaGelditu();
			denbora_amaitu_bistaratu();
			EzabatuPala(1,J1P.x,J1P.y); //Spriteak pantailatik ezabatu
			EzabatuPala(2,J2P.x,J2P.y);
			Ezabatubola(3,b.x,b.y);
			seg=0; //Denbora 0-ra jarri berriro.
			iprintf("\x1b[10;2H 'Start' berriro jokatzeko");	//Amaitu egoeratik irteteko jarraibideak:
			iprintf("\x1b[12;2H'Select' Tutoriala ikusteko");
		}
		else if (KontJ1==5) { //J1 jokalaria 5 tantora iristean, irabazlea:
			iprintf("\x1b[2J"); //goiko pantaila garbitzeko.
			EGOERA=AMAITU;
			ErlojuaGelditu();
			j1_irabazi_bistaratu();
			EzabatuPala(1,J1P.x,J1P.y);
			EzabatuPala(2,J2P.x,J2P.y);
			Ezabatubola(3,b.x,b.y);
			seg=0;
			iprintf("\x1b[10;2H  'Start' berriro jokatzeko");	
			iprintf("\x1b[12;2H 'Select' Tutoriala ikusteko");	
		}
		else if (KontJ2==5){ //J2 jokalaria 5 tantora iristean, irabazlea:
			iprintf("\x1b[2J"); //goiko pantaila garbitzeko.
			EGOERA=AMAITU;
			ErlojuaGelditu();
			j2_irabazi_bistaratu();
			EzabatuPala(1,J1P.x,J1P.y);
			EzabatuPala(2,J2P.x,J2P.y);
			Ezabatubola(3,b.x,b.y);
			seg=0;
			iprintf("\x1b[10;2H  'Start' berriro jokatzeko");	
			iprintf("\x1b[12;2H 'Select' Tutoriala ikusteko");
			
		}
			
	}
	//tik bakoitzeko pilota mugitu + norabidearen kontrola 
	b.x=b.x+(1*b.norabidex);
	b.y=b.y+(1*b.norabidey);
	if (b.y<0 | b.y>175){ //Pantailaren mugetatik irten ez dadin, baldintzen bitarteko kontrola.
		b.norabidey=b.norabidey*(-1); //Muga ikutzean, noranzkoaren aldaketa zeinua aldatuz.
	}
	//J1 palaren aurkako talkak.
	if (b.x <= J1P.x +4 && b.y > J1P.y -8 && b.y < J1P.y + 32  && b.norabidex==-1){
		//palaren eta bolaren koordenatuak konparatuz eta bolaren norantza kontuan hartuz,
		//rebote bat baino gehiago ez egiteko.
		b.norabidex=b.norabidex*(-1);

	}
	//J2 palaren aurkako talkak.
	if (b.x >= J2P.x -16 && b.y > J2P.y -8 && b.y < J2P.y + 32 && b.norabidex==1){	
		
		b.norabidex=b.norabidex*(-1);	
		
	}
	
	if (b.x<0){ //Pantailaren ezker muga ukitzean, J2 jokalariari puntu bat gehitu:
		IME=0; //Etenak gelditu, puntuen kontagailuarekin arazoak ekiditzeko.
		b.x=120;
		b.y=60;
		b.norabidex=b.norabidex*(-1);	
		IME=1;//Etenak aktibatu.
		Ezabatubola(3,b.x,b.y);
		KontJ2++;
		iprintf("\x1b[07;2HJ2-ren puntuazioa:%d", KontJ2);
	
		
	}
	if (b.x>250){ //Pantailaren eskubiko muga ukitzean, J1 jokalariari puntu bat gehitu:
		IME=0; //Etenak gelditu, puntuen kontagailuarekin arazoak ekiditzeko.
		b.x=120;
		b.y=50;
		b.norabidex=b.norabidex*(-1);	
		IME=1; // Etenak aktibatu.
		Ezabatubola(3,b.x,b.y);
		KontJ1++;
		iprintf("\x1b[06;2HJ1-en puntuazioa:%d", KontJ1);
	}
	


		
}
	
}

void etenZerbErrutEzarri()
{
irqSet(IRQ_KEYS, tekEten);
irqSet(IRQ_TIMER0, tenpEten);
}

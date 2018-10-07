/*---------------------------------------------------------------------------------
Kode hau garatu da dovotoren "Simple sprite demo" adibidean eta Jaeden Ameronen beste
adibide batean oinarrituta.
---------------------------------------------------------------------------------*/

#include <nds.h> 		//nds-rako garatuta dagoen liburutegia
#include <stdio.h>		//c-ko liburutegi estandarra sarrera eta irteerako funtzioak definitzen dituena
#include <stdlib.h>		//c-ko liburutegi estandarra memoria erreserbak eta zenbaki konbertsioak egiteko
#include <unistd.h>		//Sistema eragileen arteko konpatibilitatea ziurtatzeko liburutegia

//Geuk garatutako fitxategiak
	
#include "definizioak.h"
#include "periferikoak.h"
#include "zerbitzuErrutinak.h"
#include "fondoak.h"

touchPosition PANT_DAT;
int KontJ1;
int KontJ2;
int denb;



//Palen posizioa kontrolatzeko aldagai globala. Definizioak.h fitxategian deklaratuak.
palak J1P={3,80};
palak J2P={250,80};
void jokoa01()
{	
	EGOERA=SARRERA;
	
	// Etenak baimendu behar dira. 
	TekEtenBaimendu();
	//Honek konfiguratzen du teklatuko zein tekla egongo diren etenen bidez.  Horregatik jarri ditugu hauek. (A,B,Gora,Behera->0,1,6,7)
	konfiguratuTeklatua(0x40C3);	
	// Tenporizadorea konfiguratu behar da 45 eten segunduko.
	konfiguratuTenporizadorea(53885, 0x0041);
	// Teklatuaren etenak baimendu behar dira.
	TekEtenBaimendu();
	// Tenporizadorearen etenak baimendu behar dira.
	DenbEtenBaimendu();
	// Etenen zerbitzu errutinak ezarri behar dira.
	etenZerbErrutEzarri();

	//SARRERA Egoeran goiko pantailan agertuko den textua:
	iprintf("\x1b[08;3HEGILEAK:");
	iprintf("\x1b[08;11HMikel Echeverria");
	iprintf("\x1b[09;11HUnai Gil Zubeldia");
	iprintf("\x1b[10;11HAritz Herrero");


	iprintf("\x1b[22;01H2018");
	iprintf("\x1b[23;01HEHU-Informatika Fakultatea");
				
	//fondoak.c fitxategian definitu dugu funtzioa, honen bidez SARRERA egoerako fondoa bistaratuko dugu:
	sarrera_bistaratu();
	while(1)
	{

	if (EGOERA==SARRERA) {
	touchRead(&PANT_DAT); // Ukimen pantaila irakurtzen du eta PANT_DAT(touchPosition motakoa)-en gordetzen ditu X eta Y koordenatuen posizioak.
		if ((PANT_DAT.px!=0) | (PANT_DAT.py!=0)){ 	/* Pantaila ikutua izan bada, aurreko aginduaren bidez X eta Y koordenatuak izango 
								ditugu eta bietako bat ezberdina bada, IF-era salto egingo du, TUTORIAL-era saltatuz.  */
			iprintf("\x1b[2J"); //goiko pantaila garbitzeko.
			iprintf("\x1b[08;2HPartida irabazlea: 5 puntura");
			iprintf("\x1b[011;5HDenbora muga: 2 minutu");
			EGOERA=TUTORIALA;
			tuto_bistaratu();
		}
	}
	if (EGOERA==TUTORIALA){
		if(TeklaDetektatu()){
			
			if (SakatutakoTekla()==START){ //Jokoa martxan jartzeko beharrezkoa den guztia hasieratuko da. Fondo, sprite, testu, kontadoreak...
				iprintf("\x1b[2J"); //goiko pantaila garbitzeko.
				EGOERA=JOKOA;
				KontJ1=0;
				KontJ2=0;
				iprintf("\x1b[06;2HJ1-en puntuazioa:%d", KontJ1);
				iprintf("\x1b[07;2HJ2-ren puntuazioa:%d", KontJ2);
				pilota b={80,50,1,1}; // Definizioak.h-en definituriko pilota motako objetua hasieratzen emandako posizio eta norabideetan.
				Erakutsibola(3,b.x,b.y);
				jokoa_bistaratu();
				ErlojuaMartxanJarri();
				ErakutsiPala(1,J1P.x,J1P.y);
				ErakutsiPala(2,J2P.x,J2P.y);

			}
		}
	}
	if (EGOERA==AMAITU){ /* Behin jokoa amaituta, tutorialera itzultzeko edo berriro ere jolasteko aukera ematen du.
	 	 	 	 	 	 	START sakatuz, berriro hasiko da partida. SELECT sakatuz, toturialera itzuliko da.*/
		if(TeklaDetektatu()){
			
			if (SakatutakoTekla()==START){
				iprintf("\x1b[2J"); //goiko pantaila garbitzeko.
				EGOERA=JOKOA;
				KontJ1=0;
				KontJ2=0;
				iprintf("\x1b[06;2HJ1-en puntuazioa:%d", KontJ1);
				iprintf("\x1b[07;2HJ2-ren puntuazioa:%d", KontJ2);	
				pilota b={80,50,1,1};
				Erakutsibola(3,b.x,b.y);
				jokoa_bistaratu();
				ErlojuaMartxanJarri();
				ErakutsiPala(1,J1P.x,J1P.y);
				ErakutsiPala(2,J2P.x,J2P.y);
			}
			if (SakatutakoTekla()==SELECT){
				iprintf("\x1b[2J"); //goiko pantaila garbitzeko.
				iprintf("\x1b[08;2HPartida irabazlea: 5 puntura");
				iprintf("\x1b[011;5HDenbora muga: 2 minutu");
				EGOERA=TUTORIALA;
				tuto_bistaratu();
			}
		}
	}

	
		

}
}










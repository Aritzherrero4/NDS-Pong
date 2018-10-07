/*---------------------------------------------------------------------------------
Kode hau garatu da dovotoren "Simple sprite demo" adibidean eta Jaeden Ameronen beste
adibide batean oinarrituta.
---------------------------------------------------------------------------------*/

#include <nds.h> 		//nds-rako garatuta dagoen liburutegia
#include <stdio.h>		//c-ko liburutegi estandarra sarrera eta irteerako funtzioak definitzen dituena
#include <stdlib.h>		//c-ko liburutegi estandarra memoria erreserbak eta zenbaki konbertsioak egiteko
#include <unistd.h>		//Sistema eragileen arteko konpatibilitatea ziurtatzeko liburutegia

/* Bertan erabiliko ditugun fondoak gehitzen dira programara, aurretik karpeta gfx karpetan
 * 	gehitu baditugu. NDS-aren beheko pantailan agertuko dira. */

#include "fondoak.h"
#include "grafikoak.h"
#include "tuto.h"
#include "jokoa.h"
#include "sarrera.h"
#include "j2_irabazi.h"
#include "j1_irabazi.h"
#include "denbora_amaitu.h"

/* irudiak memorian kopiatzeko DMA kanala aukeratu (3.a) */
static const int DMA_CHANNEL = 3;

/* Pantailaratu nahi den grafiko bakoitzerako horrelako prozedura bat idatzi behar da */

void tuto_bistaratu() { //Jokoaren kontrolak adierazten dituen tutoriala bistaratzen du.
	
	dmaCopyHalfWords(DMA_CHANNEL,
                     tutoBitmap, /* Automatikoki sortzen den aldagaia */
                     (uint16 *)BG_BMP_RAM(0), /* Fondo nagusiaren helbidea */
                     tutoBitmapLen); /* Luzera (bytetan) automatikoki sortzen den aldagaia */
}

void jokoa_bistaratu() { // Partidaren jolas-tokia bistaratzen du. Bertan jolastuko dute bi jokalariek.
	
	dmaCopyHalfWords(DMA_CHANNEL,
                     jokoaBitmap, /* Automatikoki sortzen den aldagaia */
                     (uint16 *)BG_BMP_RAM(0), /* Fondo nagusiaren helbidea */
                     jokoaBitmapLen); /* Luzera (bytetan) automatikoki sortzen den aldagaia */
}

void sarrera_bistaratu() {
	
	dmaCopyHalfWords(DMA_CHANNEL,
                     sarreraBitmap, /* Automatikoki sortzen den aldagaia */
                     (uint16 *)BG_BMP_RAM(0), /* Fondo nagusiaren helbidea */
                     sarreraBitmapLen); /* Luzera (bytetan) automatikoki sortzen den aldagaia */
}
void denbora_amaitu_bistaratu() {
	
	dmaCopyHalfWords(DMA_CHANNEL,
                     denbora_amaituBitmap, /* Automatikoki sortzen den aldagaia */
                     (uint16 *)BG_BMP_RAM(0), /* Fondo nagusiaren helbidea */
                     denbora_amaituBitmapLen); /* Luzera (bytetan) automatikoki sortzen den aldagaia */
}

void j1_irabazi_bistaratu() {
	
	dmaCopyHalfWords(DMA_CHANNEL,
                     j1_irabaziBitmap, /* Automatikoki sortzen den aldagaia */
                     (uint16 *)BG_BMP_RAM(0), /* Fondo nagusiaren helbidea */
                     j1_irabaziBitmapLen); /* Luzera (bytetan) automatikoki sortzen den aldagaia */
}

void j2_irabazi_bistaratu() {
	
	dmaCopyHalfWords(DMA_CHANNEL,
                     j2_irabaziBitmap, /* Automatikoki sortzen den aldagaia */
                     (uint16 *)BG_BMP_RAM(0), /* Fondo nagusiaren helbidea */
                     j2_irabaziBitmapLen); /* Luzera (bytetan) automatikoki sortzen den aldagaia */
}




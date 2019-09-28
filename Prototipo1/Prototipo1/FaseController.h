#include <stdio.h>
// Inclui o arquivo de cabeçalho da biblioteca Allegro 5
#include <allegro5/allegro.h>
// Inclui o cabeçalho do add-on para uso de imagens
#include <allegro5/allegro_image.h>
// Inclui a coisa do mouse
#include <allegro5/allegro_native_dialog.h>

#include "Struct.h"
#include "Fase0.h"
#include "Fase1.h"
#include "Fase2.h"

#ifndef FaseController_H
#define FaseController_H


int selecionaFase(int numFase, ALLEGRO_DISPLAY* janela, ALLEGRO_EVENT_QUEUE* fila_eventos, int acerto)
{
	switch (numFase)
	{
		case 0: return JogarFase0(janela, fila_eventos, acerto);
			break;
		case 1: return JogarFase1(janela, fila_eventos, acerto);
			break;
		case 2: return JogarFase2(janela, fila_eventos, acerto);
			break;
		default: printf("Fase não encontrada"); return 0;
			break;
	}
}





#endif 

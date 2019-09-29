#include <stdio.h>
// Inclui o arquivo de cabe�alho da biblioteca Allegro 5
#include <allegro5/allegro.h>
// Inclui o cabe�alho do add-on para uso de imagens
#include <allegro5/allegro_image.h>
// Inclui a coisa do mouse
#include <allegro5/allegro_native_dialog.h>

#include "Struct.h"
#include "Fase0.h"
#include "Fase1.h"
#include "Fase2.h"
#include "Fase3.h"

#ifndef FaseController_H
#define FaseController_H

//Vers�o do Igor
//Pega um interiro como par�metro
int igor(int numFase, ALLEGRO_DISPLAY* janela, ALLEGRO_EVENT_QUEUE* fila_eventos, int acerto)
{
	switch (numFase)
	{
		case 0: return JogarFase0(janela, fila_eventos, acerto);
			break;
		case 1: return JogarFase1(janela, fila_eventos, acerto);
			break;
		case 2: return JogarFase2(janela, fila_eventos, acerto);
			break;
		default: printf("Fase n�o encontrada"); return 0;
			break;
	}
}

//Vers�o do Claro
//Pega por referencia o lugar onde est� guardado o progresso do jogo
void selecionaFase(ALLEGRO_DISPLAY* janela, ALLEGRO_EVENT_QUEUE* fila_eventos, Progresso *progresso)
{
	switch (progresso->proximaSala)
	{
	case 0: JogarFase0(janela, fila_eventos, progresso);
		return;
	case 1: JogarFase1(janela, fila_eventos, progresso);
		return;
	case 2: JogarFase2(janela, fila_eventos, progresso);
		return;
	case 3: JogarFase3(janela, fila_eventos, progresso);
		return;
	default: printf("Fase n�o encontrada"); return;
		break;
	}
}



#endif 

#include <stdio.h>
// Inclui o arquivo de cabeçalho da biblioteca Allegro 5
#include <allegro5/allegro.h>
// Inclui o cabeçalho do add-on para uso de imagens
#include <allegro5/allegro_image.h>
// Inclui a coisa do mouse
#include <allegro5/allegro_native_dialog.h>

#include "Funcoes.h"
#include "Struct.h"

int jogarFase2(ALLEGRO_DISPLAY* janela, ALLEGRO_EVENT_QUEUE* fila_eventos, int acerto)
{
	Objeto saida;
	saida.beatmap = NULL;
	saida.x = LARGURA_TELA - 100;
	saida.y = 0;
	saida.largura = 100;
	saida.altura = 100;
}
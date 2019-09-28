#include <stdio.h>
// Inclui o arquivo de cabeçalho da biblioteca Allegro 5
#include <allegro5/allegro.h>
// Inclui o cabeçalho do add-on para uso de imagens
#include <allegro5/allegro_image.h>
// Inclui a coisa do mouse
#include <allegro5/allegro_native_dialog.h>

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "Funcoes.h"
#include "Struct.h"

int JogarFase0(ALLEGRO_DISPLAY* janela, ALLEGRO_EVENT_QUEUE* fila_eventos, int acerto)
{
	Objeto saida1;
	// Variável para imagem
	saida1.bitmap = NULL;
	saida1.x = 0;
	saida1.y = 0;
	saida1.largura = 100;
	saida1.altura = 100;

	saida1.bitmap = al_load_bitmap("Imgs/esquerda.png");
	if (!saida1.bitmap) {
		fprintf(stderr, "Falha ao iniciar imagem\n");
		al_destroy_display(janela);
		return -1;
	}

	ALLEGRO_FONT* font24 = al_load_font("Font/Calligraffitti-Regular.ttf", 24, 0);
	////////////////////////////////////////////////

	// Preenchemos a janela de branco
	al_clear_to_color(al_map_rgb(255, 255, 255));

	// Atualiza a tela
	al_flip_display();

	int gameOver = 0;

	while (!gameOver)
	{
		while (!al_is_event_queue_empty(fila_eventos))
		{
			//Cria um evento
			ALLEGRO_EVENT evento;
			//espero por um evento da fila, e guarda em evento
			al_wait_for_event(fila_eventos, &evento);

			//se teve eventos e foi um evento de fechar janela, encerra repetição			
			if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
				gameOver = 1;
			}
			else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
				if (IsInside(evento.mouse.x, evento.mouse.y, saida1)) {
					acerto = selecionaFase(1, janela, fila_eventos, acerto);
				}
			}
		}

		al_clear_to_color(al_map_rgb(255, 255, 255));

		al_draw_bitmap(saida1.bitmap, saida1.x, saida1.y, 0);
		
		al_draw_text(font24, al_map_rgb(0, 0, 0), 20, ALTURA_TELA / 2, 0, "Primeira tela - Texto muito louco pra dar inicio aos enigmas");
		al_flip_display();

	}
	return 0;
}
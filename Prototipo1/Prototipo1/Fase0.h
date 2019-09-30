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

int JogarFase0(ALLEGRO_DISPLAY* janela, ALLEGRO_EVENT_QUEUE* fila_eventos, Progresso *prog)
{
	Objeto SaidaEsquerda;
	// Variável para imagem
	SaidaEsquerda.bitmap = NULL;
	SaidaEsquerda.x = 110;
	SaidaEsquerda.y = ALTURA_TELA/2 - 50;
	SaidaEsquerda.largura = 100;
	SaidaEsquerda.altura = 100;

	Objeto SaidaCima;
	SaidaCima.bitmap = NULL;
	SaidaCima.x = LARGURA_TELA / 2 - 50;
	SaidaCima.y = 0;
	SaidaCima.largura = 100;
	SaidaCima.altura = 100;

	ALLEGRO_BITMAP* Background = al_load_bitmap("Imgs/fundo.png");

	SaidaEsquerda.bitmap = al_load_bitmap("Imgs/esquerda.png");
	SaidaCima.bitmap = al_load_bitmap("Imgs/cima.png");
	if (!SaidaEsquerda.bitmap || !SaidaCima.bitmap || !Background) {
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
				prog->Gameover = 1;
				gameOver = 1;
			}
			else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
				if (IsInside(evento.mouse.x, evento.mouse.y, SaidaEsquerda)) {
					prog->proximaSala = 1;
					return;
				}
				else if (IsInside(evento.mouse.x, evento.mouse.y, SaidaCima)) {
					prog->proximaSala = 3;
					return;
				}
			}
		}

		//al_clear_to_color(al_map_rgb(255, 255, 255));
		al_draw_bitmap(Background, 0, 0, 0);

		al_draw_bitmap(SaidaEsquerda.bitmap, SaidaEsquerda.x, SaidaEsquerda.y, 0);
		al_draw_bitmap(SaidaCima.bitmap, SaidaCima.x, SaidaCima.y, 0);
		
		al_draw_text(font24, al_map_rgb(0, 0, 0), 20, ALTURA_TELA-50, 0, "Primeira tela - Texto muito louco pra dar inicio aos enigmas");

		caregaInventario();
		al_flip_display();

	}
	return 0;
}
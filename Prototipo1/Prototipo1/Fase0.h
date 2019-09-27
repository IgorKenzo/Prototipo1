#include <stdio.h>
// Inclui o arquivo de cabe�alho da biblioteca Allegro 5
#include <allegro5/allegro.h>
// Inclui o cabe�alho do add-on para uso de imagens
#include <allegro5/allegro_image.h>
// Inclui a coisa do mouse
#include <allegro5/allegro_native_dialog.h>

#include "Funcoes.h"
#include "Struct.h"

int JogarFase0(ALLEGRO_DISPLAY* janela, ALLEGRO_EVENT_QUEUE* fila_eventos, int acerto)
{
	Objeto saida1;
	// Vari�vel para imagem
	saida1.beatmap = NULL;
	saida1.x = 0;
	saida1.y = 0;
	saida1.largura = 100;
	saida1.altura = 100;

	Objeto mensagem;
	mensagem.beatmap = NULL;
	mensagem.x = LARGURA_TELA / 2 - 100;
	mensagem.y = ALTURA_TELA - 100;
	mensagem.largura = 200;
	mensagem.altura = 100;

	Objeto mensagemTravada;
	mensagemTravada.beatmap = NULL;
	mensagemTravada.x = LARGURA_TELA / 2 - 100;
	mensagemTravada.y = ALTURA_TELA - 100;
	mensagemTravada.largura = 200;
	mensagemTravada.altura = 100;

	saida1.beatmap = al_load_bitmap("Imgs/esquerda.png");
	mensagem.beatmap = al_load_bitmap("Imgs/mensagem.png");
	mensagemTravada.beatmap = al_load_bitmap("Imgs/mensagemtravada.png");
	if (!saida1.beatmap || !mensagem.beatmap || !mensagemTravada.beatmap) {
		fprintf(stderr, "Falha ao iniciar imagem\n");
		al_destroy_display(janela);
		return -1;
	}

	////////////////////////////////////////////////

	// Preenchemos a janela de branco
	al_clear_to_color(al_map_rgb(255, 255, 255));

	//desenha a imagem na tela
	al_draw_bitmap(saida1.beatmap, saida1.x, saida1.y, 0);
	al_draw_bitmap(mensagem.beatmap, mensagem.x, mensagem.y, 0);
	al_draw_bitmap(mensagemTravada.beatmap, mensagemTravada.x, mensagemTravada.y, 0);

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

			//se teve eventos e foi um evento de fechar janela, encerra repeti��o			
			if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
				gameOver = 1;
			}
			else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
				if (IsInside(evento.mouse.x, evento.mouse.y, saida1)) {
					acerto = selecionaFase(1, janela, fila_eventos, acerto);
					//acerto = JogarFase1(janela, fila_eventos, acerto);
				}
			}
		}

		al_clear_to_color(al_map_rgb(255, 255, 255));

		al_draw_bitmap(saida1.beatmap, saida1.x, saida1.y, 0);
		if (acerto) {
			al_draw_bitmap(mensagem.beatmap, mensagem.x, mensagem.y, 0);
		}
		else
		{
			al_draw_bitmap(mensagemTravada.beatmap, mensagemTravada.x, mensagemTravada.y, 0);
		}

		al_flip_display();

	}
}
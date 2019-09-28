#include <stdio.h>
// Inclui o arquivo de cabeçalho da biblioteca Allegro 5
#include <allegro5/allegro.h>
// Inclui o cabeçalho do add-on para uso de imagens
#include <allegro5/allegro_image.h>
// Inclui a coisa do mouse
#include <allegro5/allegro_native_dialog.h>

#include "Funcoes.h"
#include "Struct.h"

int JogarFase1(ALLEGRO_DISPLAY *janela, ALLEGRO_EVENT_QUEUE* fila_eventos, int acerto) {
	Objeto saida1;
	// Variável para imagem
	saida1.bitmap = NULL;
	saida1.x = 0;
	saida1.y = 0;
	saida1.largura = 100;
	saida1.altura = 100;

	Objeto saida2;
	// Variável para imagem
	saida2.bitmap = NULL;
	saida2.x = LARGURA_TELA - 100;
	saida2.y = 0;
	saida2.largura = 100;
	saida2.altura = 100;

	Objeto mensagem;
	mensagem.bitmap = NULL;
	mensagem.x = LARGURA_TELA / 2 - 100;
	mensagem.y = ALTURA_TELA - 100;
	mensagem.largura = 200;
	mensagem.altura = 100;

	Objeto mensagemTravada;
	mensagemTravada.bitmap = NULL;
	mensagemTravada.x = LARGURA_TELA / 2 - 100;
	mensagemTravada.y = ALTURA_TELA - 100;
	mensagemTravada.largura = 200;
	mensagemTravada.altura = 100;

	saida1.bitmap = al_load_bitmap("Imgs/esquerda.png");
	saida2.bitmap = al_load_bitmap("Imgs/direita.png");
	mensagem.bitmap = al_load_bitmap("Imgs/mensagem.png");
	mensagemTravada.bitmap = al_load_bitmap("Imgs/mensagemtravada.png");
	if (!saida1.bitmap || !mensagem.bitmap || !mensagemTravada.bitmap || !saida2.bitmap) {
		fprintf(stderr, "Falha ao iniciar imagem\n");
		al_destroy_display(janela);
		return -1;
	}

	////////////////////////////////////////////////

	// Preenchemos a janela de branco
	al_clear_to_color(al_map_rgb(255, 255, 255));

	//desenha a imagem na tela
	al_draw_bitmap(saida1.bitmap, saida1.x, saida1.y, 0);
	al_draw_bitmap(mensagem.bitmap, mensagem.x, mensagem.y, 0);
	al_draw_bitmap(mensagemTravada.bitmap, mensagemTravada.x, mensagemTravada.y, 0);

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
					acerto = selecionaFase(2, janela, fila_eventos, acerto);
				}
				if (IsInside(evento.mouse.x, evento.mouse.y, saida2)) {
					return acerto;
				}
			}
		}

		al_clear_to_color(al_map_rgb(255, 255, 255));

		al_draw_bitmap(saida1.bitmap, saida1.x, saida1.y, 0);
		al_draw_bitmap(saida2.bitmap, saida2.x, saida2.y, 0);

		if (acerto) {
			al_draw_bitmap(mensagem.bitmap, mensagem.x, mensagem.y, 0);
		}
		else
		{
			al_draw_bitmap(mensagemTravada.bitmap, mensagemTravada.x, mensagemTravada.y, 0);
		}

		al_flip_display();

	}
	return 0;
}
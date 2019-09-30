#include <stdio.h>
// Inclui o arquivo de cabeçalho da biblioteca Allegro 5
#include <allegro5/allegro.h>
// Inclui o cabeçalho do add-on para uso de imagens
#include <allegro5/allegro_image.h>
// Inclui a coisa do mouse
#include <allegro5/allegro_native_dialog.h>

#include "Funcoes.h"
#include "Struct.h"

int JogarFase1(ALLEGRO_DISPLAY *janela, ALLEGRO_EVENT_QUEUE* fila_eventos, Progresso *prog) {
	Objeto saidaDireita;
	// Variável para imagem
	saidaDireita.bitmap = NULL;
	saidaDireita.x = LARGURA_TELA-100;
	saidaDireita.y = ALTURA_TELA/2 - 50;
	saidaDireita.largura = 100;
	saidaDireita.altura = 100;

	Objeto saidaCima;
	// Variável para imagem
	saidaCima.bitmap = NULL;
	saidaCima.x = LARGURA_TELA/2 - 50;
	saidaCima.y = 0;
	saidaCima.largura = 100;
	saidaCima.altura = 100;

	Objeto mensagem;
	mensagem.bitmap = NULL;
	mensagem.x = (LARGURA_TELA / 2 - 100) * -1;
	mensagem.y = (ALTURA_TELA - 100) * -1;
	mensagem.largura = 200;
	mensagem.altura = 100;

	Objeto mensagemTravada;
	mensagemTravada.bitmap = NULL;
	mensagemTravada.x = LARGURA_TELA / 2 - 100;
	mensagemTravada.y = ALTURA_TELA - 100;
	mensagemTravada.largura = 200;
	mensagemTravada.altura = 100;

	saidaDireita.bitmap = al_load_bitmap("Imgs/direita.png");
	saidaCima.bitmap = al_load_bitmap("Imgs/cima.png");
	mensagem.bitmap = al_load_bitmap("Imgs/mensagem.png");
	mensagemTravada.bitmap = al_load_bitmap("Imgs/mensagemtravada.png");
	if (!saidaDireita.bitmap || !mensagem.bitmap || !mensagemTravada.bitmap || !saidaCima.bitmap) {
		fprintf(stderr, "Falha ao iniciar imagem\n");
		al_destroy_display(janela);
		return -1;
	}

	////////////////////////////////////////////////

	// Preenchemos a janela de branco
	al_clear_to_color(al_map_rgb(255, 255, 255));

	//desenha a imagem na tela
	al_draw_bitmap(saidaDireita.bitmap, saidaDireita.x, saidaDireita.y, 0);
	//al_draw_bitmap(mensagem.bitmap, mensagem.x, mensagem.y, 0);
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
				prog->Gameover = 1;
				gameOver = 1;
			}
			else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
				if (IsInside(evento.mouse.x, evento.mouse.y, saidaDireita)) {
					prog->proximaSala = 0;
					return;
				}
				if (IsInside(evento.mouse.x, evento.mouse.y, saidaCima)) {
					prog->proximaSala = 2;
					return;
				}
				if (IsInside(evento.mouse.x, evento.mouse.y, mensagem)) {
					inventario[posInvent++] = mensagem;
					prog->Item1 = 1;
				}
			}
		}

		al_clear_to_color(al_map_rgb(255, 255, 255));

		al_draw_bitmap(saidaDireita.bitmap, saidaDireita.x, saidaDireita.y, 0);
		al_draw_bitmap(saidaCima.bitmap, saidaCima.x, saidaCima.y, 0);

		if (!prog->Item1)
		{
			if (prog->Sala2) {
				mensagem.x = LARGURA_TELA / 2 - 100;
				mensagem.y = ALTURA_TELA - 100;
				al_draw_bitmap(mensagem.bitmap,mensagem.x,mensagem.y, 0);
			}
			else
			{
				al_draw_bitmap(mensagemTravada.bitmap, mensagemTravada.x, mensagemTravada.y, 0);
			}
		}

		al_flip_display();

	}
	return 0;
}
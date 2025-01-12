#include <stdio.h>
// Inclui o arquivo de cabe�alho da biblioteca Allegro 5
#include <allegro5/allegro.h>
// Inclui o cabe�alho do add-on para uso de imagens
#include <allegro5/allegro_image.h>
// Inclui a coisa do mouse
#include <allegro5/allegro_native_dialog.h>

#ifndef Struct_H
#define Struct_H

// Tamanho da tela
#define LARGURA_TELA 1000
#define ALTURA_TELA 600

#define TAMANHO_INVENTARIO 7

#define SOME_HEADER_GUARD_WITH_UNIQUE_NAME

typedef struct Obj
{
	ALLEGRO_BITMAP* bitmap;
	int x;
	int y;
	int largura;
	int altura;
	int cliqueX;
	int cliqueY;
} Objeto;

typedef struct prog
{
	int proximaSala;
	int Gameover;
	int Sala1;
	int Sala2;
	int Sala3;
	int Item1;
} Progresso;

Objeto inventario[TAMANHO_INVENTARIO];

int posInvent = 0;
#endif
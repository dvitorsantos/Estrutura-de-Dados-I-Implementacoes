//
// Vitor Santos
// Pablo Kaua
//

#ifndef TRABALHO_IMPLEMENTACAO_01_COFO_H
#define TRABALHO_IMPLEMENTACAO_01_COFO_H

typedef struct cofo Cofo;

int find_cofo(Cofo *c, int key );

int insert_cofo(Cofo *c, int item);

Cofo *create_cofo(int size);

int *itens_cofo(Cofo *cofo);

int delete_cofo(Cofo *c);

int remove_item_cofo(Cofo *cofo, int key);

int get_max_itens(Cofo *cofo);

#endif //TRABALHO_IMPLEMENTACAO_01_COFO_H
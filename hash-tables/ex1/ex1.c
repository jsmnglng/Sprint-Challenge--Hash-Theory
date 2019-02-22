#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);

  for (int i = 0; i < length; i++)
  {
    // if a pair exists in ht
    // key: diff bet limit - weights[i]
    // value: index
    if (hash_table_retrieve(ht, weights[i]) != -1)
    {
      printf("retrieve: %i\n", hash_table_retrieve(ht, weights[i]));
      printf("weights[i]: %i, i: %i\n", weights[i], i);
      Answer *output = malloc(sizeof(Answer *));

      output->index_1 = i;
      output->index_2 = hash_table_retrieve(ht, weights[i]); // smaller index

      return output;
    }

    // populate ht with difference bet limit - weights[i] as keys and i as values
    hash_table_insert(ht, (limit - weights[i]), i);
    printf("TOUCHED i= %i\n", i);
  }

  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL)
  {
    printf("%d %d\n", answer->index_1, answer->index_2);
  }
  else
  {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{
  // TEST 0
  int weights_0[] = {4, 6, 10, 15, 16};
  Answer *answer_0 = get_indices_of_item_weights(&weights_0, 5, 21);
  print_answer(answer_0); // NULL
  printf("\n----------------\n");
  // TEST 1
  int weights_1 = {9};
  Answer *answer_1 = get_indices_of_item_weights(&weights_1, 1, 9);
  print_answer(answer_1); // NULL

  // TEST 2
  int weights_2[] = {4, 4};
  Answer *answer_2 = get_indices_of_item_weights(weights_2, 2, 8);
  print_answer(answer_2); // {1, 0}

  // TEST 3
  int weights_3[] = {4, 6, 10, 15, 16};
  Answer *answer_3 = get_indices_of_item_weights(weights_3, 5, 21);
  print_answer(answer_3); // {3, 1}

  // TEST 4
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};
  Answer *answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
  print_answer(answer_4); // {6, 2}

  return 0;
}
#endif

#include <stdio.h>

void play(int attempts) {
  printf("joga %d\n", attempts);
  
  attempts++;
  printf("joga %d\n", attempts);
}

void main() {
  int attempts = 0;
  printf("main %d\n", attempts);
  
  attempts++;
  printf("main %d\n", attempts);

  attempts++;
  printf("main %d\n", attempts);

  play(attempts);

  printf("main %d\n", attempts);
}
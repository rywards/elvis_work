#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[]){
  char * word;

  for (int i=1; i<argc; i++){
    word = argv[i];
    for (int x = 0; word[x] != '\0'; x++){
      for (int j=7; j >= 0; j--){
	if (word[x] & (1 << j)){
	  printf("1");
	}else {
	  printf("0");
	}
      }
    }
    printf(" ");
  }
  printf("\n");
  return 0;
}

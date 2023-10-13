#include<stdio.h>

int main(int argc, char *argv[]){
	FILE *fp;
	void filecopy(FILE*,FILE*);
	if(argc <= 1)
		filecopy(stdin,stdout);
	while(--argc){
		if((fp = fopen(*++argv,"r")) == NULL){
			printf("The file (%s) cannot be opened\n",*argv);
			return 1;
		}else{
			filecopy(fp,stdout);
			fclose(fp);
		}
		return 0;
	}
}

void filecopy(FILE *source, FILE *dest){
	int c;
	while((c = getc(source)) != EOF)
		putc(c,dest);
}

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MAX_WORDS 100
#define BUFFSIZE 100

struct tnode{
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

int main(){
	struct tnode *root,*addtree(struct tnode*, char*);
	char word[MAX_WORDS];
	void treeprint(struct tnode *node);
	int getword(char*,int);
	root = NULL;
	while(getword(word,MAX_WORDS) != EOF){
		if(isalpha(word[0]))
			root = addtree(root,word);
	}
	treeprint(root);
	return 0;
}

struct tnode *addtree(struct tnode *p, char *w){
	int cond;
	if(p == NULL){
		p = (struct tnode*) malloc(sizeof(struct tnode));
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	}else if((cond = strcmp(w,p->word)) ==0)
		p->count++;
	else if(cond < 0)
		p->left = addtree(p->left,w);
	else if(cond > 0)
		p->right = addtree(p->right,w);
	return p;

}
void treeprint(struct tnode *node){
	if(node != NULL){
		treeprint(node->left);
		printf("%4d : %s\n",node->count, node->word);
		treeprint(node->right);
	}
}
int getword(char *word, int max_word){
	int c,getch(void);
	void ungetch(int);
	char *w = word;
	while(isspace(c = getch()))
		;
	if(c != EOF)
		*w++ = c;
	if(!isalpha(c)){
		*w = '\0';
		return c;
	}

	for(; --max_word > 0; w++){
		if(!isalnum(*w = getch())){
			ungetch(*w);
			break;
		}
	}
	*w = '\0';
	return word[0];
}
char buffer[BUFFSIZE];
int bufp = 0;

int getch(){
	return bufp > 0 ? buffer[--bufp] : getchar();
}

void ungetch(int c){
	if (bufp >= BUFFSIZE)
		printf("UNGETCH: BUFFER IS FULL");
	else
		buffer[bufp++] = c; 
}

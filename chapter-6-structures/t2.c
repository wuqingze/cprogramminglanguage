#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

char *newstr(char *s);
struct tnode *addtree(struct tnode *, char *);
struct tnode *_addnode(struct tnode *, char *);
void treeprint(struct tnode *);

// gcc 5.words-count-binary-tree.c getch.c
int main()
{
	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
    char *data[] = { "now", "is", "the", "for", "mem",
        "now", "is", "the", "for", "mem",
        "of", "time", "all", "good", "party", "their",
        "of", "time", "all", "good", "party", "their",
        "of", "time", "all", "good", "party", "their",
        "of", "time", "all", "good", "party", "their",
        "to", "aid", "come"};

//	while (getword(word, MAXWORD) != EOF)
//		if (isalpha(word[0]))
//			root = addtree(root, word);
    int len = sizeof data / sizeof data[0];
    for(int i=0; i<len; i++){
//        root = addtree(root, data[i]);
        root = _addnode(root, data[i]);
    }
	treeprint(root);

	return 0;
}

struct tnode *talloc(void);
char *mystrdup(char *s);

struct tnode *_addnode(struct tnode *root, char *value){

    if(root == NULL){
        struct tnode *node = (struct tnode*) malloc(sizeof(struct tnode));
        node->word = newstr(value); 
        node->count += 1;
        return node;
    }

    int comp = strcmp(value, root->word);
    if(comp == 0){
        root->count += 1;
    }else if(comp > 0){
        root->right = _addnode(root->right, value);
    }else{
        root->left = _addnode(root->left, value);
    }
    return root;
}

struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;

	if (p == NULL) {
		p = talloc();
		p->word = mystrdup(w);
		p->count = 1;
		p->left = p-> right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;
	else if (cond < 0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);
	return p;
}

void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *mystrdup(char *s)
{
	char *p;

	p = (char *) malloc(strlen(s)+1);
	if (p != NULL)
		strcpy(p, s);

	return p;
}

char *newstr(char *s){
    char *p = (char*) malloc(strlen(s));
    char *t = p;
    while(*t++ = *s++)
        ;
    return p;
}

#include "rec.h"


struct Artist* get_artist(struct Artist* head, struct Artist a) {
	if (head != NULL) {
		if (strcmp(head->name, a.name) == 0)
			return head;
		return get_artist(head->next, a);
	}
	return NULL;
}
struct album* get_album(struct album* head, struct album a) {
	if (head != NULL) {
		if (strcmp(head->name, a.name) == 0)
			return head;
		return get_album(head->next, a);
	}
	return NULL;
}
struct song* get_song(struct song* head, struct song a) {
	if (head != NULL) {
		if (head->id==a.id)
			return head;
		return get_song(head->next, a);
	}
	return NULL;
}
void free_memory(struct Artist* a,struct album* b,struct song* c) {
	if (a != NULL) {
		free_memory( a->next, a->albums, NULL);
		printf("artist :%s, free\n", a->name);
		free(a->name);
		free(a);
	}
	if (b != NULL) {
		free_memory( NULL, b->next, b->songs);
		printf("album :%s, free\n", b->name);
		free(b->name);
		free(b);
	}
	if (c != NULL) {
		free_memory(NULL, NULL, c->next);
		printf("Song id: %d, free\n",c->id);
		free(c->name);
		free(c);
	}
}
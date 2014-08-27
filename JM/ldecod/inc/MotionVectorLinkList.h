#include "image.h"   
//this header file defines the Linked List which include the motion vectors of the frames decoded
//mv node linlist
struct fmvnode
{
	frame_mv *fmv;
	int poc;
	struct fmvnode *next;
};
struct mv_linklist
{
	struct fmvnode *head;
	int length;
};
void mv_insert(struct fmvnode *filemv,struct mv_linklist *list);

frame_mv *mv_del(struct mv_linklist *list, int mark);

//mv node linlist
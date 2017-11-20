////
//// Created by antonio on 17-11-14.
////
//#include <stdio.h>
//#include "SeqStack.h"
//#define MAXSIZE 12
//#include <malloc.h>
//int maze[MAXSIZE][MAXSIZE] ={
//        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
//        { 0, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0,-1},
//        {-1, 0,-1,-1,-1,-1,-1, 0, 0, 0, 0,-1},
//        {-1, 0, 0, 0,-1, 0,-1, 0, 0, 0,-1,-1},
//        {-1,-1,-1, 0,-1,-1,-1, 0,-1,-1, 0,-1},
//        {-1, 0,-1, 0, 0, 0,-1, 0,-1, 0, 0,-1},
//        {-1, 0,-1,-1, 0,-1,-1,-1,-1,-1, 0,-1},
//        {-1, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0,-1},
//        {-1, 0,-1,-1,-1,-1, 0,-1,-1,-1, 0,-1},
//        {-1, 0,-1,-1, 0, 0, 0, 0, 0, 0, 0,-1},
//        {-1, 0, 0, 0, 0,-1,-1, 0,-1, 0, 0, 0},
//        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
//};
///*-1表示墙壁，0表示路径，请编程用递归的方法输出能走出迷宫的所有路线*/
////行：保存的是可行路线的个数【我可不可以不保存次数，直接在得到一次可行路线的时候输出】*这样的话行列分别可用来临时保存路径
////已知起点和终点呀，
//int stack[MAXSIZE][MAXSIZE] ;//保存行走路径的行列坐标
//int m = 0, n = 0 ;
//
//int place(int a){
//
//    return a==0 ;//0--true, [!0]--false
//}
//
//void reset(int col, int raw){
//    maze[raw][col] = -1 ;
//}
//
//void DFS(int raw, int col, SeqStack *head, DataType z){
//    int x[] = {0, 1, 0, -1} ;
//    int y[] = {1, 0, -1, 0} ;
//    for(int i = 0; i < 4; i++){
//        if(raw + x[i] >= 0 && raw + x[i] < MAXSIZE
//           && col + y[i] >= 0 && col + y[i] < MAXSIZE
//           && maze[raw + x[i]][col + y[i]] == 0 ){
//            maze[raw + x[i]][col + y[i]] = 1 ;//1为已走过
//            StackPush(head, maze[raw + x[i]][col + y[i]]) ;
//            printf("%-3d%-3d\n", raw + x[i] + 1, col + y[i] + 1);
//
//            DFS(raw + x[i], col + y[i]) ;//递归
//        }
//    }
//}
//
//void StaceMaze(){
//    int col, raw, num = 0;//保存要修改的坐标复盘
//
//    for(int i = 0; i < MAXSIZE; i ++){
//        for(int j = 0; j < MAXSIZE; j ++){
//            if( place(maze[i][j]) ){
//                maze[i][j] = 1 ;
//                raw = i, col = j ;
//                DFS(i, j) ;
//                num++ ;
//            }
//        }
//    }
//}
//
//void print(){
//    for(int i = 0; i < MAXSIZE; i ++){
//        for(int j = 0; j < MAXSIZE; j ++){
//            printf("%-3d", maze[i][j]) ;
//        }
//        printf("\n") ;
//    }
//}
//
//typedef int DataType ;
//typedef struct snode{
//    DataType data ;
//    struct snode *next ;
//}LSNode;
//
//void StackInitiate(LSNode **head){
//    *head = (LSNode *)malloc(sizeof(LSNode)) ;
//    (*head)->next = NULL ;
//}
//
//int StackNotEmpty(LSNode *head){
//    //LSNode *p = head ;
//    if (head->next == NULL) return 0 ;
//    else return 1 ;
//}
//
//int StackPush(LSNode *head, DataType x){
//    LSNode *p ;
//    p = (LSNode *)malloc(sizeof(LSNode)) ;
//    p->data = x ;
//    p->next = head->next ;
//    head->next = p ;
//
//}
//
//int StackPop(LSNode *head, DataType *x){
//    LSNode *p = head->next ;
//    if (p == NULL){
//        printf("栈为空\n") ;
//        return 0 ;
//    }
//    head->next = p->next ;
//    *x = p->data ;
//    free(p) ;
//    return 1 ;
//}
//
////取栈顶元素
//int StackTop(LSNode *head, DataType *x){
//    LSNode *p = head->next ;
//    if(p == NULL){
//        printf("栈为空\n") ;
//        return 0 ;
//    }
//
//    *x = p->data ;
//    return 1 ;
//
//}
//
////撤销动态申请空间
//void Destroy(LSNode *head){
//    LSNode *p, *q ;
//    p = head ;
//    while(p != NULL){
//        q = p ;
//        p = p->next ;
//        free(q) ;
//    }
//}
//
//int main(){
//    int a ;
//    LSNode *head ;
//    StackInitiate(&head) ;
//
//    StaceMaze() ;
//
//    print() ;
//    scanf("%d", &a) ;
//    return 0 ;
//}
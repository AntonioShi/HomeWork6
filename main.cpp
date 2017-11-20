//
// Created by antonio on 17-11-19.
//
/**
 * 很严肃的告诉你，这个方法不是我的原创，我没有生产代码，只是代码的搬运工，然后自己再想想，仅此。
 * 功能：找到已知起点和终点的迷宫的所有可行性路径，并打印出来
 */
#include <iostream>
#include <stack>//栈的库文件
using namespace std ;

#define MAXSIZE 12

int maze[MAXSIZE][MAXSIZE] ={
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0,-1},
        {-1, 0,-1,-1,-1,-1,-1, 0, 0, 0, 0,-1},
        {-1, 0, 0, 0,-1, 0,-1, 0, 0, 0,-1,-1},
        {-1,-1,-1, 0,-1,-1,-1, 0,-1,-1, 0,-1},
        {-1, 0,-1, 0, 0, 0,-1, 0,-1, 0, 0,-1},
        {-1, 0,-1,-1, 0,-1,-1,-1,-1,-1, 0,-1},
        {-1, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0,-1},
        {-1, 0,-1,-1,-1,-1, 0,-1,-1,-1, 0,-1},
        {-1, 0,-1,-1, 0, 0, 0, 0, 0, 0, 0,-1},
        {-1, 0, 0, 0, 0,-1,-1, 0,-1, 0, 0, 0},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
};
int virmaze[MAXSIZE][MAXSIZE] ;//迷宫的映射------>0未访问 1已访问
int x[] = {0, 1, 0, -1};//上下左右四方
int y[] = {1, 0, -1, 0};
int count = 0;//记录总路径条数
struct point{
    int x, y ;
}p;
stack <point> path, temp ;//

// p做移动的点， path temp做记录可行性路径的存储容器：栈，通过来回出入达到证序
//virmaze做迷宫的映射，在对应的位置做标记


void DFS(int a, int b){
    if (a == MAXSIZE - 1 || b == MAXSIZE - 1){//成功--->出口
        //如果到达迷宫最后一列或追后一行
        cout << "劳资出来啦" << ++count << endl ;
        while(!path.empty()){//非空，返回0
            point point1 = path.top() ;
            path.pop() ;
            temp.push(point1) ;
        }
        while(!temp.empty()){
            point point1 = temp.top() ;
            temp.pop() ;
            path.push(point1) ;
            cout << "(" << point1.x << ", " << point1.y << ")" << "--->"  ;//(x, y)
        }
        cout << endl ;
        return;
    }
    if (a < 0 || a >= MAXSIZE || b < 0 || b >= MAXSIZE)//越界
        return;

    //革命尚未成功
    for (int i = 0; i < 4; ++i) {
        int nx = a + x[i] ;
        int ny = b + y[i] ;
        if (nx >= 0 && nx < MAXSIZE && ny >= 0 && ny < MAXSIZE && maze[nx][ny] == 0
            && virmaze[nx][ny] == 0){
            virmaze[nx][ny] = 1 ;
            p.x = nx ;
            p.y = ny ;
            path.push(p) ;//让当前点进栈

            DFS(nx, ny) ;//下一步的探索活动

            virmaze[nx][ny] = 0 ;//如果路径不理想，则回溯--->保持原样，便于重复使用
            path.pop() ;//回到上一步，则需要弹出栈顶元素
        }
    }

}

int main6_4(){
    p.x = 1 ;
    p.y = 0 ;//起点
    path.push(p) ;//入栈

    for (int i = 0; i < MAXSIZE; ++i) {
        for (int j = 0; j < MAXSIZE; ++j) {
            virmaze[i][j] = 0 ;//初始化，映射局面
        }
    }

    DFS(1, 0) ;//
    cout << "总共有：" << count << "条可行性路径" << endl ;
}
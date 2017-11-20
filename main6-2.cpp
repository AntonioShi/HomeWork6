//
// Created by antonio on 17-11-11.
//
/*
 * 6-2
 */
//#include <iostream>
//#define N 8
//using namespace std ;
//
//int count = 0 ;//保存数目
//int MockBoard[92][N] ;//记录最多方法时:每一种方法的元素排列--列
//int BoardCol[N] ;//数组数值用于记录第i行的列坐标
//int size = 8 ;//矩阵大小
//
//bool Place(int k) ;//判断当前位置能否放置皇后
//void TraceBack(int k) ;//回溯
//
//bool Place(int k){
//    int i ;
//    for(i = 0; i < k; i++){
//        if( (BoardCol[i] == BoardCol[k]) || abs(BoardCol[i] - BoardCol[k]) == abs(k - i) ){//行列对角线不可交叉
//            return false ;
//        }
//    }
//    return true ;
//}
//
//void TraceBack(int k){
//    int i ;
//    for (int i = 0; i < size; ++i) {
//        BoardCol[k] = i ;//
//
//        if(Place(k)){   //如果k行BoardCol[k]可以存放皇后
//            if(k == size - 1){
//                //最后
//                for (int j = 0; j < size; ++j) {
//                    MockBoard[count][j] = BoardCol[j] + 1 ;//保存当前方法的元素位置列数
//                }
//                count ++ ;//方法数+1
//            }
//            else{
//                TraceBack(k + 1) ;//回溯到下一列
//            }
//        }
//    }
//}
//
//
//int main6_2(){
//
//    TraceBack(0) ;//开始游戏～0
//
//    //已经完成了皇后的放置输出
//    cout << count << endl ;
//    for (int i = 0; i < count; ++i) {
//        for (int j = 0; j < size; ++j) {
//            cout << MockBoard[i][j] << " " ;
//        }
//        cout << endl ;
//    }
//
//    return 0 ;
//}
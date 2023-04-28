
#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
const int inf = 0x3f3f3f3f;
const int N = 1e3+3;
//#define int long long

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

//Synchronization condition
//1. mutual exclusion
//2. progress
//3. bounded wait
//4. no assumptions related to hardware


//Peterson Method for 2 process P0=0 and P1=1
// void entry_section(process){
//     int other;
//     other = 1-process;
//     interested[process]=TRUE;
//     turn = process;
//     while(interested[other]==TRUE && turn == process){
//     }
// }
//
// // entry into critical ssegment
//
// void exit_section(process){
//     interested[process]=FALSE;
// }


//seamaphore --> to avoid race condition
// void down(Seamaphore S){ //entry section
//     svalue = svalue-1;
//     if(svalue<0){
//         put process(PCB) in suspended list
//         sleep();
//     }else{
//         return;
//     }
// }
//
// critical section
//
// void up(Seamaphore S){
//     svalue = svalue+1;
//     if(svalue<=0){
//         select a process from suspended list;
//         wakeup();
//     }
// }

//above solution has wait and wakeup type of solution
//to overcome this solution we have producer and consumer problem

// void producer(){
//     int item;
//     while(TRUE){
//         item = produce_item();
//         if(count==n){
//             sleep();
//         }
//         insert_item(item);
//         count++;
//         if(count ==1){
//             wakeup(consumer);
//         }
//     }
// }
// void consumer(){
//     int item;
//     while(TRUE){
//         if(count==0){
//             sleep();
//         }
//         item = remove_item();
//         count--;
//         if(count==n-1){
//             wakeup(producer);
//         }
//         consume_item(item);
//     }
// }

//condition to avoid deadloack
//1. mutual exclusion
//2. hold and wait
//3. no preemption
//4. circular wait

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    #endif




    return 0;
}

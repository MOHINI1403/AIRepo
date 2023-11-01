#include <bits/stdc++.h>
using namespace std;

/*Water Jug Problem
  This problem states that there are 2 jugs jug1 and jug2 both have capacity of (m,n) resp and 
  we need to fill one of the jug completly with d anount 
*/

/*There are 6 possible combinations

  1.Empty Jug 1 completly
  2.Emplty Jug 2 completly
  3.Fill the first Jug
  4.Fill the secodn Jug
  5.Fill water from first Jug to second till the first one is full or second one is Empty
  6.Fill the water from second Jug to the First Jug till one is full or other is Empty
*/

int visited[10000][10000]={false};


bool WaterJugProblem(int total_cap_jug1,int total_cap_jug2,int curr_cap_jug1,int curr_cap_jug2,int aim_cap){
  
  if((curr_cap_jug2==aim_cap&&curr_cap_jug1==0)||(curr_cap_jug1==aim_cap&&curr_cap_jug2==0)){
    cout<<curr_cap_jug1<<" "<<curr_cap_jug2<<endl;
    return true;
  }
  
  if(visited[curr_cap_jug1][curr_cap_jug2]==false){
    //Check weather we already visited the possibility or not 
    //If we have not visited the possibility then Proceed
    cout<<curr_cap_jug1<<" "<<curr_cap_jug2<<endl;
    visited[curr_cap_jug1][curr_cap_jug2]=true;
    
    //Check for all possible combinations
    
    //Combo1:Empty jug 1 completly
    bool combo1=WaterJugProblem(total_cap_jug1,total_cap_jug2,0,curr_cap_jug2,aim_cap);
    if(combo1){
        return true;
    }
    //Combo2:Empty the Jug 2 completly
    bool combo2=WaterJugProblem(total_cap_jug1,total_cap_jug2,curr_cap_jug1,0,aim_cap);
    if(combo2){
        return true;
    }
    //Combo3:Fill the first jug completly
    bool combo3=WaterJugProblem(total_cap_jug1,total_cap_jug2,total_cap_jug1,curr_cap_jug2,aim_cap);
    if(combo3){
        return true;
    }
    //Combo4:Fill the seocnd jug completly
    bool combo4=WaterJugProblem(total_cap_jug1,total_cap_jug2,curr_cap_jug1,total_cap_jug2,aim_cap);
    if(combo4){
        return true;
    }
    //Combo5:Fill the water into first jug from second
    bool combo5=WaterJugProblem(total_cap_jug1,total_cap_jug2,curr_cap_jug1+min(curr_cap_jug2,total_cap_jug1-curr_cap_jug1),curr_cap_jug2-min(curr_cap_jug2,total_cap_jug1-curr_cap_jug1),aim_cap);
    if(combo5){
        return true;
    }
    //Combo6://Fill the water from the second jug into the Frst jug
    bool combo6=WaterJugProblem(total_cap_jug1,total_cap_jug2,curr_cap_jug1-min(curr_cap_jug1,total_cap_jug2-curr_cap_jug2),curr_cap_jug2+min(curr_cap_jug1,total_cap_jug2-curr_cap_jug2),aim_cap);
    if(combo6){
        return true;
    }
    
    
    return combo1||combo2||combo3||combo4||combo5||combo6;
    
    
  }
  
  else{
    return false;
  }
}
int main(){
  
  int jug1_cap,jug2_cap;
  // cout<<"Enter Jug 1 capacity and Jug 2 capacity"<<endl;
  cin>>jug1_cap>>jug2_cap;
  
  int aim_cap;
  //cout<<"Enter the desired Aim water in jug"<<endl;
  cin>>aim_cap;
  
  cout<<WaterJugProblem(jug1_cap,jug2_cap,0,0,aim_cap);
  //We need to try all the possible combinations
  return 0;
  
  
}
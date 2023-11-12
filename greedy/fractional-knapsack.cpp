#include<iostream>

using namespace std;

template <typename T>
void traverse(T arr[], int size) {
  for(int i = 0; i < size; ++i) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

// Fractional Knapsack algrithm
float fractional_knapsack(int weights[], int values[], int W, int size) {
  // cout<<size<<endl;
  float P[size]; // to store thee points
  
  // O(n)
  for(int i = 0; i < size; ++i) {
    P[i] = values[i]  / weights[i];
  }

  // Arrange the weights, values and points as per 
  // descending order of points
  // O(nlogn) for best sorter but currently O(n^2)
  for(int j = 0; j < size; j++) {
    for(int k = j + 1; k < size; k++) {
      if(P[j] < P[k]){
        // swap all      
        float tempP = P[j];
        int tempV = values[j];
        int tempW  = weights[j];

        P[j] = P[k];
        values[j] = values[k];
        weights[j]  =  weights[k];

        P[k] = tempP;
        values[k] = tempV;
        weights[k] = tempW;
      }
    }
  }

  //traverse<int>(weights, 5);
  // traverse<int>(values, 5);
  // traverse<float>(P, 5);
  // cout<<endl<<endl;

  // fill the knapsack according to weights
  // we only need the maximum value we achieved
  float maxValue = 0;
  for(int i = 0; i < size; ++i) {
    if(W == 0) {
      break;
    }
    else if(W >= weights[i]) {
      maxValue += values[i];
      W -= weights[i];
    }
    else if(W  < weights[i]) {
      // compute weights and put
      // for 1 unit weight, we need value
      float unitValue = values[i] / weights[i];
      maxValue += unitValue * W;
      W = 0;
    }
  }

  return maxValue;
}



int main() {
  // the input to the program
  int weights[] = { 5, 10, 20, 30, 40 };
  int values[]  = { 30, 20, 100, 90, 160 };
  int W = 60; // the max capacity of the knapsack

  cout<<"Max Value: "<<fractional_knapsack(weights, values, W, 5)<<endl;
  return 0;
}

#include<iostream>

using namespace std;

void traverse(int  arr[], int size) {
  for (int i = 0; i < size; ++i) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

// Job sequencing algorithm
void job_sequencing(int deadline[], int profit[], int size) {
  // sort the jobs accoding to the profit
  int maxDeadline = 0;
  for(int i = 0; i < size; ++i) {
    if(deadline[i] > maxDeadline) {
      maxDeadline = deadline[i];
    } 
  }

  cout<<"Max deadline is: "<<maxDeadline<<endl;

  for(int i = 0; i < size; ++i) {
    for(int k = i  +  1; k < size;  k++){
      if(profit[k] > profit[i]) {
        // swap
        int tempP = profit[i];
        int tempD = deadline[i];

        profit[i] = profit[k];
        deadline[i] = deadline[k];

        profit[k] = tempP;
        deadline[k] = tempD;
      }
    } 
  }
  traverse(profit, 5);
  traverse(deadline, 5);
  cout<<endl<<endl;

  // feasibility analysis
  
  // Initialize an array to mark time slots as unoccupied
  bool slots[maxDeadline] = {false};
  int processingSequence[size] = { 0 };

  int totalProfit = 0;
  int occupied = 0;

  for(int i = 0; i < size; ++i) {
    // Find a suitable slot for the job
    for (int j = min(maxDeadline, deadline[i]) - 1; j >= 0; --j) {
      if (!slots[j]) {
        // Job can be scheduled at this slot
        processingSequence[i] = j + 1;  // Store the slot (1-based index)
        totalProfit += profit[i];
        slots[j] = true;  // Mark the slot as occupied
        occupied++;
        break;
      }
    }
  }

  cout<<"Total Profit: "<<totalProfit<<endl;
  traverse(processingSequence,  5);
}


int main() {
  // The Given array are the deadline and th profit for jobs J(i).
  // What is the sequence of job to be finished under deadline givig us the maximum profit.
  int deadline[] = { 1 , 2 , 2 , 3 , 1 };
  int profit[] = { 100, 60 , 40 , 20 , 20 };

  job_sequencing(deadline, profit, 5);
  return 0;
}

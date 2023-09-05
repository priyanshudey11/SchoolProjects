#include <iostream>
#include <string>
using namespace std;

// Define the struct for each entry in the priority queue
struct pqEntry 
{
   string job;
    //stores priorty
   int priority;
   struct pqEntry *nextPtr;
};

// Function to insert a job with the given priority into the linked list
void insertJob(pqEntry* &head, pqEntry* &tail, int priority, string job) 
{
   // Create a new entry for the job
   // Allocate memory for a new pqEntry struct
   pqEntry* newEntry = new pqEntry;
   // Set the job name for the new entry
   newEntry->job = job;
   // Set the priority for the new entry
   newEntry->priority = priority;
   // Set the next pointer to null
   newEntry->nextPtr = nullptr;

// If the list is empty, insert the new entry as the head and tail
if (head == nullptr) 
{
    // Set the head to the new entry
   head = newEntry; 
    // Set the tail to the new entry
   tail = newEntry;   
}
// If the new entry has the highest priority, insert it at the head
else if (priority <= head->priority) 
{
    // Set the next pointer of the new entry to the current head
   newEntry->nextPtr = head;  
    // Set the head to the new entry
   head = newEntry;           
}
// Otherwise, traverse the list to find the correct position to insert the new entry
else 
{
    // Set a pointer to the current head of the list
   pqEntry* current = head;    
   while (current->nextPtr != nullptr && current->nextPtr->priority < priority) 
   {
        // Traverse the list until the next entry has a lower priority than the new entry
      current = current->nextPtr;  
   }
   // Insert the new entry before the first entry with lower priority
    // Set the next pointer of the new entry to the next entry in the list
   newEntry->nextPtr = current->nextPtr;   
    // Set the next pointer of the current entry to the new entry
   current->nextPtr = newEntry;            
   // If the new entry is inserted at the end of the list, update the tail
   if (newEntry->nextPtr == nullptr) 
   {
    // Set the tail to the new entry if it's inserted at the end of the list
      tail = newEntry;   
   }
}

   }


// Function to print out the priority queue from head to tail
void printQueue(pqEntry* head) 
{
    //current to head of list
   pqEntry* current = head;
   //until finished
   while (current != nullptr) 
   {
      cout << "Priority: " << current->priority << " Job: " << current->job << endl;
      current = current->nextPtr;
   }
}
int main() 
{
   // Initialize the head of the linked list to null
   pqEntry* head = nullptr; 
   // Initialize the tail of the linked list to null
   pqEntry* tail = nullptr; 
   int priority;
   string job;
   // Initialize a counter for the number of elements in the linked list
   int count = 0; 
   
   // Prompt the user for jobs and their priorities
   do 
   {
      cout << "Enter priority => ";
      cin >> priority;
      // If the user enters a negative priority, exit the loop
      if (priority < 0) {
         break;
      }
      cout << "Enter name of job => ";
      cin >> job;
      // Insert the new job into the linked list
      insertJob(head, tail, priority, job);
       // Increment the counter
      count++;
   } 
   while (count < 25 && head->priority <= 10 && tail->nextPtr == nullptr);
   
   // Print out the resulting queue
   printQueue(head);
   
   return 0;
}

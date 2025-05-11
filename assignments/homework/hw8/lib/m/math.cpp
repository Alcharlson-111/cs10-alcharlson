#include "math.h"
#include "../ih/inhandling.h"
#include <cmath>
#include <vector>

void sortLL(Node*& head)
{
    Node* curr = head->next; // Start from second node

    while (curr != nullptr)
    {
        Student* temp = curr->dptr; // Save data to temp
        Node* scan = curr->prev; // Set a previous node scanner

        
        while (scan != nullptr && scan->dptr->avg < temp->avg)
        {
            // Shift data forward to leaving an open space where
            // eventually temp will be re-added when prev < temp < next
            scan->next->dptr = scan->dptr; 
            scan = scan->prev;
        }

        if (scan == nullptr)
        {
            head->dptr = temp; // Insert at the beginning
            //  since temp is the lowest so far
        }
        else
        {
            scan->next->dptr = temp; // Insert after scan
            // the scan found a lesser grade
        }

        curr = curr->next; // Advance to next node
    }
}

void grade(Student * n)
{
    int t1 = n -> t1; // Save test scores to int
    int t2 = n -> t2;
    int t3 = n -> t3;
    int t4 = n -> t4;

    n -> avg = static_cast<float>(t1 + t2 + t3 + t4)/4; 
    // save struct avg var to float avg
    // cast to float to prevent int floor()
    int savg = static_cast<int>(floor(n->avg/10));
    
    
    switch (savg)
    {
    case (10):
        n->grade ='A';
        break;
    case (9):
        n->grade ='A';
        break;
    case (8):
        n->grade ='B';
        break;
    case (7):
        n->grade ='C';
        break;
    case (6):
        n->grade ='D';
        break;
    
    default:
        n->grade ='F';
        break;
    }
}

void getMax(int num, int &cmax)
{
    if (num > cmax) cmax = num;
}
void getMin(int num, int &cm)
{
    if (num < cm) cm = num;
}

void avg(Node *& head, float * arrptr)
{
    int ctr = 0;
    int t1c = 0, t2c = 0; // test counters
    int t3c = 0, t4c = 0;
    int t1m = 0, t2m = 0; // test max
    int t3m = 0, t4m = 0;
    int min1 = 100, min2 = 100; // test mins
    int min3 = 100, min4 = 100;
    
    Node * temp = head;
    while (temp/*->next*/ != nullptr)
    {
        Student *stemp = temp->dptr;
        t1c += stemp->t1; // append current score to counter
        t2c += stemp->t2;
        t3c += stemp->t3;
        t4c += stemp->t4;
        ctr++;
        getMax(stemp->t1, t1m); // compare current to current max
        getMax(stemp->t2, t2m);
        getMax(stemp->t3, t3m);
        getMax(stemp->t4, t4m);

        getMin(stemp->t1, min1); // compare current to current min
        getMin(stemp->t2, min2);
        getMin(stemp->t3, min3);
        getMin(stemp->t4, min4);


        // if (temp->next->next == nullptr)
        // {
        //     temp = temp->next;
        //     Student *stemp = temp->dptr;
        //     t1c += stemp->t1;
        //     t2c += stemp->t2;
        //     t3c += stemp->t3;
        //     t4c += stemp->t4;
        //     ctr++;
        //     getMax(t1c, t1m);
        //     getMax(t2c, t2m);
        //     getMax(t3c, t3m);
        //     getMax(t4c, t4m);

        //     getMin(t1c, t1m);
        //     getMin(t2c, t2m);
        //     getMin(t3c, t3m);
        //     getMin(t4c, t4m);
        //     break;
        // }
        temp = temp->next; // parse

    }

    if (ctr > 0) 
    { // this should always be true but just in case
    arrptr[0] = static_cast<float>(t1c) / ctr; // save to array
    arrptr[1] = static_cast<float>(t2c) / ctr;
    arrptr[2] = static_cast<float>(t3c) / ctr;
    arrptr[3] = static_cast<float>(t4c) / ctr;
    } else 
    {
        arrptr[0] = arrptr[1] = arrptr[2] = arrptr[3] = 0.0f;
        // pass zeros in place
    }

    arrptr[4] = t1m; // save max to array
    arrptr[5] = t2m;
    arrptr[6] = t3m;
    arrptr[7] = t4m;
    arrptr[8] = min1; // save min to array
    arrptr[9] = min2;
    arrptr[10] = min3;
    arrptr[11] = min4;
}


void gAvg(Node *& head, int * arr)
{
    Node * temp = head;
    int As = 0, Bs = 0, Cs = 0, Ds = 0, Fs = 0;
    // counters for grades
    int ctr = 0;

    while (temp != nullptr)
    {
        Student * n = temp->dptr;
        // save data to n
        ctr++; // increment counter

        switch (n->grade) // check char 
        {
        case 'A': As++; break; // Increment result
        case 'B': Bs++; break;
        case 'C': Cs++; break;
        case 'D': Ds++; break;
        case 'F': Fs++; break;
        default: break;
        }

        temp = temp->next;
    }

    if (ctr > 0)
    { // again this should always be true but just incase; 
        arr[0] = (As * 100) / ctr;
        arr[1] = (Bs * 100) / ctr;
        arr[2] = (Cs * 100) / ctr;
        arr[3] = (Ds * 100) / ctr;
        arr[4] = (Fs * 100) / ctr;
    }
    else
    {
        for (int i = 0; i < 5; ++i)
            arr[i] = 0;
    }
}

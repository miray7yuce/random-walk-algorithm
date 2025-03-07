#include <iostream>
#include <time.h>

using namespace std;

bool doneORnot(int** room, int n, int m);

int main()
{
    //starting the randomizing
    srand(time(0));

    const int iter_lim = 50000;
    int n=-1, m=-1, oldn=-1, oldm=-1, newn, newm;
    int defcounter=0;
    int totalmoves=0;

    //inputs
    while(n<2||n>40)
    {
        cout<<"Enter the column number of the grid between 2-40: ";
        cin>>n;
        defcounter++;
        if(defcounter>1)
        cout<<endl<<"Invalid number, try again!"<<endl;
    }

    defcounter=0;

    while(m<2||m>20)
    {
        cout<<"Enter the line number of the grid between 2-20: ";
        cin>>m;
        defcounter++;
        if(defcounter>1)
        cout<<endl<<"Invalid number, try again!"<<endl;
    }

    defcounter=0;

    while(oldn>=n||oldm>=m||oldn<0||oldm<0)
    {
        cout<<"Enter the starting point."<<endl<<"Column number:";
        cin>>oldn;
        cout<<endl<<"Line number:";
        cin>>oldm;
        defcounter++;
        if(defcounter>1)
        cout<<"Invalid number! Check your inputs."<<endl;
    }

    //generating 2D array

    int** room = new int*[n];
    for(int i=0; i<n ; i++)
    {
        room[i]=new int[m] {};
    }

    room[oldn][oldm]++;

    //walking simulation

    while (totalmoves < iter_lim) {
        do {
            newn = rand() % n;
        } while (newn < oldn - 1 || newn > oldn + 1);

        do {
            newm = rand() % m; 
        } while (newm < oldm - 1 || newm > oldm + 1);

        if (newn == oldn && newm == oldm) {
            continue;
        }

        oldn = newn;
        oldm = newm;
        room[newn][newm]++;
        totalmoves++;

        if (doneORnot(room, n, m)) {
            cout << "Simulation succeeded. Total moves: " << totalmoves << endl;
            break;
        }
    }

    if (totalmoves == iter_lim) {
        cout << "Simulation failed." << endl;
    }

    //Results
    cout << "Final room:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << room[i][j] << " ";
        }
        cout << endl;
    }
    

    for (int i = 0; i < n; i++) {
        delete[] room[i]; 
    }

    delete[] room;

    return 0;

}

bool doneORnot(int** room, int n, int m)
    {
        int counter=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(room[i][j]>0)
                {
                    counter++;
                }
            }
        }

        if(counter== n*m)
        {
            return true;
        }
        else
        {
            return false;
        }
    } 
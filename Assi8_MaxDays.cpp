#include <iostream>
using namespace std;
int Max_Days(int task[10], int size, int D)
{
    int mean, sum = 0, Max_Element = -1;
    int cal_days = 0, max = -1, Minimum_Days;
    if (D < size)
    {
        cout << "Invalid no. of Days";
        return -1;
    }
    for (int i = 0; i < size; i++)
    {
        sum += task[i];
        if (Max_Element < task[i])
        {
            Max_Element = task[i];
        }
    }
    mean = sum / size;

    while (mean > 0 && mean <= Max_Element)
    {
        for (int i = 0; i < size; i++)
        {
            int work = task[i];
            while (work != -1)
            {
                if (mean >= work)
                {
                    cal_days++;
                    work = -1;
                }
                while (mean < work)
                {
                    work -= mean;
                    cal_days++;
                }
            }
        }
        if (cal_days == D)
        {
            return mean;
        }
        else if (cal_days < D)
        {
            mean--;
        }
        else
        {
            mean++;
        }
        if (max < cal_days && cal_days < D)
        {
            max = cal_days;
            Minimum_Days = mean;
        }
    }

    return Minimum_Days;
}

int main()
{
    int size, task[10], Minimum_Work, D;
    cout << "Enter no. of Task : ";
    cin >> size;
    cout << "Enter Tasks : ";
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << " ] : ";
        cin >> task[i];
    }
    cout << "Enter Days : ";
    cin >> D;
    Minimum_Work = Max_Days(task, size, D);
    if (Minimum_Work != -1)
    {
        cout << "Minimum Work need to be done on each day is : " << Minimum_Work;
    }
    return 0;
}

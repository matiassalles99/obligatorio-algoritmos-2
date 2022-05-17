#ifndef MF_SET
#define MF_SET

using namespace std;

class MFSet
{
private:
    int * sets;

public:
    MFSet(int N)
    {
        this->sets = new int[N + 1];
        for (int n = 1; n <= N; n++)
        {
            this->sets[n] = -1;
        }
    }

    int find(int n)
    {
        int n_parent = this->sets[n]; 
        if (n_parent == -1)
        {
            return n;
        }
        int n_representative = find(n_parent);
        return n_representative;
    }

    void merge(int n1, int n2)
    {   
        int n1_representative = find(n1);
        int n2_representative = find(n2);
        this->sets[n2_representative] = n1_representative; 
    }

    int amountConnectedComponents(int N)
    {
        int amount = 0;
        for(int n = 1; n <= N; n++)
        {
            if (this->sets[n] == -1)
            {
                amount ++;
            }
        }
        return amount;
    }

};

#endif
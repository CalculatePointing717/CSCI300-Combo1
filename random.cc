/*
    CRandom Class.
*/

#include <random>
#include <vector>
#include <algorithm>
using namespace std;

class CRandom
{
    public:
    CRandom()
    {
        random_device rd;
        rng = new mt19937(rd());
    }

    ~CRandom()
    {
        delete rng;
    }

    // Return integer in [a,b].
    int randint(int a, int b)
    {
        uniform_int_distribution<int> dist(a, b);
        return dist(*rng);
    }

    // Shuffle vector.
    template<typename T>
    void shuffle_vec(vector<T>& vec)
    {
        shuffle(vec.begin(), vec.end(), *rng);
    }

    // Pop random index from 0 to n-1.
    template<typename T>
    T random_pop(vector<T>& vec)
    {
        int index = randint(0, (int)vec.size() - 1);
        T val = vec[index];
        vec.erase(vec.begin() + index);
        return val;
    }

    private:
    mt19937* rng;
};

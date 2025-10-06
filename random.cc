/*
    CRandom Class.
*/

#include <random>
#include <vector>
#include <algorithm>

class CRandom
{
    public:
    CRandom()
    {
        std::random_device rd;
        rng = std::mt19937(rd());
    }

    // Return integer in [a,b].
    int random_int(int a, int b)
    {
        std::uniform_int_distribution<int> dist(a, b);
        return dist(rng);
    }

    // Shuffle vector.
    template<typename T>
    void shuffle_vec(std::vector<T>& vec)
    {
        shuffle(vec.begin(), vec.end(), rng);
    }

    // Pop random index from 0 to n-1.
    template<typename T>
    T random_pop(std::vector<T>& vec)
    {
        int index = random_int(0, (int)vec.size() - 1);
        T val = vec[index];
        vec.erase(vec.begin() + index);
        return val;
    }

    private:
    std::mt19937 rng;
};

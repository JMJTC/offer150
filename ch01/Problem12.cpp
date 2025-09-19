#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include <vector>

class RandomizedSet
{
  public:
    RandomizedSet()
    {
        srand((unsigned)time(NULL));
    }

    bool insert(int val)
    {
        if (map.count(val) != 0)
        {
            return false;
        }
        int index = vec.size();
        vec.push_back(val);
        map.insert({val, index});
        return true;
    }

    bool remove(int val)
    {
        if (map.count(val) == 0)
        {
            return false;
        }
        int index = map.at(val);
        int last = vec.back();
        vec[index] = last;
        map[last] = index;
        vec.pop_back();
        map.erase(val);
        return true;
    }

    int getRandom()
    {
        int randomIndex = rand() % vec.size();
        return vec[randomIndex];
    }

  private:
    std::vector<int> vec{};
    std::unordered_map<int, int> map{};
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
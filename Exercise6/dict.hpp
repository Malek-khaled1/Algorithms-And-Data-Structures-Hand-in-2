#ifndef _DICT_HPP
#define _DICT_HPP
#include <cstdlib>
#include<vector>
#include<utility>

template<typename KeyType, typename ValueType>
class Dict
{
private:
    std::vector<std::pair<KeyType, ValueType>> dictionary;
public:
    Dict(){}
    ~Dict(){}

    // inserts a pair: returns false if key already exists else true
    bool insert(const KeyType& key, const ValueType& value);
    // Remove pair: returns true if removed else false
    bool remove(const KeyType& key);
    // find pair: returns true if found else false
    bool contains(const KeyType& key) const;

    // operator[]: accessing and changing values specified with key.
    ValueType& operator[](const KeyType& key);
    // Returns size of dictionary
    size_t size() const {return dictionary.size();}
    // returns true if empty else false
    bool isEmpty() const {return dictionary.empty();}

};

template<typename KeyType, typename ValueType>
bool Dict<KeyType, ValueType>::insert(const KeyType& key, const ValueType& value)
{
    for (auto& i : dictionary) // iterate through dictionary
    {
        if (i.first == key) // compare keys
        {
            return false;
        }
    }
    
    dictionary.emplace_back(key, value); // insert pair in the back
    return true;
}


template<typename KeyType, typename ValueType>
bool Dict<KeyType, ValueType>::remove(const KeyType& key)
{
    if (dictionary.empty()){return false;} // if empty return false
    
    for(auto itr = dictionary.begin(); itr != dictionary.end(); ++itr)
    {
        if(itr->first == key){ // if key exists
            dictionary.erase(itr); // delete element
            return true;
        }
    }
    return false; // key not found

}

template<typename KeyType, typename ValueType>
bool Dict<KeyType, ValueType>::contains(const KeyType& key) const
{
    if (dictionary.empty()){return false;} // if empty return false

     for(auto itr = dictionary.begin(); itr != dictionary.end(); ++itr)
    {
        if(itr->first == key){return true;}  // if key exists: return true
    }
    return false; // key not found
}


template<typename KeyType, typename ValueType>
ValueType& Dict<KeyType, ValueType>::operator[](const KeyType& key)
{
    for (auto& i : dictionary)
    {
        if (i.first == key) // cmp keys
        {
            return i.second; // return value corresponds to key
        }   
    }
    dictionary.emplace_back(key, ValueType{}); // deafult: create pair with key and default valuetype
    return dictionary.back().second; // return reference to ValueType
}

#endif
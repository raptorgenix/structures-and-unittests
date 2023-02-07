#ifndef HASHMAP_h
#define HASHMAP_h

#include<iostream>
#include<vector>
#include<map>
#include <functional>
#include<set>

//template <typename T> class Counter;

template <class T> class HashMap{
    public:
    
        const int numbuckets = 30;
        HashMap(){
            for(int i = 0; i < numbuckets; i++){
                std::vector<T> v = {};
                vector_.push_back(v);
            }
        };
        
        
        int hashKey (T val) //generate hashkey with standard library
        {
            std::hash<T> hashnum;
            unsigned int bucket = hashnum(val);

            return (bucket%numbuckets); //30 buckets defualted
        }

        void insertElement(T val){ //insert value after getting bucket
            int bucket = hashKey(val);
            
            vector_[bucket].push_back(val);
            

            
        }
        bool search(T val){
            int bucket = hashKey(val); //get bucket
            for(int i = 0; i < vector_[bucket].size(); i++){//iterate through bucket
                if(vector_[bucket][i] == val){
                    return true;
                }
            }
            return false;
        }
    
    
        void deleteElement(T val){
            int bucket = hashKey(val);
            auto removed = std::remove(vector_[bucket].begin(), vector_[bucket].end(), val);//erase/remove idiosyncracy because of issues that arose using just erase
            vector_[bucket].erase(removed, vector_[bucket].end()); //erase from vector inside of other vector

                
        }

        template<typename U>
        friend std::ostream& operator<<(std::ostream& os, const HashMap<U> &m);


    private:
    std::vector<std::vector<T>> vector_;
};

template<typename U>
std::ostream& operator<<(std::ostream& os, const HashMap<U> &m){
    std::cout << "{ ";
    for(auto i : m.vector_)
        {
         for(auto j : i)
            std::cout << j <<", ";
         
        }

    std::cout << "}";
    return os;
}

#endif 
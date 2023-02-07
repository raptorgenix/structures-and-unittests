#ifndef LINEAR_h
#define LINEAR_h

#include<iostream>
#include<vector>
#include<map>
#include<set>

template <class T> class Linear {
    public:
        Linear(){
        vector_ = {}; //initialize empty vector
        };
        
        
        void insertElement(T val){
           vector_.push_back(val);//add value to vector
        }

        T getElementAtIndex(int index){
           return vector_[index]; //return index val
        }

        bool search(T val){
            auto iter = std::find(vector_.begin(), vector_.end(), val); //get iterator for position of val
            if(iter != vector_.end()){//if it is not the end of the vector, the element was found
                return true;
            }
            else{
                return false;
            }
        }
        void deleteElement(T val){
            auto iter = std::find(vector_.begin(), vector_.end(), val);//get value iterator
            int ind = distance(vector_.begin(), iter); //get value index from iterator
            vector_.erase(vector_.begin() + ind);//erase value

        }
    
    
    
    
    
    
    // ARRAY IMPLEMENTATION FOR EXTRA CREDIT
    
    
    
    
    
    
//          void insertElementArray(T val){
//            array_.push(val);//add value to vector
//         }

//         T getElementAtIndexArray(int index){
//            return array_[index]; //return index val
//         }

//         bool searchArray(T val){
//             for( int i = 0; i < array_.size(); i ++){
//                 if(array_[i] == val);
//             }//get iterator for position of val
//             if(iter != vector_.end()){//if it is not the end of the vector, the element was found
//                 return true;
//             }
//             else{
//                 return false;
//             }
//         }
//         void deleteElementArray(T val){
//             auto iter = std::find(vector_.begin(), vector_.end(), val);//get value iterator
//             int ind = distance(vector_.begin(), iter); //get value index from iterator
//             vector_.erase(vector_.begin() + ind);//erase value

//         }


        template<typename U>
        friend std::ostream& operator<<(std::ostream& os, const Linear<U> &l);
    private:
        std::vector<T> vector_;
//         T array_[];
};

template<typename U>
std::ostream& operator<<(std::ostream& os, const Linear<U> &l){
    std::cout << "{";
    for(int i = 0; i < l.vector_.size(); i++){
        std::cout << l.vector_.at(i) << ", " ;
        
    }
    std::cout << "}" << std::endl;
    return os;
}

#endif 
#include <vector>
#include <iostream>


void bubble_sort(std::vector<int> & vec){
    for(int i{0}; i < vec.size(); i++){
        for(int j{0}; j < vec.size() - i - 1; j++){
            if(vec[j] > vec[j+1]){
                std::swap(vec[j], vec[j+1]);
            }
        }
    }
}

void selection_sort(std::vector<int> & vec){
    for(int i{0}; i < vec.size(); i++){
        for(int j{i+1}; j < vec.size(); j++){
            if(vec[i] > vec[j]){
                std::swap(vec[i], vec[j]);
            }
        }
    }
}

// size_t quick_sort_partition(std::vector<float> & vec, size_t left, size_t right, size_t const pivot);


// void quick_sort(std::vector<float> & vec, size_t const left, size_t const right);



// void quick_sort(std::vector<float> & vec) {
//     quick_sort(vec, 0, vec.size() - 1);
// }

// void merge_sort_merge(std::vector<float> & vec, size_t const left, size_t const middle, size_t const right);
void displayVec(std::vector<float> const& vec){
    std::cout << "[" ;
    for(float element : vec){
        std::cout << element << ", ";
    }
    std::cout << "]" << std::endl;
}

void merge_sort(std::vector<float> & vec, size_t const left, size_t const right){
    if(right - left > 1){
        std::cout << "-> Je rentre dans la sous fonction de taille : " << right - left + 1<< std::endl;
        if(right - left < 100){
            merge_sort(vec, left, left + (right-left)/2);
            // std::cout << "left + 1 + right/2 : " << left + 1 + right/2 << std::endl;
            // std::cout << "right : " << right << std::endl;

            merge_sort(vec, left + 1 + (right-left)/2 , right);
        }

    }

    std::cout << "-> j'attaque le tri dans un tableau de taille : " << right - left + 1 << std::endl;
    // std::cout << "left : " << left << std::endl;
    // std::cout << "right : " << right << std::endl;
    std::vector<float> vecCopy = vec;
    int indicePivotFirst = left;
    int indicePivotSecond = left + ((right-left)/2) + 1;

    for(size_t i{left}; i < right + 1; i++){
        if((indicePivotFirst < left + ((right-left)/2) + 1) && (indicePivotSecond < right + 1)){
            if(vecCopy[indicePivotFirst] > vecCopy[indicePivotSecond]){
                vec[i] = vecCopy[indicePivotSecond];
                indicePivotSecond += 1;
            }
            else{
                vec[i] = vecCopy[indicePivotFirst];
                indicePivotFirst += 1;
            }
        }
        else{
            if(indicePivotSecond >= right + 1){
                vec[i] = vecCopy[indicePivotFirst];
                indicePivotFirst += 1;
            }
            else{
                vec[i] = vecCopy[indicePivotSecond];
                indicePivotSecond += 1;
            }
        }
    }

    std::cout << "En sortie : ";
    displayVec(vec);
    std::cout << std::endl;

}



// void merge_sort(std::vector<float> & vec) {
//     merge_sort(vec, 0, vec.size() - 1);
// }
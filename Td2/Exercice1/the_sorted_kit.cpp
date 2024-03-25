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
        int indicePivot{i};
        for(int j{i}; j < vec.size(); j++){
            if(vec[j] < vec[indicePivot]){
                indicePivot = j;
            }
        }
        std::swap(indicePivot, i);
    }
}

// size_t quick_sort_partition(std::vector<float> & vec, size_t left, size_t right, size_t const pivot);


// void quick_sort(std::vector<float> & vec, size_t const left, size_t const right);



// void quick_sort(std::vector<float> & vec) {
//     quick_sort(vec, 0, vec.size() - 1);
// }

void displayVec(std::vector<float> const& vec){
    std::cout << "[" ;
    for(float element : vec){
        std::cout << element << ", ";
    }
    std::cout << "]" << std::endl;
}

void merge_sort(std::vector<float> & vec, size_t const left, size_t const right){
    size_t middle {(right-left)/2};
    if(right - left > 1){
        // std::cout << "-> Je rentre dans la sous fonction de taille : " << right - left + 1<< std::endl;

        merge_sort(vec, left, left + middle);
        // std::cout << "left + 1 + right/2 : " << left + 1 + right/2 << std::endl;
        // std::cout << "right : " << right << std::endl;

        merge_sort(vec, left + 1 + middle , right);
    

    }

    // std::cout << "-> j'attaque le tri dans un tableau de taille : " << right - left + 1 << std::endl;
    // std::cout << "left : " << left << std::endl;
    // std::cout << "right : " << right << std::endl;
    std::vector<float> vecCopy = vec;
    int indicePivotFirst = left;
    int indicePivotSecond = left + middle + 1;

    for(size_t i{left}; i < right + 1; i++){
        if((indicePivotFirst < left + middle + 1) && (indicePivotSecond < right + 1)){
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

    // std::cout << "En sortie : ";
    // displayVec(vec);
    // std::cout << std::endl;

}



void merge_sort(std::vector<float> & vec) {
    merge_sort(vec, 0, vec.size() - 1);
}

int search(std::vector<int> vec, int number){
    int left {0};
    int right {int(vec.size()- 1)};
    int indiceOfNumber{(right - left)/2};

    while(vec[indiceOfNumber] != number){
        int checkIfRepetition = indiceOfNumber;
        if(vec[indiceOfNumber] < number){
            left = indiceOfNumber + 1;
            indiceOfNumber = indiceOfNumber + (right + 1 - left)/2;
            if(left == right){
                indiceOfNumber = left;
            }
        }
        else{
            right = indiceOfNumber - 1;
            indiceOfNumber = (right + 1 - left)/2;
        }
        if(checkIfRepetition == indiceOfNumber){
            return -1;
        }
    }

    return indiceOfNumber;
}

void counting_sort(std::vector<int> & vec, const size_t max){

    std::vector<int> biblio (max + 1, 0);

    for(int number : vec){
        biblio[number] += 1;
    }

    std::vector<int> vecResult;

    int i{0};
    while( i < max + 1){
        if(biblio[i] != 0){
            for(int x{0}; x < biblio[i]; x++){
                vec[i] = i;
            }
        }
        i++;
    }

    vec = vecResult;
}


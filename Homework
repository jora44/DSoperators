#include "complex.h"
#include <iostream>
#include <cmath>

std::ostream& operator<<(std::ostream& out, const Complex& object) {
    out<<object.real<<'+'<<object.img<<'i'<<std::endl;
    return out;
 }

Complex::Complex(): real(0), img(0) {};

Complex::Complex(int r,int i): real(r), img(i) {}; 

Complex& Complex::operator=(const Complex&number){ 
    if (this != &number){ 
        real=number.real;
        img=number.img;
    }
    return *this;
    
}

Complex& Complex::operator+(const Complex&number){
    real += number.real;
    img += number.img;
    return *this;
}

Complex& Complex::operator*(int num){
    real *= num;
    img *= num;    
    return *this;
}

double Complex::abs(){ 
    double dis=0;
    dis = sqrt(pow(real, 2)+pow(img,2));
    return dis;
}

void sort(Complex arr[], int size){
        for (int i=0; i<size;++i){ 
            for (int j = i+1; j < size; j++)
            {
                if(arr[i].real > arr[j].real || 
                        (arr[j].real == arr[i].real && arr[i].img> arr[j].img))              
                    
                    std::swap(arr[i],arr[j]);             
            }
        }    
    }

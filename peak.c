#include <stdio.h>
int mass[5] = {2, 5, 6, 9, 3}; 
int less(unsigned long , unsigned long );
unsigned long peak(unsigned long , int (*)(unsigned long , unsigned long ));
int main() {
    printf("%lu", peak(5, less));
  
    return 0; 
} 

int less(unsigned long i, unsigned long j) {
    if (mass[i] < mass[j])
        return 1;
    return 0;
}
unsigned long peak(unsigned long nel, int (*less)(unsigned long i, unsigned long j)) {
   
    if (nel == 1)
        return 0; 
    
  
    else if (nel == 2){
        if(mass[0] >= mass[1])
            return 0;
        return 1; 
    }
  
   
    for (unsigned long i = 0; i < nel - 1; i++) {
        if ((i > 0 && !less(i, i - 1)) && (i < nel - 1 && !less(i, i + 1)))
            return i; 
    }
   
    return 0;
}

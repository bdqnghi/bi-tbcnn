#include <stdio.h>
#include <stdlib.h> //rand()

//Sortiert ein Integer-Array vom links nach rechts aufsteigend
typedef struct {
    int vgl; // Anzahl Vergleiche
    int vts; // Anzahl Vertauschungen
} statistik;
typedef struct {
    int from;
    int to;
} range;

statistik arrsort(int *arr, int arrsize);
void print_arr(int *arr, int arrsize); //print sorted array content
int* gen_arr(int arrsize, range indexval); //generate an int array w/ random content

int main(){
    statistik stat;
    int *arr;
    int arr_len;
    range indexval; // specify range in which the values will lie
    printf("Wie groß soll das Array werden?: ");
        scanf("%d", &arr_len);
    printf("In Welchem Bereich sollen die Werte liegen?\n von: ");
        scanf("%d", &(indexval.from));
    printf(" bis: ");
        scanf("%d", &(indexval.to));
    
    arr = gen_arr(arr_len, indexval);

    print_arr(arr, arr_len);
    stat = arrsort(arr, arr_len);
    printf("Vergleiche: %d\nVertauschungen: %d\n", stat.vgl, stat.vts);
    print_arr(arr, arr_len);
    
    free(arr);
}

statistik arrsort(int *arr, int arrsize){
    /* Variable Initialization */
    statistik stat;
    stat.vts=0;
    stat.vgl=0;
    int max=0;

    for(int i=0; i<(arrsize); i++){
        printf("sorting element %d of %d\n", i+1,arrsize);
        max=0; // null max from last cycle
        int c; //make c avaliable after the loop
        for(c=1; c<(arrsize-i); c++){    
            if(arr[c]>arr[max]){
                max=c; //save index where maximum is
		printf("new max: %d at index %d\n", arr[max], max);
                (stat.vgl)++; //iterate comparisons
            }             
        } c--; //loop iterates one, compensate
        //swap val @ index c with val @ index which is max
        int tmp = arr[c]; // save 'original' value of last index of loop
        arr[c] = arr[max]; // copy max value to last index of loop
        arr[max] = tmp; // copy 'original' value to place of max
        (stat.vts)+=1; //iterate swaps
        print_arr(arr, arrsize);
    }
    putchar('\n');
    
    return stat;
}
void print_arr(int *arr, int arrsize){
    printf("|");
    for(int i=0; i<arrsize; i++) printf(" %d |", arr[i]);
    putchar('\n');
}

int* gen_arr(int arrsize, range indexval){
    int *arr;
    int tmpval;
    if((arr = (int*)calloc(arrsize, sizeof(int))) == NULL){
        printf("Entschuldigung, die Speicherallokation schlug fehl: beende...\n");
        exit(1);
    }
    if(indexval.from>indexval.to){
        printf("Eingabefehler: beende...\n");
        exit(1);
    }
    printf("Filling array and checking for duplicates...\n");
    for(int i=0; i<arrsize; i++){
        if(indexval.to==0){ //else division by zero
            tmpval = rand()+(indexval.from);
        } else{
            tmpval = rand()%(indexval.to)+(indexval.from);
        }
        for(int c=0; c<arrsize; c++){ //check for duplicates
            printf("\rfilled %d of %d elements | current: %d", i+1, arrsize, tmpval);
            
            if(tmpval == arr[c]){
                i--;
                break; //go generate a new number
            }
            else{
                arr[i] = tmpval;
                break; //gen new number and hope the next index will also be valid
            }
        }
    }
    putchar('\n');
    return arr;
}

#include "linkedlist.h"

//Constructor
// Intiiliases the linked list by setting the head value as -1 and head->next as NULL
linkedlist::linkedlist()
{
    head = new node;
    head->index = -1;
    head->next = NULL;
}

// Used to search for the pattern string in the given linked list, and outputs the index at which pattern matches
// Also outputs to the file
// Meant for Q2
int linkedlist::searchin(string P, string st, int m, ofstream& fout2)
{
    // Number of matches
    int matches = 0;

    // The linked list is empty, (head->index =-1)
    // Hash code doesn't match with any string
    if (head->index == -1) {
        return matches;
    }

    // Linked list is not empty
    // Hash code matches
    else {
        // Used to extract the substring from the string st
        string x;
        // Used to traverse the linked list
        node* t = head;

        // While you don't reach the end of file
        while (t != NULL) {
            // Extract the substring at index t->index till m length from string st
            x = st.substr(t->index, m);
            // If the two string are same, then
            // hash code matches and string matches
            if (scomp(P, x, m) == 0) {
                // Output standard output and to file output
                cout << "Pattern " << P << " found at index " << t->index << endl;
                fout2 << "Pattern " << P << " found at index " << t->index << endl;
                // Increment the number of matches
                matches++;
            }
            // Go to next node
            t = t->next;
        }
    }
    // If there are in any matches, then output the no of matches for that particular string
    if (matches > 0) {
        cout << "There are " << matches << " matches for pattern " << P << "\n\n";
        fout2 << "There are " << matches << " matches for pattern " << P << "\n\n";
    }

    return matches;
}

// Used to search for the pattern string in the given linked list
// Then calculates the comparisons and false positives in the form of tuple
tuple* linkedlist::search(string P, string st, int m)
{
    // Number of false positives, comparison and matches
    int falsepos = 0, comp = 0, match = 0;

    // The linked list is empty, (head->index =-1)
    // Hash code doesn't match with any string
    if (head->index == -1) {
        // Construct tuple with comp=0 and falsepos=0 and return it
        tuple* y = new tuple(comp, falsepos);
        return y;
    }

    // Linked list is not empty
    // Hash code matches
    else {
        // Used to extract the substring from the string st
        string x;
        // Used to traverse the linked list
        node* t = head;

        // While you don't reach the end of file
        while (t != NULL) {
            // Increment the no of comparisons, because you are comparing a substring with the pattern string
            comp++;
            // Extract the substring at index t->index till m length from string st
            x = st.substr(t->index, m);
            // If the two string are same, then
            // hash code matches and string matches then
            // Increment the number of matches
            if (scomp(P, x, m) == 0)
                match++;

            // Go to next node
            t = t->next;
        }
    }

    // If matches=0, which means there were comparisons but no matches were found, then
    // Set false positive as 1
    if (match == 0)
        falsepos = 1;

    // Make the tuple with values of comparisons and false postive and return it
    tuple* x = new tuple(comp, falsepos);
    return x;
}

// Adds a given item (index) to the linked list
void linkedlist::add(int i)
{
    // If the linked list is empty, then set the head->index=1
    if (head->index == -1)
        head->index = i;
    // If the linked list is not empty, then make a new node, and add it after head
    else {
        node* t = new node;
        t->index = i;
        t->next = head->next;
        head->next = t;
    }
}

linkedlist::~linkedlist()
{
    //dtor
}

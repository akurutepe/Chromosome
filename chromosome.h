#ifndef CHM_H
#define CHM_H
#include<iostream>
using namespace std;

typedef enum Nucleic_Acid { Adenine,Cytosine,Guanine,Thymine,Nullin };
typedef enum Chromatid_Pos {SL,SR,BL,BR};

class Node
{

private:
    Nucleic_Acid value;
    Node *pNext;

public:
    Node(void)
    : pNext(NULL)
    { }

    Node(Nucleic_Acid val)
    : value(val), pNext(NULL)
    { }

    Node(Nucleic_Acid val, Node* next)
    : value(val), pNext(next)
    {}
    void setNext(Node* next)
    { pNext = next; }

    void setValue(Nucleic_Acid val)
    { value = val; }

    Nucleic_Acid getValue(void)
    { return value; }

    Node* getNext(void)
    { return pNext; }
};


class Chromosome
{
    private:

    Node *pLarmHead;
    Node *pRarmHead;
    Node *pLarm;
    Node *pRarm;
    Node *pLarmT;
    Node *pRarmT;

    int centroLeft;
    int centroRight;


    public:
        void setCentromerL(int newCent);
        void setCentromerR(int newCent);


        //These are the methods required to be implemented
        Chromosome(Nucleic_Acid Seq_L[], Nucleic_Acid Seq_R[], int centromere);
        friend ostream& operator<<(ostream &out, Chromosome &C);

        void Deletion(Chromatid_Pos pos, int start, int finish);

        void Duplication(Chromatid_Pos pos, int start, int finish);

        void Inversion(Chromatid_Pos pos, int start, int finish);



        void Insertion(Chromatid_Pos source_pos, int start, int finish, int insertion_point)
        {
            cout<< "no implementation yet" << endl;
        }
        void Translocation(Chromatid_Pos pos1, int start1, int finish1, int start2, int finish2)
        {
            cout<< "no implementation yet" << endl;
        }

        int Sequence_Occurences(Nucleic_Acid Seq[])
        {
            cout<< "no implementation yet" << endl;
        }



};
#endif

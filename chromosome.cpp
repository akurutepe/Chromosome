/* CENG 707 HW 1  */

/* STUDENT INFORMATION
   -------------------
Name   : Alican
Surname: Kurutepe
Number : 1902618
 */


#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<chromosome.h>

using namespace std;



Chromosome::Chromosome(Nucleic_Acid Seq_L[], Nucleic_Acid Seq_R[], int centromere)
{
    int i = 0;

    centroLeft = centromere;
    centroRight = centromere;

    pLarmHead = new Node(*Seq_L);
    pRarmHead = new Node(*Seq_R);


    pLarm = pLarmHead;
    pRarm = pRarmHead;




    i=1;
    while (pLarm->getValue() != Nullin)
    {
        pLarmT = pLarm->getNext();
        pLarmT = new Node(Seq_L[i]);
        pLarm->setNext(pLarmT);
        pLarm = pLarmT;
        i++;
    }

    i=1;
    while (pRarm->getValue() != Nullin)
    {
       pRarmT = pRarm->getNext();
       pRarmT = new Node(Seq_R[i]);
       pRarm->setNext(pRarmT);
       pRarm = pRarmT;
       i++;
    }

}

ostream& operator<<(ostream &out, Chromosome &C)
{
    int i = 0;
    int centroDiff = 0;
    C.pLarm = C.pLarmHead;
    C.pRarm = C.pRarmHead;

    if(C.centroRight > C.centroLeft)
    {
        centroDiff = C.centroRight-C.centroLeft;
        for( i =0; i<centroDiff;i++)
        {
            cout<<" ";
        }
    }
    i = 0;
    while(i < C.centroLeft)
    {
        switch (C.pLarm->getValue())
        {
            case Adenine: out<<'A';break;
            case Guanine: out<<'G';break;
            case Cytosine: out<<'C';break;
            case Thymine: out<<'T';break;
            case Nullin: out<<'N';break;
            default: break;
        }
       i++;
       C.pLarm = C.pLarm->getNext();
    }

    cout<<"  ";

    while(C.pLarm->getValue() != Nullin)
    {
        switch (C.pLarm->getValue())
        {
            case Adenine: out<<'A';break;
            case Guanine: out<<'G';break;
            case Cytosine: out<<'C';break;
            case Thymine: out<<'T';break;
            case Nullin: out<<'N';break;
            default: break;
        }

       C.pLarm = C.pLarm->getNext();
    }
    cout<<endl;

    i = 0;
    while(i < C.centroLeft + centroDiff)
    {
       cout<<" ";
       i++;

    }

    cout<<"\\/"<<endl;

    centroDiff = 0;
    i=0;
    if(C.centroLeft > C.centroRight)
    {
        centroDiff = C.centroLeft-C.centroRight;
    }


    i = 0;
    while(i < C.centroRight + centroDiff)
    {
       cout<<" ";
       i++;

    }
    cout<<"/\\"<<endl;

    if(C.centroLeft > C.centroRight)
    {

        for( i =0; i< centroDiff;i++)
        {
            cout<<" ";
        }
    }

    i = 0;
    while(i < C.centroRight)
    {
        switch (C.pRarm->getValue())
        {
            case Adenine: out<<'A';break;
            case Guanine: out<<'G';break;
            case Cytosine: out<<'C';break;
            case Thymine: out<<'T';break;
            case Nullin: out<<'N';break;
            default: break;
        }
       i++;
       C.pRarm = C.pRarm->getNext();
    }

    cout<<"  ";

    while(C.pRarm->getValue() != Nullin)
    {
        switch (C.pRarm->getValue())
        {
            case Adenine: out<<'A';break;
            case Guanine: out<<'G';break;
            case Cytosine: out<<'C';break;
            case Thymine: out<<'T';break;
            case Nullin: out<<'N';break;
            default: break;
        }

       C.pRarm = C.pRarm->getNext();
    }
    cout<<endl;



    return out;
}

void Chromosome::setCentromerL(int newCent)
{
    this->centroLeft = newCent;
}
void Chromosome::setCentromerR(int newCent)
{
    this->centroRight = newCent;
}


void Chromosome::Deletion(Chromatid_Pos pos, int start, int finish)
{
    int delStart = start;
    int delFinish = finish;
    int delNumber = finish - start;
    int i=0;
    Node* pDeletor;
    Node* pTemp;

    if(pos == BL || pos == SL)
    {
        pDeletor = this->pLarmHead;

        if(pos == BL)
        {
            delStart = delStart + this->centroLeft;
            delFinish = delFinish + this->centroLeft;
        }

        while(i<delStart-1)
        {
            pDeletor = pDeletor->getNext();
            i++;
        }

        pTemp = pDeletor;

        while(i<delFinish)
        {
            pDeletor = pDeletor->getNext();
            i++;
        }

        pTemp->setNext(pDeletor->getNext());

        if(pos == SL)
        {
            this->centroLeft -= delNumber+1;
        }
    }
    else if(pos == BR || pos == SR)
    {
        pDeletor = this->pRarmHead;

        if(pos == BR)
        {
            delStart = delStart + this->centroRight;
            delFinish = delFinish + this->centroRight;
        }

        while(i<delStart-1)
        {
            pDeletor = pDeletor->getNext();
            i++;
        }

        pTemp = pDeletor;

        while(i<delFinish)
        {
            pDeletor = pDeletor->getNext();
            i++;
        }

        pTemp->setNext(pDeletor->getNext());

        if(pos == SR)
        {
            this->centroRight -= delNumber+1;
        }
    }
}

void Chromosome::Duplication(Chromatid_Pos pos, int start, int finish)
{
    Node* pCurrent;
    Node* pDuplicator;
    Node* pDuplicatorT;
    Node* pDuplicatorHead;
    Node* pRest;

    int dupStart = start;
    int dupFinish = finish;
    int dupNumber = finish - start;


    if(pos == BL || pos == SL)
    {
        pCurrent = pLarmHead;
        if(pos == BL)
        {
            dupStart += centroLeft;
            dupFinish += centroLeft;
        }
        for(int i = 0;i<dupStart;i++)
        {
            pCurrent = pCurrent->getNext();
        }


        pDuplicatorHead = new Node(pCurrent->getValue());
        pDuplicator = pDuplicatorHead;

         for(int i = dupStart ;i<dupFinish;i++)
        {
            pCurrent=pCurrent->getNext();
            pDuplicatorT = new Node(pCurrent->getValue());
            pDuplicator->setNext(pDuplicatorT);
            pDuplicator = pDuplicatorT;
            pDuplicatorT = pDuplicatorT->getNext();
        }

        pRest = pCurrent->getNext();
        pCurrent->setNext(pDuplicatorHead);
        pDuplicator->setNext(pRest);

        if(pos == SL)
        {
            centroLeft += dupNumber+1;
        }

    }

    else if(pos == BR || pos == SR)
    {
        pCurrent = pRarmHead;
        if(pos == BR)
        {
            dupStart += centroRight;
            dupFinish += centroRight;
        }
        for(int i = 0;i<dupStart;i++)
        {
            pCurrent = pCurrent->getNext();
        }


        pDuplicatorHead = new Node(pCurrent->getValue());
        pDuplicator = pDuplicatorHead;

         for(int i = dupStart ;i<dupFinish;i++)
        {
            pCurrent=pCurrent->getNext();
            pDuplicatorT = new Node(pCurrent->getValue());
            pDuplicator->setNext(pDuplicatorT);
            pDuplicator = pDuplicatorT;
            pDuplicatorT = pDuplicatorT->getNext();
        }

        pRest = pCurrent->getNext();
        pCurrent->setNext(pDuplicatorHead);
        pDuplicator->setNext(pRest);

        if(pos == SR)
        {
            centroRight += dupNumber+1;
        }

    }
}
void Chromosome::Inversion(Chromatid_Pos pos, int start, int finish)
{
    Node* pCurrent;
    Node* pInverter;
    Node* pInverterT;
    Node* pInverterHead;
    Node* pRest;

    int invStart = start;
    int invFinish = finish;
    int invNumber = finish - start;
    int theDecrementer;


    if(pos == BL || pos == SL)
    {
        pCurrent = pLarmHead;
        if(pos == BL)
        {
            invStart += centroLeft;
            invFinish += centroLeft;
        }

        for(int i = 0; i<invFinish; i++)
        {
            pCurrent = pCurrent->getNext();
        }

        pInverterHead = new Node(pCurrent->getValue());
        pRest = pCurrent->getNext();
        pInverter = pInverterHead;
        theDecrementer = invFinish;
        for(int j = 0; j < invNumber; j++)
        {
            theDecrementer--;
            pCurrent=pLarmHead;
            for(int i=0;i<theDecrementer;i++)
            {
                pCurrent=pCurrent->getNext();

            }
            pInverterT = pInverter->getNext();
            pInverterT = new Node(pCurrent->getValue());
            pInverter->setNext(pInverterT);
            pInverter = pInverterT;
        }
        pInverter->setNext(pRest);

        pCurrent = pLarmHead;
        for(int i = 0; i<invStart-1; i++)
        {
            pCurrent = pCurrent->getNext();
        }
        pCurrent->setNext(pInverterHead);



    }

    if(pos == BR || pos == SR)
    {
        pCurrent = pRarmHead;
        if(pos == BR)
        {
            invStart += centroRight;
            invFinish += centroRight;
        }

        for(int i = 0; i<invFinish; i++)
        {
            pCurrent = pCurrent->getNext();
        }

        pInverterHead = new Node(pCurrent->getValue());
        pRest = pCurrent->getNext();
        pInverter = pInverterHead;
        theDecrementer = invFinish;
        for(int j = 0; j < invNumber; j++)
        {
            theDecrementer--;
            pCurrent=pRarmHead;
            for(int i=0;i<theDecrementer;i++)
            {
                pCurrent=pCurrent->getNext();

            }
            pInverterT = pInverter->getNext();
            pInverterT = new Node(pCurrent->getValue());
            pInverter->setNext(pInverterT);
            pInverter = pInverterT;
        }
        pInverter->setNext(pRest);

        pCurrent = pRarmHead;
        for(int i = 0; i<invStart-1; i++)
        {
            pCurrent = pCurrent->getNext();
        }
        pCurrent->setNext(pInverterHead);

    }

}

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<chromosome.h>

using namespace std;

void print_NA(ostream &out, Nucleic_Acid NA)
{
    switch (NA)
    {
        case Adenine: out<<'A';break;
        case Guanine: out<<'G';break;
        case Cytosine: out<<'C';break;
        case Thymine: out<<'T';break;
        case Nullin: out<<'N';break;
        default: break;
    }
}

int main()
{
    unsigned int t=1414060440;
    srand(t);


    // WE'RE CREATING A RANDOM NUCLEIC ACID SEQUENCE WITH LENGTH 20
    int N=20;
    Nucleic_Acid  *Seq = new Nucleic_Acid[N+1];
    for(int i=0;i<N;i++)
        Seq[i]=(Nucleic_Acid) (rand()%4);
    Seq[N] = Nullin;

    cout<<"Content of Seq:"<<endl;
    for(int i=0;i<N;i++)
        print_NA(cout,Seq[i]);
        cout<<endl;

    cout<<endl<<"SOME EXAMPLES:\n";
    cout<<"1-Constructor:\n";
    Chromosome Crm(Seq,Seq,5);
    Chromosome Crm2(Seq,Seq+4,7);
    cout<<Crm<<endl;
    cout<<Crm2;

    cout<<"2-Deletion:\n";
    Crm.Deletion(SR,2,3);
    cout<<Crm;
    //Crm.Deletion(BR,2,4);
    //cout<<Crm;
    //Crm.Deletion(SL,2,3);
    //cout<<Crm;
    //Crm.Deletion(BL,2,4);
    //cout<<Crm;

    cout<<"3-Duplication:\n";
    Crm.Duplication(BL,1,3);
    cout<<Crm;

    cout<<"4-Insertion:\n";
    Crm.Insertion(BL,0,3,19);
    cout<<Crm;
    cout<<"5-Translocation:\n";
    Crm.Translocation(BL,0,10,0,23);
    //cout<<Crm;
    cout<<"5.5-Inversion:\n";
    Crm.Inversion(SL,1,3);
    cout<<Crm;
    cout<<"6-Occurrences:\n";
    Nucleic_Acid Seq2[3]={Adenine,Cytosine,Nullin};

    //cout<<"\tNumber of Occurences of Sequence AC: "<<Crm.Sequence_Occurences(Seq2)<<endl;


	return 0;
	}

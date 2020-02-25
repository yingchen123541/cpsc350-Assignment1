/* @author: Yuki Chen
*  Email:  yingchen@chapman.edu
*  Date:  2/23/2020
*  @version: 3.0
*  Assignment1.cpp
*  porpose: get input from user through command line to open and write to file
*  read from file and calculate mean, sum, standard deviation and variance
*  calculate probilities of each nucleotide
*  calculate probilities of each bigram
*  generate 1000 DNA strings
*  prompt the user whether to read from another file
*/

//import packages
#include <iostream>
#include<fstream>
#include <cctype>
#include<cmath>
using namespace std;

//command line argumant to get input from user
int main(int argc, char** argv) {
  //define variable types and initialize variables
  std:: string Line;
  double totalLine=0;
  string a;
  double sum=0;
  double BigramOverlapSum=0;
  double mean=0.00;
  double varianceNumerators;
  double varianceNumeratorstotal=0.00;
  double variance=0.00;
  double standarddeviation=0.00;
  string inputfileName= argv[1];
  int NumA=0;
  int NumT=0;
  int NumC=0;
  int NumG=0;
  double probabilityA=0.0;
  double probabilityC=0.0;
  double probabilityT=0.0;
  double probabilityG=0.0;
  int NumAA=0;
  int NumAC=0;
  int NumAT=0;
  int NumAG=0;
  int NumCA=0;
  int NumCC=0;
  int NumCT=0;
  int NumCG=0;
  int NumTA=0;
  int NumTC=0;
  int NumTT=0;
  int NumTG=0;
  int NumGA=0;
  int NumGC=0;
  int NumGT=0;
  int NumGG=0;
  double probabilityAA=0.0;
  double probabilityAC=0.0;
  double probabilityAT=0.0;
  double probabilityAG=0.0;
  double probabilityCA=0.0;
  double probabilityCC=0.0;
  double probabilityCT=0.0;
  double probabilityCG=0.0;
  double probabilityTA=0.0;
  double probabilityTC=0.0;
  double probabilityTT=0.0;
  double probabilityTG=0.0;
  double probabilityGA=0.0;
  double probabilityGC=0.0;
  double probabilityGT=0.0;
  double probabilityGG=0.0;
  double a1;
  double b;
  double c;
  double d;
  double pi=3.1415926;
  double randomNumber;

//open input file
  ifstream InputFile;
  InputFile.open(inputfileName);
  ofstream OutputFile;
  //open output file
  OutputFile.open("YukiChen.out");

//if fail to open input file
  if(!InputFile)
  {
    //output error message
    cerr << "unable to open file" << endl;
    exit(1);
  }
  //input file is successfully opened
  else if(InputFile)
  {
    //read through the input file line by line
    while (getline(InputFile, Line))
    {
      //calculate how many lines there are in the file
      totalLine++;
      //loop through each letter
      for(int z=0; z < Line.length(); z++)
      {
        //divide each line into single letters
           a = Line.substr(z,1);
          cout << Line[z] << endl;
          //calculate the sum
          sum++;
      }

    }
    //calculete the mean
     mean=sum/totalLine;
     //calculate the total number of bigram when overlapping
     BigramOverlapSum=sum-totalLine;

  }
//output result and write to .out file
  cout << "the sum of the length of the DNA strings is: " << sum << endl;
  cout << "the mean of the length of the DNA strings is: " << mean << endl;
  OutputFile <<"Name: Yuki Chen " << endl;
  OutputFile <<"Student ID: 2320235 " << endl;
  OutputFile <<"Email: yingchen@chapman.edu " << endl;
  OutputFile <<"Session: CPSC350-01 " << endl;
  OutputFile <<"the sum of the length of the DNA strings is: " << sum << endl;
  OutputFile << "the mean of the length of the DNA strings is: " << mean << endl;
  //close input file
  InputFile.close();

  //open file again to get variance and standard deviation
  InputFile.open(inputfileName);
//successfully open input file
  if(InputFile)
  {
    //read through each line in input file
    while (getline(InputFile, Line))
    {
      //initialize variables
      double eachlineSum=0;
      varianceNumerators=0.00;
      //loop through every single letter
      for(int z=0; z < Line.length(); z++)
      {
           a = Line.substr(z,1);
           if(a=="A" || a=="a")
           {
             //add to the numer of A when letter is A
            NumA++;
           }
           else if(a=="C" || a=="c")
           {
             //add to the numer of C when letter is C
            NumC++;
           }
           else if(a=="T" || a=="t")
           {
             //add to the numer of T when letter is T
            NumT++;
           }
           else if(a=="G" || a=="g")
           {
             //add to the numer of G when letter is G
            NumG++;
           }
// print out each letter
          cout << Line[z] << endl;
          //calculate the number of letters in each line
          eachlineSum++;

      }
        cout << "the sum of the line is: " << eachlineSum << endl;
//probability of each letter
        probabilityA=NumA/sum;
        probabilityC=NumC/sum;
        probabilityT=NumT/sum;
        probabilityG=NumG/sum;
//calculate the variance Numerators
        varianceNumerators=pow((mean-eachlineSum),2);
        varianceNumeratorstotal = varianceNumeratorstotal + varianceNumerators;
        //calculate variance
        variance=varianceNumeratorstotal/totalLine;
        // calculate standard deviation
        standarddeviation=sqrt(variance);
    }
    //output results to file
    cout << "the variance of the length of the DNA strings is: " << variance << endl;
    OutputFile <<"the variance of the length of the DNA strings is: " << variance << endl;
    cout << "the standard deviation of the length of the DNA strings is: " << standarddeviation << endl;
    OutputFile <<"the standard deviation of the length of the DNA strings is: " << standarddeviation << endl;
    cout << "the probability of A is: " << probabilityA << endl;
    cout << "the probability of C is: " << probabilityC << endl;
    cout << "the probability of T is: " << probabilityT << endl;
    cout << "the probability of G is: " << probabilityG << endl;
    OutputFile <<"the probability of A is: " << probabilityA << endl;
    OutputFile <<"the probability of C is: " << probabilityC << endl;
    OutputFile <<"the probability of T is: " << probabilityT << endl;
    OutputFile <<"the probability of G is: " << probabilityG << endl;
  }
//close input file
  InputFile.close();

//open the file the third time to get bigram probability
  InputFile.open(inputfileName);
//input file is successfully opened
  if(InputFile)
  {
    //loop through each line to get letters
    while (getline(InputFile, Line))
    {
      //get each bigram with overlapping
      for(int z=0; z < Line.length()-1; z++)
      {
         a = Line.substr(z,2);
         //check what letters each bigram contains
         if(a=="AA" || a=="Aa" || a=="aA" || a=="aa" )
         {
           //add to num AA if bigram is AA
          NumAA++;
         }
         else if(a=="AC" || a=="Ac" || a=="aC" || a=="ac")
         {
           //add to num AC if bigram is AC
          NumAC++;
         }
         else if(a=="AT" || a=="At" || a=="aT" || a=="at")
         {
           //add to num AT if bigram is AT
          NumAT++;
         }
         else if(a=="AG" || a=="Ag" || a=="aG" || a=="ag")
         {
           //add to num AG if bigram is AG
          NumAG++;
         }
         else if(a=="CA" || a=="Ca" || a=="cA" || a=="ca")
         {
           //add to num CA if bigram is CA
          NumCA++;
         }
         else if(a=="CC" || a=="Cc" || a=="cC" || a=="cc")
         {
           //add to num CC if bigram is CC
          NumCC++;
         }
         else if(a=="CT" || a=="Ct" || a=="cT" || a=="ct")
         {
           //add to num CT if bigram is CT
          NumCT++;
         }
         else if(a=="CG" || a=="Cg" || a=="cG" || a=="cg")
         {
           //add to num CG if bigram is CG
          NumCG++;
         }
         else if(a=="TA" || a=="Ta" || a=="tA" || a=="ta")
         {
           //add to num TA if bigram is TA
          NumTA++;
         }
         else if(a=="TC" || a=="Tc" || a=="tC" || a=="tc")
         {
           //add to num TC if bigram is TC
          NumTC++;
         }
         else if(a=="TT" || a=="Tt" || a=="tT" || a=="tt")
         {
           //add to num TT if bigram is TT
          NumTT++;
         }
         else if(a=="TG" || a=="Tg" || a=="tG" || a=="tg")
         {
           //add to num TG if bigram is TG
          NumTG++;
         }
         else if(a=="GA" || a=="Ga" || a=="gA" || a=="ga")
         {
           //add to num GA if bigram is GA
          NumGA++;
         }
         else if(a=="GC" || a=="Gc" || a=="gC" || a=="gc")
         {
           //add to num GC if bigram is GC
          NumGC++;
         }
         else if(a=="GT" || a=="Gt" || a=="gT" || a=="gt")
         {
           //add to num GT if bigram is GT
          NumGT++;
         }
         else if(a=="GG" || a=="Gg" || a=="gG" || a=="gg")
         {
           //add to num GG if bigram is GG
          NumGG++;
         }
         cout << a << endl;
      }
      //output probaility of each bigram
      probabilityAA=NumAA/BigramOverlapSum;
      probabilityAC=NumAC/BigramOverlapSum;
      probabilityAT=NumAT/BigramOverlapSum;
      probabilityAG=NumAG/BigramOverlapSum;
      probabilityCA=NumCA/BigramOverlapSum;
      probabilityCC=NumCC/BigramOverlapSum;
      probabilityCT=NumCT/BigramOverlapSum;
      probabilityCG=NumCG/BigramOverlapSum;
      probabilityTA=NumTA/BigramOverlapSum;
      probabilityTC=NumTC/BigramOverlapSum;
      probabilityTT=NumTT/BigramOverlapSum;
      probabilityTG=NumTG/BigramOverlapSum;
      probabilityGA=NumGA/BigramOverlapSum;
      probabilityGC=NumGC/BigramOverlapSum;
      probabilityGT=NumGT/BigramOverlapSum;
      probabilityGG=NumGG/BigramOverlapSum;
    }
//write the probabilities to output file
    cout << "the probability of AA is: " << probabilityAA << endl;
    cout << "the probability of AC is: " << probabilityAC << endl;
    cout << "the probability of AT is: " << probabilityAT << endl;
    cout << "the probability of AG is: " << probabilityAG << endl;
    OutputFile <<"the probability of AA is: " << probabilityAA << endl;
    OutputFile <<"the probability of AC is: " << probabilityAC << endl;
    OutputFile <<"the probability of AT is: " << probabilityAT << endl;
    OutputFile <<"the probability of AG is: " << probabilityAG << endl;
    cout << "the probability of CA is: " << probabilityCA << endl;
    cout << "the probability of CC is: " << probabilityCC << endl;
    cout << "the probability of CT is: " << probabilityCT << endl;
    cout << "the probability of CG is: " << probabilityCG << endl;
    OutputFile <<"the probability of CA is: " << probabilityCA << endl;
    OutputFile <<"the probability of CC is: " << probabilityCC << endl;
    OutputFile <<"the probability of CT is: " << probabilityCT << endl;
    OutputFile <<"the probability of CG is: " << probabilityCG << endl;
    cout << "the probability of TA is: " << probabilityTA << endl;
    cout << "the probability of TC is: " << probabilityTC << endl;
    cout << "the probability of TT is: " << probabilityTT << endl;
    cout << "the probability of TG is: " << probabilityTG << endl;
    OutputFile <<"the probability of TA is: " << probabilityTA << endl;
    OutputFile <<"the probability of TC is: " << probabilityTC << endl;
    OutputFile <<"the probability of TT is: " << probabilityTT << endl;
    OutputFile <<"the probability of TG is: " << probabilityTG << endl;
    cout << "the probability of GA is: " << probabilityGA << endl;
    cout << "the probability of GC is: " << probabilityGC << endl;
    cout << "the probability of GT is: " << probabilityGT << endl;
    cout << "the probability of GG is: " << probabilityGG << endl;
    OutputFile <<"the probability of GA is: " << probabilityGA << endl;
    OutputFile <<"the probability of GC is: " << probabilityGC << endl;
    OutputFile <<"the probability of GT is: " << probabilityGT << endl;
    OutputFile <<"the probability of GG is: " << probabilityGG << endl;
  }
//close input file
  InputFile.close();
  // initialize variable
  string dnaStr = "";
  for (int i = 0; i < 1000; ++i)
  {
    //generate 2 random number a1 and b
    a1=((double)rand()/(double)RAND_MAX);
    b=((double)rand()/(double)RAND_MAX);
    //calculate the DNA each line length = d
    c = (sqrt((-2) * log(a1))) * (cos(2 * pi * b));
    d = standarddeviation * c + mean;
    //get a nucleotide using probability
      for(int i = 0; i < d; ++i)
      {
        //get a random number between 0 and 1 to compare to the probability of each letter
        randomNumber = ((double)rand()/(double)RAND_MAX);
        //generate nucleotide according to its probability
        if (randomNumber < probabilityA)
        {
          //append the nucleotides in string
          dnaStr = dnaStr + "A";
        }
       //generate nucleotide according to its probability
        else if (randomNumber < probabilityA+probabilityC && randomNumber >= probabilityA)
        {
          dnaStr = dnaStr + "C";
        }
        else if (randomNumber < probabilityA+probabilityC+probabilityG && randomNumber >= probabilityA+probabilityC)
        {
          dnaStr = dnaStr + "G";
        }
        else if (randomNumber < 1 && randomNumber >= probabilityA+probabilityC+probabilityG)
        {
          dnaStr = dnaStr + "T";
        }
      }
      //go to the next line for each string
      dnaStr += "\n";
  }
  //output DNA strings to .out file
       cout << "DNA strings: " << dnaStr << endl;
       OutputFile <<"DNA strings: " <<  endl;
       OutputFile << dnaStr << endl;

//close output file
  OutputFile.close();





  //prompt the user to open another file
  string answer;
  cout << "do you want to open another file and process? enter 'yes' or 'no' " << endl;
  cin >> answer;
  string yes="yes";

  if (answer==yes)
  {
    //if user chooses yes, open the file and read from it and calculate mean, sum, variance, and standard deviation
    cout << "enter your file name " << endl;
    cin >> inputfileName;
    InputFile.open(inputfileName);
  } else
  {
    //exit the program when user chooses no
    cout << "exit the program " << endl;
  }

  return 0;
}

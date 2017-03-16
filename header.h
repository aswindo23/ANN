#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

    double input[6002][10];           /// Var Input dataset
    double net_h[6002][3];           /// Var Network of Hidden Layer     net_h[hidden layer N ][ input N ]
    double output_h[6002][3];        /// Var Output of Hidden Layer      output_h[hidden layer N ][ output N (net_h) ]
    double net_o[6002][3];           /// Var Network of Output Layer     net_h[Output layer N ][ output hidden layer(input) N ]
    double output_o[6002][3];        /// Var Network of Output from Hiden layer Output output_o[Output layer N ][ net_o N ]
    double error[6002][3];           /// Var Error   output layer        Error[Error output][itereasi (form output layer)]
    double Total_error[6002];       /// Var Total Error                 Total_error[Hidden Layer]
    double ForwardData[6002][16];         /// Var Compute Trainning Dataset
    double BackwardData[6002][21];
    double weight[6002][26];          /// Var Weight
    double weightTebakan[26];
    double deltha_o[6002][3];
    double devarative_o[6002][6];
    double deltha_h[6002][3];
    double devarative_h[6002][15];
    double AkurasiTrain[6002][30];
    double input_T[6002][10];
    double target[6002][5];
int n,N,nN;
/// BackPropagation Network
void getDataTrainning_fromFile(char* file);
double createNetwork(double w1, double w2, double w3, double w4, double w5, double w6, double i1,double i2, double i3,double i4, double i5,double b);
double createNetwork2(double w1, double w2, double w3, double w4, double i1,double i2, double i3, double b);
double output(double net);
double Error(double target, double out);
void Forward_Pass(int i,char* file1);
void Backward_Pass(double alpha,int i,char* file2, char* file3);
double dho_output(double out);
double compute_deltha(double target, double out);
double devarative_function_o(double deltha_i, double out );
double compute_deltha_h(double delthao1,double deltha_o2, double w1, double w2, double out);
double devarative_function_h(double deltha_h,double input);
//void update_weigth(double alpha);
double update_weigth_function(double W,double learningrate, double devarative_f );
double sumError(double target1,double target2, double out, double out2);
double mean_se();
void getDataTesting_fromFile(char* file);
void AkurasiTrainning();

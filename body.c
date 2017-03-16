#include "header.h"

/// Method

double createNetwork(double w1, double w2, double w3, double w4, double w5, double w6, double i1,double i2, double i3,double i4, double i5,double b){
    return ((w1*i1)+(w2*i2)+(w3*i3)+(w4*i4)+(w5*i5)+(w6*b));
}

double createNetwork2(double w1, double w2, double w3, double w4, double i1,double i2,double i3, double b){
    return ((w1*i1)+(w2*i2)+(w3*i3)+(w4*b));
}

double output(double net){
    return (1/(1+exp(-net)));
    //return ((exp(net)-exp(-net))/(exp(net)+exp(-net)));
}

double Error(double target, double out){
    return (0.5*pow((target-out),2));
}

double sumError(double target1,double target2, double out, double out2){
    return  (0.5*(pow((target1-out),2)) + 0.5*(pow((target2-out2),2))) - ((target1-out) + (target2-out2 ) );
}

double compute_deltha(double target, double out){
    return (-(target-out)*dho_output(out));
}

double devarative_function_o(double deltha_i, double out ){
    return -deltha_i*out;
}

double dho_output(double out){

    double o ;
    o = (double) (1-out);
    return (out*o);
}

double compute_deltha_h(double deltha_o1,double deltha_o2, double w1, double w2, double out){
    return (((deltha_o1*w1)+(deltha_o2*w2))*dho_output(out));
}

double devarative_function_h(double deltha_h,double input){
    return deltha_h*input;
}


double update_weigth_function(double W,double learningrate, double devarative_f ){
    return (W-(learningrate*devarative_f));

}

double mean_se(){
    int i,j;
    double sum =0;
    for(i=1; i<=nN; i++){
//        for(j=20; j<=31; j++){
            sum += sumError(target[i][1],target[i][2],output_o[i][1],output_o[i][2]);
//        }
    }
    return sum/(2*nN);
}


void Forward_Pass(int i,char* file1){  /// Trainning with Back Propagetion

    int j,e;
    FILE * forward_data;
        //printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        //printf(" %-11s | %-5s | %-5s | %-5s | %-5s | %-5s | %-5s | %-5s | %-5s | %-5s | %-5s | %-5s | %-5s |","NO DATA  Net h1","Out h1","Net h2","Out h2","Net h3","Out h3","Net o1","Out o1","Net o2","Out o2","Eo1","Eo2","Etotal"); printf("\n");
       //printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    /// Name FIle
    forward_data = fopen(file1,"a+");

    //for(i=1; i<=nN; i++){
        for(j=1; j<=15; j++){
            switch(j){

                /// Input Layer --> Hidden Layer (Neuron 1)

                case 1  :  /// Generate Network from input to hidden layer
                        ForwardData[i][j] = createNetwork(weightTebakan[1],weightTebakan[2],weightTebakan[3],weightTebakan[4],weightTebakan[5],weightTebakan[6],input[i][2],input[i][3],input[i][4],input[i][5],input[i][6],1);
                        net_h[i][1] = ForwardData[i][j];  /// [i][1] => Network hidden layer 1
                    break;
                case 2  : /// Generate Output from input to hidden layer
                        ForwardData[i][j] = output(net_h[i][1]);
                        output_h[i][1] = ForwardData[i][j];
                    break;

                ///--------------------------------------------------------------------------------
                /// Input Layer --> Hidden Layer (Neuron 2)

                case 3 : /// Generate Network from input to hidden layer
                        ForwardData[i][j] = createNetwork(weightTebakan[7],weightTebakan[8],weightTebakan[9],weightTebakan[10],weightTebakan[11],weightTebakan[12],input[i][2],input[i][3],input[i][4],input[i][5],input[i][6],1);
                        net_h[i][2] = ForwardData[i][j];  /// [i][1] => Network hidden layer 1
                    break;
                case 4 : /// Generate Output from input to hidden layer
                        ForwardData[i][j] = output(net_h[i][2]);
                        output_h[i][2] = ForwardData[i][j];
                    break;

                ///--------------------------------------------------------------------------------

                /// Input Layer --> Hidden Layer (Neuron 3)

                case 5 : /// Generate Network from input to hidden layer
                        ForwardData[i][j] = createNetwork(weightTebakan[13],weightTebakan[14],weightTebakan[15],weightTebakan[16],weightTebakan[17],weightTebakan[18],input[i][2],input[i][3],input[i][4],input[i][5],input[i][6],1);
                        net_h[i][3] = ForwardData[i][j];  /// [i][1] => Network hidden layer 1
                    break;
                case 6 : /// Generate Output from input to hidden layer
                        ForwardData[i][j] = output(net_h[i][2]);
                        output_h[i][3] = ForwardData[i][j];
                    break;

                ///--------------------------------------------------------------------------------

                /// Hidden Layer --> Output Layer (Neuron 1)

                case 7 : /// Generete Network from hidden layer to output layer
                        ForwardData[i][j] = createNetwork2(weightTebakan[19],weightTebakan[20],weightTebakan[21],weightTebakan[22],output_h[i][1],output_h[i][2],output_h[i][3],1);
                        net_o[i][1] =  ForwardData[i][j];
                    break;
                case 8 : /// Generete Output from hidden layer to output layer
                        ForwardData[i][j] = output(net_o[i][1]);
                        output_o[i][1] =  ForwardData[i][j];
                    break;

                ///--------------------------------------------------------------------------------
                /// Hidden Layer --> Output Layer (Neuron 2)


                case 9 : /// Generete Network from hidden layer to output layer
                        ForwardData[i][j] = createNetwork2(weightTebakan[23],weightTebakan[24],weightTebakan[25],weightTebakan[26],output_h[i][1],output_h[i][2],output_h[i][3],1);
                        net_o[i][2] =  ForwardData[i][j];
                    break;
                case 10 : /// Generete Output from hidden layer to output layer
                        ForwardData[i][j] = output(net_o[i][2]);
                        output_o[i][2] =  ForwardData[i][j];
                    break;

                case 11 : // Target
                        if(output_o[i][1]<0.765){
                            ForwardData[i][j]=0;
                            target[i][1]=0;
                        }else{
                            ForwardData[i][j]=1;
                            target[i][1]=1;
                        }
                    break;

                case 12 : // Target
                        if(output_o[i][2]<0.9){
                            ForwardData[i][j]=0;
                            target[i][2]=0;
                        }else{
                            ForwardData[i][j]=1;
                            target[i][2]=1;
                        }
                    break;


                ///--------------------------------------------------------------------------------

                case 13  : /// Calculate Error E01 from output H->O
                        ForwardData[i][j] = Error(target[i][1],output_o[i][1]);
                        error[i][1] =  ForwardData[i][j];
                    break;
                case 14  : /// Calculate Error E01 from output H->O
                        ForwardData[i][j] = Error(target[i][2],output_o[i][2]);
                        error[i][2] =  ForwardData[i][j];
                    break;
                case 15  : /// Total Error Eo1 Eo2 from output H->O
                        ForwardData[i][j] = error[i][1] + error[i][2];
                        Total_error[i] =  ForwardData[i][j];
                    break;

            }
            /*
            if(j==1){
                printf("Data ke - %i ",i);
            }
            */
            if(ForwardData[i][j]<0 ){
               // printf(" %5.4lf",ForwardData[i][j]);
                fprintf(forward_data,"%5.5f \t",ForwardData[i][j]);
            }else  {
                //printf(" %5.5lf",ForwardData[i][j]);
                fprintf(forward_data,"%5.6f \t",ForwardData[i][j]);
            }

        }
        //printf("\n");
        fprintf(forward_data,"\n");
        //printf("Data ke - %i | %5.6lf  %5.6lf  %5.6lf  %5.6lf  %5.6lf  %5.6lf  %5.6lf  %5.6lf  %5.6lf  %5.6lf  %5.6lf  %5.6lf  %5.6lf  \n",i,TranningData[i][1],TranningData[i][2],TranningData[i][3],TranningData[i][4],TranningData[i][5],TranningData[i][6],TranningData[i][7],TranningData[i][8],TranningData[i][9],TranningData[i][10],TranningData[i][11],TranningData[i][12],TranningData[i][13]);
    //}

    fclose(forward_data);
    //getchar();

}

void Backward_Pass(double alpha,int i,char* file2, char* file3){
    int j;

    //printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    //printf(" %-11s | %-12s | %-12s | %-12s | %-12s | %-12s | %-12s | %-12s | %-12s | %-12s | %-12s |","Deltha O1","Dev O1","Deltha O2","Dev O2","Delta H1","Dev H1","Delta H2","Dev H2","Eo1","Eo2","Etotal"); printf("\n");
    //printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------\n");



    FILE * DATA;
    FILE * WEIGHT;
    DATA = fopen(file2,"a+");
    //for(i=1; i<=nN; i++){

        for(j=1; j<=21; j++){
            switch(j){
                case 1 : /// OL N1 --> HL N1
                        deltha_o[i][1]      = compute_deltha(target[i][1],output_o[i][1]);
                        devarative_o[i][1]  = devarative_function_o(deltha_o[i][1],output_h[i][1]);
                        BackwardData[i][j]  = devarative_o[i][1] ;
                        /// Update Bobot    W19
                        weight[i][19]= update_weigth_function(weightTebakan[19],alpha,devarative_o[i][1]);

                    break;
                case 2 : /// OL N1 --> HL N2
                        devarative_o[i][2]  = devarative_function_o(deltha_o[i][1],output_h[i][2]);
                        BackwardData[i][j]  = devarative_o[i][2] ;
                        /// Update Bobot    W20
                        weight[i][20]= update_weigth_function(weightTebakan[20],alpha,devarative_o[i][2]);
                    break;
                case 3 : /// OL N1 --> HL N3
                        devarative_o[i][3]  = devarative_function_o(deltha_o[i][1],output_h[i][3]);
                        BackwardData[i][j]  = devarative_o[i][3] ;
                        /// Update Bobot    W21
                        weight[i][21]= update_weigth_function(weightTebakan[21],alpha,devarative_o[i][3]);
                    break;
                case 4 : /// OL N2 --> HL N1
                        deltha_o[i][2]      = compute_deltha(target[i][2],output_o[i][2]);
                        devarative_o[i][4]  = devarative_function_o(deltha_o[i][2],output_h[i][1]);
                        BackwardData[i][j]  = devarative_o[i][4] ;
                        /// Update Bobot    W23
                        weight[i][23]= update_weigth_function(weightTebakan[23],alpha,devarative_o[i][4]);
                    break;
                case 5 : /// OL N2 --> HL N2
                        devarative_o[i][5]  = devarative_function_o(deltha_o[i][2],output_h[i][2]);
                        BackwardData[i][j]  = devarative_o[i][5] ;
                        /// Update Bobot    W24
                        weight[i][24]= update_weigth_function(weightTebakan[24],alpha,devarative_o[i][5]);
                    break;
                case 6 : /// OL N2 --> HL N3
                        devarative_o[i][6]  = devarative_function_o(deltha_o[i][2],output_h[i][3]);
                        BackwardData[i][j]  = devarative_o[i][6] ;
                        /// Update Bobot    W25
                        weight[i][25]= update_weigth_function(weightTebakan[25],alpha,devarative_o[i][6]);
                    break;


                case 7 : /// HL N1 --> IL N1
                        deltha_h[i][1] = compute_deltha_h(deltha_o[i][1],deltha_o[i][2],weightTebakan[19],weightTebakan[23],output_h[i][1] );
                        devarative_h[i][1]= devarative_function_h(deltha_h[i][1],input[i][2]);
                        BackwardData[i][j] = devarative_h[i][1];
                        /// Update Bobot    W1
                        weight[i][1] = update_weigth_function(weightTebakan[1],alpha,devarative_h[i][1]);
                    break;
                case 8 : /// HL N1 --> IL N2
                        devarative_h[i][2]= devarative_function_h(deltha_h[i][1],input[i][3]);
                        BackwardData[i][j] = devarative_h[i][2];
                        /// Update Bobot    W1
                        weight[i][2] = update_weigth_function(weightTebakan[2],alpha,devarative_h[i][2]);
                    break;
                case 9 : /// HL N1 --> IL N3
                        devarative_h[i][3]= devarative_function_h(deltha_h[i][1],input[i][4]);
                        BackwardData[i][j] = devarative_h[i][3];
                        /// Update Bobot    W1
                        weight[i][3] = update_weigth_function(weightTebakan[3],alpha,devarative_h[i][3]);
                    break;
                case 10 : /// HL N1 --> IL N4
                        devarative_h[i][4]= devarative_function_h(deltha_h[i][1],input[i][5]);
                        BackwardData[i][j] = devarative_h[i][4];
                        /// Update Bobot    W1
                        weight[i][4] = update_weigth_function(weightTebakan[4],alpha,devarative_h[i][4]);
                    break;
                case 11 : /// HL N1 --> IL N5
                        devarative_h[i][5]= devarative_function_h(deltha_h[i][1],input[i][6]);
                        BackwardData[i][j] = devarative_h[i][5];
                        /// Update Bobot    W1
                        weight[i][5] = update_weigth_function(weightTebakan[5],alpha,devarative_h[i][5]);
                    break;

                case 12 : /// HL N2 --> IL N1
                        deltha_h[i][2] = compute_deltha_h(deltha_o[i][1],deltha_o[i][2],weightTebakan[20],weightTebakan[24],output_h[i][2] );
                        devarative_h[i][6]= devarative_function_h(deltha_h[i][2],input[i][2]);
                        BackwardData[i][j] = devarative_h[i][6];
                        /// Update Bobot    W1
                        weight[i][7] = update_weigth_function(weightTebakan[7],alpha,devarative_h[i][6]);
                    break;
                case 13 : /// HL N2 --> IL N2
                        devarative_h[i][7]= devarative_function_h(deltha_h[i][2],input[i][3]);
                        BackwardData[i][j] = devarative_h[i][7];
                        /// Update Bobot    W1
                        weight[i][8] = update_weigth_function(weightTebakan[8],alpha,devarative_h[i][7]);
                    break;
                case 14 : /// HL N2 --> IL N3
                        devarative_h[i][8]= devarative_function_h(deltha_h[i][2],input[i][4]);
                        BackwardData[i][j] = devarative_h[i][8];
                        /// Update Bobot    W1
                        weight[i][9] = update_weigth_function(weightTebakan[9],alpha,devarative_h[i][8]);
                    break;
                case 15 : /// HL N2 --> IL N4
                        devarative_h[i][9]= devarative_function_h(deltha_h[i][2],input[i][5]);
                        BackwardData[i][j] = devarative_h[i][9];
                        /// Update Bobot    W1
                        weight[i][10] = update_weigth_function(weightTebakan[10],alpha,devarative_h[i][9]);
                    break;
                case 16 : /// HL N2 --> IL N5
                        devarative_h[i][10]= devarative_function_h(deltha_h[i][2],input[i][6]);
                        BackwardData[i][j] = devarative_h[i][10];
                        /// Update Bobot    W1
                        weight[i][11] = update_weigth_function(weightTebakan[11],alpha,devarative_h[i][10]);
                    break;
                case 17 : /// HL N3 --> IL N1
                        deltha_h[i][3] = compute_deltha_h(deltha_o[i][1],deltha_o[i][2],weightTebakan[21],weightTebakan[25],output_h[i][3] );
                        devarative_h[i][11]= devarative_function_h(deltha_h[i][3],input[i][2]);
                        BackwardData[i][j] = devarative_h[i][11];
                        /// Update Bobot    W1
                        weight[i][13] = update_weigth_function(weightTebakan[13],alpha,devarative_h[i][11]);
                    break;
                case 18 : /// HL N3 --> IL N2
                        devarative_h[i][12]= devarative_function_h(deltha_h[i][3],input[i][3]);
                        BackwardData[i][j] = devarative_h[i][12];
                        /// Update Bobot    W1
                        weight[i][14] = update_weigth_function(weightTebakan[14],alpha,devarative_h[i][12]);
                    break;
                case 19 : /// HL N3 --> IL N3
                        devarative_h[i][13]= devarative_function_h(deltha_h[i][3],input[i][4]);
                        BackwardData[i][j] = devarative_h[i][13];
                        /// Update Bobot    W1
                        weight[i][15] = update_weigth_function(weightTebakan[15],alpha,devarative_h[i][13]);
                    break;
                case 20 : /// HL N3 --> IL N4
                        devarative_h[i][14]= devarative_function_h(deltha_h[i][3],input[i][5]);
                        BackwardData[i][j] = devarative_h[i][14];
                        /// Update Bobot    W1
                        weight[i][16] = update_weigth_function(weightTebakan[16],alpha,devarative_h[i][14]);
                    break;
                case 21 : /// HL N3 --> IL N5
                        devarative_h[i][15]= devarative_function_h(deltha_h[i][3],input[i][6]);
                        BackwardData[i][j] = devarative_h[i][15];
                        /// Update Bobot    W1
                        weight[i][17] = update_weigth_function(weightTebakan[17],alpha,devarative_h[i][15]);
                    break;
            }
            if(j==1){
                //printf("Data ke - %i ",i);
            }

            if(BackwardData[i][j]<0){
                //printf(" %5.5lf",BackwardData[i][j]);
                fprintf(DATA,"%5.5f \t",BackwardData[i][j]);
            }else{
                //printf(" %5.6lf",BackwardData[i][j]);
                fprintf(DATA,"%5.6f \t",BackwardData[i][j]);
            }

        }



        //printf("\n");
        fprintf(DATA,"\n");
        fclose(DATA);
        /// Update Weight
        /// Weight for Hidden Layer

        WEIGHT = fopen(file3,"a+");

        int index;

        for(index = 1 ; index<=26; index++){
                if(index != 6 || index != 12 || index != 18 || index != 22 || index !=25){
                    weightTebakan[index]= weight[i][index];
                    if(i==6000){
                            //printf("W%i :%5.8lf ",index,weightTebakan[index]);
                    }

                }
                fprintf(WEIGHT,"%5.6f \t",weightTebakan[index]);
        }//printf("\n");
        fprintf(WEIGHT,"\n");
        fclose(WEIGHT);

        //printf("Data ke - %i | %5.4lf | %5.4lf | %5.4lf | %5.4lf | %5.4lf | %5.4lf | %5.4lf | %5.4lf | %5.4lf | %5.4lf | %5.4lf | %5.4lf | %5.4lf | %5.4lf | %5.4lf | %5.4lf\n",i,TranningData[i][12],TranningData[i][13],TranningData[i][14],TranningData[i][15],TranningData[i][16],TranningData[i][17],TranningData[i][18],TranningData[i][19],TranningData[i][20],TranningData[i][21],TranningData[i][22],TranningData[i][23],TranningData[i][24],TranningData[i][25],TranningData[i][26],TranningData[i][27]);
    //}

    //getchar();

}

void getDataTrainning_fromFile(char* file) /// Fungsi mengambil data trainning dari file
{
    FILE *arr; double inputF[6002][10]; int x,y;  /// inputF => input Form FIle

    arr =fopen(file,"r");
    printf("\n\n\n\n");
    printf("\t\t\t\t\t\t ");
    printf("Data Trainning \n");
    printf("\t\t\t\t\t\t ");
    printf("----------------------------------\n");
    printf("\t\t\t\t\t\t ");
    printf(" %-2s | %-4s | %-4s | %-4s | %-4s | %-4s | %-4s | \n","No","X1","X2","X3","X4","X5","Class");
    printf("\t\t\t\t\t\t ");
    printf("----------------------------------\n");
    for(x=1;x<=nN;x++){
        printf("\t\t\t\t\t\t ");
        for(y=1;y<=7;y++){
            fscanf(arr, "%lf ",&inputF[x][y]);
            input[x][y]=inputF[x][y];

            /// Print out Data Trainning
            if(y==1 || y==7){
                      printf("%5.2lf | ",  input[x][y]);
                }else{
                     if(input[x][y]>=10){
                         printf("%5.2lf | ",  input[x][y]);
                    }else if(  input[x][y]>=0 &&   input[x][y]<=10 ) {
                         printf("%5.2lf | ",  input[x][y]);
                    }else if(  input[x][y]>=-10 &&   input[x][y]<=0) {
                         printf("%5.2lf | ",  input[x][y]);
                    }else if(  input[x][y]<=-10){
                         printf("%5.2lf | ",  input[x][y]);
                    }
                }
        }printf("\n");
    }
    getchar();
    fclose(arr);
    printf("\t\t\t\t\t\t ");
    printf("----------------------------------\n");

}

void getDataTesting_fromFile(char* file) /// Fungsi mengambil data trainning dari file
{
    FILE *datatest; double inputF[6002][10]; int x,y;  /// inputF => input Form FIle

    datatest =fopen(file,"r");
    printf("\n\n\n\n");
    printf("\t\t\t\t\t\t ");
    printf("Data Testing \n");
    printf("\t\t\t\t\t\t ");
    printf("----------------------------------\n");
    printf("\t\t\t\t\t\t ");
    printf(" %-2s | %-4s | %-4s | %-4s | %-4s | %-4s | %-4s | \n","No","X1","X2","X3","X4","X5","Class");
    printf("\t\t\t\t\t\t ");
    printf("----------------------------------\n");
    for(x=1;x<=2000;x++){
        printf("\t\t\t\t\t\t ");
        for(y=1;y<=6;y++){
            fscanf(datatest, "%lf ",&inputF[x][y]);
            input_T[x][y]=inputF[x][y];

            /// Print out Data Trainning
            if(y==1 ){
                      printf("%5.0lf | ",  input_T[x][y]);
                }else{
                     if(input_T[x][y]>=10){
                         printf("%5.2lf | ",  input_T[x][y]);
                    }else if(  input_T[x][y]>=0 &&   input_T[x][y]<=10 ) {
                         printf("%5.2lf | ",  input[x][y]);
                    }else if(  input_T[x][y]>=-10 &&   input_T[x][y]<=0) {
                         printf("%5.2lf | ",  input_T[x][y]);
                    }else if(  input_T[x][y]<=-10){
                         printf("%5.2lf | ",  input_T[x][y]);
                    }
                }
        }printf("\n");
    }
    getchar();
    fclose(datatest);
    printf("\t\t\t\t\t\t ");
    printf("----------------------------------\n");

}

void AkurasiTrainning(){

    int i,j;

    FILE *AT;

    AT = fopen("Akurasi_Trainn.txt","a+");

    for(i=1; i<=nN; i++){
        for(j=1; j<=16; j++){
            switch (j) {

                /// Hidden Layer 1 Test Akurasi

                case    1   : AkurasiTrain[i][j] = createNetwork(weightTebakan[1],weightTebakan[2],weightTebakan[3],weightTebakan[4],weightTebakan[5],weightTebakan[6],input[i][2],input[i][3],input[i][4],input[i][5],input[i][6],1); break;
                case    2   : AkurasiTrain[i][j] = output(AkurasiTrain[i][1]); break;

                case    3   : AkurasiTrain[i][j] = createNetwork(weightTebakan[7],weightTebakan[8],weightTebakan[9],weightTebakan[10],weightTebakan[11],weightTebakan[12],input[i][2],input[i][3],input[i][4],input[i][5],input[i][6],1); break;
                case    4   : AkurasiTrain[i][j] = output(AkurasiTrain[i][3]); break;

                case    5   : AkurasiTrain[i][j] = createNetwork(weightTebakan[13],weightTebakan[14],weightTebakan[15],weightTebakan[16],weightTebakan[17],weightTebakan[18],input[i][2],input[i][3],input[i][4],input[i][5],input[i][6],1); break;
                case    6   : AkurasiTrain[i][j] = output(AkurasiTrain[i][5]); break;

                case    7   : AkurasiTrain[i][j] = createNetwork2(weightTebakan[19],weightTebakan[20],weightTebakan[21],weightTebakan[22],AkurasiTrain[i][2],AkurasiTrain[i][4],AkurasiTrain[i][6],1);break;
                case    8   : AkurasiTrain[i][j] = output(AkurasiTrain[i][7]); break;


                case    9   : AkurasiTrain[i][j] = createNetwork2(weightTebakan[23],weightTebakan[24],weightTebakan[25],weightTebakan[26],AkurasiTrain[i][2],AkurasiTrain[i][4],AkurasiTrain[i][6],1);break;
                case    10  : AkurasiTrain[i][j] = output(AkurasiTrain[i][9]); break;


                //case    3   : AkurasiTrain[i][j] = dho_output(AkurasiTrain[i][2]); break;
                //case    4   : AkurasiTrain[i][j] = input[i][7] - AkurasiTrain[i][2]; break;
                case   11   : AkurasiTrain[i][j] = target[i][1];break;
                case   12   :   if(AkurasiTrain[i][8]<=0.515){
                                    AkurasiTrain[i][j] = 0;
                                }else {
                                    AkurasiTrain[i][j] = 1;
                                }
                            break;
                case    13   :  if(AkurasiTrain[i][12]==target[i][1]){
                                    AkurasiTrain[i][j] = 1;
                                }else {
                                    AkurasiTrain[i][j] = 0;
                                }
                            break;



                //case    9   : AkurasiTrain[i][j] = dho_output(AkurasiTrain[i][8]); break;
                //case    10   : AkurasiTrain[i][j] = input[i][7] - AkurasiTrain[i][8]; break;
                case   14   : AkurasiTrain[i][j] = target[i][2];break;
                case    15   :   if(AkurasiTrain[i][10]<=0.525){
                                    AkurasiTrain[i][j] = 0;
                                }else  {
                                    AkurasiTrain[i][j] = 1;
                                }
                            break;
                case   16   :  if(AkurasiTrain[i][15]==target[i][2]){
                                    AkurasiTrain[i][j] = 1;
                                }else {
                                    AkurasiTrain[i][j] = 0;
                                }
                            break;

                                /*
                //case    15   : AkurasiTrain[i][j] = dho_output(AkurasiTrain[i][14]); break;
                //case    16   : AkurasiTrain[i][j] = input[i][7] - AkurasiTrain[i][14]; break;
                //case    17   :   if(AkurasiTrain[i][14]<=0.5){
                                    AkurasiTrain[i][j] = 0;
                                }else {
                                    AkurasiTrain[i][j] = 1;
                                }
                            break;
                //case    18   :  if(AkurasiTrain[i][17]==input[i][7]){
                                    AkurasiTrain[i][j] = 1;
                                }else {
                                    AkurasiTrain[i][j] = 0;
                                }
                            break; */
            }

            if(AkurasiTrain[i][j]<0){
                printf(" %5.5lf",AkurasiTrain[i][j]);
                fprintf(AT,"%5.5lf \t",AkurasiTrain[i][j]);
            }else if(j==11 || j==12 || j==13 || j==14 || j==15 || j==16  ){
                printf(" %1.0lf",AkurasiTrain[i][j]);
                fprintf(AT,"%1.0lf \t",AkurasiTrain[i][j]);
            }else{
                printf(" %5.6lf",AkurasiTrain[i][j]);
                fprintf(AT,"%5.6lf \t",AkurasiTrain[i][j]);
            }
        }
        printf("\n");
        fprintf(AT,"\n");


    }

    fclose(AT);

    FILE *LogData;
    LogData = fopen("Log_Data.txt","a+");




        double sum[3];
        double Acc[3];
        sum[1] =0; sum[2]=0; sum[3]=0;
    for(i=1; i<=nN; i++){
        if(AkurasiTrain[i][13]==1){
            sum[1]+=1;
        }
        if(AkurasiTrain[i][16]==1){
            sum[2]+=1;
        }


    }

    double result[3];
    for(i=1; i<=2; i++){
        Acc[i]= sum[i]/nN  ;
        result[i]= Acc[i] * 100 ;
        printf("Akurasi Neuron Output Layer %i : %3.2lf %s \n",i,result[i],"%");
        fprintf(LogData,"Akurasi Neuron Output Layer %i : %3.2lf %s \n",i,result[i],"%");
    }
    fclose(LogData);

}

void AkurasiTesting(){

    int i,j;

    FILE *AT;

    AT = fopen("Akurasi_Testing.txt","a+");

    for(i=1; i<=2000; i++){
        for(j=1; j<=12; j++){
            switch (j) {

                /// Hidden Layer 1 Test Akurasi


                case    1   :  AkurasiTrain[i][j] = createNetwork(weightTebakan[1],weightTebakan[2],weightTebakan[3],weightTebakan[4],weightTebakan[5],weightTebakan[6],input_T[i][2],input_T[i][3],input_T[i][4],input_T[i][5],input_T[i][6],1); break;
                case    2   : AkurasiTrain[i][j] = output(AkurasiTrain[i][1]); break;

                case    3   : AkurasiTrain[i][j] = createNetwork(weightTebakan[7],weightTebakan[8],weightTebakan[9],weightTebakan[10],weightTebakan[11],weightTebakan[12],input_T[i][2],input_T[i][3],input_T[i][4],input_T[i][5],input_T[i][6],1); break;
                case    4   : AkurasiTrain[i][j] = output(AkurasiTrain[i][3]); break;

                case    5   : AkurasiTrain[i][j] = createNetwork(weightTebakan[13],weightTebakan[14],weightTebakan[15],weightTebakan[16],weightTebakan[17],weightTebakan[18],input_T[i][2],input_T[i][3],input_T[i][4],input_T[i][5],input_T[i][6],1); break;
                case    6   : AkurasiTrain[i][j] = output(AkurasiTrain[i][5]); break;

                case    7   : AkurasiTrain[i][j] = createNetwork2(weightTebakan[19],weightTebakan[20],weightTebakan[21],weightTebakan[22],AkurasiTrain[i][2],AkurasiTrain[i][4],AkurasiTrain[i][6],1);break;
                case    8   : AkurasiTrain[i][j] = output(AkurasiTrain[i][7]); break;


                case    9   : AkurasiTrain[i][j] = createNetwork2(weightTebakan[23],weightTebakan[24],weightTebakan[25],weightTebakan[26],AkurasiTrain[i][2],AkurasiTrain[i][4],AkurasiTrain[i][6],1);break;
                case    10  : AkurasiTrain[i][j] = output(AkurasiTrain[i][9]); break;


                case   11   :   if(AkurasiTrain[i][8]<=0.515){
                                    AkurasiTrain[i][j] = 0;
                                }else {
                                    AkurasiTrain[i][j] = 1;
                                }
                            break;



                //case    9   : AkurasiTrain[i][j] = dho_output(AkurasiTrain[i][8]); break;
                //case    10   : AkurasiTrain[i][j] = input[i][7] - AkurasiTrain[i][8]; break;

                case    12   :   if(AkurasiTrain[i][10]<=0.525){
                                    AkurasiTrain[i][j] = 0;
                                }else  {
                                    AkurasiTrain[i][j] = 1;
                                }
                            break;



            }

            if(AkurasiTrain[i][j]<0){
                printf(" %5.5lf",AkurasiTrain[i][j]);
                fprintf(AT,"%5.5lf \t",AkurasiTrain[i][j]);
            }else if(j==11 || j==12){
                printf(" %1.0lf",AkurasiTrain[i][j]);
                fprintf(AT,"%1.0lf \t",AkurasiTrain[i][j]);
            }else{
                printf(" %5.6lf",AkurasiTrain[i][j]);
                fprintf(AT,"%5.6lf \t",AkurasiTrain[i][j]);
            }
        }
        printf("\n");
        fprintf(AT,"\n");


    }

    fclose(AT);

    FILE *LogData;
    LogData = fopen("Log_Data.txt","a+");
        int Class[4][2];
        for(i=1; i<=3; i++){
            for(j=0; j<=1; j++){
                Class[i][j]=0;
            }
        }

        double sum[3];
        //double Acc[3];
        sum[1] =0; sum[2]=0; sum[3]=0;

    for(i=1; i<=2000; i++){

        if(AkurasiTrain[i][11]==0){
            Class[1][0]+=1;
        }else{
            Class[1][1]+=1;
        }
        if(AkurasiTrain[i][12]==0){
            Class[2][0]+=1;
        }else{
            Class[2][1]+=1;
        }

    }


     for(i=1; i<=2; i++){
            for(j=0; j<=1; j++){
                printf("Total Class %i Berdasarkan Output Layer %i : %i \n",j,i,Class[i][j]);
                fprintf(LogData,"Total Class %i Berdasarkan Ouput Layer %i : %i ",j,i,Class[i][j]);
            }fprintf(LogData,"\n");
    }

    ///----------

    ///----


     fclose(LogData);
}


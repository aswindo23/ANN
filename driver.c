#include "body.c"


int main () {
    n=150;
    N=1;
    nN=6000;
    double alpha =0.007;
    int i,j;

    double mse = 0;
    FILE *LogData;
    LogData = fopen("Log_Data.txt","a+");
    fprintf(LogData,"----------------------------------------------------------------------------\n");
    fprintf(LogData,"Log Running Program \n");
    fprintf(LogData,"----------------------------------------------------------------------------\n");
    fprintf(LogData,"Learning Rate : %lf \n\n",alpha);
    fprintf(LogData,"Tebakan  \n");

    for(i=1; i<=26; i++){
        double W = (double) (rand() % 100 ) / 100;

        while(W==0){
             W = (double) (rand() % 100 ) / 100;
        }
        weightTebakan[i] = W;
        printf("Weight %i --> %lf \n",i,weightTebakan[i]);
        fprintf(LogData,"Weight %i --> %lf \n",i,weightTebakan[i]);
    }

    system("pause");

    getDataTrainning_fromFile("JSTFILE_B.txt");
    getDataTesting_fromFile("Testing.txt");
    system("pause");
    //clock_t begin3 = clock();
    int itr = 1;





    while ( itr<=30){

        fprintf(LogData,"Iterasi %i \n",itr);

            char FP[30] = "Forward_Pass_";
            char BP[30] = "Backward_Pass_";
            char WP[30] = "Weight_Pass_";
            char DP[20];
            sprintf(DP,"%d",itr);
            char Format[20] = ".txt";
            strcat(DP,Format);
            strcat(BP,DP);
            strcat(FP,DP);
            strcat(WP,DP);
            printf("PROSES ITERASI %i ",itr);
            for(i=1; i<=nN; i++){
                    Forward_Pass(i,FP);
                    //system("pause");
                    Backward_Pass(alpha,i,BP,WP);
                    //system("pause");
            }
        //Forward_Pass();
        //system("pause");
        //Backward_Pass();
        //system("pause");
        //update_weigth(alpha);
        //system("pause");

        mse=mean_se();
        printf("\n MSE : %lf \n",mse);

        //AkurasiTrainning();

        fprintf(LogData,"MSE %5.5lf \n",mean_se());
        fprintf(LogData,"\n");

        itr+=1;
    }
    fclose(LogData);

    AkurasiTrainning();
    system("pause");
    AkurasiTesting();

    getchar();

    return 0;
}



#include<stdio.h>


void sort(int s[],int f[],int act_no[],int n) // to sort on the basis of finish times
{  
    int temp;
     for (int i=0; i<n-1; i++){
        for (int j=0; j<n-1-i; j++){
            if (f[j] > f[j+1])
            {
                //swap(&A[j], &A[j+1]);
                temp=f[j];
                f[j]=f[j+1];
                f[j+1]=temp;

                 temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;

                 temp=act_no[j];
                act_no[j]=act_no[j+1];
                act_no[j+1]=temp;


            }
        }


        }
    }

    void printMaxActivities(int s[], int f[], int act_no[],int n)
{
    int i, j;

    printf ("Following activities are selected \n");
   int k=0;
    // The first activity always gets selected
    i = 0;
   // printf("%d ", i);
    printf("%d",act_no[i]);


    for (j = 1; j < n; j++)
    {
      // If this activity has start time greater than or
      // equal to the finish time of previously selected
      // activity, then select it
      if (s[j] >= f[i])
      {
         // printf ("%d ", j);
          printf("%d ",act_no[j]);
          i = j;
      }
    }
}




int main()
{
    int n;
    printf("enter the total no of activites \n");
    scanf("%d",&n);
    int s[n];//array to store start time of the processes
    int f[n];//array to stpre finish time of the processes
    int ac_no[n];
    printf("enter the start time of the activites \n");

     for(int i=0;i<n;i++)
     {  
        printf("for activity no %d enter the start time \n",i+1);
        scanf("%d",&s[i]);
        ac_no[i]=i+1;//to store the activity no 
     }

      for(int i=0;i<n;i++)
     {  
        printf("for activity no %d enter the finish time \n",i+1);
        scanf("%d",&f[i]);
     }

      sort(s,f,ac_no,n);

printMaxActivities(s, f,ac_no, n);



}

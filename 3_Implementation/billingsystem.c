/**
 * @file billingsystem.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include"billing.h"

int price[7] = {200,180,177,220,150 ,120,250 };
double mealTaxPrices[7];
int adultNumber,childNumber;


void printMeals();
void orderMeals();
double orderForAdult();
double orderForChildren();
int main()
{
    char response = 'y';
    
     printMeals();
     while(response == 'y'|| response == 'Y')
    {
            printf("please enter number of adults  :");
            scanf("%d",&adultNumber);
            
            printf("please enter number of children:");
            scanf("%d",&childNumber);
            
                       
            orderMeals();
            
            printf("\nwould you like to continue(y/n):");
            scanf("\n%c",&response);
    }
  
 printf("\n      ******************** THANK YOU FOR COMING  *************************\n");
 printf("\20**********************   PLEASE VISIT US NEXT TIME  **************************\20 \n");
   system("pause");
   return 0;
}

void printMeals()
{
     
      printf("\20*******************  WELCOME TO FRIENDS RESTAURANT **************************\20\n");
      printf(" \t\t\t Below is the menue:\20\n");
      printf(" \t\t\t MEALS\t\t\tPRICE:\n");
      printf(" \t\t\t \22*******************************\22\n");
      printf(" \t\t\t 1- Fish and Chips\tRS 200\n");
      printf(" \t\t\t 2- Chicken 65\t\tRS 180\n");
      printf(" \t\t\t 3- Fry chicken\tRS 177\n");
      printf(" \t\t\t 4- Prawn fry\tRS 220\n");
      printf(" \t\t\t 5- Chicken chill\tRS 150\n");
      printf(" \t\t\t 6- Apollo fish\t\tRS 120\n");
      printf(" \t\t\t 7- Chicken Briyani\tRS 250\n");
            
      printf("\n");
}

/**
 * @brief 
 * 
 */
void orderMeals()
{
	double totalPriceForAdult, totalPriceForChildren;
	double allPayment,discount;
         printf("                      \t\t**** ORDER MENUE****\n");  
         
         
        totalPriceForAdult =  orderForAdult();
        totalPriceForChildren = orderForChildren();
		allPayment = totalPriceForAdult + totalPriceForChildren ;
        
     printf("\n \t\t     \22**************************************\22    \n");
     printf(" \t\t   ******************  final BILL   ************      \n");
     printf(" \t\t\tadult/child\tcount\t\ttotal price\n");
     printf(" \t\t\tadults\t\t%d\t\t%5.2f\n",adultNumber,totalPriceForAdult);
     printf(" \t\t\tchildren\t%d\t\t%5.2f\n",childNumber,totalPriceForChildren);
     printf(" \t\t\tTotal bill\t\t\t%5.2f\n",allPayment );

     if(allPayment < 10)
		 discount=((allPayment * 50)/100);
     else if(allPayment>= 10 && allPayment<20)
          discount=((allPayment * 10)/100);
     else if(allPayment>= 20 && allPayment<30)
          discount=((allPayment * 15)/100);
     else if(allPayment>= 30 && allPayment<40)
          discount=((allPayment * 20)/100);
	 else 
		  discount= ((allPayment * 5.0)/100);

          printf(" \t\t\tTotal bill after discount\t%5.2f\n",allPayment-discount);

}
/**
 * @brief 
 * 
 * @return double 
 */
double orderForAdult()
{
     int menuOption,i,amount;
      char response = 'y';
      double totalPerPerson = 0.0,totalAllPerson = 0.0;
      double tax = 5.0;
      if(adultNumber <=0)
		   printf("\n ");
	  else 
      printf("*\tadults:\n");
      for(i=0;i<adultNumber;i++)
     {
               printf("adult %d please enter your orders\n",i+1);
               while(response == 'y' || response == 'Y')
               {
                              printf("please enter your option:");
                              scanf("%d",&menuOption);
							  if(menuOption<1 || menuOption>7)
							  {
								  printf("sorry we don`t have this order \nagain! ");
								  continue;
							  }
                              printf("please enter your amount of order:");
                              scanf("%d",&amount);
                              
                              
                           totalPerPerson = totalPerPerson + (amount * price[menuOption - 1] );
                              
                              printf("\nWould you like to enter more orders(y/n):");
                              scanf("\n%c",&response);
               
                              
                           
               }
               printf("\n");
               totalAllPerson += totalAllPerson +  totalPerPerson;
               totalPerPerson = 0.0;
               response = 'y';
     }
     
     return totalAllPerson + ((totalAllPerson * tax) / 100);
}
/**
 * @brief 
 * 
 * @return double 
 */
double orderForChildren()
{
       int menuOption,i,amount;
      char response = 'y';
      double totalPerChild = 0.0,totalAllChildren = 0.0;
      double tax = 5.0,oneOrder;
       if(childNumber <=0)
		   printf("\n");
	   else
       printf("*\tChildren:\n");
       for(i=0;i<childNumber;i++)
     {
               printf("child %d please enter your orders\n",i+1);
               while(response == 'y' || response == 'Y')
               {
                              printf("please enter your option:");
                              scanf("%d",&menuOption);
							  if(menuOption<1 || menuOption>7)
							  {
								  printf("sorry we don`t have this order \nagain! ");
                                  continue;
							  }
                              printf("please enter your amount of order:");
                              scanf("%d",&amount);
                              
                              oneOrder = (price[menuOption - 1] * 60)/100 ;//this one order for a child with discount %60 of one order of adult
                              totalPerChild = totalPerChild + (amount * oneOrder)  ;
                              
							  printf("Would you like to enter more orders(y/n):");
                              scanf("\n%c",&response);
                              
                           
               }
               totalAllChildren += totalAllChildren +  totalPerChild;
               response = 'y';
               totalPerChild = 0.0;
               
               printf("\n");
               
     }
     
     return totalAllChildren + ((totalAllChildren * tax) / 100);
}

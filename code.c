#include <stdio.h>
#define column 8
#define row 366
#define lakes 6


//FUNCTION TO CALCULATE THE AVERAGE
double
average (double sum, int count)
{
  double ans;
  ans = sum / count;
  return (ans);
}




//FUNCTION TO PRINT SPACES
void
stars ()
{
  printf ("\n//////////////////////////////////////////////////////////////////////////////////////////\n\n");
}




//FUNCTION TO FIND HIGHEST VALUE IN ARRAY
int
findbig (double array[], int size)
{
  int i, largest, where;
  largest = array[0];
  for (i = 0; i < size; ++i)
    if (array[i] > largest)
      {
        largest = array[i];
        where = i;
      }
  return (where);
}




//FUNCTION TO FIND SMALLEST VALUE IN ARRAY
int
findsmall (double array[], int size)
{
  int i, smallest, where;
  smallest = array[0];
  for (i = 0; i < size; ++i)
    if (array[i] < smallest)
      {
        smallest = array[i];
        where = i;
      }
  return (where);
}




//FUNCTIONS TO FIND DATE
void
findsame (double value, double arr[row][column], int x)
{
  int j, temp;
  for (j = 0; j < row; ++j)
    {
      if (arr[j][x] == value)
        {
          if (j <= 30)
            {
              printf ("%d/01", j + 1);
            }
          else if (j > 30 && j <= 59)
            {
              printf ("%d/02", j - 30);
            }
          else if (j > 59 && j <= 90)
            {
              printf ("%d/03", j - 59);
            }
          else if (j > 90 && j <= 120)
            {
              printf ("%d/04", j - 90);
            }
          else if (j > 120 && j <= 151)
            {
              printf ("%d/05", j - 120);
            }
          else if (j > 151 && j <= 181)
            {
              printf ("%d/06", j - 151);
            }
          else if (j > 181 && j <= 212)
            {
              printf ("%d/07", j - 181);
            }
          else if (j > 212 && j <= 243)
            {
              printf ("%d/08", j - 212);
            }
          else if (j > 243 && j <= 273)
            {
              printf ("%d/09", j - 243);
            }
          else if (j > 273 && j <= 304)
            {
              printf ("%d/10", j - 273);
            }
          else if (j > 304 && j <= 334)
            {
              printf ("%d/11", j - 304);
            }
          else if (j > 334 && j <= 365)
            {
              printf ("%d/12", j - 334);
            }
          printf (" ");
        }
    }
  printf ("\n");


}




//FUNCTIONS TO ARRANGE ARRAY IN DESCENDING ORDER
void
warmtocold (double arr[], int value)
{
  int i, j;
  double sup, mich, huron, erie, ont, stclr, a;


  sup = arr[0];
  mich = arr[1];
  huron = arr[2];
  erie = arr[3];
  ont = arr[4];
  stclr = arr[5];


  for (i = 0; i < value; ++i)
    {
      for (j = i + 1; j < value; ++j)
        {
          if (arr[i] < arr[j])
            {
              a = arr[i];
              arr[i] = arr[j];
              arr[j] = a;
            }
        }
    }
  for (i = 0; i < value; ++i)
    {
      if (arr[i] == sup)
        printf ("LAKE SUPERIOR: %.2lf\n", sup);
      else if (arr[i] == mich)
        printf ("LAKE MICHIGAN: %.2lf\n", mich);
      else if (arr[i] == huron)
        printf ("LAKE HURON:    %.2lf\n", huron);
      else if (arr[i] == erie)
        printf ("LAKE ERIE:     %.2lf\n", erie);
      else if (arr[i] == ont)
        printf ("LAKE ONTARIO:  %.2lf\n", ont);
      else if (arr[i] == stclr)
        printf ("LAKE ST.CLAIR: %.2lf\n", stclr);


    }
}










////////////////MAIN FUNCTION////////////////


int
main (void)
{
//INITIALIZE VARIABLES    
  int count = 0, location = 0, i, j, x, y;
  double temp, sum, ans, yaverage, averaget[lakes], yaverage2, averaget2[lakes],loweravg[lakes], higheravg[lakes];






//OPEN FILE 
  FILE *in = fopen ("data.txt", "r");
  if (in == NULL)
    {
      printf ("Could not open or find the file \"data.txt\".");
      return 1;
    }






//FILL 2D ARRAY WITH DATA
  double data[row][column];
  for (i = 0; i < row; ++i)
    {
      for (j = 0; j < column; ++j)
        {
          fscanf (in, "%lf", &data[i][j]);
        }
    }
  fclose (in);
  stars ();








//FIND AVERAGE FOR ALL LAKES COMBINED
  for (i = 0; i < row; ++i)
    {
      for (j = 2; j < column; ++j)
        {
          temp = data[i][j];
          sum = sum + temp;
          count++;
        }
    }
  yaverage = average (sum, count);
  printf ("THE YEARLY AVERAGE FOR ALL THE LAKES SUMMED TOGETHER IS %.2lf\n",yaverage);
  stars ();






//CALCULATE THE YEARLY AVERAGE TEMPRATURE FOR EACH LAKE
  for (i = 2; i < column; ++i)
    {
      sum = 0;
      count = 0;
      for (j = 0; j < row; ++j)
        {
          temp = data[j][i];
          sum = sum + temp;
          count++;
        }
      ans = average (sum, count);
      switch (i)
        {
        case 2:
          printf ("THE YEARLY AVERAGE TEMPRATURE FOR LAKE SUPERIOR IS:  %.2lfC\n",ans);
          averaget[0] = ans;
          break;


        case 3:
          printf ("THE YEARLY AVERAGE TEMPRATURE FOR LAKE MICHIGAN IS:  %.2lfC\n",ans);
          averaget[1] = ans;
          break;


        case 4:
          printf ("THE YEARLY AVERAGE TEMPRATURE FOR LAKE HURON IS:     %.2lfC\n",ans);
          averaget[2] = ans;
          break;


        case 5:
          printf ("THE YEARLY AVERAGE TEMPRATURE FOR LAKE ERIE IS:      %.2lfC\n",ans);
          averaget[3] = ans;
          break;


        case 6:
          printf ("THE YEARLY AVERAGE TEMPRATURE FOR LAKE ONTARIO IS:   %.2lfC\n",ans);
          averaget[4] = ans;
          break;


        case 7:
          printf ("THE YEARLY AVERAGE TEMPRATURE FOR LAKE ST. CLAIR IS: %.2lfC\n",ans);
          averaget[5] = ans;
          break;
        }
    }
  stars ();






//FIND THE WARMEST LAKE BASED ON YEARLY AVERAGE
  location = findbig (averaget, lakes);
  switch (location)
    {
    case 0:
      printf
        ("LAKE SUPERIOR IS THE WARMEST LAKE BASED ON A YEARLY AVERAGE TEMPRATURE OF:     %.2lfC\n",averaget[location]);
      break;
    case 1:
      printf
        ("LAKE MICHIGAN IS THE WARMEST LAKE BASED ON A YEARLY AVERAGE TEMPRATURE OF:     %.2lfC\n",averaget[location]);
      break;
    case 2:
      printf
        ("LAKE HURON IS THE WARMEST LAKE BASED ON A YEARLY AVERAGE TEMPRATURE OF:        %.2lfC\n",averaget[location]);
      break;
    case 3:
      printf
        ("LAKE ERIE IS THE WARMEST LAKE BASED ON YEARLY AVERAGE TEMPRATURE OF:           %.2lfC\n",averaget[location]);
      break;
    case 4:
      printf
        ("LAKE ONTARIO IS THE WARMEST LAKE BASED ON A YEARLY AVERAGE TEMPRATURE OF:      %.2lfC\n",averaget[location]);
      break;
    case 5:
      printf("ST. CLAIR IS THE WARMEST LAKE BASED ON A YEARLY AVERAGE TEMPRATURE OF: %.2lf\n",averaget[location]);
      break;
    }
    
    


//FIND THE COLDEST LAKE BASED ON YEARLY AVERAGE
  location = findsmall (averaget, lakes);


  switch (location)
    {
    case 0:
      printf
        ("LAKE SUPERIOR IS THE COLDEST LAKE BASED ON A YEARLY AVERAGE TEMPRATURE OF:      %.2lf\n",averaget[location]);
      break;
    case 1:
      printf
        ("LAKE MICHIGAN IS THE COLDEST LAKE BASED ON A YEARLY AVERAGE TEMPRATURE OF:      %.2lf\n",averaget[location]);
      break;
    case 2:
      printf
        ("LAKE HURON IS THE COLDEST LAKE BASED ON A YEARLY AVERAGE TEMPRATURE OF:         %.2lf\n",averaget[location]);
      break;
    case 3:
      printf
        ("LAKE ERIE IS THE COLDEST LAKE BASED ON A YEARLY AVERAGE TEMPRATURE OF:          %.2lf\n",averaget[location]);
      break;
    case 4:
      printf
        ("LAKE ONTARIO IS THE COLDEST LAKE BASED ON A YEARLY AVERAGE TEMPRATURE OF:       %.2lf\n",averaget[location]);
      break;
    case 5:
      printf
        ("LAKE ST. CLAIR IS THE COLDEST LAKE BASED ON A YEARLY AVERAGE TEMPRATURE OF:      %.2lf\n",
         averaget[location]);
      break;
    }
  stars ();






//FIND LAKES WITH AVERAGE TEMPRATURES LOWER THAN OVERALL AVERAGE
  for (i = 0; i < lakes; ++i)
    if (averaget[i] <= yaverage)
      {
        switch (i)
          {
          case 0:
            printf
              ("LAKE SUPERIOR HAS AN AVERAGE YEARLY TEMPRATURE LOWER THAN THE OVERALL AVERAGE WITH A YEARLY AVERAGE OF:    %.2lfC\n",averaget[0]);
            break;


          case 1:
            printf
              ("LAKE MICHIGAN HAS AN AVERAGE YEARLY TEMPRATURE LOWER THAN THE OVERALL AVERAGE WITH A YEARLY AVERAGE OF:    %.2lfC\n",averaget[1]);
            break;
          case 2:
            printf
              ("LAKE HURON HAS AN AVERAGE YEARLY TEMPRATURE LOWER THAN THE OVERALL AVERAGE WITH A YEARLY AVERAGE OF:       %.2lfC\n",averaget[2]);
            break;
          case 3:
            printf("LAKE ERIE HAS AN AVERAGE YEARLY TEMPRATURE LOWER THAN THE OVERALL AVERAGE WITH A YEARLY AVERAGE OF:    %.2lfC\n",averaget[3]);
            break;
          case 4:
            printf
              ("LAKE ONTARIO HAS AN AVERAGE YEARLY TEMPRATURE LOWER THAN THE OVERALL AVERAGE WITH A YEARLY AVERAGE OF:     %.2lfC\n",averaget[4]);
            break;
          case 5:
            printf
              ("LAKE ST.CLAIR HAS AN AVERAGE YEARLY TEMPRATURE LOWER THAN THE OVERALL AVERAGE WITH A YEARLY AVERAGE OF:    %.2lfC\n",
               averaget[5]);
            break;
          }
      }
      printf("\n");




//FIND LAKES WITH AVERAGE TEMPRATURES HIGHER THAN OVERALL AVERAGE
  for (i = 0; i < lakes; ++i)
    if (averaget[i] > yaverage)
      {
        switch (i)
          {
          case 0:
            printf
              ("LAKE SUPERIOR HAS AN AVERAGE YEARLY TEMPRATURE HIGHER THAN THE OVERALL AVERAGE WITH A YEARLY AVERAGE OF:   %.2lfC\n",averaget[0]);
            break;
          case 1:
            printf
              ("LAKE MICHIGAN HAS AN AVERAGE YEARLY TEMPRATURE HIGHER THAN THE OVERALL AVERAGE WITH A YEARLY AVERAGE OF:   %.2lfC\n",averaget[1]);
            break;
          case 2:
            printf
              ("LAKE HURON HAS AN AVERAGE YEARLY TEMPRATURE HIGHER THAN THE OVERALL AVERAGE WITH A YEARLY AVERAGE OF:      %.2lfC\n",averaget[2]);
            break;
          case 3:
            printf
              ("LAKE ERIE HAS AN AVERAGE YEARLY TEMPRATURE HIGHER THAN THE OVERALL AVERAGE WITH A YEARLY AVERAGE OF:       %.2lfC\n",averaget[3]);
            break;
          case 4:
            printf
              ("LAKE ONTARIO HAS AN AVERAGE YEARLY TEMPRATURE HIGHER THAN THE OVERALL AVERAGE WITH A YEARLY AVERAGE OF:    %.2lfC\n",averaget[4]);
            break;
          case 5:
            printf
              ("LAKE ST.CLAIR HAS AN AVERAGE YEARLY TEMPRATURE HIGHER THAN THE OVERALL AVERAGE WITH A YEARLY AVERAGE OF:   %.2lfC\n",averaget[5]);
            break;
          }
        ans = 0;
      }
  stars ();






//CALCULATE THE HIGHEST TEMPRATURE FOR EACH LAKE
  ans = 0;
  for (i = 2; i < column; ++i)
    {
      for (j = 0; j < row; ++j)
        {
          if (data[j][i] >= ans)
            {
              ans = data[j][i];
            }
        }
      switch (i)
        {
        case 2:
          printf("THE HIGHEST RECORDED TEMPRATURE FOR LAKE SUPERIOR IS: %.2lfC, ON THE FOLLOWING DATE(S):\n",ans);
          findsame (ans, data, 2);
          break;
        case 3:
          printf("THE HIGHEST RECORDED TEMPRATURE FOR LAKE MICHIGAN IS: %.2lfC, ON THE FOLLOWING DATE(S):\n", ans);
          findsame (ans, data, 3);
          break;
        case 4:
          printf("THE HIGHEST RECORDED TEMPRATURE FOR LAKE HURON IS: %.2lfC, ON THE FOLLOWING DATE(S):\n",ans);
          findsame (ans, data, 4);
          break;
        case 5:
          printf("THE HIGHEST RECORDED TEMPRATURE FOR LAKE ERIE IS: %.2lfC, ON THE FOLLOWING DATE(S):\n",ans);
          findsame (ans, data, 5);
          break;
        case 6:
          printf("THE HIGHEST RECORDED TEMPRATURE FOR LAKE ONTARIO IS: %.2lfC, ON THE FOLLOWING DATE(S):\n",ans);
          findsame (ans, data, 6);
          break;
        case 7:
          printf("THE HIGHEST RECORDED TEMPRATURE FOR LAKE ST.CLAIR IS: %.2lfC, ON THE FOLLOWING DATE(S):\n",ans);
          findsame (ans, data, 7);
          break;
        }
      ans = 0;
    }
  stars ();






//CALCULATE THE LOWEST TEMPRATURE FOR EACH LAKE
  ans = 1000;
  for (i = 2; i < column; ++i)
    {
      for (j = 0; j < row; ++j)
        {
          if (data[j][i] < ans)
            {
              ans = data[j][i];
            }
        }
      switch (i)
        {
        case 2:
          printf
            ("THE LOWEST RECORDED TEMPRATURE FOR LAKE SUPERIOR IS: %.2lfC, ON THE FOLLOWING DATE(S):\n",ans);
          findsame (ans, data, 2);
          break;
        case 3:
          printf
            ("THE LOWEST RECORDED TEMPRATURE FOR LAKE MICHIGAN IS: %.2lfC, ON THE FOLLOWING DATE(S):\n",ans);
          findsame (ans, data, 3);
          break;
        case 4:
          printf
            ("THE LOWEST RECORDED TEMPRATURE FOR LAKE HURON IS: %.2lfC, ON THE FOLLOWING DATE(S):\n",ans);
          findsame (ans, data, 4);
          break;
        case 5:
          printf
            ("THE LOWEST RECORDED TEMPRATURE FOR LAKE ERIE IS: %.2lfC, ON THE FOLLOWING DATE(S):\n",
             ans);
          findsame (ans, data, 5);
          break;
        case 6:
          printf
            ("THE LOWEST RECORDED TEMPRATURE FOR LAKE ONTARIO IS: %.2lfC, ON THE FOLLOWING DATE(S):\n",ans);
          findsame (ans, data, 6);
          break;
        case 7:
          printf
            ("THE LOWEST RECORDED TEMPRATURE FOR LAKE ST.CLAIR IS: %.2lfC, ON THE FOLLOWING DATE(S):\n",ans);
          findsame (ans, data, 7);
          break;
        }
    }
  stars ();






//CALCULATE HIGHEST OVERALL TEMPRATURE FOR ALL LAKES:
  ans = 0;
  for (i = 2; i < column; ++i)
    {
      for (j = 0; j < row; ++j)
        {
          if (data[j][i] >= ans)
            {
              ans = data[j][i];
              x = i;
              y = j;
            }
        }
    }
  switch (x)
    {
    case 2:
      printf
        ("LAKE SUPERIOR HAS THE HIGHEST OVERALL RECORDED TEMPRATURE OF %.2lf, ON THE FOLLOWING DATES:\n",ans);
      findsame (ans, data, 2);
      break;
    case 3:
      printf
        ("LAKE MICHIGAN HAS THE HIGHEST OVERALL RECORDED TEMPRATURE OF %.2lf, ON THE FOLLOWING DATES:\n",
         ans);
      findsame (ans, data, 3);
      break;
    case 4:
      printf
        ("LAKE HURON HAS THE HIGHEST OVERALL RECORDED TEMPRATURE OF %.2lf, ON THE FOLLOWING DATES:\n",
         ans);
      findsame (ans, data, 4);
      break;
    case 5:
      printf
        ("LAKE ERIE HAS THE HIGHEST OVERALL RECORDED TEMPRATURE OF %.2lf, ON THE FOLLOWING DATES:\n",ans);
      findsame (ans, data, 5);
      break;
    case 6:
      printf
        ("LAKE ONTARIO HAS THE HIGHEST OVERALL RECORDED TEMPRATURE OF %.2lf, ON THE FOLLOWING DATES:\n",ans);
      findsame (ans, data, 6);
      break;
    case 7:
      printf
        ("LAKE ST.CLAIR HAS THE HIGHEST OVERALL RECORDED TEMPRATURE OF %.2lf, ON THE FOLLOWING DATES:\n",ans);
      findsame (ans, data, 7);
      break;
    }
  stars ();




//FIND THE LOWEST OVERALL TEMPRATURE:
  ans = 10000;
  for (i = 2; i < column; ++i)
    {
      for (j = 0; j < row; ++j)
        {
          if (data[j][i] < ans)
            {
              ans = data[j][i];
              x = i;
              y = j;
            }
        }
    }
  switch (x)
    {
    case 2:
      printf
        ("LAKE SUPERIOR HAS THE LOWEST OVERALL RECORDED TEMPRATURE OF %.2lfC, ON THE FOLLOWING DATES:\n",ans);
      findsame (ans, data, 2);
      break;


    case 3:
      printf
        ("LAKE MICHIGAN HAS THE LOWEST OVERALL RECORDED TEMPRATURE OF %.2lfC, ON THE FOLLOWING DATES:\n",ans);
      findsame (ans, data, 3);
      break;
    case 4:
      printf
        ("LAKE HURON HAS THE LOWEST OVERALL RECORDED TEMPRATURE OF %.2lfC, ON THE FOLLOWING DATES:\n",ans);
      findsame (ans, data, 4);
      break;
    case 5:
      printf
        ("LAKE ERIE HAS THE LOWEST OVERALL RECORDED TEMPRATURE OF %.2lfC, ON THE FOLLOWING DATES:\n",ans);
      findsame (ans, data, 5);
      break;
    case 6:
      printf
        ("LAKE ONTARIO HAS THE LOWEST OVERALL RECORDED TEMPRATURE OF %.2lfC, ON THE FOLLOWING DATES:\n",ans);
      findsame (ans, data, 6);
      break;


    case 7:
      printf
        ("LAKE ST.CLAIR HAS THE LOWEST OVERALL RECORDED TEMPRATURE OF %.2lfC, ON THE FOLLOWING DATES:\n",ans);
      findsame (ans, data, 7);
      break;
    }
  stars ();






//FIND SUMMER AVERAGE FOR EACH LAKE


  for (i = 2; i < column; ++i)
    {
      sum = 0;
      count = 0;
      for (j = 171; j <=264; ++j)
        {
          temp = data[j][i];
          sum = sum + temp;
          count++;
        }
      ans = average (sum, count);


      switch (i)
        {
        case 2:
          averaget2[0] = ans;
          break;
        case 3:
          averaget2[1] = ans;
          break;
        case 4:
          averaget2[2] = ans;
          break;
        case 5:
          averaget2[3] = ans;
          break;
        case 6:
          averaget2[4] = ans;
          break;
        case 7:
          averaget2[5] = ans;
          break;
        }
    }
  printf
    ("THE LAKES ORDERED WARMEST TO COLDEST BASED ON SUMMER AVERAGES IS:\n");
  warmtocold (averaget2, lakes);
  stars ();






//FIND WINTER AVERAGE FOR EACH LAKE
  for (i = 2; i < column; ++i)
    {
      count = 0;
      sum = 0;
      for (j = 0; j <= 78; ++j)
        {
          temp = data[j][i];
          sum = sum + temp;
          count++;
        }
      for (int k = 354; k <= 365; ++k)
        {
          temp = data[k][i];
          sum = sum + temp;
          count++;
        }
      ans = average (sum, count);
      switch (i)
        {
        case 2:
          averaget2[0] = ans;
          break;
        case 3:
          averaget2[1] = ans;
          break;
        case 4:
          averaget2[2] = ans;
          break;
        case 5:
          averaget2[3] = ans;
          break;
        case 6:
          averaget2[4] = ans;
          break;
        case 7:
          averaget2[5] = ans;
          break;
        }
    }


  printf
    ("THE LAKES ORDERED WARMEST TO COLDEST BASED ON WINTER AVERAGE IS:\n");
  warmtocold (averaget2, lakes);
  stars ();






//CALCULATE NUMBER OF DAYS YOU CAN COMFORTABLY SWIM 
  printf
    ("YOU CAN SWIM COMFORTABLY IN EACH LAKE IF THE TEMPRATURE IS GREATER THAN 20C\n");
  count = 0;
  for (i = 2; i < column; ++i)
    {
      for (j = 0; j < row; ++j)
        {
          if (data[j][i] > 20)
            {
              count++;
            }
        }
      switch (i)
        {
        case 2:
          printf ("NUMBER OF DAYS YOU CAN SWIM IN LAKE SUPERIOR:  %d\n", count);
          break;
        case 3:
          printf ("NUMBER OF DAYS YOU CAN SWIM IN LAKE MICHIGAN:  %d\n", count);
          break;
        case 4:
          printf ("NUMBER OF DAYS YOU CAN SWIM IN LAKE HURON:     %d\n", count);
          break;
        case 5:
          printf ("NUMBER OF TIMES YOU CAN SWIM IN LAKE ERIE:     %d\n", count);
          break;
        case 6:
          printf ("NUMBER OF TIMES YOU CAN SWIM IN LAKE ONTARIO:  %d\n", count);
          break;
        case 7:
          printf ("NUMBER OF TIMES YOU CAN SWIM IN LAKE ST.CLAIR: %d\n", count);
          break;
        }
      count = 0;
    }
  stars ();
  
  
  
//CALCULATE THE NUMBERS OF DAYS EACH LAKE IS FROZEN IN A YEAR
  count = 0;
  for (i = 2; i < column; ++i)
    {
      for (j = 0; j < row; ++j)
        {
          if (data[j][i] < 0)
            {
              count++;
            }
        }
      switch (i)
        {
        case 2:
          printf("NUMBER OF DAYS LAKE SUPERIOR IS FROZEN:   %d\n", count);
          break;
        case 3:
          printf("NUMBER OF DAYS LAKE MICHIGAN IS FROZEN:   %d\n", count);
          break;
        case 4:
          printf("NUMBER OF DAYS LAKE HURON IS FROZEN:      %d\n", count);
          break;
        case 5:
          printf("NUMBER OF DAYS LAKE ERIE IS FROZEN:       %d\n", count);
          break;
        case 6:
          printf("NUMBER OF DAYS LAKE ONTARIO IS FROZEN:    %d\n", count);
          break;
        case 7:
          printf("NUMBER OF DAYS LAKE ST.CLAIR IS FROZEN:   %d\n", count);
          break;
        }
      count = 0;
    }
  stars ();




  
//AVERAGES CALCULATED FOR 2019 YEAR


//OPEN FILE 
  FILE *here = fopen ("2019data.txt", "r");
  if (here == NULL)
    {
      printf ("Could not open or find the file \"data.txt\".");
      return 1;
    }






//FILL 2D ARRAY WITH DATA
  for (i = 0; i < row; ++i)
    {
      for (j = 0; j < column; ++j)
        {
          fscanf (here, "%lf", &data[i][j]);
        }
    }
    fclose(here);
 






//CALCULATE THE YEARLY AVERAGE TEMPRATURE FOR EACH LAKE
  for (i = 2; i < column; ++i)
    {
      sum = 0;
      count = 0;
      for (j = 0; j < 365; ++j)
        {
          temp = data[j][i];
          sum = sum + temp;
          count++;
        }
      ans = average (sum, count);
      switch (i)
        {
        case 2:
          averaget2[0] = ans;
          break;


        case 3:
          averaget2[1] = ans;
          break;


        case 4:
          averaget2[2] = ans;
          break;


        case 5:
          averaget2[3] = ans;
          break;


        case 6:
          averaget2[4] = ans;
          break;


        case 7:
          averaget2[5] = ans;
          break;
        }
    }


  
  //FIND AVERAGE FOR ALL LAKES COMBINED
  sum=0;
  count=0;
  for (i = 0; i <=5; ++i)
    {
          temp = averaget2[i];
          sum = sum + temp;
          count++;
    }
  yaverage2 = average (sum, count);
  
  printf("YEAR     LAKE SUPERIOR     LAKE MICHIGAN     LAKE HURON     LAKE ERIE     LAKE ONTARIO     LAKE ST.CLAIR     OVERALL AVERAGE\n");
  printf("2019:     ");
  for (i = 0; i <= 5; ++i)
  {
  printf("     %.2lf       ",averaget2[i]);
  }
  printf("     %.2lf       ",yaverage2);
  printf("\n2020:     ");
  for (i = 0; i <=5; ++i)
  {
  printf("     %.2lf       ",averaget[i]);
  }


  printf("    %.2lf       ",yaverage);
  
  
  return 0;
}

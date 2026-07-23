#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cal ();
int csvfile ();

int main () {
int choice;
printf("for choose calculate enter (1) for choose csv file enter (2)\n ");
scanf("%d",&choice);

if (choice == 1) {  
    return cal ();  
}   
else if (choice == 2) {  
    return  csvfile ();  
}   
else {  
    printf("input error");  
}

}

int cal () {

// تعريف المتغيرات داخل البرنامج  
float arabic, english, math, science, Islam, sports, history;  
// متغير لحفظ مجموع المواد والنسبة المئوية  
float sum;  
float average;  

printf("=========================================\n");  
printf("   Welcome to Students Grade Calculator  \n");   
printf("=========================================\n\n");  

// كود سؤال وجواب بـ printf و scanf  
printf("Enter Arabic result: ");  
scanf("%f", &arabic);   

printf("Enter English result: ");  
scanf("%f", &english);   

printf("Enter Math result: ");  
scanf("%f", &math);   

printf("Enter Science result: ");  
scanf("%f", &science);   

printf("Enter Islam result: ");  
scanf("%f", &Islam);   

printf("Enter Sports result: ");  
scanf("%f", &sports);   

printf("Enter History result: ");  
scanf("%f", &history);   

// مجموع المواد  
sum = arabic + english + math + science + Islam + sports + history;  
  
// حساب النسبة المئوية (إذا كانت كل مادة من 100، المجموع الكلي 700)  
// القسمة على 7 تعطي النسبة المئوية مباشرة  
average = sum / 7;  

printf("\n-----------------------------------------\n");  
// استخدام %.2f لطباعة رقمين فقط بعد الفاصلة العشرية  
printf("Your Average = %.2f%%\n", average);   

// كود التصنيف بناءً على النسبة المئوية  
if (average >= 90 && average <= 100) {  
    printf("Your Classification is: A\n");  
}   
else if (average >= 75 && average < 90) {  
    printf("Your Classification is: B\n");  
}   
else if (average >= 60 && average < 75) {  
    printf("Your Classification is: C\n");  
}   
else if (average >= 50 && average < 60) {  
    printf("Your Classification is: D\n");  
}   
else {  
    printf("Your Classification is: F\n");  
}  
  
printf("-----------------------------------------\n");  

return 0;

}

int csvfile ()    {

char filename [] = "Estudents grades.csv";  
FILE *file = fopen (filename,"r");  
  
if (file == NULL) {  


    printf ("Eror,inputs is not right.\n");  


    return 1;  
}  
int found = 0; 
char line [1024];  
char student [100];   //مصفوفة لتخزين قيمة اسم الطالب 100 حرف  

printf ("Enter student name: "); //لطباعة ادخل اسم الطالب  

scanf ("%99s", student); //لا نضع اند لاننا نمثل عنوان اول عنصر في المصفوفة  

//99 letters only.  

//مراحل اللوب  
// fgets = read onr line in one loop  
//line = المصفوفة او المكان الذي سيخزن فيه السطر  
//sizeof(line) = حجم المصفوفة او عدد الاحرف  
//file = الملف الذي فتحناه بfopen  



while (fgets(line,sizeof(line), file)) {  

    line[strcspn(line, "\n")] = 0;  //سطر يحذف علامة الenter   

    //\n للسطر القادم  
      
    char copy[1024];  
    //مصفوفة جديدة copy  

    strcpy(copy, line); //دالة string copy  


    char *name = strtok(copy, ","); //دالة تبحث عن اول فاصلة وتاخذ ما قبلها فقط  
    //تشير لname  

    if (strcmp(name, student) == 0) {  

        printf ("\nStudent Details:\n");  

        printf ("%s\n", line);  
        
        found = 1;
        break;  

    }  
    
}  
//not found تكافئ found == 0
	if (!found) {
		
		printf("\nError in name!\n");
}

fclose(file);  
  
return 0;

}

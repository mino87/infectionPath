//
//  main.c
//  infestPath
//
//  Created by Juyeop Kim on 2022/10/20.
//

#include <stdio.h>
#include <string.h>
#include "ifct_element.h"
#include "ifct_database.h"

#define MENU_PATIENT        1
#define MENU_PLACE          2
#define MENU_AGE            3
#define MENU_TRACK          4
#define MENU_EXIT           0

#define TIME_HIDE           2

int trackInfester(int patient_no, int *detected_time, int *place);
int main(int argc, const char * argv[]) {
    
    int menu_selection;
    void *ifct_element;
    FILE* fp;
    
    int pIndex, age, time;
    int placeHist[N_HISTORY];
    int i,k,j;
   
    char jj[100];
    //------------- 1. loading patient info file ------------------------------
    //1-1. FILE pointer open
    if (argc != 2)
    {
        printf("[ERROR] syntax : infestPath (file path).");
        return -1;
    }
    
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("[ERROR] Failed to open database file!! (%s)\n", argv[1]);
        return -1;
    }
    

    
	while (3 == fscanf(fp,"%d %d %d",&pIndex,&age,&time)){//3개 먼저 받음  
		
		for(i=0;i<N_HISTORY;i++)
		{
			fscanf(fp,"%d",&placeHist[i]);
		}
		    
		ifct_element = ifctele_genElement(pIndex, age,time,placeHist);
		
		ifctdb_addTail(ifct_element);
	}
    
    
    //1-3. FILE pointer close
    fclose(fp);
    

    
    do {
        printf("\n=============== INFECTION PATH MANAGEMENT PROGRAM (No. of patients : %i) =============\n", ifctdb_len());
        printf("1. Print details about a patient.\n");                      //MENU_PATIENT
        printf("2. Print list of patients infected at a place.\n");        //MENU_PLACE
        printf("3. Print list of patients in a range of age.\n");          //MENU_AGE
        printf("4. Track the root of the infection\n");                     //MENU_TRACK
        printf("0. Exit.\n");                                               //MENU_EXIT
        printf("=============== ------------------------------------------------------- =============\n\n");
        
        printf("Select a menu :");
        scanf("%d", &menu_selection);
        fflush(stdin);
        
        switch(menu_selection)
        {
            case MENU_EXIT:
                printf("Exiting the program... Bye bye.\n");
                break;
                
            case MENU_PATIENT:
                
                printf("환자의 번호를 입력하시오. : \n");
                scanf("%i",&pIndex);
				void* input = ifctdb_getData((pIndex-1));
				ifctele_printElement(input);
                    
                break;
                
            case MENU_PLACE:
                printf("장소를 입력하십시오. : \n");
                scanf("%s",&jj);
                int flag_2=0;
                for(i=0;i<5;i++)
                {
                	ifct_element = ifctdb_getData(i);          
                	
				}
                break;
                
            case MENU_AGE:
                printf("나이를 입력하십시오.(최소)(최대) : \n");
                int i,k,j;
                int flag=0;
				scanf("%d %d",&i,&j);
				for(k=0;k<5;k++)
				{
					if(i<=ifctele_getAge(ifctdb_getData(k))&&ifctele_getAge(ifctdb_getData(k))<=j)
					{
						flag++;
					}
					
				}
				printf("%d %d  사이의 나이인 환자는 %d명 입니다.",i,j,flag);
		
                break;
                
            case MENU_TRACK:
                    
                break;
                
            default:
                printf("[ERROR Wrong menu selection! (%i), please choose between 0 ~ 4\n", menu_selection);
                break;
        }
    
    } while(menu_selection != 0);
    
    
    return 0;
}

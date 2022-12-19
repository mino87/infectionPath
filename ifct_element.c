//
//  ifs_element.c
//  InfestPath
//
//  Created by Juyeop Kim on 2020/10/20.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ifct_element.h"

typedef enum place {
    Seoul,          //0
    Jeju,           //1
    Tokyo,          //2
    LosAngeles,     //3
    NewYork,        //4
    Texas,          //5
    Toronto,        //6
    Paris,          //7
    Nice,           //8
    Rome,           //9
    Milan,          //10
    London,         //11
    Manchester,     //12
    Basel,          //13
    Luzern,         //14
    Munich,         //15
    Frankfurt,      //16
    Berlin,         //17
    Barcelona,      //18
    Madrid,         //19
    Amsterdam,      //20
    Stockholm,      //21
    Oslo,           //22
    Hanoi,          //23
    Bangkok,        //24
    KualaLumpur,    //25
    Singapore,      //26
    Sydney,         //27
    SaoPaulo,       //28
    Cairo,          //29
    Beijing,        //30
    Nairobi,        //31
    Cancun,         //32
    BuenosAires,    //33
    Reykjavik,      //34
    Glasgow,        //35
    Warsow,         //36
    Istanbul,       //37
    Dubai,          //38
    CapeTown        //39
} place_t;// 이넘이라서 가능한 값들의 모임임 

char countryName[N_PLACE+1][MAX_PLACENAME] =//41곱하기100개임 
{   "Seoul",
    "Jeju",
    "Tokyo",
    "LosAngeles",
    "NewYork",
    "Texas",
    "Toronto",
    "Paris",
    "Nice",
    "Rome",
    "Milan",
    "London",
    "Manchester",
    "Basel",
    "Luzern",
    "Munich",
    "Frankfurt",
    "Berlin",
    "Barcelona",
    "Madrid",
    "Amsterdam",
    "Stockholm",
    "Oslo",
    "Hanoi",
    "Bangkok",
    "KualaLumpur",
    "Singapore",
    "Sydney",
    "SaoPaulo",
    "Cairo",
    "Beijing",
    "Nairobi",
    "Cancun",
    "BuenosAires",
    "Reykjavik",
    "Glasgow",
    "Warsow",
    "Istanbul",
    "Dubai",
    "CapeTown",
    "Unrecognized"
};//나라이름 모음  

typedef struct ifs_ele {
	int index;//number
	int age;//age
	unsigned int time;//time
	place_t place[N_HISTORY];//place[N_HISTORY]
} ifs_ele_t;//구조체임  

int i;

void* ifctele_genElement(int index, int age, unsigned int detected_time, int history_place[N_HISTORY])
{
	ifs_ele_t* ptr;//구조체를 가르키는 포인터 생성 
	
	ptr = (ifs_ele_t*)malloc(sizeof(ifs_ele_t));
	ptr->index = index;
	ptr->age = age;
	ptr->time = detected_time;
	
    for (i=0;i<N_HISTORY;i++)
	{
		ptr-> place[i]=history_place[i]; 	
	}
	return ptr;
}

int ifctele_getAge(void* obj)
{
	ifs_ele_t* stptr = (ifs_ele_t*)obj;
	
	return stptr->age;
}

int ifctele_getHistPlaceIndex(void* obj, int index)
{
	ifs_ele_t*  ptr=(ifs_ele_t*)obj;
	place_t(pIndex);
	return ptr->place[index];
	
}

unsigned int ifctele_getinfestedTime(void* obj)
{
	ifs_ele_t* ptr = (ifs_ele_t*)obj;
	return ptr->time;
	
}


//char* ifctele_getPlaceName(int placeIndex);


void ifctele_printElement(void* obj)
{
	ifs_ele_t* ptr = (ifs_ele_t*)obj;
	printf("환자번호 %i 번",(ptr->index)+1); 
	printf("나이: %i\n", ptr->age);
	printf("감염기간: %i\n", ptr->time);
	printf("장소: ");
	for(i=0;i<N_HISTORY;i++)
	{
		printf("  %s",ifctele_getPlaceName(ptr->place[i]));
	}
}




char* ifctele_getPlaceName(int placeIndex)
{
	return countryName[placeIndex];
}

//
//  Job_Scheduler.cpp
//  Job Scheduler
//
//  Created by mohammadButt on 4/11/15.
//  Copyright (c) 2015 M Butt. All rights reserved.
//

#include "Job_Scheduler.h"


Job_Scheduler::Job_Scheduler(){
    
    system("clear");
    cout<<"\n\n\n"
    <<"Created by: Mohammad Butt\n"
    <<"Course: Operating Systems\n"
    <<"Professor: Anatoly Gordonov\n"
    <<"Date created: April 11, 2015\n\n"
    <<"<---------------- JOB SCHEDULING SYSTEM --------------->\n\n"
    <<"This program allows a user to simulate these job scheduling algorithms:\n"
    <<"\t1. First Come First Serve\n"
    <<"\t2. Shortest Job Next\n"
    <<"\t3. Priority\n\n";
    
    create_jobs();
    display_jobs();
    
    
    
    
}
Job_Scheduler::~Job_Scheduler(){
    
}

void Job_Scheduler::display_jobs(int arr){
    cout<<"\tJob id\t\tArrival\t\tCPU Time\t\tTerminated\t\tTurnaround\n";
    for(int i = 0; i < num_of_j; i++){
        cout<<jobs[arr][i].my_id<<"\t\t"
        <<jobs[arr][i].arrival_time<<"\t\t"
        <<jobs[arr][i].cpu_time<<"\t\t"
        <<jobs[arr][i].terminated_time<<"\t\t"
        <<jobs[arr][i].turn_around_time<<"\n";
    }
    cout<<endl;
}
void Job_Scheduler::display_schedule(){
    
}
void Job_Scheduler::display_results(){
    cout<<"FIRST COME FIRST SERVE:\n";
    display_jobs(1);
    cout<<"Average turnaround: "<<average_turnaround(int arr[])<<endl;
    
}

void Job_Scheduler::create_jobs(){
    int input;
    // prompt for number of partitions
    num_of_j=prompt_int("How many jobs would you like to create...");
    while(num_of_j>=5){
        cout<<"Sorry, too many jobs.\n";
        num_of_j=prompt_int("How many jobs would you like to create...");
    }
    
    allocate_arrays();
    
    // Allocate jobs
    cout<<"Enter the Job arrival times.\n";
    for(int i = 0; i < num_of_j ; i++){
        cout<<"Job "<<jobs[0][i].my_id<<" ...";
        input = prompt_int(" arrival time...");
        for(int j = 0; j < 4 ; j++)
            jobs[j][i].arrival_time = input;
    }
    cout<<"Enter the Job cpu times.\n";
    for(int i = 0; i < num_of_j ; i++){
        cout<<"Job "<<jobs[0][i].my_id<<" ...";
        input = prompt_int(" cpu time...");
        for (int j = 0 ; j<4 ; j++){
            jobs[j][i].cpu_time = input;
        }
    }
    
    cout<<"Enter the Job priorities.\n";
    for(int i = 0; i < num_of_j ; i++){
        cout<<"Job "<<jobs[0][i].my_id<<" ...";
        input = prompt_int(" priority...");
        for (int j = 0 ; j<4 ; j++){
            jobs[j][i].priority = input;
        }
    }
    
    
}


void Job_Scheduler::allocate_arrays(){
    // allocate array
    jobs = new Job*[num_of_j];
    fcfs_order = new int[num_of_j];
    sjn_order = new int[num_of_j];
    prty_order = new int[num_of_j];
    original_order = new int[num_of_j];
    for(int i = 0; i < 4; i++){
        for(int j = 0 ; j< num_of_j; j++)
            jobs[i][j].my_id = j;
        original_order[i] = i;
    }

}

void Job_Scheduler::first_come_first_serve(){
    int time =0;
    
    for(int i = 0 ; i < num_of_j ; i++){
        fcfs_order[i]=i;
        jobs[1][i].terminated_time = time + jobs[1][i].cpu_time;
        jobs[1][i].turn_around_time = jobs[1][i].terminated_time - jobs[1][i].arrival_time;
        time +=jobs[1][i].cpu_time;
    }
}
void Job_Scheduler::shortest_job_next(){
    int time =0;
    int total_time = 0;
    for(int i = 0; i < num_of_j ; i++){
        jobs[2][i].queued = false;
        jobs[2][i].finished = false;
        total_time = jobs[2][i].cpu_time;
    }
    int lowest = -1;
    while (time < total_time){
        //check for new jobs to queue
        for(int i = 0; i < num_of_j; i++){
            if(jobs[2][i].arrival_time >= time && !jobs[2][i].finished){
                jobs[2][i].queued = true;
            }
        }
        
        //find shortest job
        for(int i = 0; i < num_of_j ; i++){
            if(jobs[2][i].queued){
                if(lowest != -1){
                    if(jobs[2][i].cpu_time < jobs[2][lowest].cpu_time){
                        lowest = i;
                    }
                }
                else{
                    lowest = i;
                }
            }
        }
        
        jobs[2][lowest].terminated_time = time + jobs[2][lowest].cpu_time;
        jobs[2][lowest].turn_around_time = jobs[2][lowest].terminated_time - jobs[2][lowest].arrival_time;
        time += jobs[2][lowest].cpu_time;
        
    }
}
void Job_Scheduler::priority(){

    for(int i = 0 ; i<num_of_j; i++){
        for(int j = 0 ; j < num_of_j ; j++){
        }
    }
}

double Job_Scheduler::average_turnaround(int arr){
    double sum = 0;
    for(int i = 0 ; i< num_of_j ; i++){
        sum += jobs[arr][i].turn_around_time;
    }
    return sum/num_of_j;
}

void Job_Scheduler::execute(int i, int arr[]){
    int time =0;
    
    for(int j = 0; j < num_of_j; j++){
        jobs[i][arr[j]].terminated_time = time + jobs[i][arr[j]].cpu_time;
        jobs[i][arr[j]].turn_around_time = jobs[i][arr[j]].terminated_time - jobs[i][arr[j]].arrival_time;
        time += jobs[i][arr[j]].cpu_time;
    }
}

int Job_Scheduler::prompt_int(string message){
    int input;
    cout<<message;
    cin>>input;
    
    while(cin.fail()){
        cout<<"Not a valid entry. Try an integer.\n"<<message;
        cin.clear();
        cin.ignore(256,'\n');
        cin>>input;
    }
    return input;
}

//
//  Job_Scheduler.h
//  Job Scheduler
//
//  Created by mohammadButt on 4/11/15.
//  Copyright (c) 2015 M Butt. All rights reserved.
//

#ifndef __Job_Scheduler__Job_Scheduler__
#define __Job_Scheduler__Job_Scheduler__

//#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct Job{
    int my_id;
    int arrival_time;
    int terminated_time;
    int cpu_time;
    int turn_around_time;
    int priority;
    bool queued;
    bool finished;

};

class Job_Scheduler{

private:
    Job **jobs;
    int *fcfs_order, *sjn_order, *prty_order, *original_order;
    //Job* fcfs, sjn, prty;
    int num_of_j;
    int current_cpu_time;
    
public:
    Job_Scheduler();
    ~Job_Scheduler();
    
    void display_jobs(int arr);
    void display_schedule();
    void display_results();
    
    void create_jobs();
    void allocate_arrays();
    int prompt_int(string message);
    
    void first_come_first_serve();
    void shortest_job_next();
    void priority();
    
    double average_turnaround(int arr);
    void execute(int i, int arr[]);
};



#endif /* defined(__Job_Scheduler__Job_Scheduler__) */

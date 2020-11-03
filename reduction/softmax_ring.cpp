// Created by Kaustubh Shivdikar
// Date: 2nd Nov 2020

int next_node(int node_id, int total_nodes) {
    return ((node_id + 1) % total_nodes); // To make sure we wrap around the last one
}

int prev_node(int node_id, int total_nodes) {
    int prev_node_id = node_id - 1;
    if (prev_node_id < 0) {
        prev_node_id = (total_nodes - 1);
    }
    return (prev_node_id);
}



void softmax(float *A, int sz, float *B) {
    int self = get_my_id();
    int proc_count = get_proc_count();
    float *send_buf = (float*)malloc(sz * sizeof(float));
    float *recv_buf = (float*)malloc(sz * sizeof(float));
    float sum_A = 0.0;

    for (int i=0; i < sz; i++) { // We dont want to modify the input data
        send_buf[i] = exp(A[i]);
    }

    int send_id = next_node(self, proc_count); // Sending to immediate next node in clockwise direction.
    int recv_id = prev_node(self, proc_count); // Receiving from immediate previouse node in anti-clockwise direction.
    send(send_id, buf, sz); // First step, send data to neighboring nodes.

    for (int step_id = 0; step_id < (proc_count - 1); step_id++) { // Recurring steps:   RECV --> PROCESS --> SEND
        recv(recv_id, recv_buf, sz);
        for (int i = 0; i < sz; ++i) {
            sum_A += recv_buf[i];
        }
        send(send_id, buf, sz);
    }

    // Final step
    // Receive data from last step

    recv(recv_id, recv_buf, sz);
    for (int i = 0; i < sz; ++i) {
        sum_A += recv_buf[i];
    }
    for (int i = 0; i < sz; ++i) {
        B[i] = (exp(A[i]) / sum_A);
    }
}



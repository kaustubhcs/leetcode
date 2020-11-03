#define EVEN 0
#define ODD 1
#define ONLINE true
#define OFFLINE false

int get_sending_id(int my_id, int root_id, int step_id) {
    // The best part about this function is that this function can be executed asynchronously. (It doesn't have any dependencies in the control flow).
    // Dynamic programming will be helpful here!
    bool keep_odd_index = false;
    bool keep_even_index = false;

    if (( (root_id / pow(2,step_id)) % 2) == EVEN) {// The next index of root id will be even.
        // We would want to keep data on even indices so root node keeps data.
        // Also we are using int divide by int and using that as a floor function (Which is not a good idea to rely on.
        // Ideally we would use a floor function)
        keep_even_index = true;
    } else {
        keep_odd_index = true;
    }

    if (keep_even_index) {
        int send_to_id;
        if ((my_id % 2) == ODD) {
            send_to_id = my_id - (pow(2,step_id);
            return (send_to_id);
        } else {
            send_to_id = my_id;
            return(my_id);
        }
    }
    if (keep_odd_index) {
        int send_to_id;
        if ((my_id % 2) == EVEN) {
            send_to_id = my_id + (pow(2,step_id));
            return (send_to_id);
        } else {
            send_to_id = my_id;
            return(my_id);
        }
    }
}

int get_receiving_id(int my_id, int root_id, int step_id) {
    // The best part about this function is that this function can be executed asynchronously. (It doesn't have any dependencies in the control flow).
    // Dynamic programming will be helpful here!
    bool keep_odd_index = false;
    bool keep_even_index = false;

    if (( (root_id / pow(2,step_id)) % 2) == EVEN) {
        keep_even_index = true;
    } else {
        keep_odd_index = true;
    }

    if (keep_even_index) {
        int recv_to_id;
        recv_to_id = my_id + (pow(2,step_id);
        return (recv_to_id);
    }
    if (keep_odd_index) {
        int recv_to_id;
        recv_to_id = my_id - (pow(2,step_id));
        return (recv_to_id);
    }
}


int calculate_total_steps(int total_processors) {
    return (int( log(total_processors) / log(2) ))
}

void reduce(int root, void* buf, int sz) {
    bool node_state = ONLINE; // To make sure we stop nodes from computing when they compute their part.
    int self = get_my_id();
    int proc_count = get_proc_count();
    int total_steps = calculate_total_steps(proc_count);
    int *recv_buf = (int*)malloc(sz * sizeof(int));
    int send_to_id;

    for (int step_id = 0; step_id < total_steps; step_id++) { // Thus Total steps = O(log(P))
        if (node_state == ONLINE) {
            send_to_id = get_sending_id(self, root, step_id);
            if (send_to_id != self) { // Send over the network only if target node is someone else.
                // Thus total messages sent = O(P)
                send(send_to_id, buf, sz);
                node_state = OFFLINE;
            }

            if (node_state == ONLINE) {
                int recv_id;
                recv_id = get_receiving_id(self, root, step_id);
                recv(recv_id, recv_buf, sz);
                for (int i = 0; i < sz; ++i) {
                    buf[i] += recv_buf[i];
                }
            }
        }
    }


}
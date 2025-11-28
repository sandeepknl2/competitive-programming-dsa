queue<int> q; 
int n = tickets.size(); 

// Push all people into the queue by their indices
for (int i = 0; i < n; i++) 
    q.push(i); 

int time = 0; 

while (true) 
{
    if (tickets[k] == 0) 
        break;  // kth person finished buying

    int curr = q.front(); // get person at the front
    q.pop();              // remove them from front of queue

    tickets[curr]--;      // buy 1 ticket
    time++;               // 1 second passes

    if (tickets[curr] != 0) 
    {
        q.push(curr);     // if person still needs tickets, go to end
    }
}

return time;


optimized
using minimu bys before and after
int total = 0;
for (int i = 0; i < tickets.size(); ++i) {
    if (i <= k) {
        total += min(tickets[i], tickets[k]);
    } else {
        total += min(tickets[i], tickets[k] - 1);
    }
}
return total;

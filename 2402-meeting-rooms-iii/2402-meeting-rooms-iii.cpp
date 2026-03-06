class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> roomAvailableAt(n, 0);
        vector<int> frequency(n, 0);
        sort(meetings.begin(),meetings.end());
        for (auto meet : meetings) {
            int start = meet[0];
            int end = meet[1];
            int duration = end - start;
            // agar koi na koi room khaali hai toh checking for the best room to
            // be assigned;
            bool found=false;
            int freefirstRoom = 0;
            long long bestEndingTime = LLONG_MAX;
            for (int room = 0; room < n; room++) {
                // for checking whether we found a free room or not
                if (roomAvailableAt[room]<=start) {
                    roomAvailableAt[room] = end;
                    frequency[room]++;
                    found=true;
                    break;
                }

                if (roomAvailableAt[room] < bestEndingTime) { // for finding the room which will be free first 
                    bestEndingTime = roomAvailableAt[room];
                    freefirstRoom = room;
                }
            }
            // in case we couldn't assign the meeting to any free room
            if (!found) {
                roomAvailableAt[freefirstRoom] += duration;
                frequency[freefirstRoom]++;
            }
        }
        int roomWithMax=0;
        int max_meetings=0;
        for(int i=0;i<n;i++){
            if(frequency[i]>max_meetings){
                max_meetings=frequency[i];
                roomWithMax=i;
            }
        }
        return roomWithMax;
    }
};
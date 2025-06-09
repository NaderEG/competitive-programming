class Solution {
public:
    int countTime(string time) {
        int possible_hours = 1;
        if(time[0] == '?' && time[1] == '?') {
            possible_hours = 24;
        } else if(time[1] == '?') {
            if(time[0] == '2') {
                possible_hours = 4;
            } else {
                possible_hours = 10;
            }
        } else if(time[0] == '?') {
            if(time[1] == '0' || time[1] == '1' || time[1] == '2' || time[1] == '3') {
                possible_hours = 3;
            } else {
                possible_hours = 2;
            }
        }

        int possible_minutes = 1;
        if(time[3] == '?' && time[4] == '?') {
            possible_minutes = 60;
        } else if(time[3] == '?') {
            possible_minutes = 6;
        } else if(time[4] == '?') {
            possible_minutes = 10;
        }
        return possible_minutes*possible_hours;
    }
};
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{   //wins：time of winning，loses:times of losing，times: times we play，A：right position and right value，B:right value but incorrect position
    //tmp:variable which is used to save the input number，index: times that we have already guessed，num:array for three random integers 
    int  wins = 0, loses = 0, times = 0, i, j, A = 0, B = 0, tmp, index, num[3];
    char judgement;        //judgement: the flag to determine whether the player wants to play again
	bool  flag1 = 1, flag2 = 1;        // flag: to determine whether the three random integers are same or not 
	srand(time(NULL));           //detemine the time seed
	cout << "需要玩游戏吗？（Y/N）" ; 
	cin >> judgement;
	while (judgement == 'Y') {
        num[0]=rand() * 10 / (RAND_MAX + 1);       //produce the first random number 
		while (flag1) {
            num[1] = rand() * 10 / (RAND_MAX + 1);
			if (num[1] != num[0]) {      //if the second random number is different from the first, we break the while loop
			    flag1 = 0;
			}
	    }
		while (flag2) {
			num[2] = rand() * 10 / (RAND_MAX + 1);
			if (num[2] != num[1] && num[2] != num[0]) {     //if the third random number is different from the first and the second, we break the while loop
				flag2=0;
			}
		}
        for (index = 0; index<7; ++index) {        //7 opportunities
            A = 0;     //every time we have to initialize A and B
			B = 0;
			cout << "请输入你要猜测的数字：";
			for (i = 0; i < 3; ++i) {
        	    cin >> tmp;             //the guessed number will be saved in the var tmp 
				if (tmp == num[i]) {        //right value, right position, ++A
        		    ++A;
        	    }
        	    else {
        		    for (j = 0; j < 3; ++j) {        //incorrect position, correct value,++B 
        			    if (tmp == num[j]) {
                            ++B; 
        				    break;
        			    }
        		    }  
        	    } 
            }
            if (A == 3) break;       //A==3 makes a sign that a correct guess has been made, so we break the loop
            cout << A << 'A' << B << 'B' << endl;    //if the guess is wrong, we give the player some reminders.
            
        }        //7-level loop has ended
        if (A == 3) {                // a correct guess, ++wins 
        	cout << "恭喜你，猜对了"; 
        	++wins;
        }
        else{            // a incorrext guess, ++loses
        	cout << "很遗憾，你没有在规定次数内猜对。答案是" << num[0] << num[1] << num[2] << endl;
		    ++loses;
		}
		++times;       // the times that the player has played should be added by 1
		cout << "需要玩游戏吗？（Y/N）";
		cin >> judgement; 
	}
    cout << "你一共玩了" << times << "局，赢了" << wins << "局，输了" << loses << "局";         //give the game records at the end  
	return 0;

}

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>answer(n);
        for(int i=1;i<=n;i++){
            if(i%3==0 && i%5==0){
                answer[i-1]="FizzBuzz";
            }
            else if(i%3==0){
                answer[i-1]="Fizz";//why i used [i-1] instead of i beacuse answer i would means answer[3]position 4 like 0123 but we want answer in 3 so i-1
            }else if( i%5==0){
                answer[i-1]="Buzz";
            }   else{
                answer[i-1]=to_string(i);
            }
        }
        return answer;
    }
};